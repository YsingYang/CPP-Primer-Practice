#include<iostream>
using namespace std;
int i=1;
class MyCls{
public:
    MyCls():m_nFor(m_nThd),m_nSec(i++),m_nFir(i++),m_nThd(i++){
        cout<<m_nThd<<endl;
        cout<<m_nFor<<endl;//m_nFor是Thd的引用。随着Thd的改变而改变
        m_nThd=i;
        cout<<m_nFor<<endl;
        cout<<m_nThd<<endl;
    }
    void echo(){
        cout<<"result:"<<m_nFir+m_nSec+m_nThd+m_nFor<<endl;
    }
private:
    int m_nFir;
    int m_nSec;
    int m_nThd;
    int &m_nFor;
};
int main()
{
    MyCls oCls;
    oCls.echo();
    return 0;
}
