#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv) {
    if (argc < 2) 
    {
        printf("Usage: ./first_openmp N");
        return -1;
    }
    size_t N = atoi(argv[1]);
    omp_set_num_threads(N);
    int i;
    int k = 0;
    int threadnum;
    #pragma omp parallel shared(N, k) private(threadnum)
    {
        int while_count = 0;
        while(k < N) 
        {
            threadnum = omp_get_thread_num();
            while(k != threadnum) {
                if(k >= N)
                    break;
            }
            if(k >= N)
                break;
            printf("Hello world by thread %d\n", omp_get_thread_num());
            k++;
            while_count++;
        }
        printf("%d\n", while_count);
    }
    

    return 0x00;
}