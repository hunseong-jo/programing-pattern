#include <iostream>

using namespace std;

class MobilePhone
{
public:
	MobilePhone()
	{
		cout << "MobilePhone을 생성합니다" << endl;
	}

	~MobilePhone()
	{
		cout << "MobilePhone을 소멸시킵니다" << endl;
	}

	void TurnOn()
	{
		cout << "MobilePhone을 켭니다" << endl;
	}

	void TurnOff()
	{
		cout << "MobilePhone을 끕니다" << endl;
	}
};

class IPhone : public MobilePhone
{
public :
	IPhone()
	{
		cout << "IPhone 을 생성합니다" << endl;
	}

	~IPhone()
	{
		cout << "IPhone 을 소멸시킵니다" << endl;
	}

	void Siri()
	{
		cout << "종강시켜달라고" << endl;
	}

	void ApplePay()
	{
		cout << "10000원 내놔" << endl;
	}
};

class Galaxy : public MobilePhone
{
public :
	Galaxy()
	{
		cout << "Galaxy 을 생성합니다" << endl;
	}

	~Galaxy()
	{
		cout << "Galaxy 을 소멸시킵니다" << endl;
	}

	void Bixby()
	{
		cout << "교수님 : 아이고 종강이야~~" << endl;
	}

	void SamsungPay()
	{
		cout << "장학금 전액 면제 개꿀" << endl;
	}
};



	void main()
	{
		cout << "MobilePhone 에 대한 예제입니다" << endl;


		IPhone *i = new IPhone();
		Galaxy g;

		i->Siri();
		g.Bixby();

		delete(i);
		
	}
