import random, os, sys

total = 1048576
if len(sys.argv) > 1:
    total = int(sys.argv[1])


def write_file(size, num_range):
    random.seed(random.random())
    f = open("input.txt", 'w')
    for i in range(size):
        f.write(str(random.randrange(0, size)))
        f.write("\n")
    f.close()


os.system("rm -f ./input.txt")

write_file(total, total)