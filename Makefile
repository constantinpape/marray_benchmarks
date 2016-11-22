marray_include =  /home/constantin/Work/software/src/marray/include
vigra_include =   /home/constantin/Work/software/src/vigra/include

time_marray: time_marray.cxx 
	g++ -std=c++11 -O3 -DNDEBUG -I $(marray_include) time_marray.cxx -o time_marray.out

vs_carray: vs_carray.cxx 
	g++ -std=c++11 -O3 -DNDEBUG -I $(marray_include) vs_carray.cxx -o vs_carray.out

vs_varray: vs_varray.cxx 
	g++ -std=c++11 -O3 -DNDEBUG -I $(marray_include) -I $(vigra_include) vs_varray.cxx -o vs_varray.out

all: time_marray vs_carray vs_varray
