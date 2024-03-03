import time
f = open("test_case/Test_5.inp", "r")
n = int(f.readline())
a = list(map(int, f.readline().split()))
f.close()

start = time.time()
a.sort()
end = time.time()

print("Sorting time: ", (end-start) * 10**3, "ms")
for i in range(1, n):
  if(a[i] < a[i-1]) :
    print("Not sorted")
    break