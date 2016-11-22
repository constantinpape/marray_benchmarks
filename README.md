# Benchmarking c++ multiarrays

## Current results

Iterating over 2000^2 array:

On my machine, compiled with -O3

* C-Array: RowMajor - 1 ms,   ColumnMajor - 2 ms
* Marray:  RowMajor - 173 ms, Column Major - 180 ms
* Vigra:   RowMajor - 2 ms, ColumnMajor - 9 ms

-NDEBUG fixes the performance issue with Marray....
