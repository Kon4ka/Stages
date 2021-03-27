#pragma once
#include "Portfolio_Elem.h"
#include <msclr\marshal_cppstd.h>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <stdlib.h>
#include <algorithm>

void MarshalString(System::String^ s, std::string& os);
std::vector<P_Elem> search(std::vector<P_Elem> elements, std::string param, bool (*comp)(P_Elem, std::string));


std::vector <P_Elem> elements;
namespace Company8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;

	private: int search_choise = 0;
	private: int sort_choise = 0;
	private: String^ name_to_delete = "\0";

	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;





	 

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(26, 560);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(538, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(93, 586);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(395, 35);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Add New";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(731, 539);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(268, 61);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Save to File";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(18, 54);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(145, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(199, 36);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(95, 40);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Delete Element";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Delete by Title:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(26, 60);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(538, 328);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Search Result:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ID", L"Title", L"Number of objects", L"Cost",
					L"Payer"
			});
			this->comboBox1->Location = System::Drawing::Point(70, 19);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 10;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Search by:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(359, 54);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 12;
			this->button4->Text = L"Search!";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 531);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(370, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Add new element, enter data with current form: ID, Title, Number, Cost, Payer";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->richTextBox2);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Location = System::Drawing::Point(579, 60);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(440, 328);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Searching";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(7, 106);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(427, 216);
			this->richTextBox2->TabIndex = 15;
			this->richTextBox2->Text = L"";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(15, 60);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(52, 13);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Parametr:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(70, 57);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(267, 20);
			this->textBox4->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(29, 41);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"ID";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(73, 41);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(27, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Title";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(159, 41);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Number";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(262, 41);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(28, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Cost";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(362, 41);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(34, 13);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Payer";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Location = System::Drawing::Point(469, 398);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(550, 115);
			this->groupBox2->TabIndex = 20;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Sorting";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(157, 76);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(177, 23);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Sort!";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ID", L"Title", L"Number of objects", L"Cost",
					L"Payer"
			});
			this->comboBox2->Location = System::Drawing::Point(98, 30);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(281, 21);
			this->comboBox2->TabIndex = 1;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(34, 33);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(43, 13);
			this->label11->TabIndex = 0;
			this->label11->Text = L"Sort by:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Location = System::Drawing::Point(26, 398);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(413, 115);
			this->groupBox3->TabIndex = 21;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Deleting";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1031, 648);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Company\'s Order Portfolio";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//Init window
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		std::string title, payer;
		std::string id, number, cost;
		//std::ofstream log;
		std::ifstream input_file;
		std::vector <P_Elem> elems;
		

		//log.open("log.txt");
		input_file.open("sourse.txt");		//open file
		try
		{
			if (!input_file.is_open())
			{
				throw "sourse.txt";
			}
		}
		catch (std::string filename)
		{
			exit(1);
		}


		while (!input_file.eof())
		{
			std::string tmp;
			input_file >> id >> title >> number >> cost >> payer;
			P_Elem tmp_s(id, title, number, cost, payer);
			elements.push_back(tmp_s);
			String^ str2 = gcnew String((elements.back().words_to_std_str()).c_str());
			richTextBox1->AppendText(str2);

		}
		richTextBox1->ReadOnly = true;
		richTextBox2->ReadOnly = true;
		input_file.close();
	}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	search_choise = comboBox1->SelectedIndex;
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{
	name_to_delete = textBox2->Text;
}
//Adding
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ tmp;
	P_Elem curr;
	std::string* words = new std::string[5];
	//std::ofstream log;
	//log.open("log.txt");

	tmp = textBox1->Text;
	if (tmp == "")
	{
		MessageBox::Show("Wrong input");
	}

	array<String^>^ ms = tmp->Split(' ');

	if (ms->Length != 5)
	{
		MessageBox::Show("Wrong input");
		return;
	}

	for (int i = 0; i < 5; i++)
		MarshalString(ms[i], words[i]);

	P_Elem s = elements[1];
	elements.push_back(P_Elem(words[0], words[1], words[2], words[3], words[4]));

	//qsort(&elements[0], elements.size(), sizeof(P_Elem), comp_id);

	re_print();

	delete[] words;
}

//Deleting
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	std::string to_del;
	MarshalString(name_to_delete,to_del);
	std::vector<P_Elem>::iterator iter;


	for (iter = elements.begin(); iter != elements.end(); iter++)
	{
		if (iter->Name_to_del(to_del))
		{
			elements.erase(iter);
			re_print();
			break;
		}
	}
}

//Update
void re_print()								
{
	std::vector<P_Elem>::iterator iter;
	richTextBox1->Clear();
	for (iter = elements.begin(); iter != elements.end(); iter++)
	{
		String^ str2 = gcnew String(iter->words_to_std_str().c_str());
		richTextBox1->AppendText(str2);
		richTextBox1->ReadOnly = true;

	}
}

//Searching
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)		
{
	String^ tmp = "0";
	std::string tmp_ss = "0";
	std::vector<P_Elem> res;
	std::vector<P_Elem>::iterator iter;

	tmp = textBox4->Text;
	MarshalString(tmp, tmp_ss); 
	switch (search_choise)
	{
	case(0): res = search(elements, tmp_ss, find_id); break;
	case(1): res = search(elements, tmp_ss, find_title); break;
	case(2): res = search(elements, tmp_ss, find_number); break;
	case(3): res = search(elements, tmp_ss, find_cost); break;
	case(4): res = search(elements, tmp_ss, find_payer); break;
	default: break;
	}
	if (res[0].id == "-1")
	{
		MessageBox::Show("There is no element with this parametr");
		return;
	}

	richTextBox2->Clear();
	for (iter = res.begin(); iter != res.end(); iter++)
	{
		String^ str2 = gcnew String(iter->words_to_std_str().c_str());
		richTextBox2->AppendText(str2);
	}
}

private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	sort_choise = comboBox2->SelectedIndex;
}

//Sorting
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) 
{
	switch (sort_choise)
	{
	case(0): qsort(&elements[0], elements.size(), sizeof(P_Elem), comp_id); break;
	case(1): qsort(&elements[0], elements.size(), sizeof(P_Elem), comp_title); break;
	case(2): qsort(&elements[0], elements.size(), sizeof(P_Elem), comp_number); break;
	case(3): qsort(&elements[0], elements.size(), sizeof(P_Elem), comp_cost); break;
	case(4): qsort(&elements[0], elements.size(), sizeof(P_Elem), comp_payer); break;
	default: break;
	}
	re_print();
}

//Saving to file
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::ofstream output_file;
	std::vector<P_Elem>::iterator iter;

	output_file.open("sourse.txt");		//open file
	try
	{
		if (!output_file.is_open())
		{
			throw "sourse.txt";
		}
	}
	catch (std::string output_file)
	{
		exit(1);
	}
	for (iter = elements.begin(); iter != elements.end(); iter++)
	{
		iter->print_to_file(output_file);
		if (iter != (elements.end() - 1)) output_file << "\n";
	}
}

};
}
void MarshalString(System::String^ s, std::string& os) {
	const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

std::vector<P_Elem> search(std::vector<P_Elem> elements, std::string param, bool (*comp)(P_Elem, std::string))
{
	std::vector<P_Elem> find_elems;
	std::vector<P_Elem>::iterator iter;
	P_Elem err("-1", "-1", "-1", "-1", "-1");
	for (iter = elements.begin(); iter != elements.end(); iter++)
	{
		if (comp(*iter, param))
		{
			find_elems.push_back(*iter);
		}
	}
	if (find_elems.empty())
		find_elems.push_back(err);

	return find_elems;
}

