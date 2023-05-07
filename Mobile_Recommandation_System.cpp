#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unistd.h>

using namespace std;

struct Phone {
    string brand;
    string model;
    int storage;
    int ram;
    double screen_size;
    int camera;
    int battery_capacity;
    double price;
};

struct Node {
    Phone data;
    Node* left;
    Node* right;
};

void insert(Node*& root, Phone data) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else if (data.price < root->data.price) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data.brand << " " << root->data.model << " $" << root->data.price << endl;
        inorder(root->right);
    }
}

void quicksort(vector<Phone>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[(left + right) / 2].price;
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[i].price < pivot) {
            i++;
        }
        while (arr[j].price > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quicksort(arr, left, j);
    quicksort(arr, i, right);
}

//void quicksort(vector<Phone>& arr, int left, int right);


int main() {
ifstream file("Mobile phone price.csv");
if (!file) {
cout << "Error: cannot open file" << endl;
return 1;
}
string line;
getline(file, line); // skip header

vector<Phone> phones;
while (getline(file, line)) {
    stringstream ss(line);
    string brand, model;
    int storage, ram, camera, battery_capacity;
    double screen_size, price;
    getline(ss, brand, ',');
    getline(ss, model, ',');
    ss >> storage;
    ss.ignore();
    ss >> ram;
    ss.ignore();
    ss >> screen_size;
    ss.ignore();
    ss >> camera;
    ss.ignore();
    ss >> battery_capacity;
    ss.ignore();
    ss >> price;
    phones.push_back({ brand, model, storage, ram, screen_size, camera, battery_capacity, price });
}

// Create a binary search tree to store the phones
Node* root = NULL;
for (int i = 0; i < phones.size(); i++) {
    insert(root, phones[i]);
}

		for (int i = 0; i < 120; i++)
        {
            printf("%c", 4);
        }
        printf("                                           Mobile Recommendation System                                                 ");
        // printf("========================================================================================================================");
        for (int i = 0; i < 120; i++)
        {
            printf("%c", 4);
        }
    
    cout<<"\n\n";

cout<<"* Provide us some specification to recommend Smartphone on that basis *"<<endl<<endl;
cout << "Enter Minimum RAM Required (GB): ";
int ram;
cin >> ram;
cout << "Enter Minimum storage Required (GB): ";
int storage;
cin >> storage;
cout << "Enter Minimum camera specification (MP): ";
int camera;
cin >> camera;
int price_x;
cout << "Enter Average Budget ($): ";
cin >> price_x;
cout<<"\n\n\n";

vector<Phone> matches;
for (int i = 0; i < phones.size(); i++) {
    Phone phone = phones[i];
    if (phone.ram >= ram && phone.storage >= storage && phone.camera >= camera &&phone.price <=price_x) {
        matches.push_back(phone);
    }
}


// Sort the matches by price using quicksort
quicksort(matches, 0, matches.size() - 1);

if (matches.empty()) {
    cout << "No matches found." << endl;
} else {
	system("cls");
	 printf("                                         - Best 10 Recommended Mobiles -                                                ");
        // printf("========================================================================================================================");
        for (int i = 0; i < 120; i++)
        {
            printf("%c", 4);
        }
	cout<<endl<<endl;
    //cout << "Based on Input Our Best 10 Recommendations : " << endl<<endl;
    for (int i = 0; i < min(10, (int)matches.size()); i++) {
    	sleep(1);
    	cout<<i+1<<")"<<endl;
        cout <<"Brand : "<< matches[i].brand << "\nModel : " << matches[i].model <<"\nStorage : "<< matches[i].storage <<"\nRam : "<< matches[i].ram <<"\nScreenSize(inch) : "<< matches[i].screen_size <<"\nCamera(MP) : "<< matches[i].camera <<"\nBattery(Mah) : "<< matches[i].battery_capacity << "\nPrice($) : " << matches[i].price << endl<<endl;
    	cout<<"________________________________________________________"<<endl;
	}
}

return 0;
}
