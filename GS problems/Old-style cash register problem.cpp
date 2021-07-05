#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
 
// Driver program
int main()
{
    vector<string> products = {"eggs", "milk", "cheese"};
    vector<float> productPrices = {2.89, 3.29, 5.79};
    vector<string> productSold = {"eggs", "eggs", "cheese", "milk"}; 
    vector<float> soldPrice = {2.89, 2.99, 5.97, 3.29};
    map<string, float> sales; //holds the item and values(better this than searching arrays each time)
    int count = 0; //the count of inconsistencies
    for(int i=0; i<products.size(); i++){
        sales[products[i]] = productPrices[i];
    }
    for(int j=0; j<productSold.size(); j++){
        if(sales[productSold[j]] != soldPrice[j]){
            count++;
        }
    }
    cout << "No of errors = " << count;
    return 0;
}