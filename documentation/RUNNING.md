## Definition

This document describes a few way how to run Astra client persistently remotely(on VPS).

### Options

We will imply that user is connected via ssh to remote host.

1. Simply running `# /path/to/Astrad/Astrad`
2. Running as daemon `# /path/to/Astrad/Astrad -daemon` or placing daemon=1 into `Astra.conf`
3. Running as service(systemd, init.d, etc)

Let's breakdown every solution. 

1. This is the worst solution since it runs as blocking process to the terminal and you are pretty much limited to do anything. 
2. This solution is better because it forks process and client runs in background as daemon, in this case you can safely close your connection and everything will work.
3. This solution is by far the best because it does the same as 2) but also supports auto-restart and auto-start. (Recommended)

### Running as service(systemd)

To run client as systemd daemon we need to make simple configuration. 

Unit file can be found at our github repository, `Astra/contrib/init/Astrad.service`

1. Place so `Astrad.service` unit file into `/etc/systemd/system`. 
2. Create folder for datadir: `sudo mkdir -p /var/lib/Astrad`
3. Enable unit for auto-start: `sudo systemctl start Astrad`. (Optional)
4. Start service: `sudo systemctl start Astrad`
5. Check status: `sudo systemctl status Astrad`

Useful commands:

* `sudo systemctl status Astrad` - shows status
* `sudo systemctl stop Astrad` - stops daemon
* `tail -f /var/lib/Astrad/debug.log` - show logs

#### Using our Astrad.service

Our unit file that is provided at `Astra/contrib/init/Astrad.service` has configuration for different from default `Astra.conf` and `datadir` folders. 
Default is: 

* `-datadir=/var/lib/Astrad`
* `-conf=/etc/Astra/Astra.conf`

Using our unit file won't place `datadir` and `Astra.conf` under `~/.Astra`. If you want to change those locations, you will need to modify unit file. 

### Daemon configuration

If you want fluid support of auto-start it might be useful to add `reindex=1` into `Astra.conf`. Motivation for this is that when daemon crashes database might corrupt, `reindex=1` will slow things a lot on restarts but will provide automatic robust experience.

It makes sense to setup strong `rpcpassword`, `rpcuser` and `rpcallowip` in `Astra.conf` to secure a bit this client.

If wallet contains any funds, it needs to be encrypted with strong passphrase. 