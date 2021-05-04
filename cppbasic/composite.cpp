#include<vector>
using namespace std;
class  component{
private:
    int value;
public:
    component(int val){
        value=val;
    }
    virtual void add(component* com){};
};

class primitive:public component{
public :
    primitive (int val):component(val){ }
};

class composite:public component{
private:
vector<component*> coms;
public :
    virtual void add(component *com){
        coms.push_back(com);
    }
};