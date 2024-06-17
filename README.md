# minitalk

### Summary:
The purpose of this project is to code a small data exchange program
using UNIX signals.

### Use:
- step 1:
```
make
```
- step 2: run server executable
```
./server
```
- step 3: run client executable in a seperate terminal window with the pid you got from the server and write a message
```
./client <server_pid> "message to send"
```