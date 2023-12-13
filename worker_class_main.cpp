#include<iostream>
using namespace std;

#include"all_class.h"
//已经在tasks.json里面改过了,当前文件和all_class.cpp一起编译

void showUI()
{ 
    cout<<"|___________欢迎使用______________|"<<endl;
    cout<<"|****1查询***********2修改********|"<<endl;
    cout<<"|****3添加***********4删除********|"<<endl;
    cout<<"|****5读取文件*******6写入文件****|"<<endl;
    cout<<"|****7排序***********8？？********|"<<endl;
    cout<<"|___________输0退出_______________|"<<endl;
    cout<<endl;
    cout<<"此程序,用于处理 程序在运行时的数据 ,"<<endl;
    cout<<"数据可源于文件,操作后的数据可写入文件"<<endl;
    cout<<endl;
    cout<<endl;
}

void test()
{
   menu m;

      while(true)
    { 
      
      cout<<endl;

      showUI();  //展示UI界面

      int a;
      cout<<"请输入你的数字选择";
      cin>>a;
      cout<<"你选择了功能（"<<a<<")"<<endl;

                switch(a)
                {
                    case 1:{//查
                    cout<<endl;
                    m.find();
                    cout<<endl;
                    system("pause");
                    } break;

                    case 2:{//改
                    cout<<endl;
                    m.change();
                    cout<<endl;
                    system("pause");
                    } break;

                    case 3:{//添加
                    cout<<endl;
                    m.add();
                    // system("pause");
                    // system("cls");
                    } break;
                    
                    case 4:{//删
                    cout<<endl;
                    m.del();
                    // system("pause");
                    // system("cls");
                    } break;
                    
                    case 5:{//读文件
                    cout<<endl;
                    m.load();
                    // system("pause");
                    // system("cls");
                    } break;
                    
                    case 6:{//写入文件
                    cout<<endl;
                    m.save();
                    // system("pause");
                    // system("cls");
                    } break;
                    
                    case 7:{//排序
                    cout<<endl;
                    m.sort();
                    // system("pause");
                    // system("cls");
                    } break;

                    case 8:{//排序
                    cout<<endl;
                    cout<<"功能暂未开放..."<<endl;
                    system("pause");
                    // system("cls");
                    } break;

                    default:break;
                }
      
      system("pause");
      system("cls");

      if(!a)
        break;
    }

    system("pause");
    cout<<endl;

}


int main()
{
    test();
    //从这里出来应该~menu()


    system("pause");
    return 0;
}


