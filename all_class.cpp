#include<iostream>
#include<fstream>
using namespace std;

#include"all_class.h" // all_class.h 中只有声明

menu::menu() //menu 类的构造函数
{
    cout<<"构造"<<endl;
     
    //初始化人数
    this->m_Empnum=0;
    //初始化数组指针
    this->m_EmpArrary=NULL;

}
menu::~menu() //menu 类的析构函数
{
    if(this->m_EmpArrary!=NULL)
    {
       cout<<"~menu"<<endl;
       for(int i=0;i<this->m_Empnum;i++)
         delete this->m_EmpArrary[i];
       
       delete[] this->m_EmpArrary;
    }
}
void menu::find() 
{ //查
    int i;
  cout<<"内存中有"<<this->m_Empnum<<"个人"<<endl;
  for(i=0;i<this->m_Empnum;i++)
    {  
       this->m_EmpArrary[i]->showinfo();
    }


}
void menu::change() 
{ //改
  cout<<"请输入你要修改职工的编号";
  int id;
  cin>>id;

  int index=-1;

  for(int i=0;i<this->m_Empnum;i++)
  {
     if(this->m_EmpArrary[i]->m_id==id)
     {
          index = i;
          break;//跳出for循环
     }
  }
 
  if(index==-1)
   {cout<<"查无此人"<<endl; return;}

   cout<<"编号"<<index+1<<"目前的信息:";
   cout<<this->m_EmpArrary[index]->m_name<<" "<<this->m_EmpArrary[index]->getdeptname()<<endl;
   
   delete this->m_EmpArrary[index];//释放掉旧的

   cout<<"输入新的名字:"; string name; cin>>name;
   cout<<"输入新的岗位编号:"; int deptid; cin>>deptid;
   
   Worker* worker=NULL;
   switch(deptid){
                         case 0:worker=new Employee(id,name,0);break;
                         case 1:worker=new Manger(id,name,1);break;
                         case 2:worker=new Boss(id,name,2);break;
                       }
   
   this->m_EmpArrary[index]=worker;

   cout<<"修改后的信息如下"<<endl;
   this->m_EmpArrary[index]->showinfo();

}
void menu::add() 
{ //添
  cout<<"请输入添加的人数:"<<endl;

  int addnum;

  cin>>addnum;
  if(addnum>0)
    {
      int newsize = this->m_Empnum + addnum; 

      Worker* *p = new Worker*[newsize];
      
      if(this->m_EmpArrary!=NULL)
       { //执行此for循环时,说明原来有东西
         for(int i=0;i<this->m_Empnum;i++)
           { p[i] = this->m_EmpArrary[i]; }
       }
      
      for(int i=0;i<addnum;i++)
      { 
         int id; //职工编号
         string name; //职工姓名
         int deptid;  //职工所在部门的岗位编号

         cout<<"请输入第"<<i+1<<"个人的信息"<<endl;
         cout<<"职工编号 姓名 岗位编号"<<endl;
         cin>>id; cin>>name; cin>>deptid;
         
         Worker* worker=NULL;

         switch(deptid){
                         case 0:worker=new Employee(id,name,0);break;
                         case 1:worker=new Manger(id,name,1);break;
                         case 2:worker=new Boss(id,name,2);break;
                       }

         p[this->m_Empnum + i] = worker;
      }
      
      //经过上面的for,都添加完了
      delete[] this->m_EmpArrary;
      this->m_EmpArrary=p;
      this->m_Empnum=newsize;
    }
    else
    {
        cout<<"cin>>addnum有误"<<endl;

    }
     
    return;
}
void menu::del() 
{ //删
  cout<<"输入要删的职工的编号";
  int del_id;
  cin>>del_id;

  int index=-1;

  for(int i=0;i<this->m_Empnum;i++)
  {
     if(this->m_EmpArrary[i]->m_id==del_id)
     {
          index = i;
          break;//跳出for循环
     }
  }
 
  if(index==-1)
   {cout<<"查无此人"<<endl; return;}



   //数据前移的删除方法
   for(int i=index+1;i<this->m_Empnum;i++)
   {
     this->m_EmpArrary[i-1] = this->m_EmpArrary[i];
   }

    this->m_Empnum--;
}
void menu::load() 
{ //读取文件,这里的实现逻辑和add()类似,也是会把看过的所有的文件里的信息添加到
//内存里面
    string path;  
cout << "你要打开文件路径：";  
cin >> path;  
    cout<<"pppp"<<endl;
    ifstream ifs;
    ifs.open(path,ios::in);
    if(ifs.fail())
    {
       cout<<"文件"<<path<<"不存在"<<endl;
       ifs.close();
       return;
    }

    char ch;
    ifs>>ch; //先读文件的一个字符////////////////////////罪魁祸首
    if(ifs.eof())
    {
       cout<<"文件"<<path<<"存在,但是里面的数据为空"<<endl;
       ifs.close();
    }
///////////////////Chat-GPT//////////////////////////////////////    
ifs.clear();            // 清除状态标志
ifs.seekg(0, ios::beg);  // 将文件指针移动到文件的开头
//在读取 ch 后，文件指针已经移动到了文件的第一个字符之后，
// 如果文件是一个文本文件，它通常是第一个有效字符之前的空格、换行符等。
// 在这种情况下，读取第一个字符之后，
// 直接进入 while (ifs >> id >> name >> deptid) 循环，
// 可能会导致第一行的数据被跳过
//////////////////////////////////////////////////////////////////


    int id;    
    string name;
    int deptid;
  
    int num=0;

while(ifs>>id>>name>>deptid) //这里读完文件后,你的文件指针又会换到不对的地方
    num++;
//所以///////////////Chat-GPT//////////////////////////////////////    
ifs.clear();            // 清除状态标志
ifs.seekg(0, ios::beg);  // 将文件指针移动到文件的开头
///////////////////Chat-GPT//////////////////////////////////////

    cout<<"刚刚读取的文件"<<path<<",里面有"<<num<<"个人，";
  
   int newsize = this->m_Empnum + num; 

   cout<<"现在共有"<<newsize<<"个人"<<endl;

   Worker* *p = new Worker*[newsize];


if(this->m_EmpArrary!=NULL)
       { //执行此for循环时,说明原来有东西
         for(int i=0;i<this->m_Empnum;i++)
           { p[i] = this->m_EmpArrary[i]; }
       }

    for(int i=0;i<num;i++)
    {  
       Worker* worker=NULL;
       ifs>>id;
       ifs>>name;
       ifs>>deptid;
       
       if(deptid==0)
          worker = new Employee(id,name,deptid);
        else if(deptid==1)
          worker = new Manger(id,name,deptid);
        else 
          worker = new Boss(id,name,deptid);


        p[this->m_Empnum+i] = worker;
    }

    //经过上面的for,都添加完了
      delete[] this->m_EmpArrary;
      this->m_EmpArrary=p;
      this->m_Empnum = newsize;


     cout<<"读完以后的人："<<endl;
      for(int i=0;i<this->m_Empnum;i++)
    {  
       this->m_EmpArrary[i]->showinfo();
      
    }

}
void menu::save() 
{ //保存文件
  string path;
  cout<<"输入保存路径";
  cin>>path;


  ofstream ofs;
ofs.open(path,ios::out);
  

  for(int i=0;i<this->m_Empnum;i++)
    ofs<<this->m_EmpArrary[i]->m_id<<" "
      <<this->m_EmpArrary[i]->m_name<<" "
       <<this->m_EmpArrary[i]->m_deptid<<endl;

  ofs.close();

}
void menu::sort()
{
  cout<<"此功能是,按照编号从小到大进行排序"<<endl;
  for(int i=0;i<this->m_Empnum-1;i++)
    for(int j=0;j<this->m_Empnum-i-1;j++)
      if(this->m_EmpArrary[j]->m_id > this->m_EmpArrary[j+1]->m_id)
      {
        Worker* p=NULL;
        p=this->m_EmpArrary[j];
        this->m_EmpArrary[j]=this->m_EmpArrary[j+1];
        this->m_EmpArrary[j+1]=p;
      }
    
}



Employee::Employee(int id,string name,int deptid)
{
   this->m_id=id;
   this->m_name=name;
   this->m_deptid=deptid; 
}
void Employee::showinfo()
{
   cout<<"职工编号"<<this->m_id
       <<"\t姓名"<<this->m_name
       <<"\t岗位"<<this->getdeptname()<<endl;

}
string Employee::getdeptname()
{
    return string("(0)员工");
}



Manger::Manger(int id,string name,int deptid)
{
   this->m_id=id;
   this->m_name=name;
   this->m_deptid=deptid;
}
void Manger::showinfo()
{
   cout<<"职工编号 "<<this->m_id
       <<"\t姓名"<<this->m_name
       <<"\t岗位"<<this->getdeptname()<<endl;

}
string Manger::getdeptname()
{
    return string("(1)经理");
}



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


