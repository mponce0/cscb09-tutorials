# Write a shell scrip that reports the following when used from the terminal,

# Sample #5 of 5, every 2 sec
# -----
# top - 03:04:08 up 21:58,  3 users,  load average: 0.08, 0.04, 0.00
# Tasks: 287 total,   1 running, 286 sleeping,   0 stopped,   0 zombie
# %Cpu(s):  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
# MiB Mem :  15690.1 total,  13981.5 free,    608.6 used,   1099.9 buff/cache
# MiB Swap:    980.0 total,    980.0 free,      0.0 used.  14695.4 avail Mem 
# -----
# ponceca1 pts/0        2023-03-26 02:53 (138.51.8.146)
# ponceca1 pts/1        2023-03-26 02:14 (138.51.8.146)
# ponceca1 pts/2        2023-03-26 02:29 (138.51.8.146)
# -----
#                total        used        free      shared  buff/cache   available
# Mem:              16           0          14           0           1          15
# Swap:              1           0           1
# -----

# Linux iits-i406-01 5.19.0-32-generic #33~22.04.1-Ubuntu SMP PREEMPT_DYNAMIC Mon Jan 30 17:03:34 UTC 2 x86_64 x86_64 x86_64 GNU/Linux

max=$1
delay=$2
for (( i=1; i <= $max; ++i ))
do
    echo Sample $i of $max, every $delay sec
    top -b -n1 | head -n 5
    echo -----
    who -d -u --ips --lookup
    echo -----
    free -m
    echo -----
    uname -a
    
    sleep $delay
done