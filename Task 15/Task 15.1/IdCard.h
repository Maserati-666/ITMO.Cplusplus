#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>
//#include <time.h>
using namespace std;

 class IdCard
 {
 private:
	 //Date dateExpire;
     int number;
	 string category;
 public:
	 IdCard();
	 IdCard(int);
	 IdCard(int, string);

    void setNumber(int newNumber);
	int getNumber();
	void setCategory(string cat);
	string getCategory();


  //   void setDateExpire(Date newDateExpire)
	 //{
  //      dateExpire = newDateExpire;
	 //}
  //   Date getDateExpire()
	 //{
  //      return dateExpire;
	 //}
};