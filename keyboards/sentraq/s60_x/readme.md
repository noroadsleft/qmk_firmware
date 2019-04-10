# S60-X

DIY compact keyboard designed by VinnyCordeiro for Sentraq. Most of the keymaps are based on GH60 code. This is a port from TMK to QMK based on the [original S60-X Repo](https://github.com/VinnyCordeiro/tmk_keyboard).

Keyboard Maintainer: QMK Community  
Hardware Supported: [S60-X non-RGB PCB](default/), [S60-X RGB PCB](rgb/)  
Hardware Availability: https://www.massdrop.com/buy/sentraq-60-diy-keyboard-kit?mode=guest_open

There are two versions of this keyboard, an RGB and a non RGB one. Firmware built for one, will not work on the other. 

Make example for S60-X non-RGB (after setting up your build environment):

    make sentraq/s60_x/default:default

Make example for S60-X RGB version:

    make sentraq/s60_x/rgb:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
