﻿#ifndef CPPSORTSUMMARY_H
#define CPPSORTSUMMARY_H

#include <list>
#include <algorithm>
#include <future>
#include <type_traits>

namespace  CPPSortSummary
{



    template<class T>
    std::list<T> sequential_quick_sort(std::list<T> input)
    {
        if(input.empty()) {
            return input   ;
        }

        std::list<T> result ;
        result.splice(result.begin(), input, input.begin())  ;
        T const& pivot = *result.begin() ;

        auto divide_point =  std::partition(input.begin() , input.end() ,
                                            [&](T const&t) {return t < pivot ;}) ;

        std::list<T> lower_part ;
        lower_part.splice(lower_part.end() ,input, input.begin() ,divide_point)  ;

        auto new_lower (sequential_quick_sort(std::move(lower_part)))  ;
        auto new_hight (sequential_quick_sort(std::move(input)))  ;

        result.splice(result.end(), new_hight)  ;
        result.splice(result.begin(), new_lower)  ;

        return  result  ;

    }




    template<class T>
    std::list<T> parallel_quick_sort(std::list<T> input)
    {
        if(input.empty()) {
            return input   ;
        }

        std::list<T> result ;
        result.splice(result.begin(), input, input.begin())  ;
        T const& pivot = *result.begin() ;

        auto divide_point =  std::partition(input.begin() , input.end() ,
                                            [&](T const&t) {return t < pivot ;}) ;

        std::list<T> lower_part ;
        lower_part.splice(lower_part.end() ,input, input.begin() ,divide_point)  ;

//        auto new_lower (parallel_quick_sort(std::move(lower_part)))  ;
//        auto new_hight (parallel_quick_sort(std::move(input)))  ;

         std::future<std::list<T>> new_lower(
                     std::async(&parallel_quick_sort<T>,std::move(lower_part)))  ;

         auto new_hight (parallel_quick_sort(std::move(input)))  ;


        result.splice(result.end(), new_hight)  ;
        result.splice(result.begin(), new_lower.get())  ;

        return  result  ;

    }


    template<typename F,typename A>
    std::future<std::result_of<F(A&&)>::type>
       spawn_task(F&& f , A&& a)
    {
        typedef  std::result_of<F(A&&)>::type result_type  ;


        std::packaged_task<result_type(A&&)>  task(std::move(f)) ;

        std::future<result_type> res(task.get_future()) ;
        std::thread t(std::move(task),std::move(a))  ;
        t.detach()  ;

        return  res ;
    }



};




#endif // CPPSORTSUMMARY_H
