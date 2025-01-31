#include<iostream>
#include<chrono>
#include<map>
#include<fstream>
#include<filesystem> //requires cpp17
#include <cstdlib>

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








int main(int argc, char* argv[]){
  using ValueType = double;
  using IndexType = int;

  using Mtx = gko::matrix::Csr<double, int>;
  using Vec = gko::matrix::Dense<double>;
  using dim = gko::dim<2>;
  using matrix_data = gko::matrix_data<double, unsigned long long>;

  auto exec = gko::ReferenceExecutor::create();
  auto x = Vec::create(exec, dim{10, 1});
  auto y = Vec::create(exec, dim{10, 1});

  /*matrix_data data{dim{10, 10}};
  for (int row = 0; row < 10; row++) {
      data.nonzeros.emplace_back(row, row, 2.0);
      data.nonzeros.emplace_back(row, (row + 1) % 10, -1.0);
      data.nonzeros.emplace_back(row, (row + 9) % 10, -1.0);
      x->at(row, 0) = 1.0; // only works on CPU executors
  }*/
  auto mtx = Mtx::create(exec);
  printClassInfo(mtx);
  auto data = gko::matrix_data<>::diag(dim{2333222111},3);
  std::cout<<"starting spmv"<<std::endl;
  mtx->read(data);
  mtx->apply(x, y);
  //gko::write(std::cout, y);



}



/*
using   auto data = gko::matrix_data<>::diag(dim{2333222111},3);

benh@milan01:~/BA-Ginkgo_vs_Dune/src/ginkgo/tests/build$ ./ginkgo-testing 
terminate called after throwing an instance of 'gko::OverflowError'
  what():  /home/benh/BA-Ginkgo_vs_Dune/dependencies/GINKGO/ginkgo-1.8.0/reference/components/prefix_sum_kernels.cpp:25: Overflowing int
Aborted
*/