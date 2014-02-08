#pragma once
#include <stdlib.h>
#include <fstream>
#include "Client.h"
namespace Guitest1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  profileName;





	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::NumericUpDown^  SweepNumber;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  StepSize;

	private: System::Windows::Forms::NumericUpDown^  SampleSize;

	private: System::Windows::Forms::NumericUpDown^  SweepDelay;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ToolTip^  toolTip2;
	private: System::Windows::Forms::ToolTip^  toolTip3;
	private: System::Windows::Forms::ToolTip^  toolTip4;
	private: System::Windows::Forms::ToolTip^  toolTip5;
	private: System::Windows::Forms::ToolTip^  toolTip6;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;

	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButton1;
	private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Test;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;


	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripMenuItem^  teaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  SaveName;

	private: System::Windows::Forms::ComboBox^  SaveLocation;

	private: System::ComponentModel::IContainer^  components;

	protected: 









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SaveName = (gcnew System::Windows::Forms::TextBox());
			this->SaveLocation = (gcnew System::Windows::Forms::ComboBox());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->teaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->StepSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->SampleSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->SweepDelay = (gcnew System::Windows::Forms::NumericUpDown());
			this->SweepNumber = (gcnew System::Windows::Forms::NumericUpDown());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->profileName = (gcnew System::Windows::Forms::ComboBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Test = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->StepSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SampleSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SweepDelay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SweepNumber))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(5, 8);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(741, 529);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->SaveName);
			this->tabPage1->Controls->Add(this->SaveLocation);
			this->tabPage1->Controls->Add(this->chart2);
			this->tabPage1->Controls->Add(this->statusStrip1);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->radioButton3);
			this->tabPage1->Controls->Add(this->radioButton2);
			this->tabPage1->Controls->Add(this->radioButton1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(733, 500);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Control/Settings";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &Form1::tabPage1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(432, 49);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(27, 17);
			this->label7->TabIndex = 19;
			this->label7->Text = L"as:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(305, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(154, 17);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Output will be saved in:";
			// 
			// SaveName
			// 
			this->SaveName->Location = System::Drawing::Point(465, 49);
			this->SaveName->Name = L"SaveName";
			this->SaveName->Size = System::Drawing::Size(203, 22);
			this->SaveName->TabIndex = 17;
			// 
			// SaveLocation
			// 
			this->SaveLocation->FormattingEnabled = true;
			this->SaveLocation->Location = System::Drawing::Point(465, 19);
			this->SaveLocation->Name = L"SaveLocation";
			this->SaveLocation->Size = System::Drawing::Size(203, 24);
			this->SaveLocation->TabIndex = 16;
			this->SaveLocation->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(353, 129);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(356, 324);
			this->chart2->TabIndex = 15;
			this->chart2->Text = L"chart2";
			title2->Name = L"Title1";
			title2->Text = L"Place Holder Chart";
			this->chart2->Titles->Add(title2);
			this->chart2->Visible = false;
			this->chart2->Click += gcnew System::EventHandler(this, &Form1::chart2_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripDropDownButton1, 
				this->toolStripProgressBar1, this->toolStripStatusLabel1, this->toolStripStatusLabel2});
			this->statusStrip1->Location = System::Drawing::Point(353, 77);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(315, 25);
			this->statusStrip1->TabIndex = 14;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->teaToolStripMenuItem});
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(29, 23);
			this->toolStripDropDownButton1->Text = L"toolStripDropDownButton1";
			// 
			// teaToolStripMenuItem
			// 
			this->teaToolStripMenuItem->Name = L"teaToolStripMenuItem";
			this->teaToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->teaToolStripMenuItem->Text = L"tea";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(100, 19);
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(47, 20);
			this->toolStripStatusLabel1->Text = L"status";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &Form1::toolStripStatusLabel1_Click);
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(120, 20);
			this->toolStripStatusLabel2->Text = L"Time Remaining:";
			this->toolStripStatusLabel2->Click += gcnew System::EventHandler(this, &Form1::toolStripStatusLabel2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->StepSize);
			this->groupBox1->Controls->Add(this->SampleSize);
			this->groupBox1->Controls->Add(this->SweepDelay);
			this->groupBox1->Controls->Add(this->SweepNumber);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->profileName);
			this->groupBox1->Location = System::Drawing::Point(11, 77);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(310, 401);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Settings";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 220);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 17);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Step Size";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 182);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 17);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Sample Size";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 145);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(90, 17);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Sweep Delay";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 17);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Number of Sweeps";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 76);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 17);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Profile Name";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// StepSize
			// 
			this->StepSize->Location = System::Drawing::Point(169, 215);
			this->StepSize->Name = L"StepSize";
			this->StepSize->Size = System::Drawing::Size(120, 22);
			this->StepSize->TabIndex = 13;
			this->StepSize->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown4_ValueChanged);
			// 
			// SampleSize
			// 
			this->SampleSize->Location = System::Drawing::Point(169, 177);
			this->SampleSize->Name = L"SampleSize";
			this->SampleSize->Size = System::Drawing::Size(120, 22);
			this->SampleSize->TabIndex = 12;
			this->SampleSize->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown3_ValueChanged);
			// 
			// SweepDelay
			// 
			this->SweepDelay->Location = System::Drawing::Point(169, 140);
			this->SweepDelay->Name = L"SweepDelay";
			this->SweepDelay->Size = System::Drawing::Size(120, 22);
			this->SweepDelay->TabIndex = 11;
			this->SweepDelay->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown2_ValueChanged);
			// 
			// SweepNumber
			// 
			this->SweepNumber->Location = System::Drawing::Point(169, 101);
			this->SweepNumber->Name = L"SweepNumber";
			this->SweepNumber->Size = System::Drawing::Size(120, 22);
			this->SweepNumber->TabIndex = 10;
			this->SweepNumber->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(128, 341);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(161, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Start Scan";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(128, 301);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(161, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Save Settings";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// profileName
			// 
			this->profileName->FormattingEnabled = true;
			this->profileName->Location = System::Drawing::Point(116, 69);
			this->profileName->Name = L"profileName";
			this->profileName->Size = System::Drawing::Size(173, 24);
			this->profileName->TabIndex = 3;
			this->profileName->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(163, 19);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(47, 27);
			this->radioButton3->TabIndex = 11;
			this->radioButton3->Text = L"Stop";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(99, 19);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(64, 27);
			this->radioButton2->TabIndex = 10;
			this->radioButton2->Text = L"Restart";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::SystemColors::Control;
			this->radioButton1->Location = System::Drawing::Point(49, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(44, 27);
			this->radioButton1->TabIndex = 9;
			this->radioButton1->Text = L"Run";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged_1);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(733, 500);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Data";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {this->Test, this->Column1, 
				this->Column2, this->Column3, this->Column4, this->Column5, this->Column6});
			this->dataGridView1->Location = System::Drawing::Point(6, 65);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(724, 418);
			this->dataGridView1->TabIndex = 0;
			// 
			// Test
			// 
			this->Test->HeaderText = L"Column1";
			this->Test->Name = L"Test";
			this->Test->ReadOnly = true;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Column2";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Column3";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Column4";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Column5";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Column6";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(733, 500);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Graphs";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(744, 528);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->StepSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SampleSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SweepDelay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SweepNumber))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void chart2_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void toolStripStatusLabel2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void toolStripStatusLabel1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void radioButton1_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {
			
			 double vSweepNumber, vSweepDelay, vSampleSize, vStepSize;
			 vSweepNumber = Convert::ToDouble(SweepNumber->Text);	 
			 vSweepDelay = Convert::ToDouble(SweepDelay->Text);	
			 vSampleSize = Convert::ToDouble(SampleSize->Text);	
			 vStepSize = Convert::ToDouble(StepSize->Text);	

			 int parameters = 0;
			 parameters  = (int)(vSweepNumber + vSweepDelay + vSampleSize + vStepSize)%200;

			 double throughPut;
			 throughPut = ClientRun(parameters);
			 SaveName-> Text = Convert::ToString(throughPut);
			 SaveLocation-> Text = "C:\Users\Andy\Documents\GitHub\Socket_Test\GUI for the PC\Gui test 1\fwrite_test.txt";
/*			
	//Server Code. Comment to make way for client code			 
			 system("\"C:\\Users\\Andy\\Documents\\Visual Studio 2012\\Projects\\Gui test 1\\Debug\\socket test 2.exe\"");	
	 
 FILE * pFile;
  long lSize;
  char * buffer;
  size_t result;

  pFile = fopen ( "fwrite_test.txt" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,pFile);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}


  // terminate
  fclose (pFile);
  free (buffer);
  */
  
		 }	//end RUN button 
		 
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void numericUpDown3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void numericUpDown4_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};


}