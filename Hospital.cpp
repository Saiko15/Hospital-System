#include<iostream>
using namespace std;

int statuses[21][6], length[21], spec, stat, spec_num;
    string names[21][6], name;

void print_choices(){
    cout << "Enter your choice:\n";
    cout << "1) Add new patient\n";
    cout << "2) Print all patients\n";
    cout << "3) Get next patient\n";
    cout << "4) Exit\n";
}

void shift_right(){
    int pos = length[spec];
    if(pos == 0)
        return;
    for (int i = pos; i > 0; --i){
        names[spec][i] = names[spec][i - 1];
        statuses[spec][i]= statuses[spec][i - 1];
    }
}

void shift_left(){
    int pos = length[spec];
    if (pos == 1)
        return;
    for (int i = 1; i < pos; ++i){
        names[spec][i-1] = names[spec][i];
        statuses[spec][i-1] = statuses[spec][i];
    }
}

void add_patient(){
    cout << "Enter specialization, name, status: ";
    cin >> spec >> name >> stat;
    int pos = length[spec];
    if (pos >= 5)
        cout << "Sorry we can't add more patients for this specialization.";
    else if(stat == 1){
        shift_right();
        names[spec][0] = name;
        statuses[spec][0] = stat;
        length[spec]++;
    }    
    else {
        names[spec][pos] = name;
        statuses[spec][pos] = stat;
        length[spec]++;
    }
}

void print_patient(){
    for (int j = 0; j < 21; ++j){
        if(length[j]){
            cout << "There are " << length[j] << " patients in specialization " << j <<"\n";
            for (int i = 0; i < length[j]; ++i){
                if (statuses[j][i] == 0)
                    cout << names[j][i] <<" regular\n";
                else
                    cout << names[j][i] << " urgent\n";
            }
        } 
        
    }
}
           
void get_next_patients(){
    cout << "Enter specialization :";
    cin >> spec;
        if(length[spec]){
            cout << names[spec][0] <<" please go with the Dr \n";
            shift_left();
            length[spec]--;
        }
        else
            cout << "No patients at the moment. Have rest, Dr\n";
    
}


int main() {
    
    while(true)
    {
        int choice;
        
        print_choices();
        cin >> choice;

        if (choice < 1 || choice > 4)
            cout <<"Invalid choice. Try again\n";

        if(choice == 1)
            add_patient();
        
        if (choice == 2)
            print_patient();

        if (choice == 3)
            get_next_patients();


        if (choice == 4)
            break;
        
    }
}