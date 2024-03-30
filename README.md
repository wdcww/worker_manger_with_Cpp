# [指针数组]、[多态]的使用案例

*all_class.h中声明了所有的类*

*all_class.cpp中实现类的定义*

*worker_class_main.cpp是主函数所在的.cpp*

*all_class.cpp 和 worker_class_main.cpp需要一起编译，它们均 #include"all_class.h"*

---

## 1. menu类的逻辑

```c++
class menu
{
 public:
   menu();
   ~menu();
   void find();
   void change();
   void add();
   void del();
   void load();
   void save();
   void sort();
   
   int m_Empnum; 
   Worker* * m_EmpArrary; 
};
```

### 程序中的操作函数都是menu类的成员函数。

### menu类使用int型成员变量m_Empnum记录此时内存中的人员个数。

### 同时，menu类利用 Worker**型的m_EmpArrary，实现了一个可以存放 Worker* 的数组，用以维护和存放new的新员工返回来的地址。

```c++
Worker* *p = new Worker*[newsize];
Worker* worker;
...
for(i=0;i<newsize;i++)
{p[i] = worker;} // 假设每次的worker已经指向了某个职工子类

this->m_EmpArrary = p;  //更新menu类的成员变量m_EmpArrary
```

### 如下图：

![](/example.png)

---

## 2. Worker类及其子类

### Worker类是职工抽象基类，其子类有Employee类、Manger类和Boss类。

### 三个子类均公有继承Worker类，有自己的有参构造，且都重写了Worker类中的虚函数。

### 以下给出Worker父类和一个子类Boss类
```c++
class Worker //职工基类
{
   public:
      virtual void showinfo()=0; //显示个人信息的 纯虚 函数
      virtual string getdeptname() = 0; //获取岗位的string型的名称,在showinfo()中被调用
      int m_id; //职工编号
      string m_name; //职工姓名
      int m_deptid;  //职工所在部门的岗位编号
};

... ... //另外两个子类不做展示

// 继承Worker基类的Boss类
class Boss : public Worker
{
public:
   Boss(int id,string name,int deptid);
   void showinfo(); 
   string getdeptname();
};

Boss::Boss(int id,string name,int deptid)
{
   this->m_id=id;
   this->m_name=name;
   this->m_deptid=deptid;
}
void Boss::showinfo()
{
   cout<<"职工编号 "<<this->m_id
       <<"\t姓名"<<this->m_name
       <<"\t岗位"<<this->getdeptname()<<endl;
}
string Boss::getdeptname()
{
    return string("(2)老板");
}
```

---

## 3. 多态

### 满足 “子类都重写了父类的虚函数” 这一条件，

### 并且menu类所维护的数组在存放时触发 “父类的指针指向子类的对象” （用Worker*接受一个new的子类对象的指针）

### 因此，发生了多态，即调用虚函数时，会根据实际对象的类型调用相应的重写的虚函数。

#### 3.1

**例如：下面的this->m_EmpArrary[i]就是一个指向某个子类的指针，调用showinfo()时，会输出对应的该子类的信息**

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

#### 3.2

**还可以再去定义一个公共的接口，以使用多态。**

**例如：一个接受Worker*的函数doshow()，调用 doshow( this->m_EmpArrary[i] ) 时，会根据实际对象的类型调用相应的重写的虚函数。**

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

## 4. 其他细节日后有所思时，回来更新


goodbye!
