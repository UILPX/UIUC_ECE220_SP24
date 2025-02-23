# ECE 220 Honors Section
# MP4 Checkpoint 1 - Cooperative Multitasking in LC-3

The goal of MP 4 is to learn how we can introduce the concepts of multitasking to LC-3. There are two checkpoints in this mp. In this first checkpoint you will get to implement context switching for a simple cooperative multitasking LC-3 program we provided. The premise behind cooperative multitasking is that the user tells the operating system when to switch to another task. 

General guideines:   
1. Do not touch any of the given code in os1.asm or usr1.asm.
2. You will need to implement the `TRAP_YIELD`, `TASK0_LOOP`, `TASK1_LOOP` functions.

# FILES

1. os1.asm - A cooperative multitasking mechanism where you need to implement the `TRAP_YIELD` function
2. usr1.asm - In the code usr1.asm, two tasks will run: Task 0 and Task 1. You will be responsible for the code in `TASK0_LOOP` and `TASK1_LOOP`. Task 0 is responsible for incrementing both a local counter and a shared counter between Task 0 and Task 1. After the loop is ran once, the system will switch to Task 1 by utilizing `TRAP_YIELD`. Similarly, Task 1 is tasked with incrementing a local counter and the shared counter between Task 0 and Task 1. After Task 1 loop is ran, the system will switch back to Task 0 by utilizing `TRAP_YIELD` once again. To switch between the tasks after each task is executed, the `TRAP_YIELD` function will be called, alternating between the two tasks.


# Modified LC3 Sim
In the release there is a modified LC3 sim that allows for interrupts. Follow the steps to download and use the modified LC3 sim. 
  1. Run the provided bash script to install lc3htools

    $ bash ./lc3h.sh
  
  You should see the following output:

    lc3htools made
    lc3has set.
    lc3hconvert set.
    lc3hsim set.
    lc3hsim-tk set.

  2. Source the changes

    $ source ~/.bashrc

  3. Test lc3h commands
  
  You should now be able to call `lc3has`,`lc3hsim`,`lc3hconvert`,`lc3hsim-tk` to compile and test your code as you would in lc3tools!

# Testing:  
    
  1. Compile all the `.asm` files with Lumetta's assembler (lc3has). 
  
    $ lc3has usr1.asm 
    $ lc3has os1.asm 


  2. Load the `usr1.obj` and `os1.obj` files into the modified LC3 simulator.

    $ lc3hsim-tk

  3. After loading `os1.obj` and `usr1.obj` set **PC** to **0x0200** and **PSR** to **0x8000**. This starts execution in unprivileged mode. 

  4. If you run the program and see `TASK0_ACC`, `TASK1_ACC`, and `SHARED_ACC` incrementing with `TASK0_ACC` + `TASK1_ACC` = `SHARED_ACC`, your implementation is correct.


# Note About Testing:
In `os1.asm`, there is a label `TRAP_YIELD_END` that holds a count. Once the program runs `TRAP_YIELD`, `TRAP_YIELD_END` number of times, the program will halt. In this checkpoint, once the program is halted you should see that `TASK0_ACC=TRAP_YIELD_END/2`, `TASK1_ACC=TRAP_YIELD_END/2`, and `SHARED_ACC=TRAP_YIELD_END`.




Todos:  

  1. Complete the trap function in os1.asm: `TRAP_YIELD`.
  2. Complete the two tasks loops in usr1.asm: `TASK0_LOOP` and `TASK1_LOOP` utilizing `TRAP_YIELD` to switch between the tasks.
  3. In your report answer the following questions
      - In your own words explain the difference between cooperative multitasking and preemptive multitasking? 
    
      - Give another analogy, not related to the one presented in the lecture, to show the difference between concurrent tasks and parallel computation? 
      
      - Of the two figures below, which system is running concurrently and which system is running in parallel?

      - Why do you need to save the PC into the TCB in `TRAP_YIELD`?


  ![HomeworkProblem](./images/Question4p1C.png?raw=true)
