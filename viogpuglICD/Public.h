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

DEFINE_GUID (GUID_DEVINTERFACE_viogpuglICD,
    0xefec16dc,0x05b7,0x4666,0xbc,0x1d,0x80,0xd1,0xb6,0x35,0x2f,0x0b);
// {efec16dc-05b7-4666-bc1d-80d1b6352f0b}
