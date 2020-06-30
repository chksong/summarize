#include <QCoreApplication>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "cppsortsummary.h"
using namespace CPPSortSummary  ;


template<typename T>
bool greatCompare(const T& lv ,const T& rv)
{
    return  lv > rv ;
}



//template<class T>
//std::list<T> sequential_quick_sort(std::list<T> input)
//{
//    if(input.empty()) {
//        return input   ;
//    }

//    std::list<T> result ;
//    result.splice(result.begin(), input, input.begin())  ;
//    T const& pivot = *result.begin() ;

//    auto divide_point =  std::partition(input.begin() , input.end() ,
//                                        [&](T const&t) {return t < pivot ;}) ;

//    std::list<T> lower_part ;
//    lower_part.splice(lower_part.end() ,input, input.begin() ,divide_point)  ;

//    auto new_lower (sequential_quick_sort(std::move(lower_part)))  ;
//    auto new_hight (sequential_quick_sort(std::move(input)))  ;

//    result.splice(result.end(), new_hight)  ;
//    result.splice(result.begin(), new_lower)  ;

//    return  result  ;

//}


int main(int argc, char *argv[])
{
   // QCoreApplication a(argc, argv);

    std::list<int> dataList {55, 99,91,20,83, 9,5,7,8,1,3,55,55,55,2,6,0,4 ,12, 98, 96,97,94,90,95} ;

    auto myResult = sequential_quick_sort(dataList) ;

    //  std::partial_sort(dataList.begin() ,dataList.begin() + 5 ,dataList.end()) ;
 //   std::nth_element(dataList.begin() ,dataList.begin()+ 20 ,dataList.end()) ;

//    auto ret = std::stable_partition(dataList.begin() ,dataList.end(), [](int val){ return  val >50 ;})  ;

//     int a[]={3,5,2,6,1,4};

// //     std::nth_element(a, a+3, a+sizeof(a)/sizeof(int));


//      copy(a, a+sizeof(a)/sizeof(int),
//              std::ostream_iterator<int>(std::cout, " "));

//   for_each(dataList.begin(), dataList.end(), [](int val){ std::cout << " " << val  ;}) ;
    return  1 ;
}
