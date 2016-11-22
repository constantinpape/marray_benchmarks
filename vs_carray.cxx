#include <chrono>
#include <iostream>

#include <andres/marray.hxx>


inline void rowMajorAcces(andres::View<int> view) {
    for( int i = 0; i < view.shape(0); ++i ) {
        for( int j = 0; j < view.shape(1); ++j ) {
            view(j,i) = i + j;
        }
    }
}

inline void columnMajorAcces(andres::View<int> view) {
    for( int j = 0; j < view.shape(1); ++j ) {
        for( int i = 0; i < view.shape(0); ++i ) {
            view(j,i) = i + j;
        }
    }
}

inline void rowMajorAcces(int array[2000][2000]) {
    for( int i = 0; i < 2000; ++i ) {
        for( int j = 0; j < 2000; ++j ) {
            array[i][j] = i + j;
        }
    }
}


inline void columnMajorAcces(int array[2000][2000]) {
    for( int j = 0; j < 2000; ++j ) {
        for( int i = 0; i < 2000; ++i ) {
            array[j][i] = i + j;
        }
    }
}

void time(int N) {

    size_t shape[] = {2000,2000};
    andres::Marray<int> array(shape, shape+2);

    std::cout << "Timeing rowMajorAcces Marray..." << std::endl;
    auto t0 = std::chrono::high_resolution_clock::now();
    for(int _ = 0; _ < N; ++_) {
        //for( int i = 0; i < array.shape(0); ++i ) {
        //    for( int j = 0; j < array.shape(1); ++j ) {
        //        array(j,i) = i + j;
        //    }
        //}
        rowMajorAcces(array);
    }
    auto t1 = std::chrono::high_resolution_clock::now();

    auto dur0 = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);
    std::cout << "... in total: " << dur0.count() << " ms" << std::endl;
    std::cout << "... per itearion " << dur0.count() / N << " ms" << std::endl;
    

    std::cout << "Here" << std::endl;
    static int carray[2000][2000];
    
    std::cout << "Timeing rowMajorAcces c-array..." << std::endl;
    auto t00 = std::chrono::high_resolution_clock::now();
    for(int _ = 0; _ < N; ++_)
        rowMajorAcces(carray);
    auto t10 = std::chrono::high_resolution_clock::now();

    auto dur00 = std::chrono::duration_cast<std::chrono::milliseconds>(t10 - t00);
    std::cout << "... in total: " << dur00.count() << " ms" << std::endl;
    std::cout << "... per itearion " << dur00.count() / N << " ms" << std::endl;
    
    
    
    std::cout << "Timeing columnMajorAcces Marray..." << std::endl;
    auto t2 = std::chrono::high_resolution_clock::now();
    for(int _ = 0; _ < N; ++_)
        columnMajorAcces(array);
    auto t3 = std::chrono::high_resolution_clock::now();

    auto dur1 = std::chrono::duration_cast<std::chrono::milliseconds>(t3 - t2);
    std::cout << "... in total: " << dur1.count() << " ms" << std::endl;
    std::cout << "... per itearion " << dur1.count() / N << " ms" << std::endl;
    
    
    std::cout << "Timeing columnMajorAcces c-array..." << std::endl;
    auto t20 = std::chrono::high_resolution_clock::now();
    for(int _ = 0; _ < N; ++_)
        columnMajorAcces(carray);
    auto t30 = std::chrono::high_resolution_clock::now();

    auto dur10 = std::chrono::duration_cast<std::chrono::milliseconds>(t30 - t20);
    std::cout << "... in total: " << dur10.count() << " ms" << std::endl;
    std::cout << "... per itearion " << dur10.count() / N << " ms" << std::endl;
    
}

int main() {
    time(10);
    return 0;
}
