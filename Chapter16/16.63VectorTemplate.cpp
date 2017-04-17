#include</home/ysing/codeblock Projects/CPP_prime/Chapter16/16.63VectorTemplate.h>


using namespace std;

int main(){
    vector<int> vec = {1,2,3,4,1,2,3};
    cout<<vectorCount(vec,1)<<endl;
    vector<const char *> vec2 = {"123","123","456"};
    const char * tem = "123";
    cout<<vectorCount(vec2,tem);///好像tmp改成字符串常量也是生效的，可以相互转换？
    return 0;
}
