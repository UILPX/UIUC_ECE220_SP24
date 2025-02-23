import random, os, sys


num_threads = 4

if len(sys.argv) > 1:
    num_threads = int(sys.argv[1])


def write_partial(i, size, num_range):
    random.seed(random.random())
    f = open("input/acc_input.part" + str(i).zfill(2), 'w')
    for i in range(size):
        f.write(str(random.randrange(0, size)))
        f.write("\n")
    f.close()


os.system("rm -rf ./input")
os.system("mkdir ./input")
total = 1000000
for i in range(num_threads):
    write_partial(i, int(total/num_threads), total)