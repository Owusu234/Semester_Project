#include <iostream>
#include <fstream>

using namespace std;

struct Bank{
	
	string f_name, l_name, address,nationality, next_kin,gender;
	int ph_no,acc_no,acc_pin;
	double amount;
	
	Bank():f_name(""), l_name(""),ph_no(),address(""),acc_no(1234567890),amount(10000),acc_pin(2468){};
	
	void info(){
		cout<<"Enter your first name : "<<endl;
		cin>>f_name;
		cout<<"Enter your last name : "<<endl;
		cin>>l_name;
		cout<<"Enter your mobile number : "<<endl;
		cin>>ph_no;
		cout<<"Enter your address : "<<endl;
		cin>>address;
		cout<<"Enter your gender : "<<endl;
		cin>>gender;
		cout<<"Enter your nationality"<<endl;
		cin>>nationality;
		cout<<"Enter next of kin"<<endl;
		cin>>next_kin;
		
		
		cout<<"YOUR PRUDENTIAL BANK ACCOUNT HAS BEEN CREATED SUCCESSFULLY " <<endl;
	}
};


int main() {
	Bank b;
	int choice,account,pin;
	int con_account,rec_account;
	double amount,with_amount;
	int attempts;
	
		
	cout<<"                                            -------------------------------------                   "<<endl<<endl;
	cout<<"                                            *              WELCOME TO           *                  "<<endl;
	cout<<"                                            *          PRUDENTIAL BANKING       *                  " <<endl;
	cout<<"                                            *               SERVICES            *                   "<<endl<<endl;
	cout<<"                                            -------------------------------------                   "<<endl<<endl;
	
	
	cout<<"1- Create Account"<<endl;
	cout<<"2- Transfer Money" <<endl;
	cout<<"3- Deposit Amount"<<endl;
	cout<<"4- Withdraw Amount"<<endl;
	cout<<"5- Check Balance"<<endl;
	cout<<"6- Transaction History"<<endl;
	cout<<"7- Account Information"<<endl;
	cout<<"0- Exit"<<endl<<endl;
	cout<<"Choose an option" <<endl<<endl;
	
	do{	
		cin>>choice;
		
//		system("cls");
		
		if(choice==1){
			cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        cout<<"                                            *           CREATE ACCOUNT          *                  "<<endl<<endl;
	        cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        
	        b.info();
	        ofstream outFile("Reg_User.txt");
	        
	        if(outFile.is_open()){
	        outFile<< "User's First Name Is : " <<b.f_name <<endl<<endl;
	        outFile<< "User's Last Name Is : " <<b.l_name <<endl<<endl;
	        outFile<< "User's Mobile Number Is : " <<b.ph_no <<endl<<endl;
	        outFile<< "User's Address Is : " <<b.address <<endl<<endl;
	        outFile<< "Your Nationality is a / an : " <<b.nationality<<endl<<endl;
	        outFile<< "Gender : " <<b.gender <<endl<<endl;
	        outFile<<"Next Of Kin : " <<b.next_kin <<endl<<endl;
	        outFile.close();	        	
			}
		}
		
		
		else if(choice==2){
			cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        cout<<"                                            *           TRANSFER MONEY          *                  "<<endl<<endl;
	        cout<<"                                            -------------------------------------                   "<<endl<<endl;	
			
			cout<<"Enter receiver's account number "<<endl;
			cin>>rec_account;
			
			cout<<"Enter amount to transfer " <<endl;
			cin>>amount;
			
			if(amount >= b.amount){
				cout<<"Insufficient balance"<<endl;
			}	
			
			else{
				cout<<"Enter pin to proceed with transaction "<<endl;
			    cin>>pin;	
			}
			
				if(pin != b.acc_pin){
					for(int i=0 ; i<=2 ; i++);
					cout<<"incorrect pin , try again " <<endl;
					cin>>pin;
				}
		    	else {
				    cout<<"You have sent an amount of $ " <<amount<< " to " <<rec_account <<endl;		
				    b.amount-=amount;	
				    cout<<"Your remaining balance is " << b.amount <<endl;		
			    }				
							
			ofstream doc("Transaction.txt",ios::app);	
			if(doc.is_open()){
				doc<<"Amount of $ "<<amount << " transferred to " <<rec_account<<endl;
			}
			
		}
		
		
		else if(choice==3){
			
        	cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        cout<<"                                            *           DEPOSIT AMOUNT          *                  "<<endl<<endl;
	        cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        
			cout<<"Enter your account number : " <<endl;
			cin>>account;
			
			for(int i=0 ; i<=3 ; i++);
			    if(account != b.acc_no){
				cout<<"invalid account number , try again" <<endl;
				cin>>account;
			    }
			
			    else if(account == b.acc_no){
				
				cout<<"Enter amount to deposit : " <<endl;
				cin>>amount;
				
				b.amount+=amount;
				cout << b.amount << endl;
				
				cout<<"You have deposited an amount of " <<amount << " into your Prudential Bank account"<<endl<<endl;
				cout<<"Your balance is $ " <<b.amount<<endl<<endl;	
				
		        }					
		
				ofstream outfile("balance.txt");
				
				if(outfile.is_open()){
					
					outfile<<"Your current balance is $"<< b.amount<<endl;
					outfile.close();
				}else{
					cout << "Couldn't save balanace! \n";
				}
		}
		
				
		
		else if(choice==4){
        	cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        cout<<"                                            *           WITHDRAW AMOUNT         *                  "<<endl<<endl;
	        cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        
	        
	        cout<<"Confirm your account number to proceed with withdrawal " <<endl;
	        cin>>con_account;

	        if(con_account != b.acc_no){
	        	cout<<"invalid account number , try again"<<endl;
	        	cin>>con_account;
			}
	        
	        else if (con_account == b.acc_no){
	        	cout<<"Enter the amount to withdraw" <<endl;
	        	cin>>with_amount;
	        	
	        	if(with_amount > b.amount){
	        		cout<<"Insufficient balance!! , re-enter amount" <<endl;
	        		cin>>with_amount;
				}
				
				else{
					cout<<"You have request to withdraw an amount of " <<with_amount<<endl<<endl;
					cout<<"Enter your pin to approve withdrawal"<<endl;
					cin>>pin;
				}
				
				if(pin!=b.acc_pin){
					for(int i = 0 ; i <=3 ; i++);
					  cout<<"wrong pin , try again"<<endl;
					  cin>>pin;	
				}
				
				else {
					cout<<"You have withdrawn an amount of " <<with_amount<<endl;
					
					b.amount -= with_amount;
					cout<<"Your remaining balance is " <<b.amount<<endl;
				}
				
	        }
	        	
				ofstream outfile("balance.txt");
				if (outfile.is_open()){
				outfile<<" Your remaining balance is "<<b.amount<<endl;
				outfile.close();
				}else{
					cout<<"couldn't open file \n";
				}
				
	
	    }
	    

	    else if(choice==5){
	    	
       	    cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        cout<<"                                            *           CHECK BALANCE           *                  "<<endl<<endl;
	        cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        	    	
	    	cout <<"Enter your account number to proceed"<<endl;
	    	cin>>account;
	    	
			if (account != b.acc_no){
				for(int i = 0 ; i<=3 ; i ++);
				cout<<"account mismatched , try again"<<endl;
				cin>>account;
			}	    	
	    	
	    	else{			
		    ifstream file("balance.txt" , ios::app);
		    
		    if(file.is_open()){
		    	string balance;
		    	while(getline(file,balance)){
		    		cout<<balance<<endl;
				}
			}
			file.close();
			}
			
		}
		
		else if(choice==6){
			cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        cout<<"                                            *           TRANSACTION HISTORY     *                  "<<endl<<endl;
	        cout<<"                                            -------------------------------------                   "<<endl<<endl;	
			
			ifstream doc("Transaction.txt");
			if(doc.is_open() ){
				string transaction;
				while(getline(doc,transaction)){
					cout<<transaction<<endl;
				}
				
				doc.close();
			}	
		}
		
		
	    else if(choice == 7){
	        cout<<"                                            -------------------------------------                   "<<endl<<endl;
	        cout<<"                                            *            USER'S ACCOUNT         *                  "<<endl;
	        cout<<"                                            *             INFORMATION           *                  " <<endl<<endl;
	        cout<<"                                            -------------------------------------                   "<<endl<<endl;		   
		
		    ifstream inFile("Reg_User.txt" , ios::app);
		    
		    if(inFile.is_open()){
		    	string line;
		    while (getline(inFile,line)){
		    		cout<<line<<endl;
				}
		    	inFile.close();
			}	
		}
		
		else if(choice ==0){
			return 0;
		}
		else{
			cout<<"invalid input";
		}
					
	}
	
	while(true);

	
	return 0;
}
