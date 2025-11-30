#!/bin/bash

# ============================================================================
# SYSTEM MONITORING SCRIPT FOR BORN2BEROOT
# ============================================================================
# This script collects various system information and displays it via wall
# command to all logged-in users. Designed to run periodically via cron.
# ============================================================================

# ARCHITECTURE & KERNEL INFO
# uname -a: prints all system information (kernel name, version, architecture)
architecture=$(uname -a)

# CPU INFORMATION
# /proc/cpuinfo: virtual file containing info about CPUs
# grep "physical id": finds lines with physical CPU IDs
# sort -u: sorts and removes duplicates to count unique physical CPUs
# wc -l: counts lines (number of physical CPUs)
cpu_physical=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)

# grep "processor": finds all processor entries (virtual cores/threads)
# wc -l: counts total number of virtual CPUs
v_cpu=$(grep "processor" /proc/cpuinfo | wc -l)

# MEMORY USAGE
# free --mega: shows memory in megabytes (MB)
# grep "Mem:": filters the memory line
# awk '{print $2}': extracts column 2 (total memory)
mem_total=$(free --mega | grep "Mem:" | awk '{print $2}')
# awk '{print $3}': extracts column 3 (used memory)
mem_used=$(free --mega | grep "Mem:" | awk '{print $3}')
# awk '{printf("%.2f"), $3/$2*100}': calculates percentage (used/total * 100)
mem_percent=$(free --mega | grep "Mem:" | awk '{printf("%.2f"), $3/$2*100}')

# DISK USAGE
# df -m: shows disk usage in megabytes
# --total: adds a total line at the end
# grep total: filters only the total line
# awk '{printf("%.1fGb"), $2/1024}': converts MB to GB with 1 decimal
disk_total=$(df -m --total | grep total | awk '{printf("%.1fGb"), $2/1024}')
# awk '{print $3}': extracts used disk space in MB
disk_used=$(df -m --total | grep total | awk '{print $3}')
# awk '{print $5}': extracts percentage already formatted by df (e.g., "42%")
disk_percent=$(df -m --total | grep total | awk '{print $5}')

# CPU LOAD
# vmstat 1 2: runs vmstat with 1 second delay, 2 iterations
# First output is average since boot, second is current state (more accurate)
# tail -1: takes only the last line (current state)
# awk '{printf $15}': extracts column 15 (idle CPU percentage)
cpu_free=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
# expr: evaluates arithmetic expression to get used CPU percentage
cpu_used=$(expr 100 - $cpu_free)
# printf "%.1f": formats to 1 decimal place
cpu_percent=$(printf "%.1f" $cpu_used)

# LAST BOOT TIME
# who -b: shows system boot time
# awk '{print $3 " " $4}': extracts date and time columns
last_boot=$(who -b | awk '{print $3 " " $4}')

# LVM CHECK
# lsblk: lists block devices (disks, partitions)
# grep "lvm": searches for LVM devices
# wc -l: counts number of LVM entries
# if [ ... -gt 0 ]: checks if count is greater than 0
# Outputs "yes" if LVM is used, "no" otherwise
lvm_used=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNECTIONS
# ss: socket statistics utility (modern replacement for netstat)
# -ta: show all (-a) TCP (-t) sockets
# grep ESTAB: filters only ESTABLISHED connections
# wc -l: counts number of established connections
tcp_connections=$(ss -ta | grep ESTAB | wc -l)

# LOGGED-IN USERS
# users: shows usernames of all logged-in users
# wc -w: counts words (each username is a word)
users_logged_in=$(users | wc -w)

# NETWORK INFORMATION
# hostname -I: displays all IP addresses assigned to the host
ip=$(hostname -I | awk '{print $1}')
# ip link: shows network interfaces
# grep "link/ether": filters lines containing MAC addresses
# awk '{print $2}': extracts the MAC address (column 2)
mac=$(ip link | grep "link/ether" | awk '{print $2}')


# SUDO COMMAND COUNT
# journalctl: queries systemd journal (system logs)
# -q: quiet mode (no pager)
# _COMM=sudo: filters entries where command is sudo
# grep COMMAND: filters lines containing "COMMAND" (actual sudo commands executed)
# wc -l: counts number of sudo commands run
sudo_count=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)

# ============================================================================
# DISPLAY OUTPUT
# ============================================================================
# wall: write a message to all logged-in users' terminals
# Sends a broadcast message containing all collected system information
wall "	#Architecture: $architecture
	#CPU physical: $cpu_physical
	#vCPU: $v_cpu
	#Memory Usage: $mem_used/${mem_total}MB ($mem_percent%)
	#Disk Usage: $disk_used/$disk_total ($disk_percent)
	#CPU load: $cpu_percent%
	#Last boot: $last_boot
	#LVM use: $lvm_used
	Connections TCP: $tcp_connections ESTABLISHED
	User log: $users_logged_in
	Network: IP $ip ($mac)
	Sudo: $sudo_count cmd"

# ============================================================================
# KEY COMMANDS SUMMARY FOR EVALUATION
# ============================================================================
# uname    - Display system information (kernel, architecture, etc.)
# grep     - Search for patterns in text
# awk      - Text processing tool for extracting/formatting data
# free     - Display memory usage statistics
# df       - Report disk space usage
# vmstat   - Report virtual memory statistics (CPU, memory, I/O)
# who      - Show who is logged in and system boot time
# lsblk    - List block devices (disks and partitions)
# ss       - Socket statistics (network connections)
# users    - Display usernames of logged-in users
# hostname - Show or set system hostname/IP addresses
# ip       - Show/manipulate routing, devices, and tunnels
# journalctl - Query systemd journal for system logs
# wall     - Send message to all logged-in users
# wc       - Word, line, character count
# sort     - Sort lines of text
# expr     - Evaluate expressions
# printf   - Format and print data
# ============================================================================