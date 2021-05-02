class Account{
public :
    static double m_rate;
    static void set_rate(const double & x){m_rate=x;}

};
double Account::m_rate=0.8;
int main(){
    Account::set_rate(0.5);
    Account a;
    a.set_rate(7.0);
}
