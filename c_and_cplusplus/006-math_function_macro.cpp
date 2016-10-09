/************************************************************************
* CREATED TIME: 2016-9-4 18:20:55
* LAST MODIFIED TIME: 2016-10-9 16:52:04
* DESCRIPTION: 一些常用的数学计算函数和宏定义
* BY: 357688981@qq.com
************************************************************************/

#include <iostream>

/***********************************
* 常用的宏定义
***********************************/
// 度数 ==> 弧度
/**Util macro for conversion from degrees to radians.*/
#define MATH_DEG_TO_RAD(x)        ((x) * 0.0174532925f)
// 弧度 ==> 度数
/**Util macro for conversion from radians to degrees.*/
#define MATH_RAD_TO_DEG(x)        ((x) * 57.29577951f)

// 最大最小值
#define MATH_MIN(a,b)            (((a) < (b)) ? (a) : (b))
#define MATH_MAX(a,b)            (((a) > (b)) ? (a) : (b))

// 浮点数比较 是否相等
#define MATH_FLOAT_EQUAL(v1, v2) (abs(v1 - v2) < std::numeric_limits<float>::epsilon())

// 3个数中的最小数(同一类型)
template <typename T>
inline T Min3(T a, T b, T c) {
    T m = a;
    if (m > b) m = b;
    if (m > c) m = c;
    return m;
}

// 交换2个数(同一类型)
template <typename T>
inline void Swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}


/***********************************
* 常用的函数
***********************************/
/* 001. 返回下一个2的幂值 */
int NextPowerOfTwo(int x);
/** Returns the Next Power of Two value.
Examples:
- If "value" is 15, it will return 16.
- If "value" is 16, it will return 16.
- If "value" is 17, it will return 32.
@param value The value to get next power of two.
@return Returns the next power of two value.
*/
int NextPowerOfTwo(int x) {
    x = x - 1;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x + 1;
}

/* 002. 将 无符号整数 转换成 16进制数 */
const char digitsHex[] = "0123456789ABCDEF";

size_t convertHex(char buf[], uintptr_t value) {
    uintptr_t i = value;
    char* p = buf;

    do {
        int lsd = static_cast<int>(i % 16);
        i /= 16;
        *p++ = digitsHex[lsd];
    } while (i != 0);

    *p = '\0';
    std::reverse(buf, p);

    return p - buf;
}

int main()
{
    // test NextPowerOfTwo()
    std::cout << NextPowerOfTwo(15) << std::endl;
    std::cout << NextPowerOfTwo(32) << std::endl;
    std::cout << NextPowerOfTwo(65) << std::endl;

    // test size_t convertHex(char buf[], uintptr_t value)
    char hex_str[32];
    size_t ret = convertHex(hex_str, 60);
    std::cout << hex_str << "\n";  // 3C

    return 0;
}