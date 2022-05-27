//
// Created by kirill_kazarin on 15.05.22.
//

#ifndef LAB_6_SUBSTR_SERCH_H
#define LAB_6_SUBSTR_SERCH_H

#include <list>
#include <utility>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <iostream>
#include <unordered_map>

#include "for_each_point.h"


namespace h_work{

    struct res_of_serch{

        res_of_serch(std::string str, std::string substr) : str(std::move(str)), substr(std::move(substr)) {};

        ~res_of_serch()=default;

        void push(size_t i){
            number_of_repetitions++;
            beg_num_substrs.push_back(i);
        }

        friend std::ostream &operator<<(std::ostream &os, const res_of_serch &serch) {
            os << "number_of_repetitions: " << serch.number_of_repetitions << std::endl << " beg_substrs: "
               << std::endl;
            auto iter_of_list=serch.beg_num_substrs.begin();

            for (size_t s=0;s<serch.str.size() ; s++) {
                if(s==iter_of_list.operator*()){
                    os<<"{"<<serch.substr<<'}';
                    s+=serch.substr.size();
                    iter_of_list.operator++();
                    } else{
                    os<<(serch.str[s]);
                }
            }
            return os;
        }

        [[nodiscard]] size_t get_number_of_repetitions() const {
            return number_of_repetitions;
        }

        [[nodiscard]] const std::list<size_t> &get_beg_num_substrs() const {
            return beg_num_substrs;
        }

    private:
        size_t number_of_repetitions=0;
        std::list<size_t> beg_num_substrs{};
        std::string str;
        std::string substr;
    };

    res_of_serch strSRCH_Rabin_Karp(std::string &str, const std::string &sub_str) {
    //функция хеширования

        auto fun_hash = std::hash<std::string>();
    //находим размер подстроки

        auto len_sub_str = sub_str.size();

        auto result = res_of_serch(str,sub_str);

        // если строка меньше чем sub-строка то возвращаем (нулевой элемент)
        if(len_sub_str>str.size())return result;

        auto hash_sab_str = fun_hash(sub_str);

        //показатель смещения отначала строчки
        int i=0;

        for_each_point(str.begin(), (str.end().operator-(len_sub_str-1)),
                   [&result, &fun_hash, &hash_sab_str, len_sub_str,&i](std::string::iterator::pointer a) -> void {

                       auto s = fun_hash(std::string(a, len_sub_str));
                       if (s == hash_sab_str){
                           result.push(i);
                       }
                       i++;
                   });

        return result;
    }


    res_of_serch strSRCH_Boyer_Moore(std::string &str,const std::string &sub_str){
        auto len_sub_str = sub_str.size();
        auto len_str = str.size();

        auto result = res_of_serch(str,sub_str);

        // если строка меньше чем sub-строка то возвращаем (нулевой элемент)
        if(len_sub_str>len_str)return result;

        //введем stop suff функции(зададим рез через  hashMAP)

        auto stop_fun=[](const std::string &sub_str)->std::unordered_map<char,size_t>{

            std::unordered_map<char,size_t> res=std::unordered_map<char,size_t>();

            for (size_t i = 0; i < sub_str.size()-1; ++i) {
                res.insert_or_assign(sub_str[i],i);
            }
            return res;
        };

        auto prefix_fun=[](std::string sub_str)->std::vector<size_t>{
            auto res_PI=std::vector<size_t>(sub_str.size(),0);
            size_t k=0;

            for (size_t i = 1; i <sub_str.size() ; ++i) {
                while ((k>0) && sub_str[k] != sub_str[i]){
                    k=res_PI[k-1];
                }

                if(sub_str[k]==sub_str[i]){
                    k++;
                }

                res_PI[i]=k;
            }
            return res_PI;
        };

        auto suff_fun=[&prefix_fun](const std::string& sub_str)->std::vector<size_t>{

            size_t len_of_substr=sub_str.size();
            auto PI=prefix_fun(sub_str);
            auto PI_rev=prefix_fun(std::string(sub_str.crbegin(), sub_str.crend()));

            auto res_vector= std::vector<size_t>(len_of_substr+1, len_of_substr - PI[len_of_substr - 1]);

            for (size_t i = 0; i <len_of_substr ; ++i) {
                size_t ind= len_of_substr - PI_rev[i];
                size_t shift = i - PI_rev[i] + 1;
                if(res_vector[ind]>shift){
                    res_vector[ind]=shift;
                }
            }

            return res_vector;
        };

        //сам алгоритм поиска
        auto Stop=stop_fun(sub_str);
        auto Suff=suff_fun(sub_str);
        size_t delta_stop;
        size_t delta_suff;

        for (size_t i=0; i <len_str-len_sub_str+1;) {
            int64_t j=len_sub_str-1;

            while (j>=0 && sub_str[j]==str[i+j]){
                j--;
            }

            if(j==-1){
                result.push(i);
                delta_stop=1;
            } else {
                delta_stop = j - ((Stop[str[i+j]]==0) ? -1 : Stop[str[i+j]]);
            }

            delta_suff=Suff[j+1];

            i+= std::max(delta_suff,delta_stop);
        }
    return result;
}


    res_of_serch strSRCH_KMP(std::string str,std::string sub_str){

    auto prefix_fun=[](std::string sub_str)->std::vector<size_t>{
        auto res_PI=std::vector<size_t>(sub_str.size(),0);
        size_t k=0;

        for (size_t i = 1; i <sub_str.size() ; ++i) {
            while ((k>0) && sub_str[k] != sub_str[i]){
                k=res_PI[k-1];
            }

            if(sub_str[k]==sub_str[i]){
                k++;
            }

            res_PI[i]=k;
        }
        return res_PI;
    };

    auto result = res_of_serch(str,sub_str);

    auto PI =prefix_fun(sub_str);
    size_t k=0;

    for (size_t i = 0; i < str.size(); ++i) {
        while ((k>0) && sub_str[k] != str[i]){
            k=PI[k-1];
        }
        if(sub_str[k]==str[i]){
            k++;
        }

        if(k==sub_str.size()){
            result.push(i-sub_str.size()+1);
            k=PI[k-1];
        }
    }

    return result;
}
/*
std::list<std::string> strSRCH_state_machine(std::string str,std::string sub_str){
    return nullptr;
}

*/
}



#endif //LAB_6_SUBSTR_SERCH_H
