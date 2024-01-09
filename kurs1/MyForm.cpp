#include "MyForm.h"
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <stack>
#include <msclr\marshal_cppstd.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include "Parser.h"
#define PI 3.14159265358979323846 
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	kurs1::MyForm form;
	Application::Run(% form);
}



System::Void kurs1::MyForm::���������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (checkBox1->Checked == false) {
		MessageBox::Show("�������� ���� �� ���� ������!", "��������!");
		return;
	}
	if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
		MessageBox::Show("��������� �� ���������!", "��������!");
		DefaultParams();
	}
	else {
		a = Convert::ToDouble(textBox1->Text);
		b = Convert::ToDouble(textBox2->Text);
		h1 = Convert::ToDouble(textBox3->Text);
	}
	
	if (checkBox1->Checked) {
		x1 = a;
		this->chart->Series[0]->Points->Clear();
		//this->chart->ChartAreas[0]->AxisX->Maximum = 10;

		//this->chart->ChartAreas[0]->AxisY->Maximum = 20000;
		// Enable range selection and zooming end user interface
		this->chart->ChartAreas[0]->CursorX->IsUserEnabled = true;
		this->chart->ChartAreas[0]->CursorX->IsUserSelectionEnabled = true;
		while (x1 <= b) {
            char* expression = ConvertStringToCharArray(textBoxFunction1->Text);
			y1 = parseExpression(expression,x1);
			this->chart->Series[0]->Points->AddXY(x1, y1);
			x1 += h1;
		}
	}
}

System::Void kurs1::MyForm::��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox1->Checked == false) {
		MessageBox::Show("�������� ���� �� ���� ������!", "��������!");
		return;
	}
	if (checkBox1->Checked) {
		this->chart->Series[0]->Points->Clear();
	}
}

System::Void kurs1::MyForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("�����?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
}

void kurs1::MyForm::DefaultParams1()
{
	a = 0;
	b = 10;
	h1 = 0.1;
	textBox1->Text = a.ToString();
	textBox2->Text = b.ToString();
	textBox3->Text = h1.ToString();
	
}



void kurs1::MyForm::DefaultParams2()
{
	c = 0;
	d = 10;
	h2 = 0.1;
	textBox4->Text = c.ToString();
	textBox5->Text = d.ToString();
	textBox6->Text = h2.ToString();
}

void kurs1::MyForm::DefaultParams()
{
	a = 0;
	b = 10;
	h1 = 0.1;
	h2 = 0.1;
	c = 0;
	d = 10;
	textBox1->Text = a.ToString();
	textBox2->Text = b.ToString();
	textBox3->Text = h1.ToString();
	textBox4->Text = c.ToString();
	textBox5->Text = d.ToString();
	textBox6->Text = h2.ToString();

}


void kurs1::MyForm::BuildFirstGraph()
{
	
	if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
		MessageBox::Show("��������� �� ���������!", "��������!");
		DefaultParams1();
	}
	else {
		a = Convert::ToDouble(textBox1->Text);
		b = Convert::ToDouble(textBox2->Text);
		h1 = Convert::ToDouble(textBox3->Text);
	}
	x1 = a;
	while (x1 <= b) {

		char* expression = ConvertStringToCharArray(textBoxFunction1->Text);
		y1 = parseExpression(expression, x1);


		this->chart->Series[0]->Points->AddXY(x1, y1);
		x1 += h1;
	}
	x1 = a;
}

void kurs1::MyForm::BuildSecondGraph()
{
	if (textBox4->Text == "" || textBox5->Text == "" || textBox6->Text == "") {
		MessageBox::Show("��������� �� ���������!", "��������!");
		DefaultParams2();
	}
	else {
		c = Convert::ToDouble(textBox4->Text);
		d = Convert::ToDouble(textBox5->Text);
		h2 = Convert::ToDouble(textBox6->Text);
	}
	x2 = c;
	while (x2 <= d) {
		char* expression = ConvertStringToCharArray(textBoxFunction2->Text);
		y2 = parseExpression(expression, x2);

		this->chart->Series[1]->Points->AddXY(x2, y2);
		x2 += h2;
	}
	x2 = c;
}


void kurs1::MyForm::BuildTwoGraphs()
{
	if ((textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") && (textBox4->Text == "" || textBox5->Text == "" || textBox6->Text == "")) {
		MessageBox::Show("��������� �� ���������!", "��������!");
		DefaultParams();
	}
	x1 = a;
	x2 = c;
	char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);
	char* expression2 = ConvertStringToCharArray(textBoxFunction2->Text);
	while (x1 <= b) {
		y1 = parseExpression(expression1, x1);
		this->chart->Series[0]->Points->AddXY(x1, y1);
		x1 += h1;
	}
	while (x2 <= d) {
		y2 = parseExpression(expression2, x2);
		this->chart->Series[1]->Points->AddXY(x2, y2);
		x2 += h2;
	}

	x1 = a;
	x2 = c;
}

System::Void kurs1::MyForm::radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{

	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();

	// ��������� ������ ������
	if (radioButton3->Checked) {
		if (textBoxFunction1->Text == "") {
			MessageBox::Show("������� �����������", "��������!");
			radioButton3->Checked = false;
			return;
		}
		BuildFirstGraph();
	}
}

System::Void kurs1::MyForm::radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{

	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();

	// ��������� ��� �������
	if (radioButton4->Checked) {
		if (textBoxFunction1->Text == "" || textBoxFunction2->Text == "") {
			MessageBox::Show("���� �� ������� �����������", "��������!");
			radioButton4->Checked = false;
			return;
		}
		BuildTwoGraphs();
	}
}

System::Void kurs1::MyForm::radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{

	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();


	if (radioButton5->Checked) {
		if (textBoxFunction2->Text == "") {
			MessageBox::Show("������� �����������", "��������!");
			radioButton5->Checked = false;
			return;
		}
		BuildSecondGraph();
	}
}




double FindMinimum(char* expression, double a, double b) {
	const double goldenRatio = (1 + sqrt(5)) / 2;
	const double epsilon = 1e-6;
	
	double x1 = b - (b - a) / goldenRatio;
	double x2 = a + (b - a) / goldenRatio;

	double f1 = parseExpression(expression, x1);
	double f2 = parseExpression(expression, x2);

	while (fabs(b - a) > epsilon) {
		if (f1 < f2) {
			b = x2;
			x2 = x1;
			f2 = f1;
			x1 = b - (b - a) / goldenRatio;
			f1 = parseExpression(expression, x1);
		}
		else {
			a = x1;
			x1 = x2;
			f1 = f2;
			x2 = a + (b - a) / goldenRatio;
			f2 = parseExpression(expression, x2);
		}
	}
	return (a + b) / 2;
}


double FindMaximum(char* expression, double a, double b) {
	const double goldenRatio = (1 + sqrt(5)) / 2;

	// ������ �������� ������
	const double epsilon = 1e-6;

	// ��������� ��������� �����
	double x1 = b - (b - a) / goldenRatio;
	double x2 = a + (b - a) / goldenRatio;

	// ��������� �������� ������� � ��������� ������
	double f1 = parseExpression(expression, x1);
	double f2 = parseExpression(expression, x2);

	// �������� �������� ������ �������� �������
	while (fabs(b - a) > epsilon) {
		if (f1 > f2) {
			b = x2;
			x2 = x1;
			f2 = f1;
			x1 = b - (b - a) / goldenRatio;
			f1 = parseExpression(expression, x1);
		}
		else {
			a = x1;
			x1 = x2;
			f1 = f2;
			x2 = a + (b - a) / goldenRatio;
			f2 = parseExpression(expression, x2);
		}
	}

	return (a + b) / 2;
}







// ������� ��� ������ ���� ����� ��������
std::vector<double> findAllMinimaGoldenSection(char* expression, double a, double b, int numPoints) {
	const double goldenRatio = (1 + sqrt(5)) / 2;

	std::vector<double> minima;  // ������ ��������� ���������
	double epsilon = 1e-6;
	for (int i = 0; i < numPoints; ++i) {
		double x1 = b - (b - a) / goldenRatio;
		double x2 = a + (b - a) / goldenRatio;

		double f1 = parseExpression(expression, x1);
		double f2 = parseExpression(expression, x2);

		while (fabs(b - a) > epsilon) {
			if (f1 < f2) {
				b = x2;
				x2 = x1;
				x1 = a + (b - a) / goldenRatio;

				f2 = f1;
				f1 = parseExpression(expression, x1);
			}
			else {
				a = x1;
				x1 = x2;
				x2 = b - (b - a) / goldenRatio;

				f1 = f2;
				f2 = parseExpression(expression, x2);
			}
		}

		// ��������� ��������� ����� �������� � ������
		minima.push_back((a + b) / 2);

		// ��������� � ���������� ���������
		a = x1;
		b = x2;
	}

	// ���������� ������ ��������� ���������
	return minima;
}

// ������� ��� ������ ���� ����� ���������
std::vector<double> findAllMaximaGoldenSection(char* expression, double a, double b, int numPoints) {
	const double goldenRatio = (1 + sqrt(5)) / 2;

	std::vector<double> maxima;  // ������ ��������� ����������
	double epsilon = 1e-6;
	for (int i = 0; i < numPoints; ++i) {
		double x1 = b - (b - a) / goldenRatio;
		double x2 = a + (b - a) / goldenRatio;

		double f1 = parseExpression(expression, x1);
		double f2 = parseExpression(expression, x2);

		while (fabs(b - a) > epsilon) {
			if (f1 > f2) {
				b = x2;
				x2 = x1;
				x1 = a + (b - a) / goldenRatio;

				f2 = f1;
				f1 = parseExpression(expression, x1);
			}
			else {
				a = x1;
				x1 = x2;
				x2 = b - (b - a) / goldenRatio;

				f1 = f2;
				f2 = parseExpression(expression, x2);
			}
		}

		// ��������� ��������� ����� ��������� � ������
		maxima.push_back((a + b) / 2);

		// ��������� � ���������� ���������
		a = x1;
		b = x2;
	}

	// ���������� ������ ��������� ����������
	return maxima;
}

System::Void kurs1::MyForm::checkBox_minmax1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox_minmax1->Checked && radioButton3->Checked) {
		try {
			// ��������� ������� �������� � �����������
			if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
				MessageBox::Show("������� ��������� ��� ������ �������� � ���������.", "��������!");
				checkBox_minmax1->Checked = false; // ������� ����� ��������
				return;
			}

			// �������� �������� �� �����������
			double a = Convert::ToDouble(textBox1->Text);
			double b = Convert::ToDouble(textBox2->Text);

			// �������� ����� ��������� �� ����������
			char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);

			// �������� ������� ������ ���� ����� �������� � ��������� ��� ������ �������
			std::vector<double> allMinima = findAllMinimaGoldenSection(expression1, a, b, 5);
			std::vector<double> allMaxima = findAllMaximaGoldenSection(expression1, a, b, 5);

			// ������� ��������� � MessageBox ��� ������ ������, ������� �� �������������
			String^ resultMessage = "��� ����� �������� ������� 1: ";
			for (double minimum : allMinima) {
				resultMessage += minimum.ToString() + " ";
			}
			resultMessage += "\n��� ����� ��������� ������� 1: ";
			for (double maximum : allMaxima) {
				resultMessage += maximum.ToString() + " ";
			}

			MessageBox::Show(resultMessage, "���������");
			checkBox_minmax1->Checked = false;
		}
		catch (System::FormatException^ ex) {
			// ��������� ������, ��������� � ������������ �������� �����
			MessageBox::Show("������ ������� �����. ��������� ��������� ��������.", "������");
		}
		catch (System::Exception^ ex) {
			// ��������� ������ ����������
			MessageBox::Show("��������� ������: " + ex->Message, "������");
		}
	}
	else if (!radioButton3->Checked) {
		MessageBox::Show("������ ������� ����������� / ������� �� ������", "��������!");
		checkBox_minmax1->Checked = false;
		return;
	}
}


//
//System::Void kurs1::MyForm::checkBox_minmax1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
//{
//	if (checkBox_minmax1->Checked && radioButton3->Checked) {
//		try {
//			// ��������� ������� �������� � �����������
//			if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
//				MessageBox::Show("������� ��������� ��� ������ �������� � ���������.", "��������!");
//				checkBox_minmax1->Checked = false; // ������� ����� ��������
//				return;
//			}
//
//			// �������� �������� �� �����������
//			double a = Convert::ToDouble(textBox1->Text);
//			double b = Convert::ToDouble(textBox2->Text);
//
//			// �������� ����� ��������� �� ����������
//			char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);
//
//			// �������� ������� ������ �������� � ��������� ��� ������ �������
//			double minimum1 = FindMinimum(expression1, a, b);
//			double maximum1 = FindMaximum(expression1, a, b);
//
//			// ������� ��������� � MessageBox ��� ������ ������, ������� �� �������������
//			MessageBox::Show("������� ������� 1: " + minimum1 + "\n�������� ������� 1: " + maximum1, "���������");
//			checkBox_minmax1->Checked = false;
//		}
//		catch (System::FormatException^ ex) {
//			// ��������� ������, ��������� � ������������ �������� �����
//			MessageBox::Show("������ ������� �����. ��������� ��������� ��������.", "������");
//		}
//		catch (System::Exception^ ex) {
//			// ��������� ������ ����������
//			MessageBox::Show("��������� ������: " + ex->Message, "������");
//		}
//	}
//	else if (!radioButton3->Checked) {
//		MessageBox::Show("������ ������� ����������� / ������� �� ������", "��������!");
//		checkBox_minmax1->Checked = false;
//		return;
//	}
//}

System::Void kurs1::MyForm::checkBox_minmax2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox_minmax2->Checked && radioButton5->Checked) {
		try {
			// ��������� ������� �������� � �����������
			if (textBox4->Text == "" || textBox5->Text == "" || textBox6->Text == "") {
				MessageBox::Show("������� ��������� ��� ������ �������� � ���������.", "��������!");
				checkBox_minmax2->Checked = false; // ������� ����� ��������
				return;
			}

			// �������� �������� �� �����������
			double � = Convert::ToDouble(textBox4->Text);
			double d = Convert::ToDouble(textBox5->Text);

			// �������� ����� ��������� �� ����������
			char* expression2 = ConvertStringToCharArray(textBoxFunction2->Text);

			// �������� ������� ������ �������� � ��������� ��� ������ �������
			double minimum2 = FindMinimum(expression2, c, d);
			double maximum2 = FindMaximum(expression2, c, d);

			// ������� ��������� � MessageBox ��� ������ ������, ������� �� �������������
			MessageBox::Show("������� ������� 2: " + minimum2 + "\n�������� ������� 2: " + maximum2, "���������");
			checkBox_minmax1->Checked = false;
		}
		catch (System::FormatException^ ex) {
			// ��������� ������, ��������� � ������������ �������� �����
			MessageBox::Show("������ ������� �����. ��������� ��������� ��������.", "������");
		}
		catch (System::Exception^ ex) {
			// ��������� ������ ����������
			MessageBox::Show("��������� ������: " + ex->Message, "������");
		}
	}
	else if (!radioButton5->Checked) {
		MessageBox::Show("������ ������� ����������� / ������� �� ������", "��������!");
		checkBox_minmax2->Checked = false;
		return;
	}
}

// ������� ��� ������ ����� ����������� ���� ������� ������� ��������
double findIntersection(char* expression1, char* expression2, double a, double b) {
	const double EPSILON = 1e-9;

	double fa = parseExpression(expression1, a) - parseExpression(expression2, a);

	// ��������, ��������, ���� �� ����� ��� �������� ������������
	if (fabs(fa) < EPSILON) {
		return a;
	}

	double fb = parseExpression(expression1, b) - parseExpression(expression2, b);

	// ��������, ��������, ���� �� ����� ��� �������� ������������
	if (fabs(fb) < EPSILON) {
		return b;
	}

	// ��������, ��������, ��������� ����� ��� �������� ������������
	if (fa * fb > 0) {
		return std::numeric_limits<double>::quiet_NaN();  // ��� ����� �� ������ ���������
	}

	while (b - a >= EPSILON) {
		double c = (a + b) / 2;
		double fc = parseExpression(expression1, c) - parseExpression(expression2, c);

		// ��������, ��������, ������� ����� ��� �������� ������������
		if (fabs(fc) < EPSILON) {
			return c;
		}

		// ���� ������ �� �������� ���������
		if (fc * fa < 0) {
			b = c;
		}
		else {
			a = c;
			fa = fc;
		}
	}

	return (a + b) / 2;  // ���������� �������� ���������� ���������
}

double kurs1::MyForm::MyFunction1(double x) {
	// ��������� ����� ������� �� ����������
	char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);

	// ��������� ������� � �������� �����
	return parseExpression(expression1, x);
}


//std::vector<double> findAllIntersections(char* expression1, char* expression2, double a, double b, double step) {
//	std::vector<double> intersections;
//	double epsilon = 1e-9;
//	for (double x = a; x <= b; x += step) {
//		double y1 = parseExpression(expression1, x);
//		double y2 = parseExpression(expression2, x);
//
//		// ���������, ��������� �� �����������
//		if (fabs(y1 - y2) < epsilon) {
//			intersections.push_back(x);
//		}
//	}
//
//	return intersections;
//}
//
//
//
//void kurs1::MyForm::DisplayAllIntersections(std::vector<double> intersections) {
//	System::Windows::Forms::DataVisualization::Charting::Series^ intersectionSeries = nullptr;
//
//	// ����� ����� ����� ����������� � ������������ ������
//	for each (System::Windows::Forms::DataVisualization::Charting::Series ^ series in chart->Series) {
//		if (series->Name == "IntersectionSeries") {
//			intersectionSeries = series;
//			break;
//		}
//	}
//	// ���� ����� ����� ����������� ���, �������� ����� �����
//	if (intersectionSeries == nullptr) {
//		intersectionSeries = gcnew System::Windows::Forms::DataVisualization::Charting::Series();
//		intersectionSeries->Name = "IntersectionSeries";
//		chart->Series->Add(intersectionSeries);
//	}
//
//	// �������� ���������� ����� � ����� ����� �����������
//	intersectionSeries->Points->Clear();
//
//	// �������� ����� ����� ����������� � �������� �� � ����� ����� �����������
//	for (double intersection : intersections) {
//		System::Windows::Forms::DataVisualization::Charting::DataPoint^ intersectionPoint = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(intersection, MyFunction1(intersection));
//		intersectionPoint->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
//		intersectionPoint->MarkerSize = 10;
//		intersectionPoint->Color = System::Drawing::Color::Red;
//		intersectionSeries->Points->Add(intersectionPoint);
//	}
//
//	// �������� ������
//	chart->Invalidate();
//}

void kurs1::MyForm::DisplayIntersectionPoint(double x) {
	// ��������������, ��� � ��� ��� ���� ������������ ������� � chart1

	System::Windows::Forms::DataVisualization::Charting::Series^ intersectionSeries = nullptr;

	// ����� ����� ����� ����������� � ������������ ������
	for each (System::Windows::Forms::DataVisualization::Charting::Series ^ series in chart->Series) {
		if (series->Name == "IntersectionSeries") {
			intersectionSeries = series;
			break;
		}
	}

	// ���� ����� ����� ����������� ���, �������� ����� �����
	if (intersectionSeries == nullptr) {
		intersectionSeries = gcnew System::Windows::Forms::DataVisualization::Charting::Series();
		intersectionSeries->Name = "IntersectionSeries";
		chart->Series->Add(intersectionSeries);
	}

	// �������� ���������� ����� � ����� ����� �����������
	intersectionSeries->Points->Clear();

	// �������� ����� ����� ����������� � �������� �� � ����� ����� �����������
	System::Windows::Forms::DataVisualization::Charting::DataPoint^ intersectionPoint = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(x, MyFunction1(x));
	intersectionPoint->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
	intersectionPoint->MarkerSize = 10;
	intersectionPoint->Color = System::Drawing::Color::Red;
	intersectionSeries->Points->Add(intersectionPoint);

	// �������� ������
	chart->Invalidate();
}







System::Void kurs1::MyForm::checkBox_searchCross_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox_searchCross->Checked && radioButton4->Checked) {
		try {
			// ��������� ������� �������� � �����������
			if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "" || textBox4->Text == "" || textBox5->Text == "" || textBox6->Text == "") {
				MessageBox::Show("������� ��������� ��� ������ �����������.", "��������!");
				checkBox_searchCross->Checked = false; // ������� ����� ��������
				return;
			}

			// �������� �������� �� �����������
			double a1 = Convert::ToDouble(textBox1->Text);
			double b1 = Convert::ToDouble(textBox2->Text);
			double h1 = Convert::ToDouble(textBox3->Text);

			double a2 = Convert::ToDouble(textBox4->Text);
			double b2 = Convert::ToDouble(textBox5->Text);
			double h2 = Convert::ToDouble(textBox6->Text);

			// �������� ����� ��������� �� �����������
			char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);
			char* expression2 = ConvertStringToCharArray(textBoxFunction2->Text);
			// �������� ������� ������ ���� ����� �����������
			/*std::vector<double> allIntersections = findAllIntersections(expression1, expression2, Math::Max(a1, a2), Math::Min(b1, b2), 0.01);*/
			// �������� ������� ������ ����� �����������
			double intersectionPoint = findIntersection(expression1, expression2, a1, b1);
			// ������� ��������� � MessageBox ��� ������ ������, ������� �� �������������
			String^ resultMessage = "��� ����� ����������� �������: ";
			//for (double intersection : allIntersections) {
			//	resultMessage += intersection.ToString() + " ";
			//}
			// ������� ������ � ���������� ����� �����������
			DisplayIntersectionPoint(intersectionPoint);

			//MessageBox::Show(resultMessage, "���������");
			MessageBox::Show("����� ����������� �������: " + intersectionPoint.ToString(), "���������");
		}
		catch (System::FormatException^ ex) {
			// ��������� ������, ��������� � ������������ �������� �����
			MessageBox::Show("������ ������� �����. ��������� ��������� ��������.", "������");
		}
		catch (System::Exception^ ex) {
			// ��������� ������ ����������
			MessageBox::Show("��������� ������: " + ex->Message, "������");
		}
	}
	else if (!radioButton4->Checked) {
		MessageBox::Show("������ ������� ����������� / ������� �� ������", "��������!");
		checkBox_searchCross->Checked = false;
		return;
	}
}


