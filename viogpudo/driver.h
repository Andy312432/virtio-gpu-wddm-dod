#pragma once
#include "helper.h"

extern "C"
DRIVER_INITIALIZE DriverEntry;

NTSTATUS InitDisplayOnly(
    _In_ DRIVER_OBJECT* pDriverObject,
    _In_ UNICODE_STRING* pRegistryPath
);

NTSTATUS InitFullGraphicsDriver(
    _In_ DRIVER_OBJECT* pDriverObject,
    _In_ UNICODE_STRING* pRegistryPath
);

//
// PnP DDIs
//

VOID
VioGpuDodUnload(VOID);

// If uncommenting ENABLE_DXGK_SAL in the sources file, all the below function prototypes should be updated to use
// the function typedef's from the header files. Additionally, annotations on the function definitions can be removed
// as they are inherited from the prototype definition here. As an example the entire 4-line prototype for BddDdiAddDevice
// is replaced by the single commented line below:
// DXGKDDI_ADD_DEVICE BddDdiAddDevice;
NTSTATUS
VioGpuDodAddDevice(
    _In_ DEVICE_OBJECT* pPhysicalDeviceObject,
    _Outptr_ PVOID*  ppDeviceContext);

NTSTATUS
VioGpuDodRemoveDevice(
    _In_  VOID* pDeviceContext);

NTSTATUS
VioGpuDodStartDevice(
    _In_  VOID*              pDeviceContext,
    _In_  DXGK_START_INFO*   pDxgkStartInfo,
    _In_  DXGKRNL_INTERFACE* pDxgkInterface,
    _Out_ ULONG*             pNumberOfViews,
    _Out_ ULONG*             pNumberOfChildren);

NTSTATUS
VioGpuDodStopDevice(
    _In_  VOID* pDeviceContext);

VOID
VioGpuDodResetDevice(
    _In_  VOID* pDeviceContext);


NTSTATUS
VioGpuDodDispatchIoRequest(
    _In_  VOID*                 pDeviceContext,
    _In_  ULONG                 VidPnSourceId,
    _In_  VIDEO_REQUEST_PACKET* pVideoRequestPacket);

NTSTATUS
VioGpuDodSetPowerState(
    _In_  VOID*              pDeviceContext,
    _In_  ULONG              HardwareUid,
    _In_  DEVICE_POWER_STATE DevicePowerState,
    _In_  POWER_ACTION       ActionType);

NTSTATUS
VioGpuDodQueryChildRelations(
    _In_                             VOID*                  pDeviceContext,
    _Out_writes_bytes_(ChildRelationsSize) DXGK_CHILD_DESCRIPTOR* pChildRelations,
    _In_                             ULONG                  ChildRelationsSize);

NTSTATUS
VioGpuDodQueryChildStatus(
    _In_    VOID*              pDeviceContext,
    _Inout_ DXGK_CHILD_STATUS* pChildStatus,
    _In_    BOOLEAN            NonDestructiveOnly);

NTSTATUS
VioGpuDodQueryDeviceDescriptor(
    _In_  VOID*                     pDeviceContext,
    _In_  ULONG                     ChildUid,
    _Inout_ DXGK_DEVICE_DESCRIPTOR* pDeviceDescriptor);

// Must be Non-Paged
BOOLEAN
VioGpuDodInterruptRoutine(
    _In_  VOID* pDeviceContext,
    _In_  ULONG MessageNumber);

VOID
VioGpuDodDpcRoutine(
    _In_  VOID* pDeviceContext);

//
// WDDM Display Only Driver DDIs
//

NTSTATUS
APIENTRY
VioGpuDodQueryAdapterInfo(
    _In_ CONST HANDLE                         hAdapter,
    _In_ CONST DXGKARG_QUERYADAPTERINFO*      pQueryAdapterInfo);

NTSTATUS
APIENTRY
VioGpuDodSetPointerPosition(
    _In_ CONST HANDLE                         hAdapter,
    _In_ CONST DXGKARG_SETPOINTERPOSITION*    pSetPointerPosition);

NTSTATUS
APIENTRY
VioGpuDodSetPointerShape(
    _In_ CONST HANDLE                         hAdapter,
    _In_ CONST DXGKARG_SETPOINTERSHAPE*       pSetPointerShape);

NTSTATUS
APIENTRY
VioGpuDodEscape(
    _In_ CONST HANDLE hAdapter,
    _In_ CONST DXGKARG_ESCAPE *pEscape);

NTSTATUS
VioGpuDodQueryInterface(
    _In_ CONST PVOID                          pDeviceContext,
    _In_ CONST PQUERY_INTERFACE               pQueryInterface);

NTSTATUS
APIENTRY
VioGpuDodPresentDisplayOnly(
    _In_ CONST HANDLE                         hAdapter,
    _In_ CONST DXGKARG_PRESENT_DISPLAYONLY*   pPresentDisplayOnly);

NTSTATUS
APIENTRY
VioGpuDodIsSupportedVidPn(
    _In_ CONST HANDLE                         hAdapter,
    _Inout_ DXGKARG_ISSUPPORTEDVIDPN*         pIsSupportedVidPn);

NTSTATUS
APIENTRY
VioGpuDodRecommendFunctionalVidPn(
    _In_ CONST HANDLE                                   hAdapter,
    _In_ CONST DXGKARG_RECOMMENDFUNCTIONALVIDPN* CONST  pRecommendFunctionalVidPn);

NTSTATUS
APIENTRY
VioGpuDodRecommendVidPnTopology(
    _In_ CONST HANDLE                                 hAdapter,
    _In_ CONST DXGKARG_RECOMMENDVIDPNTOPOLOGY* CONST  pRecommendVidPnTopology);

NTSTATUS
APIENTRY
VioGpuDodRecommendMonitorModes(
    _In_ CONST HANDLE                                hAdapter,
    _In_ CONST DXGKARG_RECOMMENDMONITORMODES* CONST  pRecommendMonitorModes);

NTSTATUS
APIENTRY
VioGpuDodEnumVidPnCofuncModality(
    _In_ CONST HANDLE                                  hAdapter,
    _In_ CONST DXGKARG_ENUMVIDPNCOFUNCMODALITY* CONST  pEnumCofuncModality);

NTSTATUS
APIENTRY
VioGpuDodSetVidPnSourceVisibility(
    _In_ CONST HANDLE                             hAdapter,
    _In_ CONST DXGKARG_SETVIDPNSOURCEVISIBILITY*  pSetVidPnSourceVisibility);

NTSTATUS
APIENTRY
VioGpuDodCommitVidPn(
    _In_ CONST HANDLE                         hAdapter,
    _In_ CONST DXGKARG_COMMITVIDPN* CONST     pCommitVidPn);

NTSTATUS
APIENTRY
VioGpuDodUpdateActiveVidPnPresentPath(
    _In_ CONST HANDLE                                       hAdapter,
    _In_ CONST DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH* CONST  pUpdateActiveVidPnPresentPath);

NTSTATUS
APIENTRY
VioGpuDodQueryVidPnHWCapability(
    _In_ CONST HANDLE                         hAdapter,
    _Inout_ DXGKARG_QUERYVIDPNHWCAPABILITY*   pVidPnHWCaps);

NTSTATUS
APIENTRY
VioGpuDodStopDeviceAndReleasePostDisplayOwnership(
    _In_  VOID*                          pDeviceContext,
    _In_  D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId,
    _Out_ DXGK_DISPLAY_INFORMATION*      DisplayInfo);

// Must be Non-Paged
NTSTATUS
APIENTRY
VioGpuDodSystemDisplayEnable(
    _In_  VOID* pDeviceContext,
    _In_  D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId,
    _In_  PDXGKARG_SYSTEM_DISPLAY_ENABLE_FLAGS Flags,
    _Out_ UINT* Width,
    _Out_ UINT* Height,
    _Out_ D3DDDIFORMAT* ColorFormat);

// Must be Non-Paged
VOID
APIENTRY
VioGpuDodSystemDisplayWrite(
    _In_  VOID* pDeviceContext,
    _In_  VOID* Source,
    _In_  UINT  SourceWidth,
    _In_  UINT  SourceHeight,
    _In_  UINT  SourceStride,
    _In_  UINT  PositionX,
    _In_  UINT  PositionY);

//FullGraphs specific
NTSTATUS APIENTRY VioGpuCreateDevice(
    IN_CONST_HANDLE hAdapter,
    INOUT_PDXGKARG_CREATEDEVICE pCreateDevice
);

NTSTATUS APIENTRY VioGpuCreateAllocation(
    _In_ IN_CONST_HANDLE hAdapter,
    _Inout_ INOUT_PDXGKARG_CREATEALLOCATION pCreateAllocation
);

NTSTATUS APIENTRY VioGpuNotifyAcpiEvent(
    _In_  IN_CONST_PVOID MiniportDeviceContext,
    _In_  IN_DXGK_EVENT_TYPE EventType,
    _In_  IN_ULONG Event,
    _In_  IN_PVOID Argument,
    _Out_ OUT_PULONG AcpiFlags
);

void VioGpuControlEtwLogging(
    _In_ IN_BOOLEAN Enable,
    _In_ IN_ULONG Flags,
    _In_ IN_UCHAR Level
);


NTSTATUS APIENTRY VioGpuDestroyAllocation(
    _In_ IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_PDXGKARG_DESTROYALLOCATION pDestroyAllocation
);

NTSTATUS APIENTRY VioGpuDescribeAllocation(
    _In_     IN_CONST_HANDLE hAdapter,
    _Inout_ INOUT_PDXGKARG_DESCRIBEALLOCATION pDescribeAllocation
);

NTSTATUS APIENTRY VioGpuGetStandardAllocationDriverData(
    _In_     IN_CONST_HANDLE hAdapter,
    _Inout_ INOUT_PDXGKARG_GETSTANDARDALLOCATIONDRIVERDATA pGetStandardAllocationDriverData
);

NTSTATUS APIENTRY VioGpuAcquireSwizzlingRange(
    _In_     IN_CONST_HANDLE hAdapter,
    _Inout_ INOUT_PDXGKARG_ACQUIRESWIZZLINGRANGE pAcquireSwizzlingRange
);

NTSTATUS APIENTRY VioGpuReleaseSwizzlingRange(
    _In_ IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_PDXGKARG_RELEASESWIZZLINGRANGE pReleaseSwizzlingRange
);

NTSTATUS APIENTRY VioGpuPatch(
    _In_ IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_PDXGKARG_PATCH pPatch
);

NTSTATUS APIENTRY VioGpuSubmitCommand(
    _In_ IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_PDXGKARG_SUBMITCOMMAND pSubmitCommand
);

NTSTATUS APIENTRY VioGpuPreemptCommand(
    _In_ IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_PDXGKARG_PREEMPTCOMMAND pPreemptCommand
);

NTSTATUS APIENTRY VioGpuBuildPagingBuffer(
    _In_     IN_CONST_HANDLE hAdapter,
    _Inout_ IN_PDXGKARG_BUILDPAGINGBUFFER pBuildPagingBuffer
);

NTSTATUS APIENTRY VioGpuSetPalette(
    _In_ IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_PDXGKARG_SETPALETTE pSetPalette
);

NTSTATUS APIENTRY VioGpuResetFromTimeout(
    _In_ IN_CONST_HANDLE hAdapter
);

NTSTATUS APIENTRY VioGpuRestartFromTimeout(
    _In_ IN_CONST_HANDLE hAdapter
);

NTSTATUS APIENTRY VioGpuCollectDbgInfo(
    _In_ IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_PDXGKARG_COLLECTDBGINFO pCollectDbgInfo
);

NTSTATUS APIENTRY VioGpuQueryCurrentFence(
    _In_     IN_CONST_HANDLE hAdapter,
    _Inout_ INOUT_PDXGKARG_QUERYCURRENTFENCE pCurrentFence
);

NTSTATUS APIENTRY VioGpuRecommendVidPnTopology(
    IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_PDXGKARG_RECOMMENDVIDPNTOPOLOGY_CONST pRecommendVidPnTopology
);

NTSTATUS APIENTRY VioGpuGetScanLine(
    _In_     IN_CONST_HANDLE hAdapter,
    _Inout_ INOUT_PDXGKARG_GETSCANLINE pGetScanLine
);

NTSTATUS APIENTRY VioGpuStopCapture(
    _In_ IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_PDXGKARG_STOPCAPTURE pStopCapture
);

NTSTATUS APIENTRY VioGpuControlInterrupt(
    _In_ IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_DXGK_INTERRUPT_TYPE InterruptType,
    _In_ IN_BOOLEAN EnableInterrupt
);

NTSTATUS APIENTRY VioGpuCreateOverlay(
    _In_     IN_CONST_HANDLE hAdapter,
    _Inout_ INOUT_PDXGKARG_CREATEOVERLAY pCreateOverlay
);

NTSTATUS APIENTRY VioGpuDestroyDevice(
    _In_ IN_CONST_HANDLE hDevice
);

NTSTATUS APIENTRY VioGpuOpenAllocation(
    _In_ IN_CONST_HANDLE hDevice,
    _In_ IN_CONST_PDXGKARG_OPENALLOCATION pOpenAllocation
);

NTSTATUS APIENTRY VioGpuCloseAllocation(
    _In_ IN_CONST_HANDLE hDevice,
    _In_ IN_CONST_PDXGKARG_CLOSEALLOCATION pCloseAllocation
);

NTSTATUS APIENTRY VioGpuRender(
    _In_     IN_CONST_HANDLE hContext,
    _Inout_ INOUT_PDXGKARG_RENDER pRender
);

NTSTATUS APIENTRY VioGpuPresent(
    _In_     IN_CONST_HANDLE hContext,
    _Inout_ INOUT_PDXGKARG_PRESENT pPresent
);


NTSTATUS APIENTRY VioGpuUpdateOverlay(
    _In_ IN_CONST_HANDLE hOverlay,
    _In_ IN_CONST_PDXGKARG_UPDATEOVERLAY pUpdateOverlay
);


NTSTATUS APIENTRY VioGpuFlipOverlay(
    _In_ IN_CONST_HANDLE hOverlay,
    _In_ IN_CONST_PDXGKARG_FLIPOVERLAY pFlipOverlay
);

NTSTATUS APIENTRY VioGpuDestroyOverlay(
    _In_ IN_CONST_HANDLE hOverlay
);

NTSTATUS APIENTRY VioGpuCreateContext(
    _In_     IN_CONST_HANDLE hDevice,
    _Inout_ INOUT_PDXGKARG_CREATECONTEXT pCreateContext
);

NTSTATUS APIENTRY VioGpuDestroyContext(
    _In_ IN_CONST_HANDLE hContext
);

NTSTATUS APIENTRY VioGpuSetDisplayPrivateDriverFormat(
    _In_ IN_CONST_HANDLE hAdapter,
    _In_ IN_CONST_PDXGKARG_SETDISPLAYPRIVATEDRIVERFORMAT pSetDisplayPrivateDriverFormat
);