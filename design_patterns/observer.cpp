/*
+-------------------------+         +------------------------+
|        ISubjectYT       |         |        IObserver       |
+-------------------------+         +------------------------+
| + Attach(Observer*)     |         |                        |
| + Detach(Observer*)     |         | + Update()             |
| + Notify()              |         +------------------------+
+-------------------------+                 ^
          ^                               / \
          |                              /   \
+------------------+                 /     \
| ConcreteSubject  |                /       \
+------------------+               /         \
| + GetState()      |              /           \
| + SetState()      |             /             \
+------------------+            /               \
                                 /                 \
                                /                   \
                       +----------------+      +----------------+
                       | ConcreteObserver|      | ConcreteObserver|
                       +----------------+      +----------------+
                       |                |      |                |
                       +----------------+      +----------------+
                       | + Update()     |      | + Update()     |
                       +----------------+      +----------------+

*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class IObserver{
public:
	virtual ~IObserver(){};
	virtual void update(string &msg) = 0;
};
class ISubjectYT{
public:
	virtual ~ISubjectYT(){}
	virtual void subscribe(IObserver *obs) = 0;
	virtual void unsubscribe(IObserver *obs) = 0;
	virtual void notify() = 0;
	//virtual void sendMsg(std::string message) = 0;
};

class TanmayBhatt : public ISubjectYT{
private:
	std::list<IObserver*> subs_list;
	std::string _msg;
public:
	TanmayBhatt(){cout << "TanmayBhatt()"<<endl;}
	void subscribe(IObserver* obj){
		subs_list.push_back(obj);
	}
	void unsubscribe(IObserver* obj){
		subs_list.remove(obj);
	}
	void notify()
	{
		auto itr = subs_list.begin();
		while(itr!=subs_list.end())
		{
			(*itr)->update(_msg);
			itr++;
		}
	}
	void CreateMsg(string msg="Empty")
	{
		this->_msg = msg;
		notify();
	}
	void howManySubs()
	{
		cout <<"TanmayBhatt subscribers :" << subs_list.size() << endl;
	}
	virtual ~TanmayBhatt(){cout << "Good buy. I was TanmayBhatt YT channel \n";}
};
class PiyusgGoyal : public ISubjectYT{
private:
	std::list<IObserver*> subs_list;
	std::string _msg;
public:
	PiyusgGoyal(){cout << "PiyusgGoyal()"<<endl;}
	void subscribe(IObserver* obj){
		subs_list.push_back(obj);
	}
	void unsubscribe(IObserver* obj){
		subs_list.remove(obj);
	}
	void notify()
	{
		auto itr = subs_list.begin();
		while(itr!=subs_list.end())
		{
			(*itr)->update(_msg);
			itr++;
		}
	}
	void CreateMsg(string msg="Empty")
	{
		this->_msg = msg;
		notify();
	}
	void howManySubs()
	{
		cout <<"PiyusgGoyal subscribers :" << subs_list.size() << endl;
	}
	virtual ~PiyusgGoyal(){cout << "Good bye. I was PiyusgGoyal YT channel\n";}
};
class observerPrakash : public IObserver{
private:
	//TanmayBhatt &subTb;
	ISubjectYT &subTb;
	string msg_from_sub;
	static int static_number;
	int number;
	
public:
	observerPrakash(ISubjectYT& sub):subTb(sub){
		this->subTb.subscribe(this);
		cout << "Hi I am the ObserverPrakash : "<< ++observerPrakash::static_number<<endl;
		this->number = observerPrakash::static_number;
	}
	virtual void update(string &msg){
		this->msg_from_sub = msg;
		printMsg();
	}
	void RemoveFromList()
	{
		subTb.unsubscribe(this);
		cout << " observerPrakash : " << this->number <<" removed from list "<<endl;
	}
	void printMsg()
	{
		cout<<"observerPrakash : "<< number << " a nev msg is available : " << this->msg_from_sub<<endl;
	}
	virtual ~observerPrakash(){
		cout << "Good bye, I was observerPrakash : " << this->number<<endl;
	}
};

class observerHimani : public IObserver{
    private:
	//TanmayBhatt &subTb;
	ISubjectYT &subTb;
	string msg_from_sub;
	static int static_number;
	int number;
	
public:
	observerHimani(ISubjectYT& sub):subTb(sub){
		this->subTb.subscribe(this);
		cout << "Hi I am the observerHimani : "<< ++observerHimani::static_number<<endl;
		this->number = observerHimani::static_number;
	}
	virtual void update(string &msg){
		this->msg_from_sub = msg;
		printMsg();
	}
	void RemoveFromList()
	{
		subTb.unsubscribe(this);
		cout << " observerHimani : " << this->number <<" removed from list "<<endl;
	}
	void printMsg()
	{
		cout<<"observerHimani : "<< number << " a nev msg is available : " << this->msg_from_sub<<endl;
	}
	virtual ~observerHimani(){
		cout << "Good bye, I was observerHimani : " << this->number<<endl;
	}
};
int observerPrakash::static_number = 0;
int observerHimani::static_number = 0;
int main()
{
	TanmayBhatt *subTB = new TanmayBhatt();
    
    observerPrakash *ob1 = new observerPrakash(*subTB);
    observerPrakash *ob2 = new observerPrakash(*subTB);
    
    observerHimani *obH1 = new observerHimani(*subTB);
    subTB->CreateMsg("new video is coming up");
    subTB->howManySubs();
    ob1->RemoveFromList();
    PiyusgGoyal *pg = new PiyusgGoyal();
    observerPrakash *ob3 = new observerPrakash(*pg);
    pg->howManySubs();
    
    delete ob1;
    delete ob2;
    
    /*
    Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject);
  Observer *observer2 = new Observer(*subject);
  Observer *observer3 = new Observer(*subject);
  Observer *observer4;
  Observer *observer5;

  subject->CreateMessage("Hello World! :D");
  observer3->RemoveMeFromTheList();

  subject->CreateMessage("The weather is hot today! :p");
  observer4 = new Observer(*subject);

  observer2->RemoveMeFromTheList();
  observer5 = new Observer(*subject);

  subject->CreateMessage("My new car is great! ;)");
  observer5->RemoveMeFromTheList();

  observer4->RemoveMeFromTheList();
  observer1->RemoveMeFromTheList();

  delete observer5;
  delete observer4;
  delete observer3;
  delete observer2;
  delete observer1;
  delete subject;
    */

    return 0;
}
