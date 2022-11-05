/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    driver and application

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_viogpuuser,
    0x9e51ce6e,0x3252,0x4858,0xa3,0x14,0x36,0x0b,0x78,0x6a,0x75,0x57);
// {9e51ce6e-3252-4858-a314-360b786a7557}
