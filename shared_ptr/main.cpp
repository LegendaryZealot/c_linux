#include <iostream>
using namespace std;

class CConnnect
{
public:
    void Disconnect() { 
        cout<<"Disconnect"<<endl;
    }
    ~CConnnect(){
        cout<<"~CConnnect"<<endl;
    }
};

void Deleter(CConnnect* obj)
{
    obj->Disconnect(); // 做其它释放或断开连接等工作
    delete obj; // 删除对象指针
}

int main(int argc,char *argv[]){
    shared_ptr<CConnnect> sps_1(new CConnnect);
    // shared_ptr<CConnnect> sps_1(new CConnnect, Deleter);//自定义删除
    shared_ptr<CConnnect> sps_2(sps_1);
    std::cout << "sps_1 Reference count = " << sps_1.use_count() << std::endl;
	std::cout << "sps_2 Reference count = " << sps_2.use_count() << std::endl;
    weak_ptr<CConnnect> wps_q(sps_1);
    std::cout << "sps_1 Reference count = " << sps_1.use_count() << std::endl;
	std::cout << "sps_2 Reference count = " << sps_2.use_count() << std::endl;
    sps_1.reset();
    std::cout << "sps_1 Reference count = " << sps_1.use_count() << std::endl;
	std::cout << "sps_2 Reference count = " << sps_2.use_count() << std::endl;
    sps_2.reset();
    std::cout << "sps_1 Reference count = " << sps_1.use_count() << std::endl;
	std::cout << "sps_2 Reference count = " << sps_2.use_count() << std::endl;
    return 0;
}