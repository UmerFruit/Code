#!/bin/bash

# Function to log messages to a log file
log_message() {
    echo "$(date '+%D %H:%M:%S') - $1" >> server_monitor.log
    echo "ERROR: Disk threshold exceeded"
}
disk_threshold=80
disk_usage=$(df -h . | awk 'NR==2 {print $5}' | sed 's/%//')
if [ $disk_usage -gt $disk_threshold ]; then
    log_message "Disk usage exceeded threshold: $disk_usage%"
    # Send alert email, push notification, or any other alert mechanism
fi

Free_threshold=1        #limit on least amount of memory that should be free
memory_free=$(/bin/bash freecmd.sh | awk 'NR==3 {print $2}')
memory_free=$(($memory_free/1024))

if [ $memory_free -gt $memory_threshold ]; then
    log_message "Available memory fell below threshold: $memory_free%"
    # Send alert email, push notification, or any other alert mechanism
fi
