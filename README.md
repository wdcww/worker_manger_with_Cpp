# 随记

## 1. class menu

### 管理程序中的操作函数都是menu类的成员函数。

### menu类使用int型成员变量m_Empnum记录此时内存中的人员个数。

### 同时，menu类通Worker**型的成员变量m_EmpArrary，实现了一个可以存放 Worker* 的数组，用以维护和存放开辟的新员工返回来的地址。

```c++
Worker* *p = new Worker*[newsize];
Worker* worker;

for(i=0;i<newsize;i++)
{p[i] = worker;} // 假如每次的worker已经指向了某个职工子类

this->m_EmpArrary = p;  //更新menu类的成员变量m_EmpArrary
```

### 如下图：

![](/example.png)

## 2. class Worker

### Worker类是职工抽象基类，其子类有Employee类、Manger类和Boss类。

### 三个子类均公有继承Worker类，重写了Worker类中的虚函数。
---

**虽然，三个子类都重写了父类的虚函数，并且menu类所维护的数组在存放时也是“父类的指针指向子类的对象”（用Worker*接受一个new的子类对象的指针），**

**但是，程序里并没有使用多态，既没有写一个公共的接口，接受子类对象，输出各自对应的行为。**

**程序里是让子类自己去调用自己的成员函数**

**例如：下面的this->m_EmpArrary[i]就是一个指向某个子类的指针,再使用这个指针去调用该子类的成员函数**

```c++
void menu::find() 
{ //查询此时内存中的数据
    int i;
  cout<<"内存中有"<<this->m_Empnum<<"个人"<<endl;
  for(i=0;i<this->m_Empnum;i++)
    {  
       this->m_EmpArrary[i]->showinfo();
    }
```
**程序的其他地方也是如此**

---

**就对于上面的例子，使用多态的话，可以再去定义一个接受Worker*的函数doshow()，调用 doshow( this->m_EmpArrary[i] ) 时，会根据实际对象的类型调用相应的重写的虚函数。**

```c++
void doshow(Worker* p)
{
   p->showinfo();  
}

void menu::find() 
{ //查询此时内存中的数据
    int i;
  cout<<"内存中有"<<this->m_Empnum<<"个人"<<endl;
  for(i=0;i<this->m_Empnum;i++)
    {  
      doshow( this->m_EmpArrary[i] ); //使用多态
    }
```
---

## 3. 其他细节：日后有所思时，回来更新
