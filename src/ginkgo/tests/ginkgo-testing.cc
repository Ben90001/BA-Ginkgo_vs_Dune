#include<iostream>
#include<chrono>
#include<map>
#include<fstream>
#include<filesystem> //requires cpp17
#include <cstdlib>
#include<cmath>

#include </usr/local/cuda-12.6/targets/x86_64-linux/include/cuda_runtime.h>

#include<ginkgo/ginkgo.hpp>

#include </home/benh/BA-Ginkgo_vs_Dune/resources/time_experiment.hh>






#include <iostream>
#include <typeinfo>

#include <tuple>

template <typename T>
void printClassInfo(const T& obj) {
    int status;
    char* demangled = abi::__cxa_demangle(typeid(obj).name(), nullptr, nullptr, &status);
    std::cout << "Class: " << (status == 0 ? demangled : typeid(obj).name()) << std::endl;
    free(demangled);
}

void print (std::string message){
  std::cout<<message<<std::endl;
}
void printGPURAM(){
  //system("nvidia-smi --query-gpu=memory.used --format=csv,noheader,nounits | awk '{print $1/1024 \" GB\"}'");
  system("nvidia-smi --query-gpu=memory.used --format=csv,noheader,nounits | awk '{print $1 \" MiB\"}'");
}
/*
void setCudaHeapSize(size_t heapSize){

    // Attempt to set the heap size
    cudaError_t err = cudaDeviceSetLimit(cudaLimitMallocHeapSize, heapSize);
    if (err != cudaSuccess) {
        std::cerr << "Failed to set heap size: " << cudaGetErrorString(err) << "\n";
    }
    else{
    // Verify the heap size was set correctly
    size_t setHeapSize;
    cudaDeviceGetLimit(&setHeapSize, cudaLimitMallocHeapSize);
    std::cout << "Heap size successfully set to: " << setHeapSize << " bytes\n";
    }
}
*/





int main(int argc, char* argv[]){
  std::cout<<"------------------------------starting to run ginkgo-testing------------------------------"<<std::endl;
  using ValueType = double;
  using IndexType = gko::int64;

  using Mtx = gko::matrix::Csr<ValueType,IndexType>;
  using Vec = gko::matrix::Dense<ValueType>;
  using dim = gko::dim<2>;
  using matrix_data = gko::matrix_data<ValueType,IndexType>;
  print("The verry beninging:");
  printGPURAM();

for (long long i= 277078826; i=i+10000; i<277088826){
  print("i: "+std::to_string(i));
  IndexType N_size_bytes = 7000L * 1024 * 1024; //MiB
  IndexType N = (N_size_bytes/8)/3;
  N = i;
  //IndexType N = std::pow(650,3) ;
  print("N:" + std::to_string(N));
  print("Vec of size N in MiB:" + std::to_string(N*8/(1024 * 1024)));
  //auto exec = gko::ReferenceExecutor::create();
  auto exec = gko::CudaExecutor::create(0,gko::OmpExecutor::create());
  
  /*
  print("exec created");
  printGPURAM();
  //setCudaHeapSize(heapSize);
  auto x = Vec::create(exec, dim{N, 1});
  print("vec x created");
  printGPURAM();
  x->fill(1);
  print("vec x filled");
  printGPURAM();
  
  auto y = Vec::create(exec, dim{N, 1});
  print("vec y created");
  printGPURAM();
  */
 
 auto mtx = Mtx::create(exec);
    printClassInfo(mtx);
    print("created matrix");
    printGPURAM();
  auto data = matrix_data::diag(dim{N},3);
    print("created matrix_data");
    printGPURAM();
  mtx->read(data);
    print("filled matrix with matrix_data");
    printGPURAM();
    /*
    mtx->apply(x, y);
    print("after SpMV");
    printGPURAM();
    */
   //gko::write(std::cout, y);
  }
  


  std::cout<<"------------------------------finished running ginkgo-testing------------------------------"<<std::endl;

}



/*
using   auto data = gko::matrix_data<>::diag(dim{2333222111},3);

benh@milan01:~/BA-Ginkgo_vs_Dune/src/ginkgo/tests/build$ ./ginkgo-testing 
terminate called after throwing an instance of 'gko::OverflowError'
  what():  /home/benh/BA-Ginkgo_vs_Dune/dependencies/GINKGO/ginkgo-1.8.0/reference/components/prefix_sum_kernels.cpp:25: Overflowing int
Aborted
*/