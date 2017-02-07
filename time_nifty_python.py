import numpy as np
import nifty
import time

def time_each_call(N):
    print "Timeing 1D access from python (each call) ..."
    x = np.zeros( (int(1e8),), dtype = int )
    taiming = []
    for _ in xrange(N):
        t0 = time.time()
        nifty.marray.marray1dBenchmark(x)
        taiming.append(time.time() - t0)
    print "... in total:", np.sum(taiming), "s"
    print "... per iteration:", np.mean(taiming), "s"

def time_one_call(N):
    print "Timeing 1D access from python (one call) ..."
    x = np.zeros( (int(1e8),), dtype = int )
    t0 = time.time()
    nifty.marray.marray1dBenchmarkOnce(x, N)
    t0 = time.time() - t0
    print "... in total:", t0, "s"
    print "... per iteration:", t0 / N, "s"

if __name__ == '__main__':
    N = 50
    time_each_call(N)
    time_one_call(N)
