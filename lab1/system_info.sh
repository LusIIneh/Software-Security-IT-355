#!/bin/bash

echo "============================"
echo "System Information"
echo "============================"

echo ""
echo "CPU Information:"
lscpu | grep "Model name"

echo ""
echo "CPU Serial:"
cat /proc/cpuinfo | grep Serial

echo ""
echo "Memory Information:"
free -h

echo ""
echo "Disk Information:"
lsblk

echo ""
echo "MAC Address:"
ip link | grep link/ether

echo ""
echo "Operating System:"
uname -a
