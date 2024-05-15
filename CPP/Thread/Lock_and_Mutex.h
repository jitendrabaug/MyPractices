#pragma once
#include<thread>
#include<iostream>
#include<vector>
#include<mutex>

class Wallet
{
    int mMoney;
public:
    Wallet() :mMoney(0) {}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
        for (int i = 0; i < money; ++i)
        {
            mMoney++;
        }
    }
};


int TestMultithreadedWallet()
{
    Wallet walletObject;
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }
    for (int i = 0; i < threads.size(); i++)
    {
        threads.at(i).join();
    }
    return walletObject.getMoney();
}


void lock_main()
{
    for (int k = 0; k < 1000; k++)
    {
        int val = 0;
        if ((val = TestMultithreadedWallet()) != 5000)
        {
            std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
        }
    }
}



