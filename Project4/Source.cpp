#include<iostream>
using namespace std;

//void dosomething() throw(char*) {
//	throw "heyy error";
//}

//void main() {	
//	/*try
//	{
//	dosomething();
//
//	}
//	catch (const char* ex)
//	{
//		cout << "Error" << endl;
//	}*/
//}

void add() {

}
//void func(bool x) {
//	char* data = new char[1024];//address lost
//	string text = "hello World";
//	if (x) {
//		throw "Boom";
//	}
//	int x2 = 0;
//	cout << "deleted data" << endl;
//	delete[]data;
//}
//
////Stack unwinding
//
//void main() {
//	//try
//	//{
//		func(true);
//	//}
//	//catch (const char*ex)
//	//{
//		//cout << ex << endl;
//	//}
//
//}

//
//int last() {
//	cout << "Start Last" << endl;
//	cout << "Last Throw Exception" << endl;
//	int x = 10;
//	throw "Hey error in Last";
//	cout << "End Last" << endl;
//	return x;
//}
//
//
//int third() {
//	cout << "Start Third" << endl;
//	return last();
//	cout << "End Third";
//}
//
//
//int second() {
//	cout << "Start Second" << endl;
//	try
//	{
//		return third();
//	}
//	catch (double ex)
//	{
//		cout << "Second caught exception double : " << ex << endl;
//	}
//	cout << "End Second" << endl;
//}
//
//
//int first() {
//	cout << "Start First" << endl;
//	try
//	{
//		return second();
//	}
//	catch (const char*ex)
//	{
//		cout << "First caught exception char* : "<<ex << endl;
//	}
//	catch (double ex) {
//		cout << "First caught exception double : "<<ex << endl;
//	}
//	cout << "End First" << endl;
//}
//
//
//
//void main() {
//
//	cout << "Main Start" << endl;
//	try
//	{
//		cout << first() << endl;
//	}
//	catch (const char*ex)
//	{
//		cout << "Error : " << ex << endl;
//	}
//	cout << "Main End" << endl;
//
//}
//


class Exception {
protected:
	string text;
	string source;
	int line;
	string date;
public:
	Exception(string text, string source, int line, string date)
		:text(text),source(source),line(line),date(date)
	{
	}

	void printMessage() const {
		cout << "+++++++++  ERROR INFO +++++++++" << endl;
		cout << "Error content : " << text << endl;
		cout << "Source : " << source << endl;
		cout << "Code Line : " << line << endl;
		cout << "Date : " << date << endl;
	}
};

class OutOfRangeException :public Exception {
public:
	OutOfRangeException(string text, string source, int line, string date)
		:Exception(text,source,line,date)
	{
		text += " OUT OF RANGE EXCEPTION";
	}
};


class InvalidArgumentException :public Exception {
public:
	InvalidArgumentException(string text, string source, int line, string date)
		:Exception(text, source, line, date)
	{
		text += " INVALID ARGUMENT EXCEPTION";
	}
};




template<typename T>
class Array {
private:
	T* data;
	int size = 0;
public:
	int getSize()const {
		return size;
	}
	const T& getData()const {
		return data;
	}
	Array<T>& operator=(const Array<T>& other) = delete;
	Array(const Array<T>& other) = delete;


	Array(int size) throw(InvalidArgumentException) {
		if (size < 0 || size>1000000) {
			throw InvalidArgumentException("Message : size was incorrect format", __FILE__, __LINE__, __DATE__);
		}
	}



	T& operator[](int index)throw(OutOfRangeException) {
		if (index < 0 || index >= size) {
			throw OutOfRangeException("Message : index should be between 0 and size", __FILE__, __LINE__, __DATE__);
		}
		return data[index];
	}

	~Array()
	{
		delete[]data;
	}

};

void main() {
	try
	{
		Array<int> myarray(100);
		cout << myarray[500];
	}
	catch (const Exception&ex)
	{
		ex.printMessage();
	}
}





