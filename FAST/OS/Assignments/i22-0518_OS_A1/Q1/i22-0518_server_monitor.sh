log_message() 
{
    echo "$(date '+%D %H:%M:%S') - $1" >> server_monitor.log
}

# Disk Usage Monitoring
disk_threshold=20
disk_usage=$(df -h . | awk 'NR==2 {print $5}' | sed 's/%//')
echo "Current disk usage: $disk_usage"
if [ $disk_usage -gt $disk_threshold ]; 
then
    log_message "Disk usage exceeded threshold: $disk_usage%"
fi

# CPU Usage Monitoring
cpu_threshold=30
a=$(top -bn1 | grep "Cpu(s)" | awk -F',' '{print $4}' | sed 's/ id//')  #will return idle usage %
a=${a%.*}                                                               # remove all chars after '.'  % is the subtitution command
cpu_usage=$((100-$a))                                                   #this will give used %
echo "Cpu usage: $cpu_usage%"
if [ $cpu_usage -gt $cpu_threshold ]; 
then
    log_message "CPU usage exceeded threshold: $cpu_usage%"
fi

# Memory Usage Monitoring
memory_threshold=70
memory_used=$(free | grep Mem | awk '{print $3/$2 * 100}')
memory_used=${memory_used%.*}           # remove all chars after '.'  % is the subtitution command
echo "Memory usage: $memory_used%"
if [ $memory_used -gt $memory_threshold ];
then
    log_message "Used memory went above threshold: $memory_free%"
fi

#Log Rotation
log_file="server_monitor.log"
curr_size=$(du -h "$log_file" | awk '{print $1}')
echo "Current log file size: $curr_size"
if [[ $curr_size == *M* ]];
then
    max_log_size=10
    log_size=$(du -h "$log_file" | awk '{print $1}' | sed 's/M//')
    
    if [ $log_size -gt $max_log_size ];
    then
        log_message "Log file size exceeded maximum size: $log_size MB"
        mv "$log_file" "$log_file.old"
        touch "$log_file"
        log_message "Log file rotated"
    fi
    
fi