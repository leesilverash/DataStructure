// Customer.h   하나의 고객 정보를 관리하기 위한 클래스
struct Customer
{
    int id;
    int tArrival;
    int tService;
    Customer(int i = 0, int tArr = 0, int tServ = 0)
        : id(i), tArrival(tArr), tService(tServ) {}
};