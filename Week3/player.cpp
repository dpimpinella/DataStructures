#include <iostream>
using namespace std;

class Player {
    private:
        string name;
        string password;
        int experience;
        string inventory[4];
        int location[2];

    public: 
        void set_name(string n);
        string get_name();
        void set_password(string p);
        string get_password();
        void set_experience(int e);
        int get_experience();
        void set_inventory(string i, int index);
        string get_inventory(int index);
        void set_location(int x, int y);
        int get_location(int index);
        void display();
        Player();
};
Player::Player(void){

}

void Player::set_name(string n){
    name = n;
}
string Player::get_name(){
    return name;
}
void Player::set_password(string p){
    password = p;
}
string Player::get_password(){
    return password;
}
void Player::set_experience(int e){
    experience = e;
}
int Player::get_experience(){
    return experience;
}
void Player::set_inventory(string i, int index){
    inventory[index] = i;
}
string Player::get_inventory(int index){
    return inventory[index];
}
void Player::set_location(int x, int y){
    location[0] = x;
    location[1] = y;
}
int Player::get_location(int index){
    return location[index];
}
void Player::display() {
    cout << "Name: " << name << '\n';
    cout << "Password: " << password << '\n';
    cout << "Experience:  " << experience << '\n';
    cout << "First Inventory Item:  " << inventory[0] << '\n';
    cout << "Second Inventory Item: " << inventory[1] << '\n';
    cout << "Third Inventory Item:  " << inventory[2] << '\n';
    cout << "Fourth Inventory Item:  " << inventory[3] << '\n';
    cout << "Location: (" << location[0] << "," << location[1] << ")\n" << '\n';
}




int main() {
    Player player1;
    player1.set_name("Emily");
    player1.set_password("aPassword");
    player1.set_experience(100);
    player1.set_inventory("sword",0);
    player1.set_inventory("shield",1);
    player1.set_inventory("axe",2);
    player1.set_inventory("bow",3);
    player1.set_location(1,1);
    player1.display();

    Player player2;
    player2.set_name("Chuck");
    player2.set_password("anotherPassword");
    player2.set_experience(200);
    player2.set_inventory("sword",0);
    player2.set_inventory("shield",1);
    player2.set_inventory("axe",2);
    player2.set_inventory("bow",3);
    player2.set_location(10,10);
    player2.display();

    Player player3;
    player3.set_name("Larry");
    player3.set_password("anotheranotherPassword");
    player3.set_experience(300);
    player3.set_inventory("sword",0);
    player3.set_inventory("shield",1);
    player3.set_inventory("axe",2);
    player3.set_inventory("bow",3);
    player3.set_location(100,100);
    player3.display();

}

