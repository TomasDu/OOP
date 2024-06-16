#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ticket {
    string match;
    float basePrice;

public:
    Ticket(string match, float basePrice) : match(match), basePrice(basePrice) {}

    // getters
    float getBasePrice() { return basePrice; }
    string getMatch() { return match; }

    // methods
    virtual float price() = 0;

    void display(){
    	cout << "Ticket: " << match<< " | price: "<<basePrice<<endl;
    }
};

// sitting
class TicketSitting : public Ticket {
    int row;
    int block;

public:
    TicketSitting(string match, float basePrice, int row, int block) : Ticket(match, basePrice), row(row), block(block) {}

    float price(){
        if (row < 8)
            return getBasePrice() * 1.4;
        else if (row >= 8 && row <= 15)
            return getBasePrice() * 1.2;
        else
            return getBasePrice();
    }
};

// standing
class TicketStanding : public Ticket {
    char tribune; // S - south, N - north, E - east, W - west

public:
    TicketStanding(string match, float basePrice, char tribune) : Ticket(match, basePrice), tribune(tribune) {}

    float price(){
        return tribune == 's' ? getBasePrice() * 1.3 : getBasePrice();
    }
};

class TicketManager {
    vector<Ticket*> tickets;

public:
	//ticketManager(){}

    void addTicket(Ticket* t) {
        tickets.push_back(t);
    }

    void addTickts(int n){
    	for (int i = 0; i < n; ++i)
    	{
            int ticketType;
            string match;
            float basePrice;
            cout << "Enter details for ticket " << i + 1 << endl;
            cout << "Enter match name: ";
            cin>>match;
            cout << "Enter base price: ";
            cin >> basePrice;
            cout << "Enter ticket type (1 for Seating, 2 for Standing): ";
            cin >> ticketType;

            if (ticketType == 1){
                int block, row;
                cout << "Enter block: ";
                cin >> block;
                cout << "Enter row: ";
                cin >> row;
                addTicket(new TicketSitting(match,basePrice,row,block));
            }else if (ticketType == 2){
            	char tribune;
                cout << "Enter tribune (S - south, N - north, E - east, W - west): ";
                cin >> tribune;
                addTicket(new TicketStanding(match, basePrice, tribune));
            }else {
            	cout<<"invalid skipping..."<<endl;
            }

    	}
    }

    void displayTickets(){
    	for(Ticket* t : tickets){
    		t->display();
    	}
    }

};

int main() {
    int n;
    TicketManager tm;
    cout << "Enter the number of tickets to add: ";
    cin >> n;
    tm.addTickts(n);
    tm.displayTickets();
    return 0;
}
