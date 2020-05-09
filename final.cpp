#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
  
void loadVectorsFromFile(); //loads lists from grocery.txt
void saveVectorsToFile(); //saves lists to grocery.txt
void recipesEditor();//display's edit the list menu
void menu();
void recipeAdd();
void recipeRemove();
void recipeDatabase();

int mainChoice;
int choice;
string str;
const int runningInt = 1;
vector<string> recipes;
string TEMPSTRING;

int recipesList[0];
int recipesChoice;
int recipesSize;
int menuChoice = 0;
int digit;

void menu(){
  cout << "=================================================\n";
  cout << "\nWelcome to the Recipe Menu Selector.\n \nPlease choose what you would like to do!\n\n";
  cout << "1. Add New Recipe Ingredients.\n";
  cout << "2. Remove Current Recipe Ingredients.\n";
  cout << "3. Save and Exit the Database.\n";
  cout << "Your Choice: ";
}
 //display's main menu (i consider the 1st menu main)
//declare void exit here


int main(){
    loadVectorsFromFile();
    while(runningInt == 1){
        menu();
        cin >> menuChoice;
        switch(menuChoice){ //case used for main menu switch
            case 1:
                recipeAdd();
                break; //Add ingredient
            case 2:
                recipeRemove();
                break; //Remove ingredient
            case 3: 
                cout << "=================================================\n";
                cout << "Saving and Exiting Database!\n";
                cout << "=================================================\n";
                saveVectorsToFile();
                exit(0);
            default:
                cout << "Invalid choice! Please enter a valid choice.\n\n";
                break;//exit switch to exit program
        }
    }
}

void loadVectorsFromFile(){
    ifstream loadItems ("recipe.txt");
    while(!loadItems.eof()){
        getline(loadItems,TEMPSTRING);
        recipes.push_back(TEMPSTRING);
    }
}

void saveVectorsToFile(){
    ofstream saveItems;
    saveItems.open("recipe.txt");
    for(int x = 0; x < recipes.size(); x++){
        saveItems << recipes[x];
        if(x < recipes.size()-1){
            saveItems << "\n";
        }
    }
}

void recipeAdd(){
  cout << "=================================================";
    cout <<"\nYour current Recipe Database is:\n\n";
        for(int x = 1; x < recipes.size()+1; x++){
            cout << x << ". " << recipes[x-1] << "\n";
        }
        cout << "=================================================";
    cout << "\n1. What would you like to add to the database: ";
            string recipesAddition;
            cin.ignore();
            getline(cin, recipesAddition);
            recipes.push_back(recipesAddition);
            cout << "\n" << recipesAddition << " has been added to the list!" << "\n";  
}

void recipeRemove(){
  int recipesRemove;
  cout << "=================================================\n";
  cout <<"\nYour current Recipe Database is:\n\n";
        for(int x = 1; x < recipes.size()+1; x++){
            cout << x << ". " << recipes[x-1] << "\n";
        }
        cout << "=================================================\n";
        cout << "\nPlease enter which item you would like to remove: ";
        cin >> recipesRemove; 
        if (recipesRemove){
            recipes.erase(recipes.begin() + recipesRemove - 1);
            cout << "The item at ";
            cout << recipesRemove;
            cout << " has been removed!\n";
        } else {
          cout << "Invalid response! Please enter a valid number.";
        }
}



    
              


/* ******ORIGINAL*DO*NOT*EDIT*******   
   cout << "\nWhat would you like to do?\n\n1. Add to this list\n2. Remove from this list\n3. Return to the main menu\n\nPlease select: ";
        cin >> recipesChoice;
        switch(recipesChoice){
            case 1: {
                string recipesAddition;
                cout << "Please enter what you would like to add to the list: ";
                cin.ignore();
                getline(cin, recipesAddition);
                recipesList.push_back(recipesAddition);
                recipesSize++;
                cout << recipesAddition << " has been added to the list!";                
                break;
            }
            case 2:
                int recipesRemoval;
                cout << "Please enter the number of which item you would like to remove: ";
                cin >> recipesRemoval;
               recipesList.erase(recipesList.begin() + recipesRemoval - 1);
                recipesSize--;
                break;
                
  void saveVectorsToFile()
    {
    ofstream recipesOut("grocery.txt");
    for (int x = 0; x < recipesSize; x++){
           recipesOut << recipesList[x] << endl;
           }
           recipesOut.close()
        }
  }
}*/
