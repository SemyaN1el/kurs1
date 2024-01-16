#pragma once
#include "Instruction.h"
#include <msclr\marshal_cppstd.h>
#include <list>
namespace kurs1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;  // Добавление этого для использования List
	using namespace System::Windows::Forms::DataVisualization::Charting;  // Добавление этого для использования DataPoint
	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

		//private: Instruction^ Instruction_form = nullptr;
	public: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ менюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ построитьГрафикToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ очиститьГрафикToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	public: System::Windows::Forms::TextBox^ textBoxFunction1;
	private:
	private:
	private: Instruction^ Instruction_form = nullptr;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	public: System::Windows::Forms::TextBox^ textBoxFunction2;
	private:
	private:
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::CheckBox^ checkBox_searchCross;
	private: System::Windows::Forms::CheckBox^ checkBox_minmax1;
	private: System::Windows::Forms::CheckBox^ checkBox_minmax2;
	private: System::Windows::Forms::Label^ labelCoordinates;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ buttonPanDown;
	private: System::Windows::Forms::Button^ buttonPanUp;
	private: System::Windows::Forms::Button^ buttonPanLeft;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ buttonPanRight;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::Button^ buttonResetCheckbox;
	private: System::Windows::Forms::CheckBox^ checkBox_globminmax2;
	private: System::Windows::Forms::CheckBox^ checkBox_globminmax1;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ справочнаяИнформацияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox4;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->менюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->построитьГрафикToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->очиститьГрафикToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxFunction2 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxFunction1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_globminmax2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_globminmax1 = (gcnew System::Windows::Forms::CheckBox());
			this->buttonResetCheckbox = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonPanRight = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->buttonPanLeft = (gcnew System::Windows::Forms::Button());
			this->buttonPanUp = (gcnew System::Windows::Forms::Button());
			this->buttonPanDown = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelCoordinates = (gcnew System::Windows::Forms::Label());
			this->checkBox_minmax2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_minmax1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_searchCross = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->справочнаяИнформацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart
			// 
			chartArea1->AxisX->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Triangle;
			chartArea1->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisX->ScrollBar->ButtonStyle = System::Windows::Forms::DataVisualization::Charting::ScrollBarButtonStyles::ResetZoom;
			chartArea1->AxisX->Title = L"Ось X";
			chartArea1->AxisY->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Triangle;
			chartArea1->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisY->IsMarksNextToAxis = false;
			chartArea1->AxisY->Title = L"Ось Y";
			chartArea1->CursorX->IsUserEnabled = true;
			chartArea1->CursorX->IsUserSelectionEnabled = true;
			chartArea1->CursorY->IsUserEnabled = true;
			chartArea1->CursorY->IsUserSelectionEnabled = true;
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			legend1->Title = L"Цвета графиков";
			legend1->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::Line;
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(6, 13);
			this->chart->Name = L"chart";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			series1->Legend = L"Legend1";
			series1->LegendText = L"График 1";
			series1->Name = L"Series1";
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->LegendText = L"График 2";
			series2->Name = L"Series2";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series3->Legend = L"Legend1";
			series3->Name = L"Точки пересечения";
			series3->YValuesPerPoint = 2;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series4->Legend = L"Legend1";
			series4->Name = L"Точки глоб. экстр.";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series5->Legend = L"Legend1";
			series5->Name = L"Точки лок. мин.";
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series6->Legend = L"Legend1";
			series6->Name = L"Точки лок. макс.";
			series7->ChartArea = L"ChartArea1";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series7->Legend = L"Legend1";
			series7->Name = L"Точки глоб. мин.";
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series8->Legend = L"Legend1";
			series8->Name = L"Точки глоб. макс.";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Series->Add(series3);
			this->chart->Series->Add(series4);
			this->chart->Series->Add(series5);
			this->chart->Series->Add(series6);
			this->chart->Series->Add(series7);
			this->chart->Series->Add(series8);
			this->chart->Size = System::Drawing::Size(727, 685);
			this->chart->TabIndex = 4;
			this->chart->Text = L"chart1";
			title1->Name = L"Title1";
			title1->Text = L"График функций";
			this->chart->Titles->Add(title1);
			this->chart->MouseEnter += gcnew System::EventHandler(this, &MyForm::chart_MouseEnter);
			this->chart->MouseLeave += gcnew System::EventHandler(this, &MyForm::chart_MouseLeave);
			this->chart->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::chart_MouseMove);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Location = System::Drawing::Point(0, 24);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1348, 24);
			this->menuStrip1->TabIndex = 9;
			// 
			// менюToolStripMenuItem
			// 
			this->менюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->построитьГрафикToolStripMenuItem,
					this->очиститьГрафикToolStripMenuItem
			});
			this->менюToolStripMenuItem->Name = L"менюToolStripMenuItem";
			this->менюToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->менюToolStripMenuItem->Text = L"Меню";
			// 
			// построитьГрафикToolStripMenuItem
			// 
			this->построитьГрафикToolStripMenuItem->Name = L"построитьГрафикToolStripMenuItem";
			this->построитьГрафикToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			// 
			// очиститьГрафикToolStripMenuItem
			// 
			this->очиститьГрафикToolStripMenuItem->Name = L"очиститьГрафикToolStripMenuItem";
			this->очиститьГрафикToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->chart);
			this->groupBox1->Location = System::Drawing::Point(0, 28);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(733, 704);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"График";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->textBoxFunction2);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->textBoxFunction1);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(739, 47);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(609, 260);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Параметры";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(169, 106);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(271, 29);
			this->textBox4->TabIndex = 21;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(3, 111);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(160, 24);
			this->label7->TabIndex = 20;
			this->label7->Text = L"h2 (шаг постр.) =";
			// 
			// textBoxFunction2
			// 
			this->textBoxFunction2->Location = System::Drawing::Point(248, 210);
			this->textBoxFunction2->Name = L"textBoxFunction2";
			this->textBoxFunction2->Size = System::Drawing::Size(278, 20);
			this->textBoxFunction2->TabIndex = 19;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(0, 206);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(242, 24);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Введите функцию №2: y =";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(0, 182);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(242, 24);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Введите функцию №1: y =";
			// 
			// textBoxFunction1
			// 
			this->textBoxFunction1->Location = System::Drawing::Point(248, 186);
			this->textBoxFunction1->Name = L"textBoxFunction1";
			this->textBoxFunction1->Size = System::Drawing::Size(278, 20);
			this->textBoxFunction1->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(169, 74);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(271, 29);
			this->textBox3->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(77, 45);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(271, 29);
			this->textBox2->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(77, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(271, 29);
			this->textBox1->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(3, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"h1 (шаг выч.) =";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(3, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"B (до) =";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"А (от) =";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->checkBox_globminmax2);
			this->groupBox3->Controls->Add(this->checkBox_globminmax1);
			this->groupBox3->Controls->Add(this->buttonResetCheckbox);
			this->groupBox3->Controls->Add(this->buttonClear);
			this->groupBox3->Controls->Add(this->buttonPanRight);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->buttonPanLeft);
			this->groupBox3->Controls->Add(this->buttonPanUp);
			this->groupBox3->Controls->Add(this->buttonPanDown);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->labelCoordinates);
			this->groupBox3->Controls->Add(this->checkBox_minmax2);
			this->groupBox3->Controls->Add(this->checkBox_minmax1);
			this->groupBox3->Controls->Add(this->checkBox_searchCross);
			this->groupBox3->Controls->Add(this->radioButton5);
			this->groupBox3->Controls->Add(this->radioButton4);
			this->groupBox3->Controls->Add(this->radioButton3);
			this->groupBox3->Location = System::Drawing::Point(743, 313);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(605, 371);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Графики";
			// 
			// checkBox_globminmax2
			// 
			this->checkBox_globminmax2->AutoSize = true;
			this->checkBox_globminmax2->Location = System::Drawing::Point(257, 112);
			this->checkBox_globminmax2->Name = L"checkBox_globminmax2";
			this->checkBox_globminmax2->Size = System::Drawing::Size(246, 17);
			this->checkBox_globminmax2->TabIndex = 36;
			this->checkBox_globminmax2->Text = L"Найти глобальные  экстремумы функции 2";
			this->checkBox_globminmax2->UseVisualStyleBackColor = true;
			this->checkBox_globminmax2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_globminmax2_CheckedChanged);
			// 
			// checkBox_globminmax1
			// 
			this->checkBox_globminmax1->AutoSize = true;
			this->checkBox_globminmax1->Location = System::Drawing::Point(257, 89);
			this->checkBox_globminmax1->Name = L"checkBox_globminmax1";
			this->checkBox_globminmax1->Size = System::Drawing::Size(246, 17);
			this->checkBox_globminmax1->TabIndex = 35;
			this->checkBox_globminmax1->Text = L"Найти глобальные  экстремумы функции 1";
			this->checkBox_globminmax1->UseVisualStyleBackColor = true;
			this->checkBox_globminmax1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_globminmax1_CheckedChanged);
			// 
			// buttonResetCheckbox
			// 
			this->buttonResetCheckbox->Location = System::Drawing::Point(150, 324);
			this->buttonResetCheckbox->Name = L"buttonResetCheckbox";
			this->buttonResetCheckbox->Size = System::Drawing::Size(157, 41);
			this->buttonResetCheckbox->TabIndex = 31;
			this->buttonResetCheckbox->Text = L"Сброс чекбоксов";
			this->buttonResetCheckbox->UseVisualStyleBackColor = true;
			this->buttonResetCheckbox->Click += gcnew System::EventHandler(this, &MyForm::buttonResetCheckbox_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(6, 324);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(138, 42);
			this->buttonClear->TabIndex = 30;
			this->buttonClear->Text = L"Очистить графики";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MyForm::buttonClear_Click);
			// 
			// buttonPanRight
			// 
			this->buttonPanRight->Location = System::Drawing::Point(87, 282);
			this->buttonPanRight->Name = L"buttonPanRight";
			this->buttonPanRight->Size = System::Drawing::Size(75, 23);
			this->buttonPanRight->TabIndex = 29;
			this->buttonPanRight->Text = L"Вправо";
			this->buttonPanRight->UseVisualStyleBackColor = true;
			this->buttonPanRight->Click += gcnew System::EventHandler(this, &MyForm::buttonPanRight_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(6, 228);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(164, 20);
			this->label6->TabIndex = 28;
			this->label6->Text = L"Панорамирование";
			// 
			// buttonPanLeft
			// 
			this->buttonPanLeft->Location = System::Drawing::Point(6, 282);
			this->buttonPanLeft->Name = L"buttonPanLeft";
			this->buttonPanLeft->Size = System::Drawing::Size(75, 23);
			this->buttonPanLeft->TabIndex = 27;
			this->buttonPanLeft->Text = L"Влево";
			this->buttonPanLeft->UseVisualStyleBackColor = true;
			this->buttonPanLeft->Click += gcnew System::EventHandler(this, &MyForm::buttonPanLeft_Click);
			// 
			// buttonPanUp
			// 
			this->buttonPanUp->Location = System::Drawing::Point(87, 253);
			this->buttonPanUp->Name = L"buttonPanUp";
			this->buttonPanUp->Size = System::Drawing::Size(75, 23);
			this->buttonPanUp->TabIndex = 26;
			this->buttonPanUp->Text = L"Вверх";
			this->buttonPanUp->UseVisualStyleBackColor = true;
			this->buttonPanUp->Click += gcnew System::EventHandler(this, &MyForm::buttonPanUp_Click);
			// 
			// buttonPanDown
			// 
			this->buttonPanDown->Location = System::Drawing::Point(6, 253);
			this->buttonPanDown->Name = L"buttonPanDown";
			this->buttonPanDown->Size = System::Drawing::Size(75, 23);
			this->buttonPanDown->TabIndex = 9;
			this->buttonPanDown->Text = L"Вниз";
			this->buttonPanDown->UseVisualStyleBackColor = true;
			this->buttonPanDown->Click += gcnew System::EventHandler(this, &MyForm::buttonPanDown_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(2, 186);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(242, 20);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Текущая точка на графике:";
			// 
			// labelCoordinates
			// 
			this->labelCoordinates->AutoSize = true;
			this->labelCoordinates->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelCoordinates->Location = System::Drawing::Point(330, 186);
			this->labelCoordinates->Name = L"labelCoordinates";
			this->labelCoordinates->Size = System::Drawing::Size(14, 20);
			this->labelCoordinates->TabIndex = 9;
			this->labelCoordinates->Text = L":";
			// 
			// checkBox_minmax2
			// 
			this->checkBox_minmax2->AutoSize = true;
			this->checkBox_minmax2->Location = System::Drawing::Point(257, 43);
			this->checkBox_minmax2->Name = L"checkBox_minmax2";
			this->checkBox_minmax2->Size = System::Drawing::Size(238, 17);
			this->checkBox_minmax2->TabIndex = 24;
			this->checkBox_minmax2->Text = L"Найти локальные экстремумы функции 2";
			this->checkBox_minmax2->UseVisualStyleBackColor = true;
			this->checkBox_minmax2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_minmax2_CheckedChanged);
			// 
			// checkBox_minmax1
			// 
			this->checkBox_minmax1->AutoSize = true;
			this->checkBox_minmax1->Location = System::Drawing::Point(257, 20);
			this->checkBox_minmax1->Name = L"checkBox_minmax1";
			this->checkBox_minmax1->Size = System::Drawing::Size(241, 17);
			this->checkBox_minmax1->TabIndex = 23;
			this->checkBox_minmax1->Text = L"Найти локальные  экстремумы функции 1";
			this->checkBox_minmax1->UseVisualStyleBackColor = true;
			this->checkBox_minmax1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_minmax1_CheckedChanged);
			// 
			// checkBox_searchCross
			// 
			this->checkBox_searchCross->AutoSize = true;
			this->checkBox_searchCross->Location = System::Drawing::Point(257, 66);
			this->checkBox_searchCross->Name = L"checkBox_searchCross";
			this->checkBox_searchCross->Size = System::Drawing::Size(227, 17);
			this->checkBox_searchCross->TabIndex = 18;
			this->checkBox_searchCross->Text = L"Найти точки пересечения двух функций";
			this->checkBox_searchCross->UseVisualStyleBackColor = true;
			this->checkBox_searchCross->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_searchCross_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(3, 65);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(128, 17);
			this->radioButton5->TabIndex = 12;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Построить 2 график";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton5_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(3, 42);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(134, 17);
			this->radioButton4->TabIndex = 11;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Построить 2 графика";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(3, 19);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(128, 17);
			this->radioButton3->TabIndex = 10;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Построить 1 график";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->справочнаяИнформацияToolStripMenuItem,
					this->выходToolStripMenuItem1
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(1348, 24);
			this->menuStrip2->TabIndex = 10;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// справочнаяИнформацияToolStripMenuItem
			// 
			this->справочнаяИнформацияToolStripMenuItem->Name = L"справочнаяИнформацияToolStripMenuItem";
			this->справочнаяИнформацияToolStripMenuItem->Size = System::Drawing::Size(161, 20);
			this->справочнаяИнформацияToolStripMenuItem->Text = L"Справочная информация";
			this->справочнаяИнформацияToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::справочнаяИнформацияToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem1
			// 
			this->выходToolStripMenuItem1->Name = L"выходToolStripMenuItem1";
			this->выходToolStripMenuItem1->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem1->Text = L"Выход";
			this->выходToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1348, 744);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->menuStrip2);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Построение и анализ графиков функций";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: static double a, b, h1, h2;
	public: static double x1, y1, x2, y2;
	private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: void DefaultParams();
    void DrawAxes();
	private:
    void BuildFirstGraph();
	private: void BuildSecondGraph();
	private: void BuildTwoGraphs();
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private:
    void ShowMinMaxMessage(List<DataPoint^>^ minPoints, List<DataPoint^>^ maxPoints);
	List<DataPoint^>^ FindMinima(List<DataPoint^>^ points);
	List<DataPoint^>^ FindMaxima(List<DataPoint^>^ points);
	System::Void checkBox_minmax1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	List<DataPoint^>^ FindGlobalMinima(List<DataPoint^>^ extremaPoints);
	List<DataPoint^>^ FindGlobalMaxima(List<DataPoint^>^ extremaPoints);
	void checkBox_globminmax1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	void checkBox_globminmax2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox_minmax2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	List<DataPoint^>^ FindIntersectionPoints(Series^ series1, Series^ series2, double epsilon);
    void HighlightIntersectionPoints(List<DataPoint^>^ intersectPoints, System::Drawing::Color color);
	void ShowIntersectionMessage(List<DataPoint^>^ intersectionPoints);
	private: System::Void checkBox_searchCross_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void chart_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	System::Void chart_MouseLeave(System::Object^ sender, System::EventArgs^ e);
	System::Void chart_MouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonPanDown_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void buttonPanUp_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void buttonPanLeft_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void buttonPanRight_Click(System::Object^ sender, System::EventArgs^ e);
	void HighlightPoints(List<DataPoint^>^ points, System::Drawing::Color color);
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonResetCheckbox_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void справочнаяИнформацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Instruction_form == nullptr || Instruction_form->IsDisposed) {
			Instruction_form = gcnew Instruction();
		}
		if (Instruction_form->Visible) {
			Instruction_form->Hide();
		}
		else {
			Instruction_form->Show();
		}
	}




};
}



