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

    return a.exec();
}
