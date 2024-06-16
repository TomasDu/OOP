#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ticket {
    string match;
    float basePrice;
public:
    Ticket(string match, float basePrice) : match(match), basePrice(basePrice) {}
    Ticket(Ticket &other) : match(other.match), basePrice(other.basePrice) {}

    virtual ~Ticket() {}

    Ticket& operator=(Ticket& other) = default;

    // getters
    float getBasePrice() { return basePrice; }
    string getMatch() { return match; }

    // methods
    virtual float cena() = 0;
    virtual void display() {}
};

class SeatingTicket : public Ticket {
    int block, row;
public:
    SeatingTicket(string match, float basePrice, int block, int row) : Ticket(match, basePrice), block(block), row(row) {}

    float cena() override {
        if (row < 8) return getBasePrice() * 1.4;
        else if (row >= 8 && row <= 15) return getBasePrice() * 1.2;
        else return getBasePrice();
    }
    void display() override {
        cout << "match: " << getMatch() << " base price: " << getBasePrice() << " final price: " << cena() << endl;
    }
};

class StandingTicket : public Ticket {
    char tribune;
public:
    StandingTicket(string match, float basePrice, char tribune) : Ticket(match, basePrice), tribune(tribune) {}

    float cena() override {
        return (tribune == 's' || tribune == 'S') ? getBasePrice() * 1.3 : getBasePrice();
    }

    void display() override {
        cout << "match: " << getMatch() << " base price: " << getBasePrice() << " final price: " << cena() << endl;
    }
};

class TicketManager {
    vector<Ticket*> tickets;
public:
    TicketManager() {}

    ~TicketManager() {
        for (Ticket* t : tickets) {
            delete t;
        }
    }

    void addTicket(Ticket* t) {
        tickets.push_back(t);
    }

    void addTickets(int n) {
        string match;
        int row, block, type;
        float basePrice;
        char tribune;

        for (int i = 0; i < n; ++i) {
        	cout<<"match: ";
            cin >> match;
            cout<<"base price: ";
            cin >> basePrice;
            cout<<"type (1-siting 2-standing): ";
            cin >> type;

            if (type == 1) {
            	cout<<"row: ";
                cin >> row;
                cout<<"block: ";
                cin >> block;
                addTicket(new SeatingTicket(match, basePrice, block, row));
            }
            else if (type == 2) {
 			    cout << "Enter tribune (S - south, N - north, E - east, W - west): ";
                cin >> tribune;
                addTicket(new StandingTicket(match, basePrice, tribune));
            }
        }
    }

    void display() {
        for (Ticket* t : tickets) {
            t->display();
        }
    }
};

int main(int argc, char const *argv[])
{
    TicketManager tm;
    tm.addTickets(1);
    tm.display();
    return 0;
}
