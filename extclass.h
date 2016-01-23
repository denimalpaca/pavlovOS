class Ext {
	public:
		Ext(string);
		Ext* next;
		string getname();
		bool getlastused();
	private:
		string name;
		bool lastused;
} ext;
