#include <iostream>
using namespace std;

class Payment {
    private:
        string CustomerName;
        char ProductType;
        int Units;
    
    public:

        Payment(string customerName, char productType, int units){
            CustomerName = customerName;
            ProductType = productType;
            Units = units;
        };

        float Price(){

            float price = 0;

            if(ProductType == 'X')
                price = 400;
            else if(ProductType == 'Y')
                price = 530;
            else if(ProductType == 'Z')
                price = 390;
            
            return price;
        };

        float SalesValue(){
            return Units * Price();
        };

        float Discount(){

            float d = 0;

            if(ProductType == 'X' || ProductType == 'Z'){
                if(SalesValue() > 15000){
                    d = 0.1 * SalesValue();
                }else {
                    d = 0.05 * SalesValue();
                }
            }

            return d;
        };


        float VAT(){

            float vat = 0;

            if(ProductType == 'Z'){
                vat = .18 * NetSalesValue();
            }

            return vat;
        };

        float NetSalesValue(){
            return SalesValue() - Discount();
        }

        float NetPay(){
            return NetSalesValue() + VAT();
        }

};

int main(){

    //instantiate inputs
    string customerName;
    char productType;
    int units;

    //collect inputs
    cout << "Customer name: " << endl;
    cin >> customerName;
    cout << "Product Type: " << endl;
    cin >> productType;
    cout << "Units bought: " << endl;
    cin >> units;

    Payment pay(customerName, productType, units);

    //output
    cout << "******************************" << endl << endl;
    cout << "Customer Name => " << customerName << endl;
    cout << "Payment => " << pay.NetPay() << " $" << endl << endl;
    cout << "******************************" << endl;

    cin.get();
}

