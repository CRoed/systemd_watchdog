# systemd_watchdog
Simple c test for a systemd watchdog

You must install libsystemd-dev to use this (apt install libsystemd-dev)

To compile
```
gcc main.c -lsystemd
```

To Install
Modify the ExecStart in watchdog_test.service file to /path/to/your/a.out
```
cd /lib/systemd/system
ln -fs /path/to/watchdog_test.service 
sudo systemctl daemon-reload
```
To run
```
sudo systemctl start watchdog_test
```

Monitor the status of the watchdog using journalctl
```
sudo journalctl -f -u watchdog_test
```

