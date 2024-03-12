#include "Double_Vector.h"
#include<iostream>

using namespace std;

Double_vector::Double_vector() :sz(0), array_capacity(100)
{
    items = new double[array_capacity];
}

Double_vector::Double_vector(int n, double val) :sz{ n }, array_capacity{ n }
{
    items = new double[array_capacity];
    for (int i = 0; i < sz; i++) {
        items[i] = val;
    }
}

Double_vector::Double_vector(double lst[], int n):sz(n), array_capacity(n)
{
    items = new double[array_capacity];
    for (int i = 0; i < sz; i++) {
        items[i] = lst[i];
    }
}

Double_vector::Double_vector (const Double_vector& x)
{
    sz = x.sz;
    array_capacity = x.array_capacity;
    items = new double[array_capacity];
    for (int i = 0; i < x.sz; i++)
    {
        items[i] = x.items[i];
    }
}

void Double_vector::print()const
{
    int i = 0;
    cout << "v = {";
    while (i < sz - 1) {
        cout << items[i] << ",";
        i++;
    }
    if (sz <= 0)
        cout << "}" << endl;
    else
        cout << items[i] << "}" << endl;
}

int Double_vector::size()const
{
    return sz;
}

int Double_vector::max_size()const { return array_capacity; }

void Double_vector::resize(int n, double val)
{
    if(sz > n)
    {
        double *new_elements = new double[n];
        for(int i=0; i < n; i++)
            new_elements[i] = items[i];
        delete []items;
        items = new_elements;
        sz = n;
        array_capacity = n;
    }
    else if(sz < n)
    {
        double *new_elements = new double[n];
        for(int i = 0; i < sz; i++)
            new_elements[i] = items[i];
        for(int i = sz; i < n; i++)
            new_elements[i] = val;
        delete []items;
        items = new_elements;
        sz = n;
        array_capacity = n;
    }
}

int Double_vector::capacity() const { return (array_capacity*sizeof(double)); }

double& Double_vector::operator[](int pos)
{
    return items[pos];
}

const double& Double_vector::at(int pos) const
{
    if(pos > 0 && pos <= sz)
    {
        return items[pos];
    }
    else
    {
        cout << "Invalid index" << endl;
    }
}

void Double_vector::push_back(const double& val)
{
    if (sz < this->array_capacity)
    {
        items[sz] = val;
        sz++;
    }
    else
    {
        double *new_elements = new double[array_capacity * 2];
        array_capacity *= 2 ;
        for (int i = 0; i < sz; i++)
            new_elements[i] = items[i];
        delete []items;
        items = new_elements;
        items[sz] = val;
        sz++;
    }
}

void Double_vector::push_back(double ls[],int n)
{
    double* new_elements = new double[array_capacity + n];
    array_capacity += n;
    for (int i = 0; i < sz; i++)
        new_elements[i] = items[i];
    delete[]items;
    items = new_elements;
    for (int i = 0; i < n; i++)
    {
        items[i + sz] = ls[i];
    }
    sz += n;
}

void Double_vector::pop_back()
{
    double *new_elements = new double[sz-1];
    for (int i = 0; i < sz-1; i++)
        new_elements[i] = items[i];
    delete []items;
    items = new_elements;
    sz --;
}

void Double_vector::insert(int pos, double value)
{
    if(pos > 0 && pos <= sz)
    {
        if(sz < array_capacity)
        {
            for(int i=sz; i > pos-1; i--)
            {
                items[i] = items[i-1];
            }
            items[pos-1] = value;
        }
        else
        {
            sz ++;
            double *new_elements = new double[array_capacity*2];
            array_capacity *= 2;
            if(pos == 1)
            {
                new_elements[0] = value;
                for(int i=1; i < sz; i++)
                    new_elements[i] = items[i-1];
            }
            else
            {
                for (int i = 0; i < pos-1; i++)
                    new_elements[i] = items[i];

                new_elements[pos-1] = value;
                for(int i=0; i < sz; i++)
                    new_elements[i] = items[i-1];
            }
            delete []items;
            items = new_elements;
        }
    }
}

void Double_vector::erase(int pos)
{
    if(pos > 0 && pos <= sz)
    {
        for(int i=pos; i < sz; i++)
        {
            items[i-1] = items[i];
        }
        sz--;
    }
}

bool Double_vector::operator==(const Double_vector& rhs)const
{
    if (this->sz != rhs.sz) return false;

    for (int i = 0; i < sz; i++)
        if (this->items[i] != rhs.items[i])
        {
            return false;
        }
    return true;
}

bool Double_vector::operator!=(const Double_vector& rhs)const
{
    return !(*this == rhs);
}

Double_vector Double_vector::operator+(const Double_vector& rhs)const
{
    Double_vector res;
    int newCapacity = this->sz + rhs.sz;
    if (res.array_capacity < newCapacity)
    {
        res.array_capacity = newCapacity;
        delete[]res.items;
    }
    int i = 0;
    for (i = 0; i < this->sz; i++)
    {
        res.items[i] = this->items[i];
    }
    res.sz = this->sz;
    for (i = 0; i < rhs.sz; i++)
    {
        res.items[i + res.sz] = rhs.items[i];
    }
    res.sz = this->sz + rhs.sz;
    this->print();
    rhs.print();
    res.print();
    return res;
}