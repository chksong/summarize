#include <QCoreApplication>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>



template<typename T>
bool greatCompare(const T& lv ,const T& rv)
{
    return  lv > rv ;
}



int main(int argc, char *argv[])
{
   // QCoreApplication a(argc, argv);

    std::vector<int> dataList {100, 99,91,20,83, 9,5,7,8,1,3,2,6,0,4 ,12, 98, 96,97,94,90,95} ;
  //  std::partial_sort(dataList.begin() ,dataList.begin() + 5 ,dataList.end()) ;
     std::nth_element(dataList.begin() ,dataList.begin()+ 20 ,dataList.end()) ;

     auto ret = std::stable_partition(dataList.begin() ,dataList.end(), [](int val){ return  val >50 ;})  ;

//     int a[]={3,5,2,6,1,4};

// //     std::nth_element(a, a+3, a+sizeof(a)/sizeof(int));


//      copy(a, a+sizeof(a)/sizeof(int),
//              std::ostream_iterator<int>(std::cout, " "));

    for_each(dataList.begin(), dataList.end(), [](int val){ std::cout << " " << val  ;}) ;
    return  1 ;
}
