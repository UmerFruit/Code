#!/bin/bash

# Function to log messages to a log file
log_message() {
    echo "$(date '+%Y-%m-%d %H:%M:%S') - $1" >> server_monitor.log
}

# Disk Usage Monitoring
disk_threshold=30
disk_usage=$(df -h / | awk 'NR==2 {print $5}' | sed 's/%//')
if [ $disk_usage -gt $disk_threshold ]; then
    log_message "Disk usage exceeded threshold: $disk_usage%"
    # Send alert email, push notification, or any other alert mechanism
fi

# CPU Usage Monitoring
cpu_threshold=30
cpu_usage=$(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | awk '{print 100 - $1}')
if [ $(echo "$cpu_usage > $cpu_threshold" | bc) -eq 1 ]; then
    log_message "CPU usage exceeded threshold: $cpu_usage%"
    # Send alert email, push notification, or any other alert mechanism
fi

# Memory Usage Monitoring
memory_threshold=10
memory_free=$(free | grep Mem | awk '{print $4/$2 * 100}')
if [ $(echo "$memory_free < $memory_threshold" | bc) -eq 1 ]; then
    log_message "Available memory fell below threshold: $memory_free%"
    # Send alert email, push notification, or any other alert mechanism
fi

# Log Rotation
log_file="/path/to/your/logfile.log"
log_size=$(du -h "$log_file" | awk '{print $1}' | sed 's/M//')
max_log_size=10
if [ $(echo "$log_size > $max_log_size" | bc) -eq 1 ]; then
    log_message "Log file size exceeded maximum size: $log_size MB"
    mv "$log_file" "$log_file.old"
    touch "$log_file"
    log_message "Log file rotated"
    # You may want to compress the old log file or archive it
fi

# End of script
