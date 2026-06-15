#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int bookID;
    string title;
    string author;
    bool issued;

    void addBook()
    {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;
    }

    void displayBook()
    {
        cout << "\nBook ID : " << bookID;
        cout << "\nTitle   : " << title;
        cout << "\nAuthor  : " << author;
        cout << "\nStatus  : ";

        if (issued)
            cout << "Issued";
        else
            cout << "Available";

        cout << endl;
    }
};

int main()
{
    Book books[100];
    int count = 0;
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Search by Title";
        cout << "\n4. Search by Author";
        cout << "\n5. Issue Book";
        cout << "\n6. Return Book";
        cout << "\n7. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            books[count].addBook();
            count++;
            cout << "Book Added Successfully!\n";
            break;
        }

        case 2:
        {
            if (count == 0)
            {
                cout << "No Books Available!\n";
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    books[i].displayBook();
                }
            }
            break;
        }

        case 3:
        {
            string searchTitle;
            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, searchTitle);

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (books[i].title == searchTitle)
                {
                    books[i].displayBook();
                    found = true;
                }
            }

            if (!found)
                cout << "Book Not Found!\n";

            break;
        }

        case 4:
        {
            string searchAuthor;
            cin.ignore();

            cout << "Enter Author Name: ";
            getline(cin, searchAuthor);

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (books[i].author == searchAuthor)
                {
                    books[i].displayBook();
                    found = true;
                }
            }

            if (!found)
                cout << "Author Not Found!\n";

            break;
        }

        case 5:
        {
            int id;
            cout << "Enter Book ID to Issue: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (books[i].bookID == id)
                {
                    if (!books[i].issued)
                    {
                        books[i].issued = true;
                        cout << "Book Issued Successfully!\n";
                    }
                    else
                    {
                        cout << "Book Already Issued!\n";
                    }

                    found = true;
                }
            }

            if (!found)
                cout << "Book Not Found!\n";

            break;
        }

        case 6:
        {
            int id;
            cout << "Enter Book ID to Return: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (books[i].bookID == id)
                {
                    if (books[i].issued)
                    {
                        books[i].issued = false;
                        cout << "Book Returned Successfully!\n";
                    }
                    else
                    {
                        cout << "Book Was Not Issued!\n";
                    }

                    found = true;
                }
            }

            if (!found)
                cout << "Book Not Found!\n";

            break;
        }

        case 7:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}