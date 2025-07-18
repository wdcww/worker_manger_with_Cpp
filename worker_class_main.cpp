#include<iostream>
#include <Windows.h>

using namespace std;

#include"all_class.h" //这个头文件中没有写using namespace std;，所以这行放在这里

void showUI()
{ 
    cout<<"|___________欢迎使用______________|"<<endl;
    cout<<"|****1查询***********2修改********|"<<endl;
    cout<<"|****3添加***********4删除********|"<<endl;
    cout<<"|****5读取文件*******6写入文件****|"<<endl;
    cout<<"|****7排序***********8？？********|"<<endl;
    cout<<"|___________输0退出_______________|"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"此程序,用于处理[程序在运行时的数据],"<<endl;
    cout<<"即程序运行时,查询、修改、添加、删除、排序的操作对象为[此时在内存中的数据]"<<endl;
    cout<<"初始内存中的数据可读取于上次保存的文件"<<endl;
    cout<<"当前操作完成后,可在程序关闭前将内存中的数据保存到文件"<<endl;
    cout<<endl;
    cout<<"PS:读取文件操作,会把数据追加到当前内存数据的末尾,即无法保证相同数据唯一"<<endl;
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
    //强制控制台使用 UTF-8 输出
    SetConsoleOutputCP(CP_UTF8);
    
    test();
    //从这里出来应该~menu()


    system("pause");
    return 0;
}


