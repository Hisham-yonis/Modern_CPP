#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

void delay(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

class Book
{
private:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y) : title(t), author(a), year(y)
    {
    }

    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    int getYear() const
    {
        return year;
    }

    void displayInfo()
    { //"Title: [title], Author: [author], Year: [year]"
        cout << "Title: [" << title
             << "], Author: [" << author
             << "], Year: [" << year << "]\n";
    }
};

class Lib_Catalog
{
private:
    vector<Book> books;

public:
    void addBook(const Book &b)
    {
        books.push_back(b);
    }
    void searchByAuthor(string name)
    {
        int flag = 0;
        for (auto it : books)
        {
            if (name == it.getAuthor())
            {
                it.displayInfo();
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "Not Found \n";
        }
    }

    void displayCatalog()
    {
        for (auto &it : books)
        {
            it.displayInfo();
        }
    }
};

int main()
{
    int x;
    string t, name;
    int year;
    Lib_Catalog lcat;

    // Book b1("Embedded_Linux", "Hisham", 2001);
    // Book b2("modern CPP", "Mohamed", 2003);
    // Book b3("Python3", "Yonis", 2002);
    // Book b4("Operating systems", "Hossam", 2004);

    while (true)
    {
        cout << "menu :\n"
             << "1. Add a book\n"
             << "2. Search by author\n"
             << "3. Display catalog\n"
             << "4. Exit\n"
             << "Enter your choice : ";
        cin >> x;
        switch (x)
        {
        case 1:
        {
            cout << "Enter the title of the book : ";
            cin.ignore();
            getline(cin, t);
            cout << "Enter the Author of the book : ";
            getline(cin, name);
            cout << "Enter the year of publication : ";
            cin >> year;
            Book b(t, name, year);
            lcat.addBook(b);
            break;
        }
        case 2:
            cout << "Enter Auther's name : ";
            cin.ignore();
            getline(cin, name);
            lcat.searchByAuthor(name);
            delay(2000);
            break;
        case 3:
            lcat.displayCatalog();
            delay(2000);
            break;
        case 4:
            return 0;
        default:
            cout << "Wrong choice \n";
        }
    }

    // b1.displayInfo();
    return 0;
}
