import os, time, sys, filecmp

def test_serial():
    start = time.time()
    if os.system("./merge_sort_serial"):
        sys.exit("sequential program failure")
    end = time.time()
    return end - start


def test_parallel():
    start = time.time()
    if os.system("./merge_sort_parallel"):
        sys.exit("parallel program failure")
    end = time.time()
    return end - start


if __name__ == '__main__':
    serial = test_serial()
    parallel = test_parallel()
    if filecmp.cmp("serial_output.txt", "parallel_output.txt"):
        print("Benchmark success!")
    else:
        print("Benchmark failed, parallel and serial output do not match!")
        exit(-1)
    
    print("Time taken for serial:\t\t{}\nTime taken for parallel:\t{}\nSpeedup:\t\t\t{} X".format(serial, parallel, round(serial/parallel, 2)))
