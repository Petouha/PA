#include <iostream>
#include <ctime>

class Account{

    protected:

        float amount;
        tm opening_time;

        Account(float amount,int year, int month, int day){
            this->amount = amount;
            opening_time = {};
            opening_time.tm_year = year - 1900;
            opening_time.tm_mon = month - 1;
            opening_time.tm_mday = day;
        };

        virtual float add(float new_amount) = 0;
        virtual float withdraw(float new_amount) = 0;
    
    public :
        void printAmount(){
            std::cout << "The amount available is : " << amount << std::endl;
        }
};


class CurrentAccount : public Account{
    public:
        CurrentAccount(float amount, int year,int month, int day) : Account(amount,year,month,day){}

        float add(float new_amount) override{
            this->amount += new_amount;
            return this->amount;
        }

        float withdraw(float new_amount) override{
            this->amount = new_amount < this->amount ? this->amount - new_amount : this->amount;
            return this->amount;
        }
};

class SavingAccount : public Account{
    public:
        float intres_rate;
        SavingAccount(float amount,int year,int month,int day,float intrest_rate) : Account(amount,year,month,day){
            this->intres_rate = intres_rate;
        }

        float add(float new_amount) override{
            this->amount = (this->amount + new_amount <= 10000) ? this->amount + new_amount : 10000;
            return this->amount;
        }

        float withdraw(float new_amount) override{
            if(compute_diff_time() < 4){
                std::cout << "Sorry you cant withdraw, 4 years not reached !" << std::endl;
                return -1;
            }else{
                this->amount = new_amount < this->amount ? this->amount - new_amount : this->amount;
                return this->amount;
            }
        }

        void computeIntrest(){
            this->amount += this->amount * compute_diff_time() * this->intres_rate;
        }



        private:
            float compute_diff_time(){
                return difftime(time(0),mktime(&this->opening_time)) / (60*60*24*365.25);
            }
};


int main(){

    CurrentAccount current(1000,2020,3,20);
    current.add(2000);
    current.withdraw(500);
    current.printAmount();

    SavingAccount saving(1000,2020,5,29,0.7);
    saving.add(10000);
    saving.withdraw(2000);
    saving.computeIntrest();
    saving.withdraw(1000);
    saving.printAmount();

    return 0;
}