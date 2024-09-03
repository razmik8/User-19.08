class user{
    private:
	std::string fullname;
	std::string email;
	std::string password;
    public:
	//seters
	void set_fullname(std::string);
	void set_email(std::string);
	void set_password(std::string);
	//geters
	std::string get_fullname();
	std::string get_email();
	//constructors,destructor
	user();
	user(std::string,std::string,std::string);
	~user();
	
	void change_password(std::string, std::string);
	void update_email(std::string, std::string);
};