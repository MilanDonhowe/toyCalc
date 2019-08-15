# toyCalc


This is a simple terminal calculator written in C with the ncurses library.  The calculator operates off a **mouse input**, meaning you will have to have some mouse-like device to actually use the calculator.


Photos coming soon!

## usage
```bash
git clone https://www.github.com/MilanDonhowe/toyCalc
cd toyCalc
make
./calc
```
Enjoy!

## Known issues

**xterm ~~sucks~~ breaks the calculator**

The calculator breaks on some terminal emulators, namely ```xterm```.  If you're getting some weird output that's likely the cause.
To fix the calculator just switch your terminal emulator with ```export TERM=emulator-name```.  I tested it with the ```gnome``` terminal but most should work as long as they support the extended ACS Masking characters.

**Negative numbers break**

Sometimes the minus operator returns an unexpected output, currently working on a fix!



