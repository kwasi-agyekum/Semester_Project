#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

void encryptDecrypt(char *input,char *output){
	char key[]={'K','C','Q'};
	int keyLength = sizeof(key)/sizeof(*key);
	int i;
	
	for (i=0;i<strlen(input); i++){
		output[i]=input[i] ^ key[i%keyLength];}} 

int main(int argc, char** argv) {
	string username, password, enteredPassword,reUsername,pro_password="012345";
	char encrypted[100], decrypted[100], choice;
	int tryAttempts=0;
	char option;
	
  
  	while(true){
	  
		cout<<"**********WELCOME TO THE PROGRAM*********\n";
		cout<<"\n";
		cout<<"1. Save account details.\n2. Retrieve already saved account details.\n3. About & Help.\n4. Exit Program.\n";
		cout<<"Choose from option 1 to 4: ";
		cin>>choice;
		cin.ignore();
		
		//OPTION 1(STORING ACCOUNT DETAILS)
		if(choice=='1'){cout<<"\n";
			ofstream file("passwords.txt", ios::app);
			cout<<"Enter the Username of the Account: ";
			getline(cin, username);
			cout<<"Enter the Password of the Account: ";
			getline(cin, password);
			encryptDecrypt(&password[0], encrypted);
			file<<username<<" "<<encrypted<<endl;
			file.close();
			cout<<" "<<endl;
			cout<<"Username :"<<username<<endl;
			cout<<"Password :"<<password<<endl;
			cout<<"Are you sure to want to save the above account details?\n";
			cout<<"1. yes\n";
			cout<<"2. no\n";
			cin>>option;
			if(option=='1'){
			cout<<"Account details saved successfully.";break;}
			else cout<<"Account details saving cancelled";break;}
		
		//  OPTION 2(RETRIEVING ACCOUNT DETAILS) (USERS HAVE 3 ATTEMPTS TO ENTER PROGRAM PASSWORD)
		else if(choice=='2'){cout<<"\n";
			ifstream file("passwords.txt");
			bool found=false;
			cout<<"Enter the username: ";
			getline(cin, reUsername);
			while(file>>username>>encrypted){
				encryptDecrypt(encrypted,decrypted);
				if(reUsername==username){
					found=true;
	while(true){
		cout<<"Enter program password: ";
		cin>>enteredPassword;
		if(enteredPassword==pro_password){cout<<"The password for "<<username<<" is "<<decrypted<<endl;return 0;
		}
		if(enteredPassword!=pro_password){ tryAttempts++;
		if(tryAttempts>=3){cout<<"Too many attempts. Exiting...\n";
		return 0;}
			cout<<"Incorrect password enetered.Try again. "; continue;}
				
			}}
					file.close();
					if(reUsername!=username||!found){
				cout<<"Username not found."; return 0;}}}
				
		//OPTION 3(About & HELP)
		else if(choice=='3'){
			cout<<"\n";
			cout<<"This is a password manager program created by Mr. Agyekum Peter, the CEO of GREATNESS SOFTWARE DEVELOPMENT.\n";
			cout<<"It helps its users to save their account details and later retrieve at the appropriate time under secured management.\n";
			cout<<"\n";
			cout<<"THE OPTIONS\n";
			cout<<"Option 1 helps users to save account details.Thus username and password.\n";
			cout<<"Option 2 helps users to retrieve already saved account password by providing the username of the account and entering the program password.\n";
			cout<<"Option 4 is just an option to exit the program.\n\n";
			cout<<"NOTE: In order to make changes to already saved account, contact the head office on 020-238-1700 for assistance.";break;}		
		
		//OPTION 4(EXITING THE PROGRAM)
		else if(choice=='4'){cout<<"\n";
			cout<<"Thank you for using our program.\nProgram Exiting..."; break;}
		else cout<<"\nInvalid Input.\nPlease Try Again.\n";
		}}

	

	
	

