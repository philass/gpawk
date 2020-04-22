#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/copy.h>
#include <thrust/count.h>

#include <iostream>

char TESTSTRING[] = "how many lines\n are in this\n guy right\n here";
struct is_end
{
  __host__ __device__
  bool operator()(const char x)
  {
    return x == '\n';
  }
};

int main() {
    int stringSize = sizeof TESTSTRING - 1;
    thrust::device_vector<char> dev(stringSize);
    thrust::copy(TESTSTRING, TESTSTRING + stringSize, dev.begin());
    int break_cnt = thrust::count(dev.begin(), dev.end(), '\n');
    thrust::device_vector<int> dev_pos(break_cnt);
    thrust::copy_if(thrust::make_counting_iterator(0),
                   thrust::make_counting_iterator(stringSize),
                                   dev.begin(), dev_pos.begin(), is_end());
    thrust::host_vector<int> hos = dev_pos;
    for (int i = 0; i < hos.size(); i++) {
        std::cout << hos[i] << std::endl;
    }
}
