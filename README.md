# 随记

### 管理程序中的操作函数都是menu类的成员函数。

### menu类使用int型成员变量m_Empnum记录此时内存中的人员个数。

### 同时，menu类使用一个可以存放 Worker* 的数组，用以维护和存放开辟的新员工返回来的地址。

### 如下图：

![](/example.png)

### Worker类是职工抽象基类，其子类有Employee类、Manger类和Boss类。

### 三个子类均公有继承Worker类，重写了Worker类中的虚函数。
