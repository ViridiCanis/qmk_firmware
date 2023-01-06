default:
    {{just_executable()}} -f {{justfile()}} --list

compile:
    make keychron/k8_pro/ansi/rgb:default

flash:
    make keychron/k8_pro/ansi/rgb:default:flash
    # factory reset: fn+j+z
    # unplug, off, hold reset, cable mode
