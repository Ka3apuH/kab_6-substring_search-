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
    auto str=std::string("abcbacdabdbabdbabcabddba");

    auto list= strSRCH_Boyer_Moore(str, "abdbab");

    ASSERT_EQ(2, list.get_number_of_repetitions());
}

TEST_F(Testing_substr_serch,alg_Boyer_Moore_2){
    auto str=std::string("eabdbababdbababdbababdbababdbababdbababdbababdbabtuzirzxrtixhfxrxrtoabdbabkjiabdbabyjijabdbabiurdzutezutez");

    auto list= strSRCH_Boyer_Moore(str, "abdbab");

    ASSERT_EQ(11, list.get_number_of_repetitions());
}

TEST_F(Testing_substr_serch,alg_KMP){
    auto str=std::string("eabdbababdbababdbababdbababdbababdbababdbababdbabtuzirzxrtixhfxrxrtoabdbabkjiabdbabyjijabdbabiurdzutezutez");

    auto list= strSRCH_KMP(str, "abdbab");

    ASSERT_EQ(11, list.get_number_of_repetitions());
}


