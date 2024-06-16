#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ticket {
    string movie_name;
    float basePrice;
public:
    Ticket(string movie_name, float basePrice) : movie_name(movie_name), basePrice(basePrice) {}

    virtual ~Ticket() {}

    float getBasePrice() { return basePrice; }
    string getMovie_name() { return movie_name; }

    virtual float price() = 0;
    virtual void display(){}

};

class regularTicket : public Ticket {
    int seatNumber;
public:
    regularTicket(string movie_name, float basePrice, int seatNumber) : Ticket(movie_name, basePrice), seatNumber(seatNumber) {}

    float price() override {
        return seatNumber <= 10 ? getBasePrice() * 1.2 : getBasePrice();
    }

    void display() override {
        cout << "Ticket: " << getMovie_name() << " | " << "Base price: " << getBasePrice() << " | " << "Seat number: " << seatNumber << " | " << "Final price: " << price() << endl;
    }
};

class vipTicket : public Ticket {
    bool hasLoungeAccess;
public:
    vipTicket(string movie_name,float basePrice, bool hasLoungeAccess) : Ticket(movie_name,basePrice), hasLoungeAccess(hasLoungeAccess){}

    float price() override{
        return hasLoungeAccess ? getBasePrice() * 1.5 : getBasePrice();
    }

    void display() override {
        cout << "Ticket: " << getMovie_name() << " | " << "Base price: " << getBasePrice() << " | " << "Has Lounge Access? : " << hasLoungeAccess << " | " << "Final price: " << price() << endl;
    }
};

class TicketManage{
    vector<Ticket*> tickets;
public:
    TicketManage(){}
    virtual ~TicketManage(){}

    void addTicket(Ticket* t){
        tickets.push_back(t);
    }


    void loadTickets(int n) {
        string movie_name;
        char isVip;
        float basePrice;
        int seatNumber;
        bool hasLoungeAccess;

        for (int i = 0; i < n; i++) {
            cout << "Enter movie name: ";
            cin >> movie_name;
            cout << "Enter base price: ";
            cin >> basePrice;
            cout << "Is the ticket a VIP? (y-yes | n-no): ";
            cin >> isVip;

            if (isVip == 'n' || isVip == 'N') {
                cout << "Enter seat number: ";
                cin >> seatNumber;
                addTicket(new regularTicket(movie_name, basePrice, seatNumber));
            }
            else if (isVip == 'y' || isVip == 'Y'){
                cout<<"Has acess to the lounge? (1-yes | n-no):";
                cin>>hasLoungeAccess;
                addTicket(new vipTicket(movie_name,basePrice,hasLoungeAccess));
            }
            
        }
    }

    void display(){
        for(Ticket* t: tickets){
            t->display();
        }
    }

    void totalPrice(){
        float totalPrice = 0;
        for(Ticket* t : tickets){
            totalPrice += t->price();
        }
        cout<<"total price: "<<totalPrice<<endl;
    }
};

int main() {

    TicketManage tm;
    tm.loadTickets(2);
    tm.display();
    tm.totalPrice();
    return 0;
}
