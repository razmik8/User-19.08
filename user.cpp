#include <iostream>
#include <cstring>
#include "user.h"


//seters
void user::set_fullname(std::string fullname){
    this->fullname = fullname;
}
void user::set_email(std::string email){
    this->email = email;
}
void user::set_password(std::string Password){
    const char* passwordCStr = Password.c_str();
    int size = strlen(passwordCStr);
    if(size > 8 && size < 12){
	bool mecatar = false;
	bool poqratar = false;
	bool tiv = false;
	for(int i = 0;i < size;i++){
	    if(Password[i] < 47 || Password[i] > 58 && Password[i] < 64 || Password[i] > 91 && Password[i] < 96 || Password[i] > 123){
		std::cout << "Invalid password. Input only capital letters, lower cases and numbers." << std::endl;
	    }
	    if(Password[i] > 47 && Password[i] < 58){
	        tiv = true;
	    }
	    else if(Password[i] > 96 && Password[i] < 123){
	        poqratar = true;
	    }
	    else if(Password[i] > 64 && Password[i] < 91){
	        mecatar = true;
	    }
	}
	if(tiv && mecatar && poqratar){
	    this->password = Password;
	}
    }
    else{
	std::cout << "Password is long or short. Password can have more than 8 symbols and less than 12 symbols." << std::endl;
    }
}
//geters
std::string user::get_fullname(){
    return fullname;
}
std::string user::get_email(){
    return email;
}
//constructors
user::user() = delete;
user::user(std::string name,std::string email,std::string Password){
    set_fullname(name);
    set_email(email);
    set_password(Password);
    std::cout << "User created:";
}
user::~user(){};

void user::change_password(std::string old_password,std::string new_password){
    if(old_password == password){
	    set_password(new_password);
    	std::cout << "Pasword changed:" << std::endl;
    }
    else{
        std::cout << "Password is wrong:" << std::endl;
    }
}
void user::update_email(std::string Password, std::string new_email){
    if(Password == password){
        email = new_email;
        std::cout << "Email changed:";
    }
    else{
        std::cout << "Password is wrong:" << std::endl;
    }
}



int main(){
    user us1("Razmik","raz8","Aa123456789");
    us1.change_password("Aa12345679","aA123456789");
    std::cout << us1.get_email() << " " << us1.get_fullname();
    us1.update_email("Aa123456789","razz8");
    std::cout << std::endl << std::endl;
    std::cout << typeid(us1).name();
}

