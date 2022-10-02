#include <iostream>
using namespace std;
int nf =0;
int no_book = 0;
string bname,bauth;
class bookstore{
private:
string title,author,publisher;
int issn,stock;
float price;
public:
void ask();
void add();
int search_book(string bname,string bauth);
void display_data();
void buy();
};
void bookstore :: ask(){
 cin.ignore();
 cout<<" ENTER THE TITLE OF BOOK :- ";
 getline(cin,title);
 cout<<endl;
 cout<<" ENTER THE AUTHOR OF BOOK :- ";
 getline(cin,author);
 cout<<endl;
}
void bookstore :: add(){
 ask();
 cout<<" ENTER THE PUBLISHER OF BOOK :- ";
 getline(cin,publisher);
 cout<<endl;
 cout<<" ENTER THE ISSN CODE OF BOOK :- ";
 cin>>issn;
 cout<<endl;
 cout<<" ENTER THE TOTAL STOCK OF THE BOOK :- ";
 cin>>stock;
 cout<<endl;
 cout<<" ENTER THE PRICE OF THE BOOK(in rupees) :- ";
 cin>>price;
 cout<<endl;
}
int bookstore::search_book(string bname,string bauth){
 if(title == bname&&author==bauth){
 return 1;
 }
 else{
 return 0;
 }
}
void bookstore :: buy(){
 int btb;
 int total_price;
 cout<<" HOW MANY COPIES YOU NEED TO BUY :-"<<endl;
 cin>>btb;
 if(stock>btb){
 stock = stock - btb;
 total_price = btb*price;
 cout<<" TOTAL PRICE :- "<<total_price<<endl;
 cout<<" PAYMENT DONE"<<endl;
 }
 else if(stock<btb){
 cout<<" ONLY "<<btb-stock<<" IS AVAILABLE"<<endl;
 btb = btb-stock;
 stock = 0;
 total_price = btb*price;
 cout<<" TOTAL PRICE :- "<<total_price<<endl;
 cout<<" AYMENT DONE"<<endl;
 }
 else{
 cout<<" NO BOOK IS AVAILABLE VISIT NEXT TIME."<<endl;
 no_book =1;
 }
}
void ask_detail(){
 cin.ignore();
 cout<<" ENTER THE TITLE OF BOOK :- ";
 getline(cin,bname);
 cout<<endl;
 cout<<" ENTER THE AUTHOR OF BOOK :- ";
 getline(cin,bauth);
 cout<<endl;
}
void bookstore :: display_data(){
 cout<<" BOOK NAME :- "<<title<<endl;
 cout<<" AUTHOR NAME :- "<<author<<endl;
 cout<<" PUBLISHER :- "<<publisher<<endl;
 cout<<" ISSN CODE :- "<<issn<<endl;
 cout<<" STOCK :- "<<stock<<endl;
 cout<<" PRICE :- "<<price<<endl;
}
int main()
{
 bookstore book[100];
 cout<<" WELCOME TO BOOK STORE"<<endl;
 int i = 1;
 int j = 0;
 int k;
 int choice;
 while(i){
cout<<" ENTER THE OPTION TO PROCEED"<<endl;
 cout<<" 1 - ADD BOOKS"<<endl;
 cout<<" 2 - EDIT BOOKS"<<endl;
 cout<<" 3 - SEARCH BOOKS"<<endl;
 cout<<" 4 - BUY BOOKS"<<endl;
 cout<<" 5 - EXIT"<<endl;
 cin>>choice;
 switch(choice){
 case 1:
 book[j].add();
 j++;
 break;
 case 2:
 ask_detail();
 for(int t=0;t<j;t++){
 if(book[t].search_book(bname,bauth)==1){
 cout<<" BOOK FOUND"<<endl;
 nf--;
 book[t].display_data();
 cout<<" EDIT THE DATA"<<endl;
 book[t].add();
 cout<<" DATA UPDATED"<<endl;
 break;
 }
 else{
 nf=1;
 }
 }
 if(nf==1){
 cout<<" BOOK NOT FOUND"<<endl;
 }
 break;
 case 3:
 ask_detail();
 for(int t=0;t<j;t++){
 if(book[t].search_book(bname,bauth)==1){
 cout<<" BOOK FOUND"<<endl;
 nf--;
 book[t].display_data();
 break;
 }
 else{
 nf=1;
 }
 }
 if(nf==1){
 cout<<" BOOK NOT FOUND"<<endl;
 }
 break;
 case 4:
 cout<<" ENTER DETAILS HERE"<<endl;
 ask_detail();
 for(int t=0;t<j;t++){
 if(book[t].search_book(bname,bauth)==1){
 cout<<" BOOK FOUND"<<endl;
 nf--;
 book[t].display_data();
 book[t].buy();
 if(no_book==1){
 break;
 }
 break;
 }
 else{
 nf=1;
 }
 }
 if(nf==1){
 cout<<" BOOK NOT FOUND"<<endl;
 }
 break;
 case 5:
 i=0;
 break;
 default:
 cout<<" INVALID OPTION!";
 }
 }
}
