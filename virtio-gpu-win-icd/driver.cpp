#include "driver.h"

HRESULT InitKernelTHunks()
{
    HINSTANCE hInst = NULL;

    hInst = LoadLibrary("gdi32.dll");
    if (hInst == NULL) {
        return E_FAIL;
    }

    pfnKTCreateAllocation = (PFND3DKMT_CREATEALLOCATION)
        GetProcAddress((HMODULE)hInst, "D3DKMTCreateAllocation");

    pfnKTQueryResourceInfo = (PFND3DKMT_QUERYRESOURCEINFO)
        GetProcAddress((HMODULE)hInst, "D3DKMTQueryResourceInfo");

    pfnKTOpenResource = (PFND3DKMT_OPENRESOURCE)
        GetProcAddress((HMODULE)hInst, "D3DKMTCreateAllocation");

    pfnKTDestroyAllocation = (PFND3DKMT_DESTROYALLOCATION)
        GetProcAddress((HMODULE)hInst, "D3DKMTDestroyAllocation");

    pfnKTSetAllocationPriority = (PFND3DKMT_SETALLOCATIONPRIORITY)
        GetProcAddress((HMODULE)hInst, "D3DKMTSetAllocationPriority");

    pfnKTQueryAllocationResidency = (PFND3DKMT_QUERYALLOCATIONRESIDENCY)
        GetProcAddress((HMODULE)hInst, "D3DKMTQueryAllocationResidency");

    pfnKTCreateDevice = (PFND3DKMT_CREATEDEVICE)
        GetProcAddress((HMODULE)hInst, "D3DKMTCreateDevice");

    pfnKTDestroyDevice = (PFND3DKMT_DESTROYDEVICE)
        GetProcAddress((HMODULE)hInst, "D3DKMTDestroyDevice");

    pfnKTQueryAdapterInfo = (PFND3DKMT_QUERYADAPTERINFO)
        GetProcAddress((HMODULE)hInst, "D3DKMTQueryAdapterInfo");

    pfnKTLock = (PFND3DKMT_LOCK)
        GetProcAddress((HMODULE)hInst, "D3DKMTLock");

    pfnKTUnlock = (PFND3DKMT_UNLOCK)
        GetProcAddress((HMODULE)hInst, "D3DKMTUnlock");

    pfnKTGetDisplayModeList = (PFND3DKMT_GETDISPLAYMODELIST)
        GetProcAddress((HMODULE)hInst, "D3DKMTGetDisplayModeList");

    pfnKTSetDisplayMode = (PFND3DKMT_SETDISPLAYMODE)
        GetProcAddress((HMODULE)hInst, "D3DKMTSetDisplayMode");

    pfnKTGetMultisampleMethodList = (PFND3DKMT_GETDISPLAYMODELIST)
        GetProcAddress((HMODULE)hInst, "D3DKMTGetMultisampleMethodList");

    pfnKTPresent = (PFND3DKMT_PRESENT)
        GetProcAddress((HMODULE)hInst, "D3DKMTPresent");

    pfnKTRender = (PFND3DKMT_RENDER)
        GetProcAddress((HMODULE)hInst, "D3DKMTRender");

    pfnKTOpenAdapterFromHdc = (PFND3DKMT_OPENADAPTERFROMHDC)
        GetProcAddress((HMODULE)hInst, "D3DKMTOpenAdapterFromHdc");

    pfnKTOpenAdapterFromDeviceName = (PFND3DKMT_OPENADAPTERFROMDEVICENAME)
        GetProcAddress((HMODULE)hInst, "D3DKMTOpenAdapterFromDeviceName");

    pfnKTCloseAdapter = (PFND3DKMT_CLOSEADAPTER)
        GetProcAddress((HMODULE)hInst, "D3DKMTCloseAdapter");

    pfnKTGetSharedPrimaryHandle = (PFND3DKMT_GETSHAREDPRIMARYHANDLE)
        GetProcAddress((HMODULE)hInst, "D3DKMTGetSharedPrimaryHandle");

    pfnKTEscape = (PFND3DKMT_ESCAPE)
        GetProcAddress((HMODULE)hInst, "D3DKMTEscape");

    pfnKTSetVidPnSourceOwner = (PFND3DKMT_SETVIDPNSOURCEOWNER)
        GetProcAddress((HMODULE)hInst, "D3DKMTSetVidPnSourceOwner");

    pfnKTReleaseProcessVidPnSourceOwners = (PFND3DKMT_RELEASEPROCESSVIDPNSOURCEOWNERS)
        GetProcAddress((HMODULE)hInst, "D3DKMTReleaseProcessVidPnSourceOwners");

    pfnKTCreateOverlay = (PFND3DKMT_CREATEOVERLAY)
        GetProcAddress((HMODULE)hInst, "D3DKMTCreateOverlay");

    pfnKTUpdateOverlay = (PFND3DKMT_UPDATEOVERLAY)
        GetProcAddress((HMODULE)hInst, "D3DKMTUpdateOverlay");

    pfnKTFlipOverlay = (PFND3DKMT_FLIPOVERLAY)
        GetProcAddress((HMODULE)hInst, "D3DKMTFlipOverlay");

    pfnKTDestroyOverlay = (PFND3DKMT_DESTROYOVERLAY)
        GetProcAddress((HMODULE)hInst, "D3DKMTDestroyOverlay");

    pfnKTWaitForVerticalBlankEvent = (PFND3DKMT_WAITFORVERTICALBLANKEVENT)
        GetProcAddress((HMODULE)hInst, "D3DKMTWaitForVerticalBlankEvent");

    pfnKTSetGammaRamp = (PFND3DKMT_SETGAMMARAMP)
        GetProcAddress((HMODULE)hInst, "D3DKMTSetGammaRamp");

    pfnKTGetDeviceState = (PFND3DKMT_GETDEVICESTATE)
        GetProcAddress((HMODULE)hInst, "D3DKMTGetDeviceState");

    pfnKTCreateDCFromMemory = (PFND3DKMT_CREATEDCFROMMEMORY)
        GetProcAddress((HMODULE)hInst, "D3DKMTCreateDCFromMemory");

    pfnKTDestroyDCFromMemory = (PFND3DKMT_DESTROYDCFROMMEMORY)
        GetProcAddress((HMODULE)hInst, "D3DKMTDestroyDCFromMemory");

    pfnKTSetContextSchedulingPriority = (PFND3DKMT_SETCONTEXTSCHEDULINGPRIORITY)
        GetProcAddress((HMODULE)hInst, "D3DKMTSetContextSchedulingPriority");

    pfnKTGetContextSchedulingPriority = (PFND3DKMT_GETCONTEXTSCHEDULINGPRIORITY)
        GetProcAddress((HMODULE)hInst, "D3DKMTGetContextSchedulingPriority");

    pfnKTSetProcessSchedulingPriorityClass = (PFND3DKMT_SETPROCESSSCHEDULINGPRIORITYCLASS)
        GetProcAddress((HMODULE)hInst, "D3DKMTSetProcessSchedulingPriorityClass");

    pfnKTGetProcessSchedulingPriorityClass = (PFND3DKMT_GETPROCESSSCHEDULINGPRIORITYCLASS)
        GetProcAddress((HMODULE)hInst, "D3DKMTGetProcessSchedulingPriorityClass");

    pfnKTGetScanLine = (PFND3DKMT_GETSCANLINE)
        GetProcAddress((HMODULE)hInst, "D3DKMTGetScanLine");

    pfnKTSetQueuedLimit = (PFND3DKMT_SETQUEUEDLIMIT)
        GetProcAddress((HMODULE)hInst, "D3DKMTSetQueuedLimit");

    pfnKTPollDisplayChildren = (PFND3DKMT_POLLDISPLAYCHILDREN)
        GetProcAddress((HMODULE)hInst, "D3DKMTPollDisplayChildren");

    pfnKTInvalidateActiveVidPn = (PFND3DKMT_INVALIDATEACTIVEVIDPN)
        GetProcAddress((HMODULE)hInst, "D3DKMTInvalidateActiveVidPn");

    pfnKTCheckOcclusion = (PFND3DKMT_CHECKOCCLUSION)
        GetProcAddress((HMODULE)hInst, "D3DKMTCheckOcclusion");

    pfnKTGetPresentHistory = (PFND3DKMT_GETPRESENTHISTORY)
        GetProcAddress((HMODULE)hInst, "D3DKMTGetPresentHistory");

    pfnKTCreateContext = (PFND3DKMT_CREATECONTEXT)
        GetProcAddress((HMODULE)hInst, "D3DKMTCreateContext");

    pfnKTDestroyContext = (PFND3DKMT_DESTROYCONTEXT)
        GetProcAddress((HMODULE)hInst, "D3DKMTDestroyContext");

    pfnKTCreateSynchronizationObject = (PFND3DKMT_CREATESYNCHRONIZATIONOBJECT)
        GetProcAddress((HMODULE)hInst, "D3DKMTCreateSynchronizationObject");

    pfnKTDestroySynchronizationObject = (PFND3DKMT_DESTROYSYNCHRONIZATIONOBJECT)
        GetProcAddress((HMODULE)hInst, "D3DKMTDestroySynchronizationObject");

    pfnKTWaitForSynchronizationObject = (PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECT)
        GetProcAddress((HMODULE)hInst, "D3DKMTWaitForSynchronizationObject");

    pfnKTSignalSynchronizationObject = (PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECT)
        GetProcAddress((HMODULE)hInst, "D3DKMTSignalSynchronizationObject");

    pfnKTCheckMonitorPowerState = (PFND3DKMT_CHECKMONITORPOWERSTATE)
        GetProcAddress((HMODULE)hInst, "D3DKMTCheckMonitorPowerState");

    pfnKTOpenAdapterFromGDIDisplayName = (PFND3DKMT_OPENADAPTERFROMGDIDISPLAYNAME)
        GetProcAddress((HMODULE)hInst, "D3DKMTOpenAdapterFromGdiDisplayName");

    pfnKTCheckExclusiveOwnership = (PFND3DKMT_CHECKEXCLUSIVEOWNERSHIP)
        GetProcAddress((HMODULE)hInst, "D3DKMTCheckExclusiveOwnership");

    pfnKTSetDisplayPrivateDriverFormat = (PFND3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT)
        GetProcAddress((HMODULE)hInst, "D3DKMTSetDisplayPrivateDriverFormat");

    pfnKTSharedPrimaryLockNotification = (PFND3DKMT_SHAREDPRIMARYLOCKNOTIFICATION)
        GetProcAddress((HMODULE)hInst, "D3DKMTSharedPrimaryLockNotification");

    pfnKTSharedPrimaryUnLockNotification = (PFND3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION)
        GetProcAddress((HMODULE)hInst, "D3DKMTSharedPrimaryUnLockNotification");

    if ((pfnKTCreateAllocation == NULL) ||
        (pfnKTQueryResourceInfo == NULL) ||
        (pfnKTOpenResource == NULL) ||
        (pfnKTDestroyAllocation == NULL) ||
        (pfnKTSetAllocationPriority == NULL) ||
        (pfnKTQueryAllocationResidency == NULL) ||
        (pfnKTCreateDevice == NULL) ||
        (pfnKTDestroyDevice == NULL) ||
        (pfnKTQueryAdapterInfo == NULL) ||
        (pfnKTLock == NULL) ||
        (pfnKTUnlock == NULL) ||
        (pfnKTGetDisplayModeList == NULL) ||
        (pfnKTSetDisplayMode == NULL) ||
        (pfnKTGetMultisampleMethodList == NULL) ||
        (pfnKTPresent == NULL) ||
        (pfnKTRender == NULL) ||
        (pfnKTOpenAdapterFromHdc == NULL) ||
        (pfnKTOpenAdapterFromDeviceName == NULL) ||
        (pfnKTCloseAdapter == NULL) ||
        (pfnKTGetSharedPrimaryHandle == NULL) ||
        (pfnKTEscape == NULL) ||
        (pfnKTSetVidPnSourceOwner == NULL) ||
        (pfnKTCreateOverlay == NULL) ||
        (pfnKTUpdateOverlay == NULL) ||
        (pfnKTFlipOverlay == NULL) ||
        (pfnKTDestroyOverlay == NULL) ||
        (pfnKTWaitForVerticalBlankEvent == NULL) ||
        (pfnKTSetGammaRamp == NULL) ||
        (pfnKTGetDeviceState == NULL) ||
        (pfnKTCreateDCFromMemory == NULL) ||
        (pfnKTDestroyDCFromMemory == NULL) ||
        (pfnKTSetContextSchedulingPriority == NULL) ||
        (pfnKTGetContextSchedulingPriority == NULL) ||
        (pfnKTSetProcessSchedulingPriorityClass == NULL) ||
        (pfnKTGetProcessSchedulingPriorityClass == NULL) ||
        (pfnKTReleaseProcessVidPnSourceOwners == NULL) ||
        (pfnKTGetScanLine == NULL) ||
        (pfnKTSetQueuedLimit == NULL) ||
        (pfnKTPollDisplayChildren == NULL) ||
        (pfnKTInvalidateActiveVidPn == NULL) ||
        (pfnKTCheckOcclusion == NULL) ||
        (pfnKTCreateContext == NULL) ||
        (pfnKTDestroyContext == NULL) ||
        (pfnKTCreateSynchronizationObject == NULL) ||
        (pfnKTDestroySynchronizationObject == NULL) ||
        (pfnKTWaitForSynchronizationObject == NULL) ||
        (pfnKTSignalSynchronizationObject == NULL) ||
        (pfnKTCheckMonitorPowerState == NULL) ||
        (pfnKTOpenAdapterFromGDIDisplayName == NULL) ||
        (pfnKTCheckExclusiveOwnership == NULL) ||
        (pfnKTSetDisplayPrivateDriverFormat == NULL) ||
        (pfnKTSharedPrimaryLockNotification == NULL) ||
        (pfnKTSharedPrimaryUnLockNotification == NULL) ||
        (pfnKTGetPresentHistory == NULL))
    {
        return E_FAIL;
    }

    return S_OK;
}