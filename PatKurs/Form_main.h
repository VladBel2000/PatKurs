#pragma once
#include "Navigator.h"
#include "Device.h"
#include "Real_Device.h"
#include "Type_move.h"
#include "Types_moves.h"
#include "Proxy_Device.h"
#include "Adapter.h"
#include "Device_traffic_Wrapper.h"


namespace PatKurs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;
	//vector<Node> list_node;					// Список исходных вершин
	//vector<Node> list_way;					// Список вершин найденного пути
	bool flag_green_way = false;			// Флаг для отрисовки
	bool way_find = false;					// Флаг для пометки найденного пути
	/// <summary>
	/// Сводка для Form_main
	/// </summary>
	public ref class Form_main : public System::Windows::Forms::Form
	{
	public:
		Form_main(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form_main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_list_point;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label_start_point;
	private: System::Windows::Forms::Label^ label_finish_point;
	private: System::Windows::Forms::Button^ button_find_way;
	private: System::Windows::Forms::Label^ label_type_move;
	private: System::Windows::Forms::PictureBox^ pictureBox_map;
	private: System::Windows::Forms::ComboBox^ comboBox_type_move;




	private: System::Windows::Forms::DataGridView^ dataGridView_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_x;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_y;
	private: System::Windows::Forms::ComboBox^ comboBox_start;
	private: System::Windows::Forms::ComboBox^ comboBox_finish;
	private: System::Windows::Forms::Label^ label_type;
	private: System::Windows::Forms::Label^ label_speed;
	private: System::Windows::Forms::Label^ label_time;
	private: System::Windows::Forms::TextBox^ textBox_type;
	private: System::Windows::Forms::TextBox^ textBox_speed;
	private: System::Windows::Forms::TextBox^ textBox_time;
	private: System::Windows::Forms::Label^ label_length;
	private: System::Windows::Forms::TextBox^ textBox_length;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label_list_point = (gcnew System::Windows::Forms::Label());
			this->label_start_point = (gcnew System::Windows::Forms::Label());
			this->label_finish_point = (gcnew System::Windows::Forms::Label());
			this->button_find_way = (gcnew System::Windows::Forms::Button());
			this->label_type_move = (gcnew System::Windows::Forms::Label());
			this->pictureBox_map = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox_type_move = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView_table = (gcnew System::Windows::Forms::DataGridView());
			this->Column_number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_x = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBox_start = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_finish = (gcnew System::Windows::Forms::ComboBox());
			this->label_type = (gcnew System::Windows::Forms::Label());
			this->label_speed = (gcnew System::Windows::Forms::Label());
			this->label_time = (gcnew System::Windows::Forms::Label());
			this->textBox_type = (gcnew System::Windows::Forms::TextBox());
			this->textBox_speed = (gcnew System::Windows::Forms::TextBox());
			this->textBox_time = (gcnew System::Windows::Forms::TextBox());
			this->label_length = (gcnew System::Windows::Forms::Label());
			this->textBox_length = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_map))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_table))->BeginInit();
			this->SuspendLayout();
			// 
			// label_list_point
			// 
			this->label_list_point->AutoSize = true;
			this->label_list_point->Location = System::Drawing::Point(741, 217);
			this->label_list_point->Name = L"label_list_point";
			this->label_list_point->Size = System::Drawing::Size(87, 13);
			this->label_list_point->TabIndex = 0;
			this->label_list_point->Text = L"Список пунктов";
			// 
			// label_start_point
			// 
			this->label_start_point->AutoSize = true;
			this->label_start_point->Location = System::Drawing::Point(739, 76);
			this->label_start_point->Name = L"label_start_point";
			this->label_start_point->Size = System::Drawing::Size(89, 13);
			this->label_start_point->TabIndex = 1;
			this->label_start_point->Text = L"Исходный пункт";
			// 
			// label_finish_point
			// 
			this->label_finish_point->AutoSize = true;
			this->label_finish_point->Location = System::Drawing::Point(739, 119);
			this->label_finish_point->Name = L"label_finish_point";
			this->label_finish_point->Size = System::Drawing::Size(99, 13);
			this->label_finish_point->TabIndex = 2;
			this->label_finish_point->Text = L"Пункт назначения";
			// 
			// button_find_way
			// 
			this->button_find_way->Location = System::Drawing::Point(742, 161);
			this->button_find_way->Name = L"button_find_way";
			this->button_find_way->Size = System::Drawing::Size(75, 23);
			this->button_find_way->TabIndex = 3;
			this->button_find_way->Text = L"Поиск";
			this->button_find_way->UseVisualStyleBackColor = true;
			this->button_find_way->Click += gcnew System::EventHandler(this, &Form_main::button_find_way_Click);
			// 
			// label_type_move
			// 
			this->label_type_move->AutoSize = true;
			this->label_type_move->Location = System::Drawing::Point(739, 34);
			this->label_type_move->Name = L"label_type_move";
			this->label_type_move->Size = System::Drawing::Size(121, 13);
			this->label_type_move->TabIndex = 4;
			this->label_type_move->Text = L"Способ передвижения";
			// 
			// pictureBox_map
			// 
			this->pictureBox_map->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox_map->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox_map->Location = System::Drawing::Point(5, 5);
			this->pictureBox_map->Name = L"pictureBox_map";
			this->pictureBox_map->Size = System::Drawing::Size(650, 650);
			this->pictureBox_map->TabIndex = 5;
			this->pictureBox_map->TabStop = false;
			this->pictureBox_map->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form_main::pictureBox_map_Paint);
			// 
			// comboBox_type_move
			// 
			this->comboBox_type_move->FormattingEnabled = true;
			this->comboBox_type_move->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Car", L"Bicycle", L"Walk", L"Sport walk" });
			this->comboBox_type_move->Location = System::Drawing::Point(867, 31);
			this->comboBox_type_move->Name = L"comboBox_type_move";
			this->comboBox_type_move->Size = System::Drawing::Size(121, 21);
			this->comboBox_type_move->TabIndex = 6;
			// 
			// dataGridView_table
			// 
			this->dataGridView_table->AllowUserToAddRows = false;
			this->dataGridView_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column_number,
					this->Column_name, this->Column_x, this->Column_y
			});
			this->dataGridView_table->Location = System::Drawing::Point(742, 245);
			this->dataGridView_table->Name = L"dataGridView_table";
			this->dataGridView_table->ReadOnly = true;
			this->dataGridView_table->Size = System::Drawing::Size(445, 150);
			this->dataGridView_table->TabIndex = 10;
			// 
			// Column_number
			// 
			this->Column_number->HeaderText = L"Номер";
			this->Column_number->Name = L"Column_number";
			this->Column_number->ReadOnly = true;
			this->Column_number->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_number->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column_number->Width = 101;
			// 
			// Column_name
			// 
			this->Column_name->HeaderText = L"Название";
			this->Column_name->Name = L"Column_name";
			this->Column_name->ReadOnly = true;
			this->Column_name->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Column_x
			// 
			this->Column_x->HeaderText = L"X";
			this->Column_x->Name = L"Column_x";
			this->Column_x->ReadOnly = true;
			this->Column_x->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_x->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column_x->Width = 101;
			// 
			// Column_y
			// 
			this->Column_y->HeaderText = L"Y";
			this->Column_y->Name = L"Column_y";
			this->Column_y->ReadOnly = true;
			this->Column_y->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column_y->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// comboBox_start
			// 
			this->comboBox_start->FormattingEnabled = true;
			this->comboBox_start->Location = System::Drawing::Point(867, 73);
			this->comboBox_start->Name = L"comboBox_start";
			this->comboBox_start->Size = System::Drawing::Size(121, 21);
			this->comboBox_start->TabIndex = 11;
			// 
			// comboBox_finish
			// 
			this->comboBox_finish->FormattingEnabled = true;
			this->comboBox_finish->Location = System::Drawing::Point(867, 119);
			this->comboBox_finish->Name = L"comboBox_finish";
			this->comboBox_finish->Size = System::Drawing::Size(121, 21);
			this->comboBox_finish->TabIndex = 12;
			// 
			// label_type
			// 
			this->label_type->AutoSize = true;
			this->label_type->Location = System::Drawing::Point(736, 437);
			this->label_type->Name = L"label_type";
			this->label_type->Size = System::Drawing::Size(124, 13);
			this->label_type->TabIndex = 13;
			this->label_type->Text = L"Способ передвижения:";
			// 
			// label_speed
			// 
			this->label_speed->AutoSize = true;
			this->label_speed->Location = System::Drawing::Point(739, 472);
			this->label_speed->Name = L"label_speed";
			this->label_speed->Size = System::Drawing::Size(58, 13);
			this->label_speed->TabIndex = 14;
			this->label_speed->Text = L"Скорость:";
			// 
			// label_time
			// 
			this->label_time->AutoSize = true;
			this->label_time->Location = System::Drawing::Point(739, 541);
			this->label_time->Name = L"label_time";
			this->label_time->Size = System::Drawing::Size(110, 13);
			this->label_time->TabIndex = 15;
			this->label_time->Text = L"Затраченное время:";
			// 
			// textBox_type
			// 
			this->textBox_type->Location = System::Drawing::Point(888, 434);
			this->textBox_type->Name = L"textBox_type";
			this->textBox_type->ReadOnly = true;
			this->textBox_type->Size = System::Drawing::Size(100, 20);
			this->textBox_type->TabIndex = 16;
			// 
			// textBox_speed
			// 
			this->textBox_speed->Location = System::Drawing::Point(888, 472);
			this->textBox_speed->Name = L"textBox_speed";
			this->textBox_speed->ReadOnly = true;
			this->textBox_speed->Size = System::Drawing::Size(100, 20);
			this->textBox_speed->TabIndex = 17;
			// 
			// textBox_time
			// 
			this->textBox_time->Location = System::Drawing::Point(888, 541);
			this->textBox_time->Name = L"textBox_time";
			this->textBox_time->ReadOnly = true;
			this->textBox_time->Size = System::Drawing::Size(100, 20);
			this->textBox_time->TabIndex = 18;
			// 
			// label_length
			// 
			this->label_length->AutoSize = true;
			this->label_length->Location = System::Drawing::Point(741, 508);
			this->label_length->Name = L"label_length";
			this->label_length->Size = System::Drawing::Size(65, 13);
			this->label_length->TabIndex = 19;
			this->label_length->Text = L"Длина пути";
			// 
			// textBox_length
			// 
			this->textBox_length->Location = System::Drawing::Point(888, 508);
			this->textBox_length->Name = L"textBox_length";
			this->textBox_length->ReadOnly = true;
			this->textBox_length->Size = System::Drawing::Size(100, 20);
			this->textBox_length->TabIndex = 20;
			// 
			// Form_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1400, 703);
			this->Controls->Add(this->textBox_length);
			this->Controls->Add(this->label_length);
			this->Controls->Add(this->textBox_time);
			this->Controls->Add(this->textBox_speed);
			this->Controls->Add(this->textBox_type);
			this->Controls->Add(this->label_time);
			this->Controls->Add(this->label_speed);
			this->Controls->Add(this->label_type);
			this->Controls->Add(this->comboBox_finish);
			this->Controls->Add(this->comboBox_start);
			this->Controls->Add(this->dataGridView_table);
			this->Controls->Add(this->comboBox_type_move);
			this->Controls->Add(this->pictureBox_map);
			this->Controls->Add(this->label_type_move);
			this->Controls->Add(this->button_find_way);
			this->Controls->Add(this->label_finish_point);
			this->Controls->Add(this->label_start_point);
			this->Controls->Add(this->label_list_point);
			this->Name = L"Form_main";
			this->Text = L"Навигатор";
			this->Load += gcnew System::EventHandler(this, &Form_main::Form_main_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_map))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form_main_Load(System::Object^ sender, System::EventArgs^ e) 
	{		
		read_info();
		read_neighbors();
	}

	// Читаем основную информацию о пунктах. Заполняем таблицу.
	public: void read_info()
	{
		String^ FileName = "C:\\Users\\belom\\OneDrive\\Рабочий стол\\Vlad\\Корней Курсач\\PatKurs\\PatKurs\\info.txt";
		StreamReader^ file = File::OpenText(FileName);
		String^ now_string = file->ReadLine();
		
		for (int i = 0; now_string != nullptr; i++)
		{
			int start = 0, finish = 0, count_words = 0;
			String^ help;
			string my_words;
			vector <string> list_words;
			for (int j = 0; j < now_string->Length; j++)
			{
				// Если слово закончилось
				if (now_string[j] == ' ' || now_string[j] == '\0')
				{
					finish = j;
					help = now_string->Remove(finish);
					help = help->Substring(start);
					for (int w = 0; w < help->Length; w++)
						my_words += (char)help[w];
					list_words.push_back(my_words);
					my_words = "";
					start = finish + 1;
				}
			}
			help = now_string;
			help = help->Substring(start);
			for (int w = 0; w < help->Length; w++)
				my_words += (char)help[w];
			list_words.push_back(my_words);
			my_words = "";
			// Заносим строку в таблицу
			dataGridView_table->Rows->Add(i + 1, gcnew String(list_words[0].c_str()), gcnew String(list_words[1].c_str()), gcnew String(list_words[2].c_str()));
			Node now_node = Node(list_words[0], stoi(list_words[1]), stoi(list_words[2]));
			Navigator::getInstance()->list_node.push_back(now_node);
			now_string = file->ReadLine();
		}
		// Обновляем ComboBox
		for (int i = 0; i < dataGridView_table->RowCount; i++)
		{
			this->comboBox_start->Items->AddRange(gcnew cli::array< System::Object^  >(1) { dataGridView_table->Rows[i]->Cells[1]->Value->ToString() });
			this->comboBox_finish->Items->AddRange(gcnew cli::array< System::Object^  >(1) { dataGridView_table->Rows[i]->Cells[1]->Value->ToString() });
		}
	}
	// Считываем и заполняем соседей каждого пункта
	public: void read_neighbors()
	{
		String^ FileName = "C:\\Users\\belom\\OneDrive\\Рабочий стол\\Vlad\\Корней Курсач\\PatKurs\\PatKurs\\way.txt";
		StreamReader^ file = File::OpenText(FileName);
		String^ now_string = file->ReadLine();

		for (int i = 0; now_string != nullptr; i++)
		{
			int start = 0, finish = 0, count_words = 0;
			String^ help;
			string my_words;
			vector <int> list_points;
			for (int j = 0; j < now_string->Length; j++)
			{
				// Если слово закончилось
				if (now_string[j] == ' ' || now_string[j] == '\0')
				{
					finish = j;
					help = now_string->Remove(finish);
					help = help->Substring(start);
					for (int w = 0; w < help->Length; w++)
						my_words += (char)help[w];
					list_points.push_back(stoi(my_words));
					my_words = "";
					start = finish + 1;
				}
			}
			help = now_string;
			help = help->Substring(start);
			for (int w = 0; w < help->Length; w++)
				my_words += (char)help[w];
			list_points.push_back(stoi(my_words));
			my_words = "";
			// Первой вершине добавляем вторую вершину как соседа
			Navigator::getInstance()->list_node[list_points[0] - 1].add_neighbors(&(Navigator::getInstance()->list_node[list_points[1] - 1 ] ) );
			// Второй вершине добавялем первую вершину как соседа
			Navigator::getInstance()->list_node[list_points[1] - 1].add_neighbors(&(Navigator::getInstance()->list_node[list_points[0] - 1 ] ) );

			now_string = file->ReadLine();
		}
	}
	private: System::Void pictureBox_map_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{

		System::Drawing::Font^ fn = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 12.0F, FontStyle::Bold);
		System::Drawing::SolidBrush^ br = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
		for (int i = 0; i < Navigator::getInstance()->list_node.size(); i++)
		{
			int x_1 = Navigator::getInstance()->list_node[i].get_x();
			int y_1 = Navigator::getInstance()->list_node[i].get_y();
			vector<Node*> help_vector_neighbors = Navigator::getInstance()->list_node[i].get_vector_neighbors();
			for (int j = 0; j < help_vector_neighbors.size(); j++)
			{
				int x_2 = help_vector_neighbors[j]->get_x();
				int y_2 = help_vector_neighbors[j]->get_y();

				// Рисуем линии
				Pen^ p = gcnew Pen(Color::Orange, 2.0f);
				Point pt1 = Point(x_1, y_1);
				Point pt2 = Point(x_2, y_2);
				e->Graphics->DrawLine(p, pt1, pt2);

				// Отмечаем пункт красной точкой
				e->Graphics->FillEllipse(Brushes::Red, x_1 - 3, y_1 - 3, 8, 8);

				// Подписываем пункт
				String^ name = gcnew System::String(Navigator::getInstance()->list_node[i].get_name().c_str());
				e->Graphics->DrawString(name, fn, br, x_1, y_1);
			}
		}
		if(flag_green_way)
		{
			// Закрашиваем найденный путь
			for (int i = 0; i < Navigator::getInstance()->list_way.size() - 1; i++)
			{
				int x_1 = Navigator::getInstance()->list_way[i].get_x();
				int y_1 = Navigator::getInstance()->list_way[i].get_y();
				int x_2 = Navigator::getInstance()->list_way[i + 1].get_x();
				int y_2 = Navigator::getInstance()->list_way[i + 1].get_y();

				// Рисуем линии
				Graphics^ g = pictureBox_map->CreateGraphics();
				Pen^ p = gcnew Pen(Color::Green, 3.0f);
				Point pt1 = Point(x_1, y_1);
				Point pt2 = Point(x_2, y_2);
				e->Graphics->DrawLine(p, pt1, pt2);
			}
		}
	}
	private: System::Void button_find_way_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Отчищаем все поля
		textBox_type->Text = "";
		textBox_speed->Text = "";
		textBox_time->Text = "";
		textBox_length->Text = "";
		// Читаем тип передвижения
		string type_move;
		for (int i = 0; i < comboBox_type_move->Text->Length; i++)
			type_move += (char)comboBox_type_move->Text[i];

		// Создаём устройство
		Real_Device* dv_real;
		Proxy_Device* dv_proxy;
		int now_speed_const = 0;

		// Если спортсмен (Adapter)
		if (type_move == "Sport walk")
		{
			Special_Walk* human_sport = new Special_Walk();
			Device* device_sport = new Adapter(human_sport);
			int speed = device_sport->get_rez();

			// Вычисляем сложности пути - скорость уменьшается
			Device* decorator1 = new Device_traffic_Wrapper(device_sport);
			int traffic = decorator1->get_rez();

			now_speed_const = device_sport->get_rez(); -traffic;
		}
		else
		{
			// Если deafault
			if (type_move.size() == 0)
				dv_real = new Real_Device();
			else
				dv_real = new Real_Device(type_move);
			dv_real->set_speed(dv_real->get_rez());

			// Вычисляем сложности пути - скорость уменьшается
			Device* decorator1 = new Device_traffic_Wrapper(dv_real);
			int traffic = decorator1->get_rez();
			dv_real->set_speed(dv_real->get_speed() - traffic);

			Proxy_Device* dv_proxy = new Proxy_Device();
			dv_proxy->initDevice(dv_real);

			now_speed_const = dv_proxy->get_rez();
		}


		// Отчищаем список путей
		Navigator::getInstance()->list_way.clear();

		// Закрашиваем пути в исходный цвет
		flag_green_way = false;
		pictureBox_map->Refresh();

		// Получаем имена исходного и конечного пункта
		string name_start, name_finish;
		for (int i = 0; i < comboBox_start->Text->Length; i++)
			name_start += (char)comboBox_start->Text[i];
		for (int i = 0; i < comboBox_finish->Text->Length; i++)
			name_finish += (char)comboBox_finish->Text[i];
		
		Node start_node, finish_node;
		// Ищем начальную точку
		for (int i = 0; i < Navigator::getInstance()->list_node.size(); i++)
		{
			if (Navigator::getInstance()->list_node[i].get_name() == name_start)
			{
				start_node = Navigator::getInstance()->list_node[i];
			}
			if (Navigator::getInstance()->list_node[i].get_name() == name_finish)
			{
				finish_node = Navigator::getInstance()->list_node[i];
			}
		}
		way_find = false;
		find_way_rec(&start_node, finish_node);
		if (Navigator::getInstance()->list_way[Navigator::getInstance()->list_way.size() - 1].get_name() != finish_node.get_name())
		{
			Navigator::getInstance()->list_way.clear();
			string msg = "Путь из пункта '" + name_start + "' в пункт '" + name_finish + "' не найден";
			String^ msg_rez = gcnew String(msg.c_str());
			MessageBox::Show(msg_rez, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		// Перерисовываем карту
		if (Navigator::getInstance()->list_way.size() != 0)
		{
			flag_green_way = true;
			pictureBox_map->Refresh();
		}

		// Выводим полученные данные
		// Тип транспорта
		String^ type_move_text = gcnew String(type_move.c_str());
		textBox_type->Text = type_move_text;
		
		// Скорость
		string now_speed = to_string(now_speed_const);
		String^ speed_text = gcnew String(now_speed.c_str());
		textBox_speed->Text = speed_text;

		// Длина пути
		int length = Navigator::getInstance()->find_length();
		string now_length = to_string(length);
		String^ length_text = gcnew String(now_length.c_str());
		textBox_length->Text = length_text;

		// Время
		int time = length / now_speed_const;
		string now_time = to_string(time);
		String^ time_text = gcnew String(now_time.c_str());
		textBox_time->Text = time_text;

	}
	// Поиск путей
	 Boolean find_way_rec(Node* node_now, Node node_finish)
	 {
		 // Если уже нашли путь
		 if (way_find)
		 {
			 return true;
		 }
		 // Если дошли до конечной вершины
		 if (node_now->get_name() == node_finish.get_name())
		 {
			 Navigator::getInstance()->list_way.push_back(*node_now);
			 way_find = true;
			 return true;
		 }
		 // Если попали в цикл
		 bool have_cycle = false;
		 for (int i = 0; i < Navigator::getInstance()->list_way.size(); i++)
		 {
			 if (Navigator::getInstance()->list_way[i].get_name() == node_now->get_name())
				 have_cycle = true;
		 }
		 if (have_cycle)
		 {
			 //list_way.pop_back();
			 return true;
		 }
		 Navigator::getInstance()->list_way.push_back(*node_now);
		 for (int i = 0; i < node_now->get_vector_neighbors().size(); i++)
		 {
			 Boolean rez = find_way_rec(node_now->get_vector_neighbors()[i], node_finish);
			 if(!rez)
				 Navigator::getInstance()->list_way.pop_back();
		 }
		 if (node_now->get_name() != node_finish.get_name() && node_now->get_vector_neighbors().size() == 1)
			 return false;
		 return true;
	 }
};
}
