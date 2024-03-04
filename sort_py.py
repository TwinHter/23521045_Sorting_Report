import time

g = open("test_case/sort_py.out", "w")
for testth in range(1, 11):
  fname = "test_case/Test_" + str(testth) + ".inp"
  f = open(fname, "r")
  n = int(f.readline())
  a = list(map(int, f.readline().split()))
  f.close()

  start = time.time()
  a.sort()
  end = time.time()

  name_test = ["Test case " + str(testth) + ": " + str((end-start) * 1000) + " ms", "\n"];
  # name_test = [str((end - start)*1000), "\n"]
  g.writelines(name_test)

g.close()