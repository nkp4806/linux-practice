#!/bin/bash

name=$(whoami)
hostname=$(hostname)
cpu_count=$(nproc)
kernel=$(uname -r)
system_uptime=$(uptime)
memory=$(free -h)

echo "User: $name"
echo "Hostname: $hostname"
echo "CPU Cores: $cpu_count"
echo "Kernel: $kernel"
echo "Uptime: $system_uptime"
echo "$memory"
