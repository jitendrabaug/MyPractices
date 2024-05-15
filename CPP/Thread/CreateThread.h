#pragma once
#include<thread>
#include<iostream>
#include<vector>
#include<mutex>
std::mutex m;
void Threadfunction()
{
	std::cout << "This is called from outside thread function " << std::endl;
}
class FromFunctor
{
public:
	void operator() ()
	{
		std::cout << "This is called inside a functor thread function " << std::endl;
	}
};

void ThreadParam(int a, std::string s)
{
	std::cout << "Passed Number = " << a << std::endl;
	std::cout << "Passed String = " << s << std::endl;
}

class TestThread
{
public:
	void CreateThread1(std::string& str)
	{
		std::cout << "This member function thread is : " << std::this_thread::get_id()<< " and name is " << str << std::endl;
	}
};

void creatingThread()
{
	std::thread t1(Threadfunction);
	std::thread t2(Threadfunction);

	std::cout << t1.get_id() << " --  " << t2.get_id() << std::endl;

	t2.join();
	t1.detach();

	std::thread t3((FromFunctor()));
	t3.join();
}

void ThreadOfVectors()
{
	std::vector<std::thread> threadList;
	for (int i = 0; i < 5; i++)
	{
		std::lock_guard<std::mutex> lg(m);
		threadList.emplace_back(std::thread(Threadfunction));
		std::cout << "The thread inside the vector at index " << i <<" is " << threadList.at(i).get_id() << std::endl;
	}

	for (int i = 0; i < 5; i++)
	{
		threadList.at(i).join();
	}
}

void PassingArguments()
{
	std::thread t1(ThreadParam, 12, "Jitendra");
	t1.join();
}

void creating_from_class_method()
{
	TestThread ct;
	std::string str = "Jitendra";
	std::thread t1(&TestThread::CreateThread1, &ct,std::ref(str));
	t1.join();
}

void test_main()
{
	
	creatingThread();
	ThreadOfVectors();
	PassingArguments();
	creating_from_class_method();
}