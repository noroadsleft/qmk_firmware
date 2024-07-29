# TG4x

40% sandwich keyboard driven by a Pro Micro.

For more info please refer to [MythosMann's GitHub](https://github.com/MythosMann/tg4x).

* Keyboard Maintainer: [MechMerlin](https://github.com/mechmerlin)
* Hardware Supported:
  * [TG4x v2.0 PCB](https://github.com/MythosMann/tg4x/tree/5b22200a2fbd8f2704717ceb4a18b7f3ca6e60d6), Pro Micro
  * [TG4x v2.1 PCB](https://github.com/MythosMann/tg4x/tree/v2.1), Pro Micro
* Hardware Availability: [Geekhack](https://geekhack.org/index.php?topic=99163.0)

If soldering in a RGB underglow strip, please use pin D2, the pin labeled RXI on the Pro Micro.

Make example for this keyboard (after setting up your build environment):

    make tg4x/v20:default  # for v2.0 PCBs
    make tg4x/v21:default  # for v2.1 PCBs

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
