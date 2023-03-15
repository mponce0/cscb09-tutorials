## simplefork

### Which lines of output are printed more than once?
All lines that come after the fork command and are not in an if statement:
- B
- E

### Write down all the different possible orders for the output. Note that this includes output orders that you may not be able to reproduce.
- A B D E B C E
- A B C E B D E
- A B B C E D E
- A B B D E C E
- A B B C D E E
- A B C B E D E
- A B C B D E E
- ...

## forkloop

### How many processes are created including the original parent when forkloop is called with 2, 3, and 4 as arguments?
- 2: 6
- 3: 14
- 4: 30
- n: sum of 2^i

### Use an ASCII diagram to show the processes and their relationships when you run with 3 processes. For example, the diagram for simplefork with two processes would be (assuming the process id of the parent is 414 and the process id of the child is 416)
Modify `printf` statement
