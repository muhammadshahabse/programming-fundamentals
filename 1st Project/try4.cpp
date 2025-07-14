#include <iostream>
#include <iomanip>
#include <string>
// #include <vector>
#include <fstream>
using namespace std;
int isbn,check2=0;  // Declare counter before loop
struct BookRecord {
          string title, author, status;
          int sr,isbn;
      };

    void mainmenu();
    void addbook();
    void option();
    void displayallRecord();
    void Searching();
    void  Issuing();
    void Returningissuedbook();
    void Updatingbookinfo();
    void deletebookrecord();
    int lastbookserialnumber();

  int main () {
              mainmenu();
        return 0;
}
//MAIN MENU to selecte the option
void mainmenu() {
       int option;// declear variablefor swlection of the option
       cout << "\t\t------------------------------------------------------------------------"<<endl;
       cout << " \t\t                  WELCOME TO Library Management System                 " <<endl;
       cout << "\t\t------------------------------------------------------------------------"<<endl;
       cout << "\t\t\t\t\t\t*--------*"<<endl;
       cout << "\t\t\t\t\t     ~~~|MainMenu|~~~"<<endl;
       cout << "\t\t\t\t\t\t*--------*"<<endl;
       cout << "\n\t\tPlease Select  \n";
       cout <<"\t\t1) Adding new books to the library."<<endl;
       cout <<"\t\t2) Displaying all books available in the library."<<endl;
       cout <<"\t\t3) Searching for a book by title, author, or other criteria."<<endl;
       cout <<"\t\t4) Issuing books to borrowers." <<endl;
       cout <<"\t\t5) Returning issued books to the library."<<endl;
       cout <<"\t\t6) Updating book information if needed"<<endl;
       cout <<"\t\t7) Delete Book Record" <<endl;
       cout <<"\t\t0) for Exit the program"<<endl;
       cout <<"\t\t  ";
       cin >>option;
       switch (option) {
          case 1:addbook(); 
        break;
          case 2:displayallRecord();
        break;
          case 3: Searching();
        break;
          case 4 : Issuing();
        break;
          case 5 : Returningissuedbook();
          break;
          case 6  : Updatingbookinfo();
          break;
        case 7  : deletebookrecord();
          break;

          case 0: cout <<"\t\tthank you for using our system"<<endl;
          cout << "\t\t------------------------------------------------------------------------"<<endl;
          exit(0);
        break;
        default :  
                cout << "\t\tInvalid Selection Please try Again ";
                return mainmenu ();
}
}
void option(){
    int choice;
    cout << "\t\tPlease enter 1 key for Mainmenu\n\t\t";
    cin >> choice ;
    if (choice == 1 ){ mainmenu(); }
    else { cout << "\t\tInvalid number ";
        option();
    }
    
 }
int lastbookserialnumber() {
    BookRecord b;
    fstream infile("bookdata.txt", ios::in);
    if (!infile) { 
        cout << "Error opening file" << endl;
        return 0; // or handle the error as needed
    }
    
    int lastSerialNumber = 0;
    while (infile >> b.sr >> b.title >> b.author >> b.status >> b.isbn) {
        if (b.sr > lastSerialNumber) {
            lastSerialNumber = b.sr;
        }
    }
    infile.close();
    return lastSerialNumber;
}
//function of  add new book
void addbook(){ 
    BookRecord b;
    b.sr=1;
    int nb;
          cout << "\t\tHow many books do you want to add?\n\t\t";
          cin >>nb;// nb==number of books
          fstream outfile("bookdata.txt", ios ::out |  ios::app);
          for (int i =0 ; i < nb ; i++) {
             b.sr = lastbookserialnumber() + b.sr;   // serial number of the book
              cout << "\t\tEnter the book title: ";
              cin >> b.title;
              
              cout << "\t\tEnter the book author: ";
              cin>> b.author;
              cout << "\t\tEnter Book Status: ";
              cin>> b.status;
              cout << "\t\tEnter the ISBN: ";
              cin >> b.isbn;
              outfile  <<"\n "<< b.sr <<" " << b.title<< " " <<b.author<<" "  <<b.status << "  " << b.isbn;
            b.sr++;
            } outfile.close();  
    
            if (nb>0){
    cout << "\t\t\t\tBook saved successfully!" << endl;}
            else cout << "Sorry";
      option();
     
}
void displayallRecord() {
        BookRecord b;
        
        fstream infile("bookdata.txt", ios::in);

        if (!infile) { 
            cout << "Error opening file" << endl;
            return mainmenu();  // or just mainmenu(); return 0;
        }
    
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                        BOOK RECORD                                             |" << endl;
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "Sr No\t\tBook Title\t\tBook Author\t\tBook Status\t\tISBN" << endl;
    
        
    
        while (infile >> b.sr >>b.title >> b.author >> b.status >> b.isbn) {  
                
            
            cout << b.sr << ")\t\t" << b.title << "\t\t\t" << b.author << "\t\t\t" << b.status << "\t\t\t" << b.isbn << endl;
            
            
        }
    
        infile.close();
        cout << "-------------------------------------------------------------------------------------------------" << endl;
      
        option();
    }
    void Searching()
    {
        BookRecord b;

        fstream infile("bookdata.txt", ios::in);
        if (!infile) { 
            cout << "Error opening file" << endl;
            return mainmenu();  // or just mainmenu(); return 0;
        }
    
        int check=0;
    
        cout<< "Enter the ISBN of the book";
        cin >> isbn;
    
        while (infile >> b.sr >>b.title >> b.author >> b.status >> b.isbn) {  
        if (isbn==b.isbn){ 
            check =1;
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            cout << "Book Record:" << endl;
        cout << "Sr No\t\tBook Title\t\tBook Author\t\tBook Status\t\tISBN" << endl;
            cout << b.sr << ")\t\t" << b.title << "\t\t\t" << b.author << "\t\t\t" << b.status << "\t\t\t" << b.isbn << endl;
        }
        }
        if (check==0){
            cout<<"Invaild ISBN ";
        }
        infile.close();
        cout << "-------------------------------------------------------------------------------------------------" << endl;
           cout << "Enter 2 for More Search "<<endl;
        option();
        

    }
    void Issuing(){
        BookRecord b;
        int compare,check=0;
        fstream infile("bookdata.txt", ios::in);
        fstream temfile("temporyfile.txt", ios :: app); 
        fstream issuingbookfile("issuingbookfile.txt", ios :: app);
        if (!infile) { 
            cout << "Error opening file" << endl;
            return mainmenu ();  // or just mainmenu(); return 0;
        }
    
        
        cout<< "Enter the ISBN of the book";
        cin >> isbn;
    
        while (infile >> b.sr >>b.title >> b.author >> b.status >> b.isbn) {  
            
            if (isbn==b.isbn){
            check=1,check2=1;
            issuingbookfile<<"\n "<< b.sr<<"  " << b.title<< " " <<b.author<<" "  <<b.status << "  " << b.isbn;
            compare=b.sr;
            continue;
                }  
            if (check==1)  {
            if (compare < b.sr){
            b.sr--;}
            temfile<<"\n "<<b.sr<<"  "  << b.title<< " " <<b.author<<" "  <<b.status << "  " << b.isbn;
            
        } 
        else {
            temfile<<"\n "<<b.sr<<"  "  << b.title<< " " <<b.author<<" "  <<b.status << "  " << b.isbn;
        }    
        
        }
        temfile.close();
        infile.close();
        issuingbookfile.close();
        if(check == 1)
        {       cout  << "Book Issued succussfuly"<<endl;
            remove("bookdata.txt");
            rename("temporyfile.txt","bookdata.txt");
        }
        else
        {
            cout << " Sorry No BookRecord found"<<endl;
            remove("temporyfile.txt");
            
        }
        cout << "-------------------------------------------------------------------------------------------------" << endl;
       check=0;
        option();
    }
     void Returningissuedbook(){
        BookRecord b;
        int check=0;
        fstream issuingbookfile("issuingbookfile.txt", ios::in);
        fstream temfile("temporyfile.txt", ios :: app); 
        fstream infile("bookdata.txt", ios::app);
        fstream Returningissuedbook("Returningissuedbook.txt", ios :: app);
        if (!issuingbookfile) { 
            cout << "Error opening file" << endl;
            return mainmenu();  // or just mainmenu(); return 0;
        }
    
        
        cout<< "Enter the ISBN of the book";
        cin >> isbn;
    
        while ( issuingbookfile >> b.sr >>b.title >> b.author >> b.status >> b.isbn) {  
            
        if (isbn==b.isbn){
            check=1;
            b.sr=lastbookserialnumber()+1;
            infile <<"\n "<< b.sr << b.title<< " " <<b.author<<" "  <<b.status << "  " << b.isbn;

            continue;
        }         
            temfile <<"\n "<< b.sr << b.title<< " " <<b.author<<" "  <<b.status << "  " << b.isbn;    
        }
        temfile.close();
        infile.close();
        issuingbookfile.close();
        if(check ==1)
        {       cout << "Book Retured succussfuly\n";
            remove("issuingbookfile.txt");
            rename("temporyfile.txt","issuingbookfile.txt");



        }
        else
        {
            cout << " Sorry No BookRecord found "<<endl;
            remove("temporyfile.txt");
            
        }
        cout << "-------------------------------------------------------------------------------------------------" << endl;
      
        option();


    }
     void Updatingbookinfo()
{   
         BookRecord b;
        int i,check=0;
      fstream temporyfile("temporyfile.txt", ios :: app);
      fstream infile("bookdata.txt", ios::in);
     
      if (!infile) { 
            cout << "Error opening file" << endl;
            return mainmenu();  // or just mainmenu(); return 0;
        }
         cout<< "Enter the ISBN of the book";
         cin >> isbn;
        while (infile >>  b.sr>> b.title >> b.author >> b.status >> b.isbn)
     {
        if (isbn==b.isbn)
            {
                check=1;
                cout << "-------------------------------------------------------------------------------------------------" << endl;
                cout << "Enter 1 to Update book title: "<<endl;
                cout << "Enter 2 to Update book author: "<<endl;
                cout << "Enter 3 to UpdateBook Status: "<<endl;
                cout << "Enter 4 to Updatethe ISBN: "<<endl;
                cout << "Enter 5 to Update all book information: "<<endl;
                cin >> i;
                switch (i) 
                {
                    case 1:{ cout << "Enter the  book new title: ";
                            cin >> b.title;
                    
                            break;}
                    case 2: {cout << "Enter the book new  author: ";
                            cin >> b.author;
                        
                            break;}
                    case 3:{cout << "Enter Book Status: ";
                            cin >> b.status;
                        
                            break;}
                    case 4: {cout << "Enter the ISBN: ";
                            cin >> b.isbn;
                        
                            break;}   
                            case 5:
                            {cout << "Enter the book new  title: ";
                                    cin >> b.title;
                                    cout << "Enter the book new  author: ";
                                    cin >> b.author;
                                    cout << "Enter Book Status: ";
                                    cin >> b.status;
                                    cout << "Enter the ISBN: ";
                                    cin >> b.isbn;
                                    break;} 
                     default: 
                    {       cout << "Invalid option. Please try again." << endl;
                        }
                
                }
                
                // temporyfile  <<"\n "<< b.sr << " "<< b.title<< " " <<b.author<<" "  <<b.status << "  " << b.isbn;
                   
            }
            
            temporyfile  <<"\n "<< b.sr << " "<< b.title<< " " <<b.author<<" "  <<b.status << "  " << b.isbn; 
    
    }    
            temporyfile.close();
            infile.close();
            
            if(check ==1)
            { 
            
            cout << "\t\tBook update succussfuly\n";
            remove("bookdata.txt");
            rename("temporyfile.txt","bookdata.txt");
            }
        else
            {
            cout << "\t\tSorry No BookRecord found "<<endl;
            remove("temporyfile.txt");
            
            }

            cout << "-------------------------------------------------------------------------------------------------" << endl;
      
            option();
        
}
void deletebookrecord()
{
    BookRecord b;
    int check=0;
    fstream infile("bookdata.txt", ios::in);
    fstream temfile("temporyfile.txt", ios :: app);
    if (!infile)
            {   
                cout <<"Error opening file" << endl;
                return mainmenu();  // or just mainmenu(); return 0;
            }
    cout<< "\t\tEnter the ISBN of the book";
    cin >> isbn;
    while (infile >> b.sr >> b.title >> b.author >> b.status >> b.isbn){
    if (isbn == b.isbn)
             {
            check = 1;
            cout << "\t\tBook Record Deleted Successfully" << endl;
            continue;
            }  
            temfile <<"\n "<< b.sr << " "<< b.title<< " " <<b.author<<" "  <<b.status << "  " << b.isbn;
    }
    temfile.close();
    infile.close();
    if  (check == 1)
                       {
                 remove("bookdata.txt");
                rename("temporyfile.txt","bookdata.txt");
                       }
    else
                        {
                         cout << "\t\tSorry No BookRecord found "<<endl;
                 remove("temporyfile.txt");
                        }
                        option();
    
}
