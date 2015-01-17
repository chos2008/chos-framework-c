class TString 
{
public:
	TString(const char *s);

	TString(TString &s);

	TString& operator=(const TString& s);

	bool operator==(const TString& s);

	void print();

private:
	char *data;
};