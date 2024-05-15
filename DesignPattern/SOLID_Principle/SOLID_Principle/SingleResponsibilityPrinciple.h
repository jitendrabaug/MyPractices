#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <boost/lexical_cast.hpp>
using namespace std;

struct Journal
{
    string title;
    vector<string> entries;

    explicit Journal(const string& title)
        : title{ title }
    {
    }

    void add(const string& entry);

    // persistence is a separate concern
    void save(const string& filename);
};

void Journal::add(const string& entry)
{
    static int count = 1;
    entries.push_back(std::to_string(count++)
        + ": " + entry);
}

void Journal::save(const string& filename)
{
    ofstream ofs(filename);
    for (auto& s : entries)
        ofs << s << endl;
}

//Writing task can be taken elsewhere like writing the below class

struct PersistenceManager
{
    static void save(const Journal& j, const string& filename)
    {
        ofstream ofs(filename);
        for (auto& s : j.entries)
            ofs << s << endl;
    }
};

