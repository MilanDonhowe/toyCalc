# toyCalc.c


This is a simple terminal calculator written in C with the ncurses library.  The calculator uses **mouse input** to enter inputs, meaning you will have to have some mouse-like device to actually use the calculator.

![gif of the calculator running in a terminal](https://raw.githubusercontent.com/MilanDonhowe/ReadmeImages/master/ttty/toyCalc.gif)

## usage
1. Get ncurses library if not already installed.

2. Compile the program :)
```bash
git clone https://www.github.com/MilanDonhowe/toyCalc
cd toyCalc
make
./calc
```

Alternatively you could try to run the already compiled file under bin, however your results may vary.

Enjoy!

## Known issues

** Why is the top and bottom of the calculator broken? **

This is due to a problem with terminal emulators.  In order to fix it change your $TERM variable from "xterm" to the actual name of the terminal emulator you're using such as "putty" (for SSHing with PuTTy) or "gnome" (for GNOME desktop clients).

You can read more about the error [on this stackoverflow post](https://stackoverflow.com/questions/46507473/ncurses-in-urxvt-does-not-print-repeating-characters)
