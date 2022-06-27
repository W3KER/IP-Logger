iplogger
===================

A tool which updates all the network interfaces on a machine. It should be scheduled to run at regular interval (crontab, scheduler, etc) & and as a start script.

Standalone hardware installations using Desktops/Raspberry Pi/ ODROID, etc can benefit from this as the updated IP can be used for remotely connecting over the network.

Schedule it to run after 5 minutes:

**For Linux:** Add to crontab `*/5 * * * * <iplogger path> >> <log file>`
        
**For Windows:** Add to Scheduler


# License

keplerlab projects typically use the MIT licenses for code. See specific projects to understand the license used.













