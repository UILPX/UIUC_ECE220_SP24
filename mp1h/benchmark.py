import os, time, filecmp

def test_serial():
    os.system("gcc acc_serial.c -g -o acc_serial")
    start = time.time()
    os.system("./acc_serial")
    end = time.time()
    return end - start


def test_parallel():
    os.system("gcc acc_parallel.c -g -lpthread -o acc_parallel")
    start = time.time()
    os.system("./acc_parallel")
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