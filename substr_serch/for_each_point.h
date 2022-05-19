//
// Created by kirill_kazarin on 17.05.22.
//

#ifndef LAB_6_SUBSTRSERCH_FOR_EACH_POINT_H
#define LAB_6_SUBSTRSERCH_FOR_EACH_POINT_H

#include <bits/algorithmfwd.h>

template<typename _InputIterator, typename _Function>
_Function
for_each_point(_InputIterator __first, _InputIterator __last, _Function __f)
{

    __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
    __glibcxx_requires_valid_range(__first, __last);
    for (; __first != __last; ++__first)
        __f(__first.operator->());
    return __f;
}

#endif //LAB_6_SUBSTRSERCH_FOR_EACH_POINT_H
