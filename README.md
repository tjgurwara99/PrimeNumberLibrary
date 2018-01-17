# PrimeNumberLibrary

This makefile will compile and create an executable file called fermatprime in the current directory by default. If you want to make this into a systemwide command, type `sudo make install`. Once done, the executable will be copied to `/usr/local/bin` directory. 
Using this command requires an argument which can hold a unsigned long long int (128 bit) value.

To execute the command type with local executable type:

`./fermatprime <number>`

where `<number>` is the number that you want to check.

If `sudo make install` has been used, it would run if you type:

`fermatprime <number>`

Keep in mind that this program is based on Fermat's Primality Test and is not very accurate. I am still working on ways that can improve the accuracy of this function.
The prime.h library also has some (extra) functions that you might like to try and are very usefull. I haven't used most of them because they were increasing the speed at which it checks the nunmber but they can still be modified to get better results.

Note: The makefile uses GNU make format wildcards, therefore in some BSD systems it would potentially not compile properly. I am trying to figure out a way to make it more cross platform so that this works in most `*nix` systems.
