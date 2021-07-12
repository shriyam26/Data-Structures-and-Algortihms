#include<iostream>
using namespace std;

class cashRegister{
private:
    int cashInHand;
public:
    int getCurrentBalance() const{
        return cashInHand;
    }
    void acceptAmount(int amountIn){
        cashInHand += amountIn;
    }
    cashRegister(int cashIn = 500){
        if(cashIn > 0)
            cashInHand = cashIn;
        else
            cashInHand = 500;
    }
};

class dispenserType{
private:
    int noOfItems;
    int cost;
public:
    int getNoOfItems() const{
        return noOfItems;
    }
    int getCost() const{
        return cost;
    }
    void makeSale(){
        noOfItems--;
    }
    dispenserType(int setNoOfItems = 50, int setCost = 50){
        if(setNoOfItems > 0)
            noOfItems = setNoOfItems;
        else
            noOfItems = 50;
        if(setCost > 0)
            cost = setCost;
        else
            cost = 50;
    }
};

void showSelection()
{
	cout<<"***Welcome to diyhoo's candy shop***"<<endl;
	cout<<"To select an item,enter"<<endl;
	cout<<"1 for candy"<<endl;
	cout<<"2 for chips"<<endl;
	cout<<"3 for gum"<<endl;
	cout<<"4 for cookies"<<endl;
	cout<<"9 for exit"<<endl;
}

void sellProduct(dispenserType &product, cashRegister &pCounter){
    if(product.getNoOfItems() > 0){
        int amount1;
        cout << "Please deposit " << product.getCost() << " " << endl;
        cin >> amount1;
        if(amount1 < product.getCost()){
            cout << "Please deposit more " << product.getCost() - amount1 << endl;
            cin >> amount2;
            amount1 += amount2;
        }
        if(amount1 >= product.getCost()){
            cout << "Please collect change " << amount1 - product.getCost() << endl;
            pCounter.acceptAmount(amount1);
            product.makeSale();
            cout << "Enjoy your item" << endl;
        }
        else {
            cout << "Insufficient balance. Please retry." << endl;
        }
    }
    else{
        cout << "Insufficient no of items present in the machine"
    }
}

int main(){
    cashRegister counter;
    dispenserType candy(100,50);
	dispenserType chips(100,65);
	dispenserType gum(75,45);
	dispenserType cookies(100,85);
	showSelection();
	cin>>choice;
	while(choice!=9)
	{
		switch(choice)
		{
		case 1:sellProduct(candy,counter);
			break;
		case 2:sellProduct(chips,counter);
			break;
		case 3:sellProduct(gum,counter);
			break;
		case 4:sellProduct(cookies,counter);
			break;
		default:cout<<"Invaild selection."<<endl;
		}
	showSelection();
	cin>>choice;
	}

}