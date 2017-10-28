/* William Blair
 * CS 548
 * 10/18/17
 * Assignment 3
 * Surface.hpp - header for Surface Class */

#include <string>

#ifndef SURFACE_H_INCLUDED
#define SURFACE_H_INCLUDED

class Surface
{
public:
    virtual std::string toString() = 0;
    virtual ~Surface(){}
};

#endif