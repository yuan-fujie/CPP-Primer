#ch02 NOTE
#第2章
#变量和基本类型
------
------

##2.1 基本内置类型
------
##Exercise 2.1.1
###练习2.1：类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？
C++定义了`int`、`short` **最小尺寸**为16位，`long`**最小尺寸**是32位，`long long`**最小尺寸**是64位

`signed`(`带符号类型`)可以表示正数、负数和0，`unsigned`(`无符号类型`)只能表示大于等于0的值。
浮点型可以表示为单精度、双精度和扩展精度值。C++标准置顶了一个浮点数有效位数的最小值，然而大多数编译器都实现了更高的精度。通常，`float`以1个字（32比特）来表示，`double`以2个字节（64比特）来表示，`long double`以3或4个字(96或128比特)来表示。一般来说，类型`float`和`double`分别有7和16个有效位；类型`long double`则常常被用于有特殊浮点需求的硬件，它的具体实现不同，精度也各有不同。

**建议用法**

-	当明确知晓数值不可能为负时，应当选用无符号类型

-	使用`int`执行正整数运算。在实际应用中，`short`常常显得太小而`long`一般和`int`有一样的尺寸。如果数值超过`int`的表示范围，选用`long long`。

-	在算数表达式中不要使用`char`或`bool`，只有在存放字符或布尔值时才使用它们。因为类型`char`在一些机器上是有符号的，而在另一些机器上又是无符号的，所有如果使用`char`进行运算特别容易出问题。如果你需要使用一个不大的整数，那么明确指定它的类型是`signed char`或者是`unsigned char`。

-	执行浮点数运算选用`double`，这是因为`float`通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几。事实上，对于某些机器来说，双精度运算甚至比单精度还快。`long double`提供的精度在一般情况下是没有必要的，况且它带来的运行时消耗也不容忽视。

###练习2.2：计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由
使用`double`或者`float`。
数据都是有小数点的。

##Exercise 2.1.2
###练习2.3：读程序写结果。

```cpp

 #include <iostream>

using namespace std;

int main()
{

	unsigned u = 10, u2 = 42;
	
	cout << u2 - u << endl;
	cout << u - u2 << endl;
	
	int i = 10, i2 = 42;
	
	cout << i2 - i << endl;
	cout << i - i2 << endl;
	cout << i - u << endl;
	cout << u - i << endl;
	
	return 0;
} ```

输出：
```
32
4294967264
32
-32
0
0
```

![out](\screenshots\ch02\ex_2_3.png)

##2.1.3 字面值常量
------
##Exercise 2.1.3
###练习2.5：指出下述字面值的数据类型并说明每组内几种字面值的区别：
 
> -	(a) 'a', L'a', "a", L"a"
> -	(b) 10, 10u, 10L, 10uL, 012, 0xC
> -	(c) 3.14, 3.14f, 3.14L
> -	(d) 10, 10u, 10., 10e-2

（a）字符字面值、宽字符字面值、字符串字面值、宽字符串字面值

（b）十进制、无符号的十进制、long十进制、无符号long十进制、8进制、16进制。

（c）double、float、long double

（d）10进制、无符号10进制、double、double。

###练习2.6：下面两组定义是否有区别，如果有，请叙述之：
>int month = 9, day = 7;
>int month = 09, day = 07;

第一行： 十进制；

第二行：
 09是错误的，八进制 0-7，
 07是八进制。

###练习2.7：下述字面值表示何种含义？它们各自的数据类型是什么？
>(a)"Who goes with F\145rguuus?\012"
>(b)3.14e1l
>(c)1023f
>(d)3.24L

(a)Who goes with Fergus?(new line);"string"

(b)**31.4;"long double"

(c)1023.0 ;"float"

(d)3.24 ; "long double"


-	[ASCII Table](http://www.asciitable.com/)

###练习2.8：请利用转义序列写一段程序，要求线输出2M，然后转到新一行。修改程序，使其先输出2，然后输出制表符，再输出M，最后转到新一行。
```cpp

 #include <iostream>

using namespace std;

int main()
{

	cout << "2M\n" << endl;
	cout << "\062\115\012" << endl;
	cout << "\062\t\115\012" << endl;	
	return 0;
}
```

输出：
![out](\screenshots\ch02\ex_2_8.png)

##2.2 变量
------
##Exercise 2.2.1
###练习2.9：解释下列定义的含义。对于非法的定义，请说明错在何处并将其改正。
>(a)`std::cin >> int input_value;`
>(b)`int i = { 3.14 };`
>(c)`double salary = wage = 9999.99;`
>(d)`int i = 3.14;`

(a)不合法，出现错误 `error: expected '(' for function-style cast or type construction.
error: expected primary-expression before 'int'
  cin >> int input_value;`
```cpp
int input_value;
std::cin >> input_value;
```
(b)不合法，出现错误 `error: type 'double' cannot be narrowed to 'int' in initializer list.`

```cpp
double i = { 3.14 };
```
非法定义，列表初始化时，初始值存在信息丢失，将出错,但编译通过了，g++ ex_2_9.cpp，什么情况?

(c)不合法，出现错误 `error: ‘wage’ was not declared in this scope`
  double salary = wage = 9999.99;
```cpp
double wage;
double salary = wage = 9999.99;
```
(d)合法，但存在信息丢失
```cpp
double i = 3.14;
```

###练习2.10：下列变量的初值分别是什么？
```cpp
std::string global_str;
int global_int;
int main()
{
	int local_int;
	std::string local_str;
	return 0;
}
```
`

global_str: 这是全局变量，初始值为空字符串；

global_int: 这是全局变量，初始值为0；

local_int: 本地变量，没初始化，未定义的值；

local_str: 本地变量，虽然没初始化，但是在class里面定义了，初始值为空字符串。

`
**提示：**
未初始化的变量含一个不确定的值，使用未初始化的变量的值是一种错误的编程行为，而且出现错误时很难调试。带来无法预计的后果。建议初始化每一个内置类型的变量。

##2.2.2 变量声明和定义的关系
------
##Exercise 2.2.2
###练习2.11：指出下面的语句是声明还是定义：

>(a)extern int ix = 1023;
>(b)int iy;
>(c)extern int iz;

(a) 定义(definition)
(b) 定义(definition)
(c) 声明(declaration)

##2.2.3 标识符
------
##Exercise 2.2.3
###练习2.12：指出下面的名字中哪些是非法的：
>(a)int double = 3.14;
>(b)int _;
>(c)int catch-22;
>(d)int 1_or_2 = 1;
>(e)double Double = 3.14;

`a`、`c`、`d`是非法的。

##2.2.4 名字的作用域
------
###note:
名字的有效区域始于名字的声明语句，以声明语句所在的作用域末端为结束。
一般来说，在对象第一次被使用的地方附近定义它是一种好的选择。

**eg.**
```cpp
#include <iostream>
//该程序用于说明：函数内部不宜定义与全局变量同名的新变量
int reused = 42;	// resued拥有全局作用域
int main()
{
	int unique = 0;	//unique拥有块作用域
	//输出#1：使用全局变量 reused；输出 42 0
	std::cout << reused << " " << unique << std::endl;

	int reused = 0;	//新建局部变量reused，覆盖了全局的reused
	//输出#2：使用局部变量reused；输出0 0
	std::cout << reused << " " << unique << std::endl;

	//输出#3：显式地访问全局变量reused；输出42 0
	std::cout << ::reused << " " << unique << std::endl;

	return 0;
}
```
**输出**
![out](\screenshots\ch02\eg._2_24_name_scope.png)

**note:**
如果函数有可能用到某全局变量，则不宜再定义一个同名的局部变量

##Exercise2.2.4
###2.13：下面程序中j的值是多少？
```cpp
int i = 42;
int main()
{
	int i = 100;
	int j = i;
}
```

	j = 100;

###2.14：下面的程序合法吗？如果合法，它将输出什么？
```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
{
	sum += i;
}
std::cout << i << " " << sum << std::endl;

```

	100 55


##2.3复合类型
复合类型是指基于其他类型定义的类型
### 引用

引用（reference）为对象起了另外一个名字，引用类型另外一种类型。通常将声明符写成&d的形式来定义引用类型，其中d是声明的变量名：
int ival = 1024;
int &refVal = ival;	//refVal指向ival(是ival的另一个名字)
int &refVal2;		//错误 绑定，无法再绑定到其他，所以必须初始化
引用即别名

引用类型必须初始化
引用类型的初始值必须是一个对象
引用类型的初始值对象一致
------
##Exercise 2.3.1
###练习2.15：下面哪个定义是不合法的？为什么？
(a) int ival = 1.01 (b) int &rval1 = 1.01;
(c) int &rval2 = ival; (d) int &rval3;

(a) 合法
(b) 不合法，引用类型的初始值必须是一个对象
(c) 合法
(d) 不合法，引用类型必须初始化

###练习2.16： 考察下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？他们执行了什么样的操作？
int i = 0, &r1 = i;	double d = 0, &r2 = d;

(a) r2 = 3.14159;	(b)r2 = r1;
(c) i = r2;	(d) r1 = d;

(a) 合法，给d赋值为3.14159
(b) 合法，数据丢失
(c) 合法，
(d) 

###练习2.17：














