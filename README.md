# TVS-IO Demo
This is a sample Core Flight Software (cFS) project to demonstrate how [Trick Variable Server IO](https://github.com/nasa/tvsio) can be used.

TVS-IO is included as a submodule at [`apps/tvs_io`](apps)

## Building
### CFS[^1]
```bash
TODO: Add brief CFS build directions
```
### Trick[^2]

This project includes two very basic Trick simulations. One is a producer the other is a consumer. TVS-IO connects to the Trick Variable Server of each sim, reading and writing values as defined by the \*.tvm files. These sims are located in the [trick_sims](trick_sims) folder

 
1. #### SIM_temp
   This sim is extremely simple. All it does is to count up and periodically reset back to 0. This value is mapped in a \*.tvm file to be read by TVS-IO and sent to SIM_range


2. #### SIM_range
   This sim monitors a value which is set by TVS-IO, and prints it to the console
   
For both, the same process will build each sim.
   ```bash
   cd trick_sims/SIM_...
   trick-CP
   ```
   This command will build the executable, which will be named `S_main_<platform>.exe`. For example on 64bit linux it might be named `S_main_Linux_4.8_x86_64.exe`

## Running

1. Start cFS
   ```bash
   TODO: cFS steps
   ```
3. Start each sim:
   
   ```bash
   cd trick_sims/SIM_temp
   ./S_main_Linux_4.8_x86_64.exe
   ```
   



[^1]: For the cFS portion of this project [CFS-101](https://github.com/nasa/CFS-101) is recommended. That will teach you the basics of cFS.
[^2]: It is necessary to build and install Trick. Please visit [Trick Github](https://github.com/nasa/trick) and follow the installation guide.
