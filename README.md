# Benchmarking c++ multiarrays

## Nifty - binding performance

Iterating (write) over an 1D-array of integers with size 10^8 (50 iterations):

|               | Marray (pure c++) | Vigra (pure c++) | Nifty-python (one call) | Nifty-python (call for each iteration) |
| ------------- | ----------------: | ---------------: | ----------------------: | -------------------------------------: |
| per iteration | 0.042 s           | 0.042 s          | 0.113 s                 | 1.027 s                                |
| total         | 2.146 s           | 2.147 s          | 5.654 s                 | 51.34 s                                |
