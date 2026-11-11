#pragma once

namespace casinotest2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Главное окно рулетки
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			balance = StartBalance;
			bid = 0;
			selectedBet = nullptr;
			rng = gcnew Random();

			InitializeComponent();

			// Убираем рамки окна
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;

			// Добавляем обработчики для перетаскивания окна
			this->MouseDown += gcnew MouseEventHandler(this, &MyForm::Form_MouseDown);
			this->MouseMove += gcnew MouseEventHandler(this, &MyForm::Form_MouseMove);
			this->MouseUp += gcnew MouseEventHandler(this, &MyForm::Form_MouseUp);

			// Гифки загружаем один раз, а не на каждый спин
			winImage = LoadGif(L"win.gif");
			loseImage = LoadGif(L"lose.gif");
			noMoneyImage = LoadGif(L"no_money.gif");
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			pictureBox1->Image = nullptr;
			delete winImage;
			delete loseImage;
			delete noMoneyImage;
		}

	private:
		literal int StartBalance = 100;

		int balance;
		int bid;
		// Текст нажатой кнопки ставки: "17", "red", "row1", "1-12"... (nullptr — ставка не выбрана)
		String^ selectedBet;
		Random^ rng;

		Image^ winImage;
		Image^ loseImage;
		Image^ noMoneyImage;

		// Ищет картинку рядом с exe, потом в рабочей папке (так работает и запуск из Visual Studio).
		// Если файла нет — возвращает nullptr, и игра просто идёт без анимации.
		static Image^ LoadGif(String^ fileName)
		{
			String^ path = System::IO::Path::Combine(Application::StartupPath, fileName);
			if (!System::IO::File::Exists(path))
				path = System::IO::Path::Combine(System::IO::Directory::GetCurrentDirectory(), fileName);
			if (!System::IO::File::Exists(path))
				return nullptr;

			try
			{
				return Image::FromFile(path);
			}
			catch (Exception^)
			{
				return nullptr;
			}
		}

		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
			UpdateBalance();
		}

		// Для отслеживания, была ли нажата кнопка мыши для перетаскивания
		bool isMouseDown = false;
		Point mouseOffset;

		// Обработчик для начала перетаскивания окна (только левой кнопкой)
		void Form_MouseDown(Object^ sender, MouseEventArgs^ e)
		{
			if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				isMouseDown = true;
				// Сохраняем смещение относительно верхнего левого угла формы
				mouseOffset = e->Location;
			}
		}

		// Обработчик для перетаскивания окна
		void Form_MouseMove(Object^ sender, MouseEventArgs^ e)
		{
			if (isMouseDown)
			{
				this->Location = Point(this->Location.X + e->X - mouseOffset.X, this->Location.Y + e->Y - mouseOffset.Y);
			}
		}

		// Обработчик для завершения перетаскивания
		void Form_MouseUp(Object^ sender, MouseEventArgs^ e)
		{
			isMouseDown = false;
		}


	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ your_bid_field;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button_zero;
	private: System::Windows::Forms::Button^ button_minus;
	private: System::Windows::Forms::Button^ button_plus;
	private: System::Windows::Forms::Button^ button_half;
	private: System::Windows::Forms::Button^ button1_4;
	private: System::Windows::Forms::Button^ button_all_in;
	private: System::Windows::Forms::Button^ button_minus20;
	private: System::Windows::Forms::Button^ button_plus20;
	private: System::Windows::Forms::Label^ your_balance;
	private: System::Windows::Forms::Label^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button_0;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button_9;

	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button_8;

	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button_16;

	private: System::Windows::Forms::Button^ button_13;
	private: System::Windows::Forms::Button^ button_17;


	private: System::Windows::Forms::Button^ button_14;
	private: System::Windows::Forms::Button^ button_18;



	private: System::Windows::Forms::Button^ button_15;

	private: System::Windows::Forms::Button^ button_10;
	private: System::Windows::Forms::Button^ button_11;
	private: System::Windows::Forms::Button^ button_12;
	private: System::Windows::Forms::Button^ button_25;




	private: System::Windows::Forms::Button^ button_22;
	private: System::Windows::Forms::Button^ button_26;


	private: System::Windows::Forms::Button^ button_23;
	private: System::Windows::Forms::Button^ button_27;


	private: System::Windows::Forms::Button^ button_24;

	private: System::Windows::Forms::Button^ button_19;
	private: System::Windows::Forms::Button^ button_20;
	private: System::Windows::Forms::Button^ button_21;
	private: System::Windows::Forms::Button^ button_34;




	private: System::Windows::Forms::Button^ button_31;
private: System::Windows::Forms::Button^ button_35;


private: System::Windows::Forms::Button^ button_32;
private: System::Windows::Forms::Button^ button_36;


private: System::Windows::Forms::Button^ button_33;

private: System::Windows::Forms::Button^ button_28;
private: System::Windows::Forms::Button^ button_29;
private: System::Windows::Forms::Button^ button_30;



	private: System::Windows::Forms::Button^ button39;
	private: System::Windows::Forms::Button^ button40;
	private: System::Windows::Forms::Button^ button41;
	private: System::Windows::Forms::Button^ button42;
	private: System::Windows::Forms::Button^ button43;
	private: System::Windows::Forms::Button^ button46;
	private: System::Windows::Forms::Button^ button47;
	private: System::Windows::Forms::Button^ button44;
	private: System::Windows::Forms::Button^ button45;


	private: System::Windows::Forms::Button^ button50;
	private: System::Windows::Forms::Button^ button48;
	private: System::Windows::Forms::Button^ button49;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::Label^ textBox2;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Button^ button7;






	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->your_bid_field = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button_zero = (gcnew System::Windows::Forms::Button());
			this->button_minus = (gcnew System::Windows::Forms::Button());
			this->button_plus = (gcnew System::Windows::Forms::Button());
			this->button_half = (gcnew System::Windows::Forms::Button());
			this->button1_4 = (gcnew System::Windows::Forms::Button());
			this->button_all_in = (gcnew System::Windows::Forms::Button());
			this->button_minus20 = (gcnew System::Windows::Forms::Button());
			this->button_plus20 = (gcnew System::Windows::Forms::Button());
			this->your_balance = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_0 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button_9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button_8 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button_16 = (gcnew System::Windows::Forms::Button());
			this->button_13 = (gcnew System::Windows::Forms::Button());
			this->button_17 = (gcnew System::Windows::Forms::Button());
			this->button_14 = (gcnew System::Windows::Forms::Button());
			this->button_18 = (gcnew System::Windows::Forms::Button());
			this->button_15 = (gcnew System::Windows::Forms::Button());
			this->button_10 = (gcnew System::Windows::Forms::Button());
			this->button_11 = (gcnew System::Windows::Forms::Button());
			this->button_12 = (gcnew System::Windows::Forms::Button());
			this->button_25 = (gcnew System::Windows::Forms::Button());
			this->button_22 = (gcnew System::Windows::Forms::Button());
			this->button_26 = (gcnew System::Windows::Forms::Button());
			this->button_23 = (gcnew System::Windows::Forms::Button());
			this->button_27 = (gcnew System::Windows::Forms::Button());
			this->button_24 = (gcnew System::Windows::Forms::Button());
			this->button_19 = (gcnew System::Windows::Forms::Button());
			this->button_20 = (gcnew System::Windows::Forms::Button());
			this->button_21 = (gcnew System::Windows::Forms::Button());
			this->button_34 = (gcnew System::Windows::Forms::Button());
			this->button_31 = (gcnew System::Windows::Forms::Button());
			this->button_35 = (gcnew System::Windows::Forms::Button());
			this->button_32 = (gcnew System::Windows::Forms::Button());
			this->button_36 = (gcnew System::Windows::Forms::Button());
			this->button_33 = (gcnew System::Windows::Forms::Button());
			this->button_28 = (gcnew System::Windows::Forms::Button());
			this->button_29 = (gcnew System::Windows::Forms::Button());
			this->button_30 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->button43 = (gcnew System::Windows::Forms::Button());
			this->button46 = (gcnew System::Windows::Forms::Button());
			this->button47 = (gcnew System::Windows::Forms::Button());
			this->button44 = (gcnew System::Windows::Forms::Button());
			this->button45 = (gcnew System::Windows::Forms::Button());
			this->button50 = (gcnew System::Windows::Forms::Button());
			this->button48 = (gcnew System::Windows::Forms::Button());
			this->button49 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(888, 492);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(174, 47);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Spin";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// your_bid_field
			// 
			this->your_bid_field->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->your_bid_field->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->your_bid_field->ForeColor = System::Drawing::Color::Black;
			this->your_bid_field->Location = System::Drawing::Point(871, 451);
			this->your_bid_field->Name = L"your_bid_field";
			this->your_bid_field->Size = System::Drawing::Size(48, 21);
			this->your_bid_field->TabIndex = 3;
			this->your_bid_field->TextChanged += gcnew System::EventHandler(this, &MyForm::your_bid_field_TextChanged);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(652, 350);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 29);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Enter Bet";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(891, 348);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Your number:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Location = System::Drawing::Point(342, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(413, 275);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 4000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button_zero
			// 
			this->button_zero->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_zero->BackColor = System::Drawing::Color::Transparent;
			this->button_zero->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_zero->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_zero->ForeColor = System::Drawing::Color::Transparent;
			this->button_zero->Location = System::Drawing::Point(713, 445);
			this->button_zero->Name = L"button_zero";
			this->button_zero->Size = System::Drawing::Size(42, 30);
			this->button_zero->TabIndex = 7;
			this->button_zero->Text = L"0";
			this->button_zero->UseVisualStyleBackColor = false;
			this->button_zero->Click += gcnew System::EventHandler(this, &MyForm::button_zero_Click);
			// 
			// button_minus
			// 
			this->button_minus->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_minus->BackColor = System::Drawing::Color::Transparent;
			this->button_minus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_minus->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_minus->ForeColor = System::Drawing::Color::Transparent;
			this->button_minus->Location = System::Drawing::Point(665, 445);
			this->button_minus->Name = L"button_minus";
			this->button_minus->Size = System::Drawing::Size(42, 30);
			this->button_minus->TabIndex = 8;
			this->button_minus->Text = L"-10";
			this->button_minus->UseVisualStyleBackColor = false;
			this->button_minus->Click += gcnew System::EventHandler(this, &MyForm::button_minus_Click);
			// 
			// button_plus
			// 
			this->button_plus->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_plus->BackColor = System::Drawing::Color::Transparent;
			this->button_plus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_plus->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_plus->ForeColor = System::Drawing::Color::Transparent;
			this->button_plus->Location = System::Drawing::Point(761, 445);
			this->button_plus->Name = L"button_plus";
			this->button_plus->Size = System::Drawing::Size(42, 30);
			this->button_plus->TabIndex = 9;
			this->button_plus->Text = L"+10";
			this->button_plus->UseVisualStyleBackColor = false;
			this->button_plus->Click += gcnew System::EventHandler(this, &MyForm::button_plus_Click);
			// 
			// button_half
			// 
			this->button_half->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_half->BackColor = System::Drawing::Color::Transparent;
			this->button_half->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_half->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_half->ForeColor = System::Drawing::Color::Transparent;
			this->button_half->Location = System::Drawing::Point(617, 396);
			this->button_half->Name = L"button_half";
			this->button_half->Size = System::Drawing::Size(62, 30);
			this->button_half->TabIndex = 10;
			this->button_half->Text = L"half";
			this->button_half->UseVisualStyleBackColor = false;
			this->button_half->Click += gcnew System::EventHandler(this, &MyForm::button_half_Click);
			// 
			// button1_4
			// 
			this->button1_4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1_4->BackColor = System::Drawing::Color::Transparent;
			this->button1_4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1_4->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1_4->ForeColor = System::Drawing::Color::Transparent;
			this->button1_4->Location = System::Drawing::Point(789, 396);
			this->button1_4->Name = L"button1_4";
			this->button1_4->Size = System::Drawing::Size(62, 30);
			this->button1_4->TabIndex = 11;
			this->button1_4->Text = L"1/4";
			this->button1_4->UseVisualStyleBackColor = false;
			this->button1_4->Click += gcnew System::EventHandler(this, &MyForm::button1_4_Click);
			// 
			// button_all_in
			// 
			this->button_all_in->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_all_in->BackColor = System::Drawing::Color::Transparent;
			this->button_all_in->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_all_in->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_all_in->ForeColor = System::Drawing::Color::Transparent;
			this->button_all_in->Location = System::Drawing::Point(702, 396);
			this->button_all_in->Name = L"button_all_in";
			this->button_all_in->Size = System::Drawing::Size(62, 30);
			this->button_all_in->TabIndex = 12;
			this->button_all_in->Text = L"all in";
			this->button_all_in->UseVisualStyleBackColor = false;
			this->button_all_in->Click += gcnew System::EventHandler(this, &MyForm::button_all_in_Click);
			// 
			// button_minus20
			// 
			this->button_minus20->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_minus20->BackColor = System::Drawing::Color::Transparent;
			this->button_minus20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_minus20->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_minus20->ForeColor = System::Drawing::Color::Transparent;
			this->button_minus20->Location = System::Drawing::Point(617, 445);
			this->button_minus20->Name = L"button_minus20";
			this->button_minus20->Size = System::Drawing::Size(42, 30);
			this->button_minus20->TabIndex = 13;
			this->button_minus20->Text = L"-20";
			this->button_minus20->UseVisualStyleBackColor = false;
			this->button_minus20->Click += gcnew System::EventHandler(this, &MyForm::button_minus20_Click);
			// 
			// button_plus20
			// 
			this->button_plus20->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_plus20->BackColor = System::Drawing::Color::Transparent;
			this->button_plus20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_plus20->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_plus20->ForeColor = System::Drawing::Color::Transparent;
			this->button_plus20->Location = System::Drawing::Point(809, 445);
			this->button_plus20->Name = L"button_plus20";
			this->button_plus20->Size = System::Drawing::Size(42, 30);
			this->button_plus20->TabIndex = 14;
			this->button_plus20->Text = L"+20";
			this->button_plus20->UseVisualStyleBackColor = false;
			this->button_plus20->Click += gcnew System::EventHandler(this, &MyForm::button_plus20_Click);
			// 
			// your_balance
			// 
			this->your_balance->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->your_balance->AutoSize = true;
			this->your_balance->BackColor = System::Drawing::Color::Transparent;
			this->your_balance->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->your_balance->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->your_balance->ForeColor = System::Drawing::Color::Transparent;
			this->your_balance->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->your_balance->Location = System::Drawing::Point(759, 500);
			this->your_balance->Name = L"your_balance";
			this->your_balance->Size = System::Drawing::Size(61, 29);
			this->your_balance->TabIndex = 16;
			this->your_balance->Text = L"100";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox1->AutoSize = true;
			this->textBox1->BackColor = System::Drawing::Color::Transparent;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(1021, 375);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(31, 13);
			this->textBox1->TabIndex = 17;
			this->textBox1->Text = L"-_-";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(891, 375);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Random number:";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label4->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Transparent;
			this->label4->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label4->Location = System::Drawing::Point(630, 500);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(125, 29);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Balance";
			// 
			// button_0
			// 
			this->button_0->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_0->BackColor = System::Drawing::Color::Transparent;
			this->button_0->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_0->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_0->ForeColor = System::Drawing::Color::White;
			this->button_0->Location = System::Drawing::Point(36, 363);
			this->button_0->Name = L"button_0";
			this->button_0->Size = System::Drawing::Size(23, 96);
			this->button_0->TabIndex = 20;
			this->button_0->Text = L"0";
			this->button_0->UseVisualStyleBackColor = false;
			this->button_0->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->BackColor = System::Drawing::Color::Red;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(65, 363);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(30, 28);
			this->button3->TabIndex = 21;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button4->BackColor = System::Drawing::Color::Black;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(65, 396);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(30, 28);
			this->button4->TabIndex = 22;
			this->button4->Text = L"2";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button5
			// 
			this->button5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button5->BackColor = System::Drawing::Color::Red;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(65, 431);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(30, 28);
			this->button5->TabIndex = 23;
			this->button5->Text = L"1";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button6
			// 
			this->button6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button6->BackColor = System::Drawing::Color::Black;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Location = System::Drawing::Point(101, 363);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(30, 28);
			this->button6->TabIndex = 24;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_9
			// 
			this->button_9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_9->BackColor = System::Drawing::Color::Red;
			this->button_9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_9->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_9->ForeColor = System::Drawing::Color::White;
			this->button_9->Location = System::Drawing::Point(137, 363);
			this->button_9->Name = L"button_9";
			this->button_9->Size = System::Drawing::Size(30, 28);
			this->button_9->TabIndex = 25;
			this->button_9->Text = L"9";
			this->button_9->UseVisualStyleBackColor = false;
			this->button_9->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button8
			// 
			this->button8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button8->BackColor = System::Drawing::Color::Red;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button8->ForeColor = System::Drawing::Color::White;
			this->button8->Location = System::Drawing::Point(101, 396);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(30, 28);
			this->button8->TabIndex = 26;
			this->button8->Text = L"5";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_8
			// 
			this->button_8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_8->BackColor = System::Drawing::Color::Black;
			this->button_8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_8->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_8->ForeColor = System::Drawing::Color::White;
			this->button_8->Location = System::Drawing::Point(137, 396);
			this->button_8->Name = L"button_8";
			this->button_8->Size = System::Drawing::Size(30, 28);
			this->button_8->TabIndex = 27;
			this->button_8->Text = L"8";
			this->button_8->UseVisualStyleBackColor = false;
			this->button_8->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button10
			// 
			this->button10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button10->BackColor = System::Drawing::Color::Black;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button10->ForeColor = System::Drawing::Color::White;
			this->button10->Location = System::Drawing::Point(101, 431);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(30, 28);
			this->button10->TabIndex = 28;
			this->button10->Text = L"4";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button11
			// 
			this->button11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button11->BackColor = System::Drawing::Color::Red;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button11->ForeColor = System::Drawing::Color::White;
			this->button11->Location = System::Drawing::Point(137, 431);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(30, 28);
			this->button11->TabIndex = 29;
			this->button11->Text = L"7";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_16
			// 
			this->button_16->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_16->BackColor = System::Drawing::Color::Red;
			this->button_16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_16->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_16->ForeColor = System::Drawing::Color::White;
			this->button_16->Location = System::Drawing::Point(246, 430);
			this->button_16->Name = L"button_16";
			this->button_16->Size = System::Drawing::Size(30, 28);
			this->button_16->TabIndex = 38;
			this->button_16->Text = L"16";
			this->button_16->UseVisualStyleBackColor = false;
			this->button_16->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_13
			// 
			this->button_13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_13->BackColor = System::Drawing::Color::Black;
			this->button_13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_13->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_13->ForeColor = System::Drawing::Color::White;
			this->button_13->Location = System::Drawing::Point(209, 430);
			this->button_13->Name = L"button_13";
			this->button_13->Size = System::Drawing::Size(30, 28);
			this->button_13->TabIndex = 37;
			this->button_13->Text = L"13";
			this->button_13->UseVisualStyleBackColor = false;
			this->button_13->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_17
			// 
			this->button_17->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_17->BackColor = System::Drawing::Color::Black;
			this->button_17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_17->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_17->ForeColor = System::Drawing::Color::White;
			this->button_17->Location = System::Drawing::Point(246, 396);
			this->button_17->Name = L"button_17";
			this->button_17->Size = System::Drawing::Size(30, 28);
			this->button_17->TabIndex = 36;
			this->button_17->Text = L"17";
			this->button_17->UseVisualStyleBackColor = false;
			this->button_17->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_14
			// 
			this->button_14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_14->BackColor = System::Drawing::Color::Red;
			this->button_14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_14->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_14->ForeColor = System::Drawing::Color::White;
			this->button_14->Location = System::Drawing::Point(209, 396);
			this->button_14->Name = L"button_14";
			this->button_14->Size = System::Drawing::Size(30, 28);
			this->button_14->TabIndex = 35;
			this->button_14->Text = L"14";
			this->button_14->UseVisualStyleBackColor = false;
			this->button_14->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_18
			// 
			this->button_18->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_18->BackColor = System::Drawing::Color::Red;
			this->button_18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_18->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_18->ForeColor = System::Drawing::Color::White;
			this->button_18->Location = System::Drawing::Point(246, 362);
			this->button_18->Name = L"button_18";
			this->button_18->Size = System::Drawing::Size(30, 28);
			this->button_18->TabIndex = 34;
			this->button_18->Text = L"18";
			this->button_18->UseVisualStyleBackColor = false;
			this->button_18->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_15
			// 
			this->button_15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_15->BackColor = System::Drawing::Color::Black;
			this->button_15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_15->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_15->ForeColor = System::Drawing::Color::White;
			this->button_15->Location = System::Drawing::Point(209, 362);
			this->button_15->Name = L"button_15";
			this->button_15->Size = System::Drawing::Size(30, 28);
			this->button_15->TabIndex = 33;
			this->button_15->Text = L"15";
			this->button_15->UseVisualStyleBackColor = false;
			this->button_15->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_10
			// 
			this->button_10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_10->BackColor = System::Drawing::Color::Black;
			this->button_10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_10->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_10->ForeColor = System::Drawing::Color::White;
			this->button_10->Location = System::Drawing::Point(173, 431);
			this->button_10->Name = L"button_10";
			this->button_10->Size = System::Drawing::Size(30, 28);
			this->button_10->TabIndex = 32;
			this->button_10->Text = L"10";
			this->button_10->UseVisualStyleBackColor = false;
			this->button_10->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_11
			// 
			this->button_11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_11->BackColor = System::Drawing::Color::Black;
			this->button_11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_11->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_11->ForeColor = System::Drawing::Color::White;
			this->button_11->Location = System::Drawing::Point(173, 396);
			this->button_11->Name = L"button_11";
			this->button_11->Size = System::Drawing::Size(30, 28);
			this->button_11->TabIndex = 31;
			this->button_11->Text = L"11";
			this->button_11->UseVisualStyleBackColor = false;
			this->button_11->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_12
			// 
			this->button_12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_12->BackColor = System::Drawing::Color::Red;
			this->button_12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_12->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_12->ForeColor = System::Drawing::Color::White;
			this->button_12->Location = System::Drawing::Point(173, 363);
			this->button_12->Name = L"button_12";
			this->button_12->Size = System::Drawing::Size(30, 28);
			this->button_12->TabIndex = 30;
			this->button_12->Text = L"12";
			this->button_12->UseVisualStyleBackColor = false;
			this->button_12->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_25
			// 
			this->button_25->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_25->BackColor = System::Drawing::Color::Red;
			this->button_25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_25->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_25->ForeColor = System::Drawing::Color::White;
			this->button_25->Location = System::Drawing::Point(354, 430);
			this->button_25->Name = L"button_25";
			this->button_25->Size = System::Drawing::Size(30, 28);
			this->button_25->TabIndex = 47;
			this->button_25->Text = L"25";
			this->button_25->UseVisualStyleBackColor = false;
			this->button_25->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_22
			// 
			this->button_22->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_22->BackColor = System::Drawing::Color::Black;
			this->button_22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_22->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_22->ForeColor = System::Drawing::Color::White;
			this->button_22->Location = System::Drawing::Point(318, 430);
			this->button_22->Name = L"button_22";
			this->button_22->Size = System::Drawing::Size(30, 28);
			this->button_22->TabIndex = 46;
			this->button_22->Text = L"22";
			this->button_22->UseVisualStyleBackColor = false;
			this->button_22->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_26
			// 
			this->button_26->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_26->BackColor = System::Drawing::Color::Black;
			this->button_26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_26->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_26->ForeColor = System::Drawing::Color::White;
			this->button_26->Location = System::Drawing::Point(354, 396);
			this->button_26->Name = L"button_26";
			this->button_26->Size = System::Drawing::Size(30, 28);
			this->button_26->TabIndex = 45;
			this->button_26->Text = L"26";
			this->button_26->UseVisualStyleBackColor = false;
			this->button_26->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_23
			// 
			this->button_23->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_23->BackColor = System::Drawing::Color::Red;
			this->button_23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_23->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_23->ForeColor = System::Drawing::Color::White;
			this->button_23->Location = System::Drawing::Point(318, 396);
			this->button_23->Name = L"button_23";
			this->button_23->Size = System::Drawing::Size(30, 28);
			this->button_23->TabIndex = 44;
			this->button_23->Text = L"23";
			this->button_23->UseVisualStyleBackColor = false;
			this->button_23->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_27
			// 
			this->button_27->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_27->BackColor = System::Drawing::Color::Red;
			this->button_27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_27->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_27->ForeColor = System::Drawing::Color::White;
			this->button_27->Location = System::Drawing::Point(354, 362);
			this->button_27->Name = L"button_27";
			this->button_27->Size = System::Drawing::Size(30, 28);
			this->button_27->TabIndex = 43;
			this->button_27->Text = L"27";
			this->button_27->UseVisualStyleBackColor = false;
			this->button_27->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_24
			// 
			this->button_24->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_24->BackColor = System::Drawing::Color::Black;
			this->button_24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_24->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_24->ForeColor = System::Drawing::Color::White;
			this->button_24->Location = System::Drawing::Point(318, 362);
			this->button_24->Name = L"button_24";
			this->button_24->Size = System::Drawing::Size(30, 28);
			this->button_24->TabIndex = 42;
			this->button_24->Text = L"24";
			this->button_24->UseVisualStyleBackColor = false;
			this->button_24->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_19
			// 
			this->button_19->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_19->BackColor = System::Drawing::Color::Red;
			this->button_19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_19->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_19->ForeColor = System::Drawing::Color::White;
			this->button_19->Location = System::Drawing::Point(282, 430);
			this->button_19->Name = L"button_19";
			this->button_19->Size = System::Drawing::Size(30, 28);
			this->button_19->TabIndex = 41;
			this->button_19->Text = L"19";
			this->button_19->UseVisualStyleBackColor = false;
			this->button_19->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_20
			// 
			this->button_20->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_20->BackColor = System::Drawing::Color::Black;
			this->button_20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_20->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_20->ForeColor = System::Drawing::Color::White;
			this->button_20->Location = System::Drawing::Point(282, 396);
			this->button_20->Name = L"button_20";
			this->button_20->Size = System::Drawing::Size(30, 28);
			this->button_20->TabIndex = 40;
			this->button_20->Text = L"20";
			this->button_20->UseVisualStyleBackColor = false;
			this->button_20->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_21
			// 
			this->button_21->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_21->BackColor = System::Drawing::Color::Red;
			this->button_21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_21->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_21->ForeColor = System::Drawing::Color::White;
			this->button_21->Location = System::Drawing::Point(282, 362);
			this->button_21->Name = L"button_21";
			this->button_21->Size = System::Drawing::Size(30, 28);
			this->button_21->TabIndex = 39;
			this->button_21->Text = L"21";
			this->button_21->UseVisualStyleBackColor = false;
			this->button_21->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_34
			// 
			this->button_34->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_34->BackColor = System::Drawing::Color::Red;
			this->button_34->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_34->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_34->ForeColor = System::Drawing::Color::White;
			this->button_34->Location = System::Drawing::Point(462, 430);
			this->button_34->Name = L"button_34";
			this->button_34->Size = System::Drawing::Size(30, 28);
			this->button_34->TabIndex = 56;
			this->button_34->Text = L"34";
			this->button_34->UseVisualStyleBackColor = false;
			this->button_34->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_31
			// 
			this->button_31->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_31->BackColor = System::Drawing::Color::Black;
			this->button_31->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_31->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_31->ForeColor = System::Drawing::Color::White;
			this->button_31->Location = System::Drawing::Point(426, 430);
			this->button_31->Name = L"button_31";
			this->button_31->Size = System::Drawing::Size(30, 28);
			this->button_31->TabIndex = 55;
			this->button_31->Text = L"31";
			this->button_31->UseVisualStyleBackColor = false;
			this->button_31->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_35
			// 
			this->button_35->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_35->BackColor = System::Drawing::Color::Black;
			this->button_35->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_35->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_35->ForeColor = System::Drawing::Color::White;
			this->button_35->Location = System::Drawing::Point(462, 396);
			this->button_35->Name = L"button_35";
			this->button_35->Size = System::Drawing::Size(30, 28);
			this->button_35->TabIndex = 54;
			this->button_35->Text = L"35";
			this->button_35->UseVisualStyleBackColor = false;
			this->button_35->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_32
			// 
			this->button_32->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_32->BackColor = System::Drawing::Color::Red;
			this->button_32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_32->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_32->ForeColor = System::Drawing::Color::White;
			this->button_32->Location = System::Drawing::Point(426, 396);
			this->button_32->Name = L"button_32";
			this->button_32->Size = System::Drawing::Size(30, 28);
			this->button_32->TabIndex = 53;
			this->button_32->Text = L"32";
			this->button_32->UseVisualStyleBackColor = false;
			this->button_32->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_36
			// 
			this->button_36->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_36->BackColor = System::Drawing::Color::Red;
			this->button_36->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_36->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_36->ForeColor = System::Drawing::Color::White;
			this->button_36->Location = System::Drawing::Point(462, 362);
			this->button_36->Name = L"button_36";
			this->button_36->Size = System::Drawing::Size(30, 28);
			this->button_36->TabIndex = 52;
			this->button_36->Text = L"36";
			this->button_36->UseVisualStyleBackColor = false;
			this->button_36->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_33
			// 
			this->button_33->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_33->BackColor = System::Drawing::Color::Black;
			this->button_33->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_33->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_33->ForeColor = System::Drawing::Color::White;
			this->button_33->Location = System::Drawing::Point(426, 362);
			this->button_33->Name = L"button_33";
			this->button_33->Size = System::Drawing::Size(30, 28);
			this->button_33->TabIndex = 51;
			this->button_33->Text = L"33";
			this->button_33->UseVisualStyleBackColor = false;
			this->button_33->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_28
			// 
			this->button_28->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_28->BackColor = System::Drawing::Color::Black;
			this->button_28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_28->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_28->ForeColor = System::Drawing::Color::White;
			this->button_28->Location = System::Drawing::Point(390, 430);
			this->button_28->Name = L"button_28";
			this->button_28->Size = System::Drawing::Size(30, 28);
			this->button_28->TabIndex = 50;
			this->button_28->Text = L"28";
			this->button_28->UseVisualStyleBackColor = false;
			this->button_28->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_29
			// 
			this->button_29->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_29->BackColor = System::Drawing::Color::Black;
			this->button_29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_29->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_29->ForeColor = System::Drawing::Color::White;
			this->button_29->Location = System::Drawing::Point(390, 396);
			this->button_29->Name = L"button_29";
			this->button_29->Size = System::Drawing::Size(30, 28);
			this->button_29->TabIndex = 49;
			this->button_29->Text = L"29";
			this->button_29->UseVisualStyleBackColor = false;
			this->button_29->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button_30
			// 
			this->button_30->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_30->BackColor = System::Drawing::Color::Red;
			this->button_30->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_30->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button_30->ForeColor = System::Drawing::Color::White;
			this->button_30->Location = System::Drawing::Point(390, 362);
			this->button_30->Name = L"button_30";
			this->button_30->Size = System::Drawing::Size(30, 28);
			this->button_30->TabIndex = 48;
			this->button_30->Text = L"30";
			this->button_30->UseVisualStyleBackColor = false;
			this->button_30->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button39
			// 
			this->button39->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button39->BackColor = System::Drawing::Color::Transparent;
			this->button39->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button39->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button39->ForeColor = System::Drawing::Color::White;
			this->button39->Location = System::Drawing::Point(65, 465);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(138, 21);
			this->button39->TabIndex = 57;
			this->button39->Text = L"1-12";
			this->button39->UseVisualStyleBackColor = false;
			this->button39->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button40
			// 
			this->button40->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button40->BackColor = System::Drawing::Color::Transparent;
			this->button40->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button40->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button40->ForeColor = System::Drawing::Color::White;
			this->button40->Location = System::Drawing::Point(209, 465);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(139, 21);
			this->button40->TabIndex = 58;
			this->button40->Text = L"13-24";
			this->button40->UseVisualStyleBackColor = false;
			this->button40->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button41
			// 
			this->button41->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button41->BackColor = System::Drawing::Color::Transparent;
			this->button41->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button41->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button41->ForeColor = System::Drawing::Color::White;
			this->button41->Location = System::Drawing::Point(354, 465);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(138, 21);
			this->button41->TabIndex = 59;
			this->button41->Text = L"25-36";
			this->button41->UseVisualStyleBackColor = false;
			this->button41->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button42
			// 
			this->button42->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button42->BackColor = System::Drawing::Color::Transparent;
			this->button42->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button42->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button42->ForeColor = System::Drawing::Color::White;
			this->button42->Location = System::Drawing::Point(65, 492);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(66, 23);
			this->button42->TabIndex = 60;
			this->button42->Text = L"1-18";
			this->button42->UseVisualStyleBackColor = false;
			this->button42->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button43
			// 
			this->button43->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button43->BackColor = System::Drawing::Color::Transparent;
			this->button43->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button43->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button43->ForeColor = System::Drawing::Color::White;
			this->button43->Location = System::Drawing::Point(137, 492);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(66, 23);
			this->button43->TabIndex = 61;
			this->button43->Text = L"EVEN";
			this->button43->UseVisualStyleBackColor = false;
			this->button43->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button46
			// 
			this->button46->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button46->BackColor = System::Drawing::Color::Transparent;
			this->button46->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button46->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button46->ForeColor = System::Drawing::Color::White;
			this->button46->Location = System::Drawing::Point(426, 492);
			this->button46->Name = L"button46";
			this->button46->Size = System::Drawing::Size(66, 23);
			this->button46->TabIndex = 65;
			this->button46->Text = L"19-36";
			this->button46->UseVisualStyleBackColor = false;
			this->button46->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button47
			// 
			this->button47->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button47->BackColor = System::Drawing::Color::Transparent;
			this->button47->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button47->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button47->ForeColor = System::Drawing::Color::White;
			this->button47->Location = System::Drawing::Point(354, 492);
			this->button47->Name = L"button47";
			this->button47->Size = System::Drawing::Size(66, 23);
			this->button47->TabIndex = 64;
			this->button47->Text = L"ODD";
			this->button47->UseVisualStyleBackColor = false;
			this->button47->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button44
			// 
			this->button44->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button44->BackColor = System::Drawing::Color::Black;
			this->button44->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button44->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button44->ForeColor = System::Drawing::Color::White;
			this->button44->Location = System::Drawing::Point(282, 492);
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(66, 23);
			this->button44->TabIndex = 67;
			this->button44->Text = L"black";
			this->button44->UseVisualStyleBackColor = false;
			this->button44->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button45
			// 
			this->button45->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button45->BackColor = System::Drawing::Color::Red;
			this->button45->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button45->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button45->ForeColor = System::Drawing::Color::White;
			this->button45->Location = System::Drawing::Point(209, 492);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(67, 23);
			this->button45->TabIndex = 66;
			this->button45->Text = L"red";
			this->button45->UseVisualStyleBackColor = false;
			this->button45->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button50
			// 
			this->button50->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button50->BackColor = System::Drawing::Color::Transparent;
			this->button50->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button50->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button50->ForeColor = System::Drawing::Color::White;
			this->button50->Location = System::Drawing::Point(498, 361);
			this->button50->Name = L"button50";
			this->button50->Size = System::Drawing::Size(43, 28);
			this->button50->TabIndex = 68;
			this->button50->Text = L"row1";
			this->button50->UseVisualStyleBackColor = false;
			this->button50->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button48
			// 
			this->button48->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button48->BackColor = System::Drawing::Color::Transparent;
			this->button48->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button48->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button48->ForeColor = System::Drawing::Color::White;
			this->button48->Location = System::Drawing::Point(498, 395);
			this->button48->Name = L"button48";
			this->button48->Size = System::Drawing::Size(43, 28);
			this->button48->TabIndex = 69;
			this->button48->Text = L"row2";
			this->button48->UseVisualStyleBackColor = false;
			this->button48->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// button49
			// 
			this->button49->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button49->BackColor = System::Drawing::Color::Transparent;
			this->button49->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button49->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F));
			this->button49->ForeColor = System::Drawing::Color::White;
			this->button49->Location = System::Drawing::Point(498, 429);
			this->button49->Name = L"button49";
			this->button49->Size = System::Drawing::Size(43, 27);
			this->button49->TabIndex = 70;
			this->button49->Text = L"row3";
			this->button49->UseVisualStyleBackColor = false;
			this->button49->Click += gcnew System::EventHandler(this, &MyForm::bet_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(28, 350);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(521, 176);
			this->pictureBox2->TabIndex = 71;
			this->pictureBox2->TabStop = false;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox2->AutoSize = true;
			this->textBox2->BackColor = System::Drawing::Color::Transparent;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(994, 348);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(31, 13);
			this->textBox2->TabIndex = 72;
			this->textBox2->Text = L"-_-";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 11.25F));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(976, 47);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 41);
			this->button2->TabIndex = 73;
			this->button2->Text = L"Restart";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Transparent;
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::Color::Red;
			this->button7->Location = System::Drawing::Point(1047, 12);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(20, 20);
			this->button7->TabIndex = 74;
			this->button7->Text = L"X";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1079, 567);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->your_balance);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button49);
			this->Controls->Add(this->button48);
			this->Controls->Add(this->button50);
			this->Controls->Add(this->button44);
			this->Controls->Add(this->button45);
			this->Controls->Add(this->button46);
			this->Controls->Add(this->button47);
			this->Controls->Add(this->button43);
			this->Controls->Add(this->button42);
			this->Controls->Add(this->button41);
			this->Controls->Add(this->button40);
			this->Controls->Add(this->button39);
			this->Controls->Add(this->button_34);
			this->Controls->Add(this->button_31);
			this->Controls->Add(this->button_35);
			this->Controls->Add(this->button_32);
			this->Controls->Add(this->button_36);
			this->Controls->Add(this->button_33);
			this->Controls->Add(this->button_28);
			this->Controls->Add(this->button_29);
			this->Controls->Add(this->button_30);
			this->Controls->Add(this->button_25);
			this->Controls->Add(this->button_22);
			this->Controls->Add(this->button_26);
			this->Controls->Add(this->button_23);
			this->Controls->Add(this->button_27);
			this->Controls->Add(this->button_24);
			this->Controls->Add(this->button_19);
			this->Controls->Add(this->button_20);
			this->Controls->Add(this->button_21);
			this->Controls->Add(this->button_16);
			this->Controls->Add(this->button_13);
			this->Controls->Add(this->button_17);
			this->Controls->Add(this->button_14);
			this->Controls->Add(this->button_18);
			this->Controls->Add(this->button_15);
			this->Controls->Add(this->button_10);
			this->Controls->Add(this->button_11);
			this->Controls->Add(this->button_12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button_8);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button_9);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button_0);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button_plus20);
			this->Controls->Add(this->button_minus20);
			this->Controls->Add(this->button_all_in);
			this->Controls->Add(this->button1_4);
			this->Controls->Add(this->button_half);
			this->Controls->Add(this->button_plus);
			this->Controls->Add(this->button_minus);
			this->Controls->Add(this->button_zero);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->your_bid_field);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"Casino";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// ---------------------------------------------------------------
	// Логика игры
	// ---------------------------------------------------------------

	static bool IsRed(int n)
	{
		switch (n)
		{
		case 1: case 3: case 5: case 7: case 9: case 12:
		case 14: case 16: case 18: case 19: case 21: case 23:
		case 25: case 27: case 30: case 32: case 34: case 36:
			return true;
		default:
			return false;
		}
	}

	// Множитель выигрыша для ставки bet, если выпало число n.
	// 0 — ставка проиграла. При выигрыше игрок получает ставку * множитель.
	static int GetPayout(String^ bet, int n)
	{
		int number;
		if (Int32::TryParse(bet, number))
			return number == n ? 35 : 0;   // ставка на одно число

		if (n == 0)
			return 0;                      // на зеро все остальные ставки проигрывают

		if (bet == L"row1")  return n % 3 == 0 ? 2 : 0;   // 3, 6, 9 ... 36
		if (bet == L"row2")  return n % 3 == 2 ? 2 : 0;   // 2, 5, 8 ... 35
		if (bet == L"row3")  return n % 3 == 1 ? 2 : 0;   // 1, 4, 7 ... 34
		if (bet == L"1-12")  return n <= 12 ? 2 : 0;
		if (bet == L"13-24") return n >= 13 && n <= 24 ? 2 : 0;
		if (bet == L"25-36") return n >= 25 ? 2 : 0;
		if (bet == L"1-18")  return n <= 18 ? 1 : 0;
		if (bet == L"19-36") return n >= 19 ? 1 : 0;
		if (bet == L"EVEN")  return n % 2 == 0 ? 1 : 0;
		if (bet == L"ODD")   return n % 2 == 1 ? 1 : 0;
		if (bet == L"red")   return IsRed(n) ? 1 : 0;
		if (bet == L"black") return IsRed(n) ? 0 : 1;
		return 0;
	}

	void UpdateBalance()
	{
		your_balance->Text = balance.ToString();
	}

	void SetBid(int value)
	{
		bid = Math::Max(0, value);
		your_bid_field->Text = bid.ToString();
	}

	void ResetGame()
	{
		balance = StartBalance;
		UpdateBalance();
		SetBid(0);
	}

	// Показывает гифку на 4 секунды (потом timer1 её убирает)
	void ShowGif(Image^ image)
	{
		timer1->Stop();
		pictureBox1->Image = nullptr;
		if (image != nullptr)
			image->SelectActiveFrame(System::Drawing::Imaging::FrameDimension::Time, 0); // анимация с начала
		pictureBox1->Image = image;
		timer1->Start();
	}

	// ---------------------------------------------------------------
	// Обработчики
	// ---------------------------------------------------------------

	// Spin
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (selectedBet == nullptr) {
			MessageBox::Show(L"Choose what to bet on first.");
			return;
		}

		int value;
		if (!Int32::TryParse(your_bid_field->Text, value) || value <= 0) {
			MessageBox::Show(L"Enter a bet greater than 0.");
			return;
		}
		bid = value;

		if (bid > balance) {
			MessageBox::Show(L"Your bet is bigger than your balance.");
			return;
		}

		int randomNumber = rng->Next(0, 37);   // 0..36, верхняя граница не включается
		textBox1->Text = randomNumber.ToString();

		int payout = GetPayout(selectedBet, randomNumber);
		if (payout > 0) {
			balance += bid * payout;
			UpdateBalance();
			ShowGif(winImage);
			return;
		}

		balance -= bid;
		UpdateBalance();
		if (balance > 0) {
			ShowGif(loseImage);
			return;
		}

		ShowGif(noMoneyImage);
		MessageBox::Show(L"You are out of money! The game starts over with a balance of 100.");
		ResetGame();
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Image = nullptr;
		timer1->Stop();
	}

	// Кнопки изменения ставки
	private: System::Void button_zero_Click(System::Object^ sender, System::EventArgs^ e) {
		SetBid(0);
	}
	private: System::Void button_plus_Click(System::Object^ sender, System::EventArgs^ e) {
		SetBid(bid + 10);
	}
	private: System::Void button_plus20_Click(System::Object^ sender, System::EventArgs^ e) {
		SetBid(bid + 20);
	}
	private: System::Void button_minus_Click(System::Object^ sender, System::EventArgs^ e) {
		SetBid(bid - 10);
	}
	private: System::Void button_minus20_Click(System::Object^ sender, System::EventArgs^ e) {
		SetBid(bid - 20);
	}
	private: System::Void button_half_Click(System::Object^ sender, System::EventArgs^ e) {
		SetBid(balance / 2);
	}
	private: System::Void button1_4_Click(System::Object^ sender, System::EventArgs^ e) {
		SetBid(balance / 4);
	}
	private: System::Void button_all_in_Click(System::Object^ sender, System::EventArgs^ e) {
		SetBid(balance);
	}

	// Ручной ввод ставки: мусор и отрицательные числа считаем нулём, без исключений
	private: System::Void your_bid_field_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		int value;
		bid = (Int32::TryParse(your_bid_field->Text, value) && value > 0) ? value : 0;
	}

	// Одна функция на все кнопки ставок: что ставим — берём из текста кнопки
	private: System::Void bet_Click(System::Object^ sender, System::EventArgs^ e) {
		selectedBet = safe_cast<Button^>(sender)->Text;
		textBox2->Text = selectedBet;
	}

	// Restart
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			L"Reset your balance to 100?", L"Restart", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		if (result == System::Windows::Forms::DialogResult::Yes)
			ResetGame();
	}

	// X
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
};
}
