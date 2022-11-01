# virtio-gpu-wddm-dod(For UTM)
Fork of https://github.com/utmapp/virtio-gpu-wddm-dod
Trying to imporve UTM Windows experience(Other qemu set-up not supported)

Future imagination
------------
Since I am **not** an experienced developer, there is no promise!

DOD part
- [ ] Investigate why there is only certain cursor that supports accerlation
- [ ] Better cursor hiding implementation
- [ ] Improve PnP support to avoid freezing when manually install driver
- [ ] Clean-up code
------------

ICD part
- [ ] GPU accerlation supoort ([This](https://github.com/Keenuts/virtio-gpu-win-icd "This")) (ICD user mode driver)
- [ ] OpenGL accerlation
- [ ] Limited DirectX accerlation using [DXGL](https://github.com/dxgldotorg/dxgl "DXGL")
- [ ] Limited DirectX accerlation using [DXVK](https://github.com/doitsujin/dxvk "DXVK") (Only when Osy done implementing [this](https://github.com/utmapp/UTM/issues/4551 "this"))
- [ ] Fall back to software rendering without giving out errors when the above method fails
- [ ] Dynamic accerlation changing (possible?)
------------

Other stuff
- [ ] Upgrade to WDDM 3.1(latest ver)
- [ ] Merge latest [kvm-win driver code](https://github.com/virtio-win/kvm-guest-drivers-windows/tree/master/viogpu "kvm-win driver code")
- [ ] QXL communication
- [ ] UTM-specific feature with cooperation with UTM
- [ ] Legal issues?
More to come if i can do these...

## Developers wanted, Pull requests wanted
