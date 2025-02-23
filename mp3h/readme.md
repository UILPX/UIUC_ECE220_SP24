# ECE 220 Honors Section
# MP3 Parallel Mergesort

In this MP you will implement both the sequential and parallel versions of the Mergesort algorithm.

General guideines:  
1. You can vary the parallel thread spawning threshold in merge_sort_parallel.c  
2. Do not touch any of the python (.py) files  


Usage:  
    
  1. generate 1,048,576 random integer [0, 1048576) data in the input file, one number per line

    $ python3 generate_data.py

  2. compile program

    $ make all

  3. run test program

    $ ./merge_sort_serial
    $ ./merge_sort_parallel
    The sorted linked list will be saved in serial_output.txt and parallel_output.txt respectively.

  4. run both versions of the sorter, compares the output and speedup

    $ python3 benchmark.py
    
Todos:  

  1. Complete list utility functions in ll.c: `make_node`, `insert_at_head`, `free_list`.  
  2. Complete mergesort helper functions in merge_sort.c: `split_ll`, `merge_ordered_ll`, and the `merge_sort` function itself.  
  3. Complete the sequential version main function in merge_sort_serial.c  
  4. Complete the recursive thread wrapper and main function (root thread) in merge_sort_parallel.c  
  5. In your report answer the following questions  
      - What is the speedup that you get from benchmark.py when using `THRESHOLD` = 1024? Is it slower or faster than the sequential merge_sort? Why?  
      - Try changing the threshold to 1. What happens when you run ./merge_sort_parallel ? Why? (Hint: try running the program with valgrind. What is the size of pthread_t structure? How many pthread_t did your program allocate with `THRESHOLD` = 1 ?)  
      - Try tuning the threshold until you get a reasonable speedup (>= 1.35X) Include the parameter and the benchmark result in your report.  
      - As number of threads increases, when do you start seeing diminishing return? Why? (Hint: this is related to the physical setup of your machine).  
      - Draw out the recursive tree of what would happen if you called the `merge_sort` function on the following linked list.
    
      ![HomeworkProblem](./images/LinkedListMp3h.png?raw=true)
