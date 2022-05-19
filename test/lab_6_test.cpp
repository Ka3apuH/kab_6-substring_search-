//
// Created by kirill_kazarin on 17.05.22.
//

#include "lab_6_test.h"

#include <iostream>

#include "gtest/gtest.h"

using namespace h_work;
using namespace std;

TEST_F(Testing_substr_serch,alg_Rabin_Karp){
    auto str=std::string("errevkdfobfmbr9oweveromfdirwmibnieverrever");
    auto list= strSRCH_Rabin_Karp(str, "ever");

    cout<<str.crbegin().operator*();

    ASSERT_EQ(3, list.get_number_of_repetitions());
}

TEST_F(Testing_substr_serch,alg_Rabin_Karp_0){
    auto str=std::string("");
    auto list= strSRCH_Rabin_Karp(str, "ever");

    //cout<<list;
    ASSERT_EQ(0, list.get_number_of_repetitions());
}

TEST_F(Testing_substr_serch,alg_Boyer_Moore){


}

TEST_F(Testing_substr_serch,alg_KMP){


}

TEST_F(Testing_substr_serch,alg_state_machine){


}



