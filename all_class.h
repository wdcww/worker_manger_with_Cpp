#include<string>




class Worker //职工基类
{
   public:
      virtual void showinfo()=0; //显示个人信息的 纯虚 函数
      
      virtual string getdeptname() = 0; //获取岗位的string型的名称

      int m_id; //职工编号
      string m_name; //职工姓名
      int m_deptid;  //职工所在部门的岗位编号
};



// 继承Worker基类 的 普通员工类////////////////////////////////////////////////
class Employee : public Worker
{
public:
   Employee(int id,string name,int deptid);
   virtual void showinfo(); 
   virtual string getdeptname();
};


// 继承Worker基类 的 经理类////////////////////////////////////////////////
class Manger : public Worker
{
public:
   Manger(int id,string name,int deptid);
   virtual void showinfo(); 
   virtual string getdeptname();
};


// 继承Worker基类 的 老板类////////////////////////////////////////////////
class Boss : public Worker
{
public:
   Boss(int id,string name,int deptid);
   virtual void showinfo(); 
   virtual string getdeptname();
};




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
   
   int m_Empnum; //记录内存中的人数个数

   Worker* * m_EmpArrary;  


};




