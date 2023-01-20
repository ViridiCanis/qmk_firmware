# factory reset: fn+j+z

default:
    {{just_executable()}} -f {{justfile()}} --list

compile:
    make keychron/k8_pro/ansi/rgb:viridi

flash:
    # flash mode: 'off, hold esc, cable' or 'unplug, off, hold reset, cable mode'
    make keychron/k8_pro/ansi/rgb:viridi:flash
