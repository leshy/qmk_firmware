docker run -e keymap=lesh -e keyboard=ergodox --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware && echo 'reset ergodox!'; teensy-loader-cli -mmcu=atmega32u4 -w ergodox_ez_lesh.hex
