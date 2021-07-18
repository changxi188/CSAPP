#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; ++i)
    {
        printf(" %.2x", *(start + i));
    }
    std::cout << std::endl;
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(x));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(x));
}

void show_pointer(void* x)
{
    show_bytes((byte_pointer)&x, sizeof(x));
}

void show_string(const char* s)
{
    show_bytes((byte_pointer)s, strlen(s));
}

void test_show_bytes(int val)
{
    int   ival = val;
    float fval = val;
    int*  pval = &val;
    std::cout << "show int : ";
    show_int(ival);
    std::cout << "show float : ";
    show_float(fval);
    std::cout << "show pointer : ";
    show_pointer(pval);
}

int main()
{
    const char* s = "abcdef";

    int val = 12345;
    test_show_bytes(12345);
    std::cout << "showo string : ";
    show_string(s);
}
