#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Book{
    private:
    string title;
    string author;
    string isbn;
    int pages;

    public:
    Book(){
        cout<<"Book information is being created\n";
    }

    void setTitle(string t){
        title=t;
    }
    void setAuthor(string a){
        author=a;
    }
    void setIsbn(string i){
        isbn=i;
    }
    void setPages(int p){
        pages=p;
    }
    string getTitle(){
        return title;
    }
    string getAuthor(){
        return author;
    }
    string getIsbn(){
        return isbn;
    }
    int getPages(){
        return pages;
    }

    void display(){
    cout<<"Title:"<<getTitle()<<","<<"Author:"<<getAuthor()<<","<<"ISBN"<<getIsbn()<<","<<"Pages:"<<getPages()<<"\n";
    }

    ~Book(){
        cout<<"Book object destroyed.\n";
    }
};


class Member{
    private:
    string memberName;
    int memberId;
    string borrowedBookTitle;

    public:
    Member(string name,int id){
        memberName=name;
        memberId=id;
        borrowedBookTitle="None";
    }

    void borrowBook(string title){
    borrowedBookTitle=title;
    }

    string getBorrowedBook(){
        return borrowedBookTitle;
    }

    void displayMemberInfo(){
        cout<<"Member Name: "<<memberName<<"\n";
        cout<<"Member ID: "<<memberId<<"\n";
        cout<<"Borrowed Book: "<<borrowedBookTitle<<"\n";
        }

};

 Book books[10];
int bookCount=0;

void addBook();
void listBooks();
void borrowBook();


int main(){
    int choice;

    while (true) {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. List Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: listBooks(); break;
            case 3: borrowBook(); break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }





    return 0;
}

void addBook() {
    if (bookCount >= 10) {
        cout << "Maximum book limit reached.\n";
        return;
    }

    string title, author, isbn;
    int pages;

    cin.ignore(); 

    cout << "Book Title: ";
    getline(cin, title);

    cout << "Author Name: ";
    getline(cin, author);

    cout << "ISBN: ";
    getline(cin, isbn);

    cout << "Number of Pages: ";
    cin >> pages;

    books[bookCount].setTitle(title);
    books[bookCount].setAuthor(author);
    books[bookCount].setIsbn(isbn);
    books[bookCount].setPages(pages);

    cout << "Book added successfully!\n";
    bookCount++;
}


void listBooks(){
    if(bookCount==0){
        cout<<"No books have been added yet.\n";
        return;
    }

    cout<<"\n--- Book List ---\n";
    cout<<left<<setw(25)<<"Title"<<setw(25)<<"Author"<<setw(20)<<"ISBN"<<setw(6)<<"Pages"<<"\n";
    cout<<string(76,'-')<<"\n";

    for(int i=0;i<bookCount;i++){
        cout<<left<<setw(25)<<books[i].getTitle()<<setw(25)<<books[i].getAuthor()<<setw(20)<<books[i].getIsbn()<<setw(6)<<books[i].getPages()<<"\n";
    }
}

void borrowBook(){
    if(bookCount==0){
        cout<<"No boooks avaliable to borrow.\n";
        return;
    }

    string name;
    int id;

    cin.ignore();

    cout<<"Member Name: ";
    getline(cin,name);

    cout<<"Member ID: ";
    cin>>id;

    Member m(name,id);

    cout<<"Avilable Books:\n";

    for(int i=0; i<bookCount;i++){
        cout<<i+1<<"."<<books[i].getTitle()<<"\n";
    }

    int selection;

    cout<<"Enter the number of book you want to borrow: ";
    cin>>selection;

    if(selection<1 || selection > bookCount){
        cout<<"Invalid selection.\n";
        return;
    }

    m.borrowBook(books[selection-1].getTitle());

    cout<<"Book Successfully borrowed.\n";
    m.displayMemberInfo();

    for(int i=selection-1;i<bookCount-1;i++){
        books[i]=books[i+1];
    }
    bookCount--;

    


}



  