#include <QCoreApplication>
#include <iostream>
#include <iterator>
#include <fstream>
using namespace std;

//使用流迭代器读取文本
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<string> vec;

    QString path = a.applicationDirPath();
    QString fileName=path+"\\test.txt";
    QByteArray arr;
    arr.append(fileName);

    ifstream in(arr.data());
    if(!in.is_open())
        cout<<"file open failed"<<endl;

    istream_iterator<string> int_it(in),eof;
    while (int_it != eof) {
        vec.push_back(*int_it);
        int_it++;
    }

    list<int>lst={1,2,3,4,5,6,7,8,9};
    auto it=lst.begin();
    while (it!=lst.end()) {
        if(*it%2)
            it=lst.erase(it);
        else
            it++;
    }

    //数组指针的使用
    int (*p1)[10]=func(5);
    cout<<(*p1)[1]<<endl;

    int c[4] = {1,2,3,4};
    int (*b)[4];
    b = &c;
    cout << (*b)[2] << endl;
    int a1[sizeof (c)/sizeof (int)];
    auto ret=copy(begin(c),end(c),begin(a1));
    sort(begin(c),end(c));
    sort(begin(c),end(c),DescendOrder);
    sort(begin(c),end(c),[](const int &a,const int &b)->
         bool {return a>b;});

    //bind函数
    sort(begin(c),end(c),bind(DescendOrder,_1,_2));

    list<int> list1,list2;
    copy(begin(c),end(c),front_inserter(list1));
    copy(begin(c),end(c),inserter(list2,begin(list2)));


    return a.exec();
}
