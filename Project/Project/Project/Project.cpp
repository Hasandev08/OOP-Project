#include<iostream>
#include<cstring>
#include<string.h>																			//header files
#include<fstream>

using namespace std;

const int SIZE = 100;																		//global variable

#pragma warning(disable:4996)																//pragma to remove warning

//validity functions
bool checkName(char check[SIZE])
{
	bool valid = true;

	for (int i = 0; i < SIZE; i++)
	{
		if ((check[i] >= 'A' && check[i] <= 'Z') || (check[i] >= 'a' && check[i] <= 'z') || check[i] == ' ')
		{
			valid = true;
			if (i + 1 == SIZE && valid == true)
			{
				return true;
			}
		}
		else
		{
			return false;
		}

		if (valid == true)
		{
			return true;
		}
	}
}

bool idCheck(char id[SIZE])
{
	bool valid = true;

	for (int i = 0; i < SIZE; i++)
	{
		if (id[i] != 0)
		{
			if (id[i] >= '0' && id[i] <= '9')
			{
				valid = true;
				if (i + 1 == SIZE && valid == true)
				{
					return true;
				}
			}
			else
			{
				return false;
			}
		}
	}

	if (valid == true)
	{
		return true;
	}

}

class Category																							//category class
{

private:
	char catname[500][SIZE];																			//data members
	char catid[500][SIZE];

public:																									//member functions
	Category()
	{
		for (int i = 0; i < 500; i++)
		{
			catname[i][0] = 0;																			//default constructor
			catid[i][0] = 0;
		}
	}

	Category(char newName[500][SIZE], char newID[500][SIZE])
	{
		for (int i = 0; i < 500; i++)
		{
			strcpy(catname[i], newName[i]);																//parameterized constructor
			strcpy(catid[i], newID[i]);
		}
	}

	void addCategory()
	{
		bool namecheck = false;
		bool checkid = false;

		char check[SIZE] = { 0 };
		char idcheck[SIZE] = { 0 };
		
		cout<<"fine"<<endl;

		cout << "Enter Category name that you want to add" << endl;

		cin.getline(check, SIZE, '\n');																	//add function

		cout << "Enter the Category id that you want to add" << endl;
		cin >> idcheck;
		cin.ignore(1000, '\n');
		


		namecheck = checkName(check);

		while (!namecheck)
		{
			cout<<"fine1"<<endl;
			cout << "Input is invalid, Enter the Category name again" << endl;
			cin.getline(check, SIZE, '\n');
			namecheck = checkName(check);
		}

		checkid = idCheck(idcheck);
		


		while (!checkid)
		{
			cout<<"fine2"<<endl;
			cout << "Id entered is invalid , Enter the id again" << endl;
			cin >> idcheck;
			cin.ignore(1000, '\n');
			checkid = idCheck(idcheck);
		}
		


		for (int i = 0; i < 500; i++)
		{
			if (catname[i][0] == 0)
			{
				strcpy(catname[i], check);
				break;
			}
		}

		for (int i = 0; i < 500; i++)
		{
			if (catid[i][0] == 0)
			{
				strcpy(catid[i], idcheck);
				break;
			}
		}
		
		cout<<"Category has been added successfully"<<endl;
	}

	void editCategory()
	{
		bool namecheck = false;
		bool idcheck = false;

		char edit[SIZE] = { 0 };
		char editid[SIZE] = { 0 };

		cout << "Enter the Category name that you want to edit" << endl;
		cin.ignore(1000, '\n');
		cin.getline(edit, SIZE, '\n');																//edit function

		for (int i = 0; i < 500; i++)
		{

			if (strcmp(edit, catname[i]) == 0)
			{

				for (int j = 0; j < SIZE; j++)
				{
					catname[i][j] = 0;
					catid[i][j] = 0;
				}

				cout << "Enter the new Category name that you want to enter" << endl;
				cin.getline(catname[i], SIZE, '\n');

				cout << "Enter the new ID that you want to add" << endl;
				cin >> catid[i];
				cin.ignore(100, '\n');

				namecheck = checkName(catname[i]);
				idcheck = idCheck(catid[i]);

				while (!namecheck)
				{
					cout << "Input is invalid, Enter the category name again" << endl;
					cin.getline(catname[i], SIZE);
					namecheck = checkName(catname[i]);
				}

				while (!idcheck)
				{
					cout << "Input is invalid, Enter the category id again" << endl;
					cin >> catid[i];
					idcheck = idCheck(catid[i]);
				}

				cout << "Category edited Successfully" << endl;
				break;
			}

			if (i == 499)
			{
				cout << "No such Category found" << endl;
			}
		}
	}

	void deleteCategory()
	{
		char dlt[SIZE] = { 0 };

		cout << "Enter the Category name that you want to delete" << endl;
		cin.getline(dlt, SIZE, '\n');
		cout << dlt << endl;


		for (int i = 0; i < 500; i++)																	//delete function
		{
			if (catname[i][0] != 0)
			{

				if (strcmp(dlt, catname[i]) == 0)
				{
					for (int j = 0; j < SIZE; j++)
					{
						catname[i][j] = 0;
						catid[i][j] = 0;
					}
					cout << "Category deleted successfully" << endl;
					break;
				}

			}

			if (i == 499)
			{
				cout << "No such Category found" << endl;
			}
		}
	}

	void saveCategory()
	{
		ofstream cat;

		cat.open("category.txt");

		for (int i = 0; i < 500; i++)
		{

			if (catname[i][0] != 0 && !cat.eof())
			{
				cat << catid[i] << "     " << catname[i] << endl;										//save function
				cout<<"Saving Cat"<<endl;
			}
		}

		cat.close();
	}

	void loadCategory()
	{
		ifstream cat;

		cat.open("category.txt");

		for (int i = 0; i < 500; i++)
		{
			if (catname[i][0] == 0 && !cat.eof())
			{
				cat >> catid[i];
				cin.ignore(5);																		//load function

				cat.getline(catname[i], SIZE, '\n');
			}
		}

		cat.close();
	}

	void getCategory(char category[500][SIZE])
	{
		for (int i = 0; i < 500; i++)
		{
			if (catname[i][0] != 0)
			{																						//getter function
				strcpy(category[i], catname[i]);
			}
		}
	}

	void testprint()
	{
		for (int i = 0; i < 500; i++)
		{
			if (catname[i][0] != 0)
			{
				cout << catname[i] << endl;
			}
		}
	}
};

class Topic : public Category																//class Topic 
{
private:

	char topname[500][SIZE];																	//data members
	char topid[500][SIZE];

public:																						//member functions
	Topic()
	{
		for (int i = 0; i < 500; i++)
		{
			topname[i][0] = 0;																	//default constructor
			topid[i][0] = 0;
		}
	}

	Topic(char name1[500][SIZE], char id1[500][SIZE])
	{
		for (int i = 0; i < 500; i++)
		{
			strcpy(topname[i], name1[i]);														//parameterized constructor
			strcpy(topid[i], id1[i]);
		}
	}

	void addTopic()
	{
		bool namecheck = false;
		bool checkid = false;

		char check[SIZE] = { 0 };
		char idcheck[SIZE] = { 0 };															//add function

		cout << "Enter Topic name that you want to add" << endl;

		cin.getline(check, SIZE, '\n');

		cout << "Enter the Topic id that you want to add" << endl;
		cin >> idcheck;
		cin.ignore(1000, '\n');

		namecheck = checkName(check);

		while (!namecheck)
		{
			cout << "Input is invalid, Enter the Topic name again" << endl;
			cin.getline(check, SIZE, '\n');
			namecheck = checkName(check);
		}

		checkid = idCheck(idcheck);

		while (!checkid)
		{
			cout << "Id entered is invalid , Enter the id again" << endl;
			cin >> idcheck;
			cin.ignore(1000, '\n');
			checkid = idCheck(idcheck);
		}

		for (int i = 0; i < 500; i++)
		{
			if (topname[i][0] == 0)
			{
				strcpy(topname[i], check);
				break;
			}
		}

		for (int i = 0; i < 500; i++)
		{
			if (topid[i][0] == 0)
			{
				strcpy(topid[i], idcheck);
				break;
			}
		}
	}

	void editTopic()
	{
		bool namecheck = false;
		bool idcheck = false;

		char edit[SIZE] = { 0 };
		char editid[SIZE] = { 0 };

		cout << "Enter the Topic name that you want to edit" << endl;
		cin.getline(edit, SIZE, '\n');

		for (int i = 0; i < 500; i++)
		{
			if (topname[i][0] != 0)																//edit function
			{
				if (strcmp(edit, topname[i]) == 0)
				{
					for (int j = 0; j < SIZE; j++)
					{
						topname[i][j] = 0;
						topid[i][j] = 0;
					}

					cout << "Enter the new Topic name that you want to enter" << endl;
					cin.getline(topname[i], SIZE, '\n');

					cout << "Enter the new ID that you want to add" << endl;
					cin >> topid[i];
					cin.ignore(100, '\n');

					namecheck = checkName(topname[i]);
					idcheck = idCheck(topid[i]);

					while (!namecheck)
					{
						cout << "Input is invalid, Enter the Topic name again" << endl;
						cin.getline(topname[i], SIZE);
						namecheck = checkName(topname[i]);
					}

					while (!idcheck)
					{
						cout << "Input is invalid, Enter the topic id again" << endl;
						cin >> topid[i];
						idcheck = idCheck(topid[i]);
					}

					cout << "Topic edited Successfully" << endl;
					break;
				}

				if (i == 499)
				{
					cout << "No such Topic found" << endl;
				}

			}
		}
	}

	void deleteTopic()
	{
		char dlt[SIZE] = { 0 };

		cout << "Enter the Topic name that you want to delete" << endl;
		cin.getline(dlt, SIZE, '\n');
		cout << dlt << endl;																			//delete function


		for (int i = 0; i < 500; i++)
		{
			if (topname[i][0] != 0)
			{

				if (strcmp(dlt, topname[i]) == 0)
				{
					for (int j = 0; j < SIZE; j++)
					{
						topname[i][j] = 0;
						topid[i][j] = 0;
					}
					cout << "Topic deleted successfully" << endl;
					break;
				}

			}

			if (i == 499)
			{
				cout << "No such Topic found" << endl;
			}
		}
	}

	void saveTopic()
	{
		ofstream top;

		top.open("topic.txt");

		for (int i = 0; i < 500; i++)
		{
			//save function
			if (topname[i][0] != 0 && !top.eof())
			{
				top << topid[i] << "     " << topname[i] << endl;
			}
		}

		top.close();
	}

	void loadTopic()
	{
		ifstream top;

		top.open("topic.txt");

		for (int i = 0; i < 500; i++)
		{
			if (topname[i][0] == 0 && !top.eof())
			{
				top >> topid[i];
				cin.ignore(5);																		//load function

				top.getline(topname[i], SIZE, '\n');
			}
		}

		top.close();

	}

	void getTopic(char topic[500][SIZE])
	{
		for (int i = 0; i < 500; i++)
		{
			if (topname[i][0] != 0)
			{																							//getter function
				strcpy(topic[i], topname[i]);
			}
		}
	}
};

class Tags : public Topic																		//class tags 
{

private:
	char tagname[500][SIZE];																		//data members

public:																							//member functions
	Tags()
	{
		for (int i = 0; i < 500; i++)
		{																						//default constructor
			tagname[i][0] = 0;
		}
	}

	Tags(char newName[SIZE][SIZE])
	{
		for (int i = 0; i < 500; i++)
		{
			strcpy(tagname[i], newName[i]);														//parameterized constructor
		}
	}

	void addtag()
	{
		bool namecheck = false;

		char check[SIZE] = { 0 };
		cout << "Enter tag name that you want to add(tags does not have any spaces in them)" << endl;
		cin >> check;

		namecheck = checkName(check);

		while (!namecheck)
		{																						//add function
			cout << "Input is invalid, Enter the tag name again" << endl;
			cin >> check;
			namecheck = checkName(check);
		}

		for (int i = 0; i < 500; i++)
		{
			if (tagname[i][0] == 0)
			{
				strcpy(tagname[i], check);
				break;
			}
		}
	}

	void editTag()
	{
		bool namecheck = false;
		char edit[SIZE] = { 0 };

		cout << "Enter the Tag that you want to edit" << endl;
		cin >> edit;

		for (int i = 0; i < 500; i++)
		{																							//edit function
			if (tagname[i] != 0)
			{
				if (strcmp(edit, tagname[i]) == 0)
				{

					for (int j = 0; j < SIZE; j++)
					{
						tagname[i][j] = 0;
					}

					cout << "Enter the new Tag that you want to enter" << endl;
					cin >> tagname[i];

					namecheck = checkName(tagname[i]);

					while (!namecheck)
					{
						cout << "Input is invalid, Enter the tag name again" << endl;
						cin >> tagname[i];
						namecheck = checkName(tagname[i]);
					}

					cout << "Tag edited Successfully" << endl;
					break;
				}
			}

			if (i == 499)
			{
				cout << "No such tag found" << endl;
			}
		}
	}

	void deleteTag()
	{
		char dlt[SIZE] = { 0 };

		cout << "Enter the Tag that you want to delete" << endl;
		cin >> dlt;

		for (int i = 0; i < 500; i++)
		{
			if (tagname[i] != 0)
			{
				//delete function
				if (strcmp(dlt, tagname[i]) == 0)
				{
					for (int j = 0; j < SIZE; j++)
					{
						tagname[i][j] = 0;
					}
					cout << "Tag deleted successfully" << endl;
					break;
				}

			}

			if (i == 499)
			{
				cout << "No such tag found" << endl;
			}
		}
	}

	void saveTags()
	{
		ofstream tags;

		tags.open("tags.txt", ios::out);

		for (int i = 0; i < 500; i++)
		{
			if (tagname[i][0] != 0 && !tags.eof())															//save function
			{
				tags << tagname[i] << endl;
			}
		}

		tags.close();
	}

	void loadTags()
	{
		ifstream tags;

		tags.open("tags.txt", ios::in);

		for (int i = 0; i < 500; i++)
		{
			if (tagname[i][0] == 0 && !tags.eof())																//load function
			{
				tags >> tagname[i];
			}
		}

		tags.close();

	}

	void getTags(char tags[500][SIZE])
	{
		for (int i = 0; i < 500; i++)
		{
			if (tagname[i][0] != 0)
			{
				strcpy(tags[i], tagname[i]);																//getter function
			}
		}
	}
};

class Document : public Tags																			//class document
{
protected:
	char docName[500][SIZE];
	char docCat[500][SIZE];
	char docTopic[500][SIZE];																			//data members
	char docTags[500][20][SIZE];

public:																									//member functions

	Document()
	{
		for (int i = 0; i < 500; i++)
		{																								//default constructor
			for (int j = 0; j < SIZE; j++)
			{
				if (j < 20)
				{
					for (int k = 0; k < SIZE; k++)
					{
						docTags[i][j][k] = 0;
					}
				}

				docName[i][j] = 0;
				docCat[i][j] = 0;
				docTopic[i][j] = 0;
			}
		}
	}

	Document(char name[500][SIZE], char catname[500][SIZE], char topicname[500][SIZE], char tagname[500][20][SIZE])
	{
		for (int i = 0; i < 500; i++)
		{
			for (int j = 0; j < 20; j++)																//parameterized constructor
			{
				strcpy(docTags[i][j], tagname[i][j]);
			}

			strcpy(docName[i], name[i]);
			strcpy(docCat[i], catname[i]);
			strcpy(docTopic[i], topicname[i]);
		}
	}

	void addDoc()
	{
		char catList[500][SIZE] = { {0} };
		getCategory(catList);

		char check[SIZE] = { 0 };
		bool valid = true;

		cout << "Enter the Doc Name that you want to add" << endl;
		cin.getline(check, SIZE, '\n');																		//add function

		valid = checkName(check);

		while (!valid)
		{
			cout << "Entered name is invalid, enter again" << endl;
			cin.getline(check, SIZE, '\n');
			valid = checkName(check);
		}

		for (int i = 0; i < 500; i++)
		{
			if (docName[i][0] == 0)
			{
				strcpy(docName[i], check);
				break;
			}
		}

		cout << "Enter the Topic of this Doc" << endl;
		cin.getline(check, SIZE, '\n');

		for (int i = 0; i < 500; i++)
		{
			if (docTopic[i][0] == 0)
			{
				strcpy(docTopic[i], check);
				break;
			}
		}

		bool catCheck = false;

		cout << "Enter the Category of this Document" << endl;
		cin.getline(check, SIZE, '\n');

		for (int i = 0; i < 500; i++)
		{
			if (strcmp(check, catList[i]) == 0)
			{
				catCheck = true;
				break;
			}

			if (i == 499)
			{
				cout << "No Such category exists in system" << endl;
				cout << "Enter the Category again" << endl;
				cin.getline(check, SIZE, '\n');

				i = -1;
			}

		}

		if (catCheck == true)
		{
			for (int i = 0; i < 500; i++)
			{
				if (docCat[i][0] == 0)
				{
					strcpy(docCat[i], check);
					break;
				}
			}
		}

		int num = 0;

		cout << "Enter the number of tags that you want to enter for this document in tag,tag,tag,....tag, format" << endl;
		cin >> num;
		cin.ignore(1000, '\n');

		for (int i = 0; i < 500; i++)
		{
			if (docTags[i][0][0] == 0)
			{
				for (int j = 0; j < num; j++)
				{
					cin.getline(docTags[i][j], SIZE, ',');
				}

				break;
			}
		}



	}

	void editDoc()
	{
		char catList[500][SIZE] = { {0} };
		getCategory(catList);

		char name[SIZE] = { 0 };
		bool valid = true;

		cout << "Enter the name of document that you want to edit" << endl;
		cin.getline(name, SIZE, '\n');

		for (int i = 0; i < 500; i++)																			//edit function
		{
			if (docName[i][0] != 0)
			{
				if (strcmp(docName[i], name) == 0)
				{
					cout << "Enter the document name that you want to add" << endl;
					cin.getline(docName[i], SIZE, '\n');

					valid = checkName(docName[i]);

					while (!valid)
					{
						cout << "Entered name is invalid, enter again" << endl;
						cin.getline(docName[i], SIZE, '\n');
						valid = checkName(docName[i]);
					}

					cout << "Enter the topic of the Document" << endl;
					cin.getline(docTopic[i], SIZE, '\n');

					cout << "Enter the Category of this Document" << endl;
					cin.getline(docCat[i], SIZE, '\n');

					for (int j = 0; j < 500; j++)
					{
						if (strcmp(docCat[i], catList[j]) == 0)
						{
							break;
						}

						if (j == 499)
						{
							cout << "No Such category exists in system" << endl;
							cout << "Enter the Category again" << endl;
							cin.getline(docCat[i], SIZE, '\n');

							j = -1;
						}

					}

					int num = 0;

					cout << "Enter the number of tags that you want to enter for this document" << endl;
					cin >> num;
					cin.ignore(1000, '\n');

					for (int j = 0; j < num; j++)
					{
						cin.getline(docTags[i][j], SIZE, ',');
					}

					cin.ignore('\n');

					break;


				}
			}
		}
	};

	void  deleteDoc()
	{
		char name[SIZE] = { 0 };
		bool valid = true;

		cout << "Enter the name of document that you want to delete" << endl;
		cin.getline(name, SIZE, '\n');

		for (int i = 0; i < 500; i++)																			//delete function
		{
			if (docName[i][0] != 0)
			{
				if (strcmp(docName[i], name) == 0)
				{
					for (int j = 0; j < SIZE; j++)
					{
						docName[i][j] = 0;
						docTopic[i][j] = 0;
						docCat[i][j] = 0;
					}

					for (int j = 0; j < 20; j++)
					{
						for (int k = 0; k < SIZE; k++)
						{
							docTags[i][j][k] = 0;
						}
					}

				}
			}
		}
	};

	void saveDoc()
	{
		ofstream doc;
		doc.open("document.txt");

		for (int i = 0; i < 500; i++)
		{
			if (docName[i][0] != 0)
			{
				doc << docName[i] << " , " << docTopic[i] << " , " << docCat[i] << endl;
				for (int j = 0; j < 20; j++)
				{
					if (docTags[i][j][0] != 0)																//save function
					{
						doc << docTags[i][j] << " , ";
					}
				}
				doc << endl;
			}
		}

		doc.close();
	};

	void loadDoc()
	{
		ifstream doc;
		doc.open("document.txt");

		for (int i = 0; i < 500; i++)
		{
			if (!doc.eof())
			{
				if (docName[i][0] == 0)
				{
					doc.getline(docName[i], SIZE, ' ');
					cin.ignore(2, ' ');																		//load function

					doc.getline(docTopic[i], SIZE, ' ');
					cin.ignore(2, ' ');

					doc.getline(docCat[i], SIZE, ' ');
					cin.ignore(2, ' ');

					for (int j = 0; j < 20; j++)
					{
						if (docTags[i][j][0] == 0)
						{
							doc.getline(docTags[i][j], SIZE, ' ');
							cin.ignore(2, ' ');
						}
					}
				}
			}
			else
			{
				break;
			}
		}

		doc.close();
	};

	void print() {
		cout << " All  Documents in the System Are Printed Below " << endl;
		cout << " Categories \t \t  Tags \t \t Topics \t \t Name " << endl;
		cout << endl;
		for (int i = 0; i < 500; i++)
		{																								//print function
			for (int j = 0; j < SIZE/* or 1 */; j++)
			{
				cout << docCat[i][j] << "\t\t" << docTags[i][j] << "\t\t" << docTopic[i][j] << "\t\t" << docName[i][j];
				cout << endl;
			}
			break;

		}

	}
};

//main function
int main()
{
	cout << endl << "**************** WELCOME TO DOCUMENT MANAGEMENT SYSTEM ****************" << endl;
	cout << endl;
	int option, suboption;
	char choice;																					//initialization
g:;
	cout << "Choose  the option from (1-4) " << endl;
	cout << "Press 1 for Category Management  " << endl;
	cout << "Press 2 for Tags Management  " << endl;													//options for management
	cout << "Press 3 for Topics Management " << endl;
	cout << "Press 4 for Document Mangement " << endl;
	cin >> option;
	switch (option)
	{
	case 1:																								//case 1 for categories
	{
		cout << endl;

		cout << "Press 1 for Adding Category " << endl;
		cout << "Press 2 for deleting Category " << endl;
		cout << "Press 3 for Editing Category " << endl;
		cout << "Press 4 for Loading Categories " << endl;
		cout << "Press 5 for Saving Categories " << endl;
		cout << "Press 6 for Printing Categories " << endl;
		cin >> suboption;
		Category c1;																					//object
		cin.ignore();
		if (suboption == 1)
		{
			c1.addCategory();
		}
		else if (suboption == 2)
		{
			c1.deleteCategory();
		}
		else if (suboption == 3)
		{
			c1.editCategory();																			//calling class
		}
		else if (suboption == 4)
		{
			c1.loadCategory();
		}
		else if (suboption == 5)
		{
			c1.saveCategory();
		}
		else if (suboption == 6)
		{
			c1.testprint();
		}
		else
		{
			cout << "Invalid Choice " << endl;
			cout << "Note : Press Only a Number between 1-6" << endl;										//for invalid inputs
		}
		cout << "Do you Want to Exit the Program Press Y/N" << endl;
		cin >> choice;
		if (choice == 'N' || choice == 'n')
			goto g;
		else if (choice = 'Y' || choice == 'y')
			break;
		else
			cout << "Invalid Choice" << endl;
	}
	case 2:																						//case 2 for tags
	{
		cout << endl;

		cout << "Press 1 for Adding Tag " << endl;
		cout << "Press 2 for deleting Tag " << endl;
		cout << "Press 3 for Editing Tag " << endl;
		cout << "Press 4 for Loading Tags " << endl;
		cout << "Press 5 for Saving Tags " << endl;

		cin >> suboption;
		cin.ignore();
		Tags t1;																			//object
		if (suboption == 1)
		{
			t1.addtag();
		}
		else if (suboption == 2)
		{
			t1.deleteTag();
		}
		else if (suboption == 3)
		{
			t1.editTag();																			//calling classes
		}
		else if (suboption == 4)
		{
			t1.loadTags();
		}
		else if (suboption == 5)
		{
			t1.saveTags();
		}

		else
		{
			cout << "Invalid Choice " << endl;
			cout << "Note : Press Only a Number between 1-5" << endl;
		}																							//for invalid input
		cout << "Do you Want to Exit the Program Press Y/N" << endl;
		cin >> choice;
		if (choice == 'N' || choice == 'n')
			goto g;
		else if (choice = 'Y' || choice == 'y')
			break;
		else
			cout << "Invalid Choice" << endl;
	}
	case 3:																							//case 3
	{
		cout << endl;

		cout << "Press 1 for Adding Topic " << endl;
		cout << "Press 2 for deleting Topic " << endl;
		cout << "Press 3 for Editing Topic " << endl;
		cout << "Press 4 for Loading Topic " << endl;
		cout << "Press 5 for Saving Topic " << endl;
		cin >> suboption;
		Topic t1;																						//object
		cin.ignore();
		if (suboption == 1)
		{
			t1.addTopic();
		}
		else if (suboption == 2)
		{
			t1.deleteTopic();
		}
		else if (suboption == 3)
		{
			t1.editTopic();																			//calling class
		}
		else if (suboption == 4)
		{
			t1.loadTopic();
		}
		else if (suboption == 5)
		{
			t1.saveTopic();
		}
		else
		{
			cout << "Invalid Choice " << endl;
			cout << "Note : Press Only a Number between 1-6" << endl;										//invalid input
		}
		cout << "Do you Want to Exit the Program Press Y/N" << endl;
		cin >> choice;
		if (choice == 'N' || choice == 'n')
			goto g;
		else if (choice = 'Y' || choice == 'y')
			break;
		else
			cout << "Invalid Choice" << endl;
	}
	case 4:																								//case 4
		cout << endl << endl;
		cout << "Press 1 for Adding Document " << endl;
		cout << "Press 2 for deleting Document " << endl;
		cout << "Press 3 for Editing Document " << endl;
		cout << "Press 4 for Loading Documents " << endl;
		cout << "Press 5 for Saving Documents " << endl;
		cout << "Press 6 for Printing Documents " << endl;
		cin >> suboption;
		Document d1;																					//object
		cin.ignore();
		if (suboption == 1)
		{
			d1.addDoc();
		}
		else if (suboption == 2)
		{
			d1.deleteDoc();
		}
		else if (suboption == 3)
		{
			d1.editDoc();
		}
		else if (suboption == 4)
		{
			d1.loadDoc();																				//calling class
		}
		else if (suboption == 5)
		{
			d1.saveDoc();
		}
		else if (suboption == 6)
		{
			d1.print();
		}
		else
		{
			cout << "Invalid Choice " << endl;
			cout << "Note : Press Only a Number between 1-6" << endl;
		}
		cout << "Do you Want to Exit the Program Press Y/N" << endl;
		cin >> choice;																						//invalid input
		if (choice == 'N' || choice == 'n')
			goto g;
		else if (choice = 'Y' || choice == 'y')
			break;
		else
			cout << "Invalid Choice" << endl;
	}

}
