# GoPolar GG86

![GoPolar GG86](https://cdn.shopify.com/s/files/1/0281/3122/9834/products/GopolarGG86HotswappableTKLMechanicalKeyboard1_1024x1024@2x.jpg?v=1633869982)

A hotswap tenkeyless keyboard with Tsangan bottom row, OLED display, and per-key RGB lighting.

The RGB lighting is not supported in this port.

* Keyboard Maintainer: [The QMK Community](https://github.com/qmk)
* Hardware Supported: GoPolar GG86 (ATmega32U4)
* Hardware Availability: [Mecha Store (Singapore)](https://mecha.store/products/gopolar-gg86-tenkeyless-hotswappable-barebones-keyboard)

Make example for this keyboard (after setting up your build environment):

    make gopolar/gg86:default

Flashing example for this keyboard:

    make gopolar/gg86:default:flash

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
