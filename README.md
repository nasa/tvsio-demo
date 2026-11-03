# TVSIO Demo
This is a sample Core Flight Software (cFS) project to demonstrate how [Trick Variable Server IO](https://github.com/nasa/tvsio) can be used.

This project includes two very basic Trick simulations and one basic CFS app. One trick sim is a 'temperature' data producer the other is a consumer. The CFS app, called temp_mon, will monitor the 'temperature' data and send a reset command to reset the data counter. TVSIO app connects to the Trick Variable Server of each sim, reading and writing values as defined by the \*.tvm files. TVSIO is the messenger that allows the two trick sims to talk to the temp_mon CFS app. 

TVSIO is included as a submodule at [`apps/tvsio`](apps)

## Building
### CFS[^1]
At the top level of the repo:
```bash
make SIMULATION=native install
```
### Trick[^2]

The sims are located in the [trick_sims](trick_sims) folder

 
1. #### SIM_temp
   This sim is extremely simple. All it does is to count up and reset back to 0 when a reset flag is received. This value is mapped in a \*.tvm file to be read by TVSIO and sent to SIM_range


2. #### SIM_range
   This sim monitors a value which is set by TVSIO, and prints it to the console
   
For both, the same process will build each sim.
   ```bash
   cd trick_sims/SIM_...
   trick-CP
   ```
   This command will build the executable, which will be named `S_main_<platform>.exe`. For example on 64bit linux it might be named `S_main_Linux_4.8_x86_64.exe`

## Running
You will need three terminals, two for each sim and one for cfs
1. Start cFS
   ```bash
   cd build/exe/cpu1
   ./core-cpu1
   ```
2. Start each sim:
   ```bash
   cd trick_sims/SIM_temp
   ./S_main_Linux_4.8_x86_64.exe RUN_temp/input.py
   ...
   cd trick_sims/SIM_range
   ./S_main* RUN_range/input.py
   ```
If you built cFS with `SIMULATION=native`, OSAL should be put in a "permissive" state which allows for msg queue size errors to be non-fatal. However if you see an error running cFS which looks like this:
```
Your queue depth may be too large for the
OS to handle. Please check the msg_max
parameter located in /proc/sys/fs/mqueue/msg_max
on your Linux file system and raise it if you
need to or run as root
```
You may need to increase your message queue limit.

Increase the limit using
```bash
sudo sysctl -w fs.mqueue.msg_max=256 | sudo tee -a /etc/sysctl.conf
sudo sysctl --system
```
Note this limit is an artifact of how cFS works, it is NOT TVSIO specific
### What you should see
If everything is running correctly, when CFS is started, you should see a bunch of initialization messages followed by TVSIO periodically attempting to connect to each trick sim.

When each trick sim is started, you should see a succesful connection message. Finally once everything is connected, SIM temp will begin counting



[^1]: For the cFS portion of this project [CFS-101](https://github.com/nasa/CFS-101) is recommended. That will teach you the basics of cFS.
[^2]: It is necessary to build and install Trick. Please visit [Trick Github](https://github.com/nasa/trick) and follow the installation guide.
