https://www.scs.stanford.edu/21wi-cs140/pintos/pintos_12.html 

` 

sudo apt-get install qemu make binutils perl gdb 

` 

 

Installing Bochs for simulation 

https://www.scs.stanford.edu/21wi-cs140/pintos/pintos_12.html#SEC163 

Download from here (.tar.gz file) https://sourceforge.net/projects/bochs/\ 

Download this and move it to `student0` folder 

 

For this project, will be working in `~/student0/proj-pregame` 

`cd proj-pregame/src/misc` 

`sudo env SRCDIR=~/student0 PINTOSDIR=~/student0/proj-pregame DSTDIR=/usr/local sh bochs-2.2.6-build.sh` 


 

Create a folder `~/student0/pintos_install_bin` 

Copy binaries in `~/student0/proj-pregame/src/utils/` to `~/student0/pintos_install_bin` 

Add `~/student0/pintos_install_bin` to `$PATH` 

Add this line in `~/.bashrc` `PATH="$PATH:~/student0/pintos_install_bin"` 

 

Copy `~student0/proj-pregame/src/misc/gdb-macros` to `~/student0/pintos_install_bin` 

Open `~/student0/pintos_install_bin/pintos-gdb` and edit first line to point to the copied `gdb-macros file` `GDBMACROS=~/student0/pintos_install_bin/gdb-macros` 

 

`cd ~/student0/proj-pregame/src/utils` 

`make` 

Move `~/student0/proj-pregame/src/utils/squish-pty` to `~/student0/pintos_install_bin/squish-pty` 

 

With this all binaries should run fine once shell is updated using `bash` 
