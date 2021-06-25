#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
istream &get_data(istream &is){
    int v;
    while (is>>v,!is.eof())
    {
        if(is.bad()){ throw runtime_error("IO流错误");}
        if(is.fail()){
            cerr<<"数据错误，请重试："<<endl;
            is.clear();
            is.ignore(100,'\n');
            continue;
        }
        cout<<v<<endl;
    }
    is.clear();
    return is;
    
}

// int main(){
//     cout<<"请输入一些整数,按Ctrl+z 结束"<<endl;
//     get_data(cin);
//     return 0;
// }
int main(){
    fstream in("/root/cppstudy/cppPrimer/data.txt");
    if(!in.is_open()){
        cerr<<"无法打开输入文件"<<endl;
        return -1;
    }
    string line;
    vector<string> words;
    while (getline(in,line))
    {
        words.push_back(line);
    }
    in.close();
    vector<string>::const_iterator it=words.begin();
    while (it!=words.end())
    {
        cout<<*it<<endl;
        ++it;
    }
    return 0;
    
}