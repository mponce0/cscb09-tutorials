# Using solely shell scripting and programs in the shell, create your own version of the watch command.
# Notice that your implementation should take at least three command-line arguments:
# number of times to repeat the execution of a program,
# delay (i.e. time) between the different repetitions,
# the name of the program to run.

# usage ./shell_2.sh program_name number_of_times delay
# i.e., ./shell_2.sh ./shell_2_program.out 10 1

program=$1
# set default values for arguments 2 and 3
max=${2:-'10'}
sleep_time=${3:-'2'}
for (( i=1; i <= $max; ++i ))
do
    $program
    sleep $sleep_time
done
