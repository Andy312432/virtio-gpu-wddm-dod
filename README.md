# virtio-gpu-wddm-dod(For UTM)
Fork of https://github.com/utmapp/virtio-gpu-wddm-dod

Trying to imporve UTM Windows experience (Other qemu set-up not supported)

Future imagination
------------
Since I am **not** an experienced developer, there is no promise!

DOD part
- [ ] Investigate why there is only certain cursor that supports accerlation
- [ ] Better cursor hiding implementation
- [ ] Improve PnP support to avoid freezing when manually install driver
- [ ] Clean-up code
- [ ] Intergration with User-mode driver
------------
Full-Graphs part

![圖片](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/images/dx10arch.png)

As shown above, this part split into two parts: (Source: Microsoft)

OpenGL ICD part
- [ ] OpenGL accerlation supoort ([This](https://github.com/Keenuts/virtio-gpu-win-icd "This")) (The project only shows the concept of OPENGL ICD)

Usermode driver part
- [ ] User mode display driver(probably use DXVK to help us with DirectX? )
- [ ] Limited DirectX accerlation using [DXGL](https://github.com/dxgldotorg/dxgl "DXGL")
- [ ] Fall back to software rendering without giving out errors when the above method fails
- [ ] Dynamic accerlation changing (possible?)

There is only a project available for us to investigate: [vbox wddm](https://github.com/mirror/vbox/tree/master/src/VBox/Additions/WINNT/Graphics/Video/mp/wddm "vbox wddm"), so it'll be a hard work.

------------
Other stuff
- [ ] Upgrade to WDDM 3.1(latest ver)
- [ ] Merge latest [kvm-win driver code](https://github.com/virtio-win/kvm-guest-drivers-windows/tree/master/viogpu "kvm-win driver code")
- [ ] QXL communication
- [ ] UTM-specific feature with cooperation with UTM
- [ ] Legal issues?
------------
More to come if i can do these...

## Developers wanted, Pull requests wanted
