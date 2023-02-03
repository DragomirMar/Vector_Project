#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<stdexcept>
#include<initializer_list>

using namespace std;

class Vector{
public:
    //class ConstIterator;
    //class Iterator;
    using value_type = double;
    using const_reference = const value_type&;
    //using iterator = Vector::Iterator;
    //using const_iterator = Vector::ConstIterator;
private:
    size_t sz;
    size_t max_sz;
    static constexpr size_t min_sz{5};
    value_type* values;
public:

//defaultconstructor
    Vector() : Vector(min_sz){
    }

    Vector(size_t n){
        if(n< min_sz)
            n = min_sz;
        sz=0;
        values = nullptr;
        max_sz = 0;
        reserve(n);
    }
    // Vector(initializer_list<double> list){}
    Vector(initializer_list<double> list)
            :sz(list.size()), max_sz(list.size()*2),values(new value_type[list.size()*2]){

        int i{0};
        for(const auto &l: list){
            values[i]= l;
            ++i;
        }
    }

//copyconstructor
    Vector(const Vector& src){
        max_sz = src.max_sz;
        values = new value_type[max_sz];
        for(size_t i{0}; i<src.sz; ++i)
            values[i] = src.values[i];
        sz = src.sz;
    }

//Kopierzuweisungsoperator
    Vector operator= (Vector src){
        swap(sz, src.sz);
        swap(max_sz, src.max_sz);
        swap(values, src.values);
        return *this;
    }
//destructor
    ~Vector(){
        delete[] values;
    }


    size_t size() const{
        return sz;
    }

    bool empty() const{
        if(sz==0)
            return true;
        return false;
    }

    void clear(){
        sz=0;
    }

    void reserve(size_t n){
        if(n>max_sz){
            size_t new_sz= n;
            value_type* new_values = new value_type[new_sz];
            for(size_t i{0}; i<sz; ++i)
                new_values[i] = values[i];
            max_sz = new_sz;
            delete[] values;
            values = new_values;
        }
    }

    void shrink_to_fit(){
        value_type* new_values = new value_type[sz];

        for(size_t i{0}; i<sz; ++i){
            new_values[i]= values[i];
        }
        max_sz=sz;

        delete[] values;
        values= new_values;
    }

    void push_back(const_reference val){
        if(sz >= max_sz) {
            reserve(max_sz*2);
        }
        values[sz++] = val;
    }

    void pop_back() {
        if(sz==0)
            throw runtime_error ("Empty vector");
        --sz;
    }

    double& operator[](size_t index){
        if(index>= sz)
            throw runtime_error("No such value in the vector!");
        return values[index];
    }

    const double& operator[](size_t index) const{
        if(index>= sz)
            throw runtime_error("No such value in the vector!");
        return values[index];
    }

    size_t capacity() const{
        return max_sz;
    }

    ostream& print(ostream& o) const{
        o<<"[";
        bool first{true};
        for(size_t i{0}; i<sz; ++i) {
            if(first){
                first=false;
            }
            else
                cout<<", ";
            o << values[i];
        }
        o<<"]"<<endl;
        return o;
    }

    friend ostream& operator<<(ostream& o, const Vector& v){
        return v.print(o);
    }

    void change(){
        values[0]= 5;
    }
};


#endif
