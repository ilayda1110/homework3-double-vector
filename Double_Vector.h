#ifndef DOUBLE_VECTOR_DOUBLE_VECTOR_H
#define DOUBLE_VECTOR_DOUBLE_VECTOR_H

#pragma once
#include <iostream>

using namespace std;

class Double_vector
{
private:
    double* items;
    int sz;
    int array_capacity;
public:
    Double_vector();
    Double_vector(int n, double val = 0.0);
    Double_vector(double[], int);
    Double_vector(const Double_vector& x);
    void print()const;
    ~Double_vector() { cout << "Destructor" << endl; }
    int size() const;
    //Double_vector& operator=(const Double_vector& x);

    int max_size() const;
    void resize(int n, double val = 0.0);
    int capacity() const;
    //bool empty() const;
    //void reserve(int n);
    //void shrink_to_fit();
    double& operator[](int pos);
    const double& operator[](int pos) const;
    double& at(int pos);
    const double& at(int pos) const;
    //double& front();
    //const double& front() const;
    //double& back();
    //const double& back() const;
    //double* data();
    //const double* data() const;


    void push_back(const double& value);
    void push_back(double[], int);


    void pop_back();
    void insert(int pos, double value);
    void erase(int pos);
    //void clear();
    friend std::ostream& operator<<(std::ostream& os, const Double_vector& vec);

    bool operator==(const Double_vector& rhs)const;
    bool operator!=(const Double_vector& rhs)const;
    Double_vector operator+(const Double_vector &other)const;
};

#endif //DOUBLE_VECTOR_DOUBLE_VECTOR_H