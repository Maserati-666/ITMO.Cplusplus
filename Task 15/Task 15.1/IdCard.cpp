
#include "IdCard.h"
//#include "student.h"

	IdCard::IdCard(int n)
	 {
        number = n;
		category = "Не установлена";
	 }
	IdCard::IdCard()
	 {
        number = 0;
		category = "Не установлена";
	 }
	IdCard::IdCard(int n, string cat)
	 {
        number = n;
		category = cat;
	 }

    void IdCard::setNumber(int newNumber)
	{
        number = newNumber;
    }
    
	int IdCard::getNumber()
	{
        return number;
    }


	void IdCard::setCategory(string cat)
	{
		category = cat;
	}

	string IdCard::getCategory()
	{
		return category;
	}

  //   void setDateExpire(Date newDateExpire)
	 //{
  //      dateExpire = newDateExpire;
	 //}
  //   Date getDateExpire()
	 //{
  //      return dateExpire;
	 //}
