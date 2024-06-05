#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include<stdlib.h>
#include<time.h>
#include <chrono>
using namespace std;

class Account 
{
protected:
    vector<unsigned int> foodCount;

public:
    virtual void print_Info() const = 0;
    // setter
    void push_back_foodCount(unsigned int foodCount);

    // getter
    const vector<unsigned int>* getFoodCount() const;
    size_t size() const;
};

class UserAccount : public Account 
{
private:
    string ID;
    string password;
    vector<unsigned int> total; // 모든 객체의 foodCount 값을 합산한 결과를 저장할 변수

public:
    UserAccount(const string ID, const string password)
    {
        this->ID = ID;
        this->password = password;
    }
    // setter
    void set_ID(const string& ID);
    void set_password(const string& password);

    // getter
    string get_ID() const;
    string get_Password() const;
    //string get_password();
    void print_Info() const override;

    const vector<unsigned int>& getTotal() const {
        return total;
    }

    // 모든 UserAccount 객체의 foodCount 값을 합산하여 total 객체에 저장하는 함수
    static UserAccount calculateTotal(const vector<UserAccount>& accounts) {
        UserAccount totalAccount("Total", "Nopassword"); // total을 저장할 UserAccount 객체 생성
        // 모든 객체의 foodCount 값을 total에 누적
        for (const auto& account : accounts) {
            const vector<unsigned int>& foodCount = *(account.getFoodCount());
            for (size_t i = 0; i < foodCount.size(); ++i) {
                // total의 크기가 충분하지 않으면 늘려줌
                if (i >= totalAccount.total.size()) {
                    totalAccount.total.resize(i + 1, 0);
                }
                totalAccount.total[i] += foodCount[i];
            }
        }
        return totalAccount;
    }

};

class Similarity 
{
private:
    vector<UserAccount> accounts;
    vector<vector<double>> cos_similarity;
    vector<vector<double>> recommendations;

    inline double cosine_similarity(const vector<unsigned int>& v1, const vector<unsigned int>& v2)
    {
        unsigned int dot_product = 0;
        unsigned int norm_v1 = 0;
        unsigned int norm_v2 = 0;

        for (size_t i = 0; i < v1.size(); ++i) {
            dot_product += v1[i] * v2[i];
            norm_v1 += v1[i] * v1[i];
            norm_v2 += v2[i] * v2[i];
        }

        if (norm_v1 == 0 || norm_v2 == 0) return 0.0;
        return dot_product / (sqrt(norm_v1) * sqrt(norm_v2));
    }
public:
    Similarity(const vector<UserAccount>& accounts) : accounts(accounts) 
    {
        cos_similarity.resize(accounts.size(), vector<double>(accounts.size(), 0.0));
        recommendations.resize(accounts.size());

        for (size_t i = 0; i < accounts.size(); ++i) 
        {
            recommendations[i].resize(accounts[i].size(), 0.0);
        }
    }

    void calculate_cosine_similarity();
    void generate_recommendations();


    vector<double> get_recommendations_for_user(const UserAccount& user) const;
    void print_recommendations() const;

    
};

