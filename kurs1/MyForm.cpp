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
using namespace System::Collections::Generic;  // Добавление это для использования List
using namespace System::Windows::Forms::DataVisualization::Charting;  // Добавление этого для использования DataPoint
[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	kurs1::MyForm form;
	Application::Run(% form);
}

System::Void kurs1::MyForm::buttonClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();
	radioButton3->Checked = false;
	radioButton4->Checked = false;
	radioButton5->Checked = false;
	checkBox_minmax1->Checked = false;
	checkBox_minmax2->Checked = false;
	checkBox_searchCross->Checked = false;
}

System::Void kurs1::MyForm::buttonResetCheckbox_Click(System::Object^ sender, System::EventArgs^ e)
{
	checkBox_minmax1->Checked = false;
	checkBox_minmax2->Checked = false;
	checkBox_searchCross->Checked = false;
}






System::Void kurs1::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Выйти?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
}



void kurs1::MyForm::DefaultParams()
{
	a = -10;
	b = 10;
	h1 = 0.01;
	textBox1->Text = a.ToString();
	textBox2->Text = b.ToString();
	textBox3->Text = h1.ToString();


}



void kurs1::MyForm::DrawAxes() {
	// Рисуем ось X
	this->chart->ChartAreas[0]->AxisX->MajorGrid->LineColor = System::Drawing::Color::Black;
	this->chart->ChartAreas[0]->AxisX->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
	this->chart->ChartAreas[0]->AxisX->Crossing = 0; // Проходит через начало координат
	this->chart->ChartAreas[0]->AxisX->LineWidth = 2;

	// Рисуем ось Y
	this->chart->ChartAreas[0]->AxisY->MajorGrid->LineColor = System::Drawing::Color::Black;
	this->chart->ChartAreas[0]->AxisY->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
	this->chart->ChartAreas[0]->AxisY->Crossing = 0; // Проходит через начало координат
	this->chart->ChartAreas[0]->AxisY->LineWidth = 2;
}




// Function to convert System::String to char array
char* ConvertStringToCharArray(System::String^ str) {
	cli::pin_ptr<const wchar_t> wch = PtrToStringChars(str);
	int len = wcslen(wch);
	char* ch = new char[len + 1];
	wcstombs(ch, wch, len + 1);
	return ch;
}


void kurs1::MyForm::BuildFirstGraph()
{

	if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
		MessageBox::Show("Параметры по умолчанию!", "Внимание!");
		DefaultParams();
	}
	else {
		a = Convert::ToDouble(textBox1->Text);
		b = Convert::ToDouble(textBox2->Text);
		h1 = Convert::ToDouble(textBox3->Text);
	}
	x1 = a;
	Solver sol1;
	char* expression = ConvertStringToCharArray(textBoxFunction1->Text);
	if (sol1.Load(expression)) {
		while (x1 <= b) {
			y1 = sol1.Solve(x1);
			this->chart->Series[0]->Points->AddXY(x1, y1);
			x1 += 0.01;
		}
	}
	DrawAxes();
	x1 = a;
}

void kurs1::MyForm::BuildSecondGraph()
{

	if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
		MessageBox::Show("Параметры по умолчанию!", "Внимание!");
		DefaultParams();
	}
	else {
		a = Convert::ToDouble(textBox1->Text);
		b = Convert::ToDouble(textBox2->Text);
		h1 = Convert::ToDouble(textBox3->Text);
	}
	x2 = a;
	Solver sol1;
	char* expression = ConvertStringToCharArray(textBoxFunction2->Text);
	if (sol1.Load(expression)) {
		while (x2 <= b) {
			y2 = sol1.Solve(x2);
			this->chart->Series[1]->Points->AddXY(x2, y2);
			x2 += 0.01;
		}
	}
	DrawAxes();
	x2 = a;
}


void kurs1::MyForm::BuildTwoGraphs()
{
	if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
		MessageBox::Show("Параметры по умолчанию!", "Внимание!");
		DefaultParams();
	}
	x1 = a;
	x2 = x1;
	char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);
	char* expression2 = ConvertStringToCharArray(textBoxFunction2->Text);
	Solver sol1;
	Solver sol2;
	if (sol1.Load(expression1)) {
		while (x1 <= b) {
			y1 = sol1.Solve(x1);
			this->chart->Series[0]->Points->AddXY(x1, y1);
			x1 += 0.01;
		}
	}
	x1 = a;
	if (sol2.Load(expression2)) {
		while (x2 <= b) {
			y2 = sol2.Solve(x2);
			this->chart->Series[1]->Points->AddXY(x2, y2);
			x2 += 0.01;
		}
	}
	DrawAxes();
	x2 = a;
}

bool isGraph1Built = false;
bool isGraph2Built = false;

System::Void kurs1::MyForm::radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{

	isGraph1Built = true;
	isGraph2Built = false;
	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();
	//this->chart->ChartAreas[0]->RecalculateAxesScale();
	// Настройка оси Y для первой серии
	this->chart->ChartAreas[0]->AxisY->Minimum = -10; // Минимальное значение Y
	this->chart->ChartAreas[0]->AxisY->Maximum = 10;  // Максимальное значение Y
	this->chart->ChartAreas[0]->AxisY->Interval = 0.5; // Интервал между делениями оси Y
	// Постройте первый график
	if (radioButton3->Checked) {
		if (textBoxFunction1->Text == "") {
			MessageBox::Show("Функция отсутствует", "Внимание!");
			radioButton3->Checked = false;
			return;
		}
		BuildFirstGraph();
	}
}

System::Void kurs1::MyForm::radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	isGraph1Built = true;
	isGraph2Built = true;
	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();
	//this->chart->ChartAreas[0]->RecalculateAxesScale();
	this->chart->ChartAreas[0]->AxisY->Minimum = -10; // Минимальное значение Y
	this->chart->ChartAreas[0]->AxisY->Maximum = 10;  // Максимальное значение Y
	this->chart->ChartAreas[0]->AxisY->Interval = 0.5; // Интервал между делениями оси Y
	// Постройте два графика
	if (radioButton4->Checked) {
		if (textBoxFunction1->Text == "" || textBoxFunction2->Text == "") {
			MessageBox::Show("Одна из функций отсутствует", "Внимание!");
			radioButton4->Checked = false;
			return;
		}
		BuildTwoGraphs();
	}
}

System::Void kurs1::MyForm::radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	isGraph1Built = false;
	isGraph2Built = true;
	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();
	//this->chart->ChartAreas[0]->RecalculateAxesScale();
	this->chart->ChartAreas[0]->AxisY->Minimum = -10; // Минимальное значение Y
	this->chart->ChartAreas[0]->AxisY->Maximum = 10;  // Максимальное значение Y
	this->chart->ChartAreas[0]->AxisY->Interval = 0.5; // Интервал между делениями оси Y
	if (radioButton5->Checked) {
		if (textBoxFunction2->Text == "") {
			MessageBox::Show("Функция отсутствует", "Внимание!");
			radioButton5->Checked = false;
			return;
		}
		BuildSecondGraph();
	}
}





void kurs1::MyForm::HighlightMinMaxPoints() {
	if (isGraph1Built || isGraph2Built) {
		// Списки для хранения минимумов и максимумов
		List<DataPoint^>^ minPoints = gcnew List<DataPoint^>();
		List<DataPoint^>^ maxPoints = gcnew List<DataPoint^>();

		// Минимальное и максимальное значение Y на графике
		double minY = std::numeric_limits<double>::infinity();
		double maxY = -std::numeric_limits<double>::infinity();

		// Поиск минимумов и максимумов по всем сериям графика
		for each (Series ^ series in chart->Series) {
			for each (DataPoint ^ point in series->Points) {
				double yValue = point->YValues[0];

				// Проверка на минимум
				if (yValue < minY) {
					minY = yValue;
					minPoints->Clear();
					minPoints->Add(point);
				}
				else if (yValue == minY) {
					minPoints->Add(point);
				}

				// Проверка на максимум
				if (yValue > maxY) {
					maxY = yValue;
					maxPoints->Clear();
					maxPoints->Add(point);
				}
				else if (yValue == maxY) {
					maxPoints->Add(point);
				}
			}
		}

		// Подсветка минимумов и максимумов
		HighlightPoints(minPoints, System::Drawing::Color::Blue);
		HighlightPoints(maxPoints, System::Drawing::Color::Green);
	}
}


void kurs1::MyForm::HighlightPoints(List<DataPoint^>^ points, System::Drawing::Color color) {
	for each (DataPoint ^ point in points) {
		point->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
		point->MarkerSize = 15;
		point->MarkerColor = color;
	}
}



void kurs1::MyForm::ShowMinMaxMessage(List<DataPoint^>^ minPoints, List<DataPoint^>^ maxPoints) {
	// Вывод результатов в MessageBox
	String^ resultMessage = "Минимумы:\n";
	for each (DataPoint ^ point in minPoints) {
		resultMessage += String::Format("X: {0:F2}, Y: {1:F2}\n", point->XValue, point->YValues[0]);
	}

	resultMessage += "\nМаксимумы:\n";
	for each (DataPoint ^ point in maxPoints) {
		resultMessage += String::Format("X: {0:F2}, Y: {1:F2}\n", point->XValue, point->YValues[0]);
	}

	MessageBox::Show(resultMessage, "Минимумы и максимумы");
}


double CalculateDerivative(DataPoint^ point1, DataPoint^ point2) {
	if (point2->XValue == point1->XValue) {
		// Обработка случая, когда точки имеют одинаковое значение X
		return 0.0; 
	}
	// Вычисление производной между двумя точками
	return (point2->YValues[0] - point1->YValues[0]) / (point2->XValue - point1->XValue);
}

List<DataPoint^>^ kurs1::MyForm::FindMinima(List<DataPoint^>^ points) {
	if (isGraph1Built) {
		List<DataPoint^>^ minimaPoints = gcnew List<DataPoint^>();
		Solver sol;
		char* expression = ConvertStringToCharArray(textBoxFunction1->Text);
		if (!sol.Load(expression)) {
			return nullptr;
		}
		double pastPos = sol.Solve(a - h1);
		bool pastCons = pastPos > sol.Solve(a);
		int count = 0;
		double minimum = DBL_MAX;
		for (double i = a; i <= b; i += h1) {
			double y = sol.Solve(i);
			bool currCons = pastPos > y;
			if (pastCons && !currCons) {
				//if (sol.Solve(i) < minimum) {
				//	minimum = sol.Solve(i);
				//	minimaPoints->Clear();
				//}
				chart->Series[4]->Points->AddXY(i, sol.Solve(i));
				minimaPoints->Add(chart->Series[4]->Points[count]);
				count++;
			}
			pastPos = y;
			pastCons = currCons;
		}
		return minimaPoints;
	}
	else if (isGraph2Built) {
		List<DataPoint^>^ minimaPoints = gcnew List<DataPoint^>();
		Solver sol;
		char* expression = ConvertStringToCharArray(textBoxFunction2->Text);
		if (!sol.Load(expression)) {
			return nullptr;
		}
		double pastPos = sol.Solve(a - h1);
		bool pastCons = pastPos > sol.Solve(a);
		int count = 0;
		for (double i = a; i <= b; i += h1) {
			double y = sol.Solve(i);
			bool currCons = pastPos > y;
			if (pastCons && !currCons) {
				chart->Series[4]->Points->AddXY(i, sol.Solve(i));
				minimaPoints->Add(chart->Series[4]->Points[count]);
				count++;
			}
			pastPos = y;
			pastCons = currCons;
		}
	    return minimaPoints;
	}
	/*List<DataPoint^>^ minimaPoints = gcnew List<DataPoint^>();*/

	//for (int i = 1; i < points->Count - 1; ++i) {
	//	double derivative1 = CalculateDerivative(points[i - 1], points[i]);
	//	double derivative2 = CalculateDerivative(points[i], points[i + 1]);

	//	// Проверка на изменение направления производной (минимум)
	//	if (derivative1 > 0 && derivative2 < 0) {
	//		minimaPoints->Add(points[i]);
	//	}
	//}

	//return minimaPoints;
}

List<DataPoint^>^ kurs1::MyForm::FindMaxima(List<DataPoint^>^ points) {
	if (isGraph1Built) {
		List<DataPoint^>^ maximaPoints = gcnew List<DataPoint^>();
		Solver sol;
		char* expression = ConvertStringToCharArray(textBoxFunction1->Text);
		if (!sol.Load(expression)) {
			return nullptr;
		}
		double pastPos = sol.Solve(a - h1);
		bool pastCons = pastPos > sol.Solve(a);
		int count = 0;
		double maximum = -DBL_MAX;
		for (double i = a; i <= b; i += h1) {
			double y = sol.Solve(i);
			bool currCons = pastPos > y;
			if (!pastCons && currCons) {
				chart->Series[5]->Points->AddXY(i, sol.Solve(i));
				maximaPoints->Add(chart->Series[5]->Points[count]);
				count++;
			}
			pastPos = y;
			pastCons = currCons;
		}
		return maximaPoints;
	}
	else if (isGraph2Built) {
		List<DataPoint^>^ maximaPoints = gcnew List<DataPoint^>();
		Solver sol;
		char* expression = ConvertStringToCharArray(textBoxFunction2->Text);
		if (!sol.Load(expression)) {
			return nullptr;
		}
		double pastPos = sol.Solve(a - h1);
		bool pastCons = pastPos > sol.Solve(a);
		int count = 0;
		double maximum = -DBL_MAX;
		for (double i = a; i <= b; i += h1) {
			double y = sol.Solve(i);
			bool currCons = pastPos > y;
			if (!pastCons && currCons) {
				chart->Series[5]->Points->AddXY(i, sol.Solve(i));
				maximaPoints->Add(chart->Series[5]->Points[count]);
				count++;
			}
			pastPos = y;
			pastCons = currCons;
		}
		return maximaPoints;
	}
	//List<DataPoint^>^ maximaPoints = gcnew List<DataPoint^>();

	//for (int i = 1; i < points->Count - 1; ++i) {
	//	double derivative1 = CalculateDerivative(points[i - 1], points[i]);
	//	double derivative2 = CalculateDerivative(points[i], points[i + 1]);

	//	// Проверка на изменение направления производной (максимум)
	//	if (derivative1 < 0 && derivative2 > 0) {
	//		maximaPoints->Add(points[i]);
	//	}
	//}

	//return maximaPoints;
}

void kurs1::MyForm::checkBox_minmax1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox_minmax1->Checked) {
		List<DataPoint^>^ allPoints = gcnew List<DataPoint^>();

		if (isGraph1Built) {
			// Собираем все точки с графика в один список
			for each (Series ^ series in chart->Series) {
				allPoints->AddRange(series->Points);
			}

			// Ищем минимумы и максимумы
			List<DataPoint^>^ minimaPoints = FindMinima(allPoints);
			List<DataPoint^>^ maximaPoints = FindMaxima(allPoints);

			// Подсветка минимумов и максимумов
			HighlightPoints(minimaPoints, System::Drawing::Color::Yellow);
			HighlightPoints(maximaPoints, System::Drawing::Color::Green);

			// Вывод результатов в MessageBox
			ShowMinMaxMessage(minimaPoints, maximaPoints);
		}
		else {
			checkBox_minmax1->Checked = false;
			MessageBox::Show("График не построен.", "Внимание!");
		}
	}
	else {
		chart->Series[4]->Points->Clear();
		chart->Series[5]->Points->Clear();
	}
}



System::Void kurs1::MyForm::checkBox_minmax2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox_minmax2->Checked) {
		List<DataPoint^>^ allPoints = gcnew List<DataPoint^>();

		if (isGraph2Built) {
			// Собираем все точки с графика в один список
			for each (Series ^ series in chart->Series) {
				allPoints->AddRange(series->Points);
			}

			// Ищем минимумы и максимумы
			List<DataPoint^>^ minimaPoints = FindMinima(allPoints);
			List<DataPoint^>^ maximaPoints = FindMaxima(allPoints);

			// Подсветка минимумов и максимумов
			HighlightPoints(minimaPoints, System::Drawing::Color::Yellow);
			HighlightPoints(maximaPoints, System::Drawing::Color::Green);

			// Вывод результатов в MessageBox
			ShowMinMaxMessage(minimaPoints, maximaPoints);
		}
		else {
			checkBox_minmax2->Checked = false;
			MessageBox::Show("График не построен.", "Внимание!");
		}
	}
	else {
		chart->Series[4]->Points->Clear();
		chart->Series[5]->Points->Clear();
	}
}


List<DataPoint^>^ kurs1::MyForm::FindGlobalMinima(List<DataPoint^>^ Points) {
	if (isGraph1Built) {
		List<DataPoint^>^ minimaPoints = gcnew List<DataPoint^>();
		Solver sol;
		char* expression = ConvertStringToCharArray(textBoxFunction1->Text);
		if (!sol.Load(expression)) {
			return nullptr;
		}
		int count = 0;
		double minimum = DBL_MAX;
		for (double i = a; i <= b; i += h1) {
			double y = sol.Solve(i);
			if (sol.Solve(i) <= minimum) {
				if (sol.Solve(i) < minimum) {
					minimum = sol.Solve(i);
					minimaPoints->Clear();
				}
				chart->Series[6]->Points->AddXY(i, sol.Solve(i));
				minimaPoints->Add(chart->Series[6]->Points[count]);
				count++;
			}
		}
		return minimaPoints;
	}
	else if (isGraph2Built) {
		List<DataPoint^>^ minimaPoints = gcnew List<DataPoint^>();
		Solver sol;
		char* expression = ConvertStringToCharArray(textBoxFunction2->Text);
		if (!sol.Load(expression)) {
			return nullptr;
		}
		double minimum = DBL_MAX;
		int count = 0;
		for (double i = a; i <= b; i += h1) {
			double y = sol.Solve(i);
			bool pred = sol.Solve(i - h1) > y;
			bool now = sol.Solve(i + h1) > y;
			if (sol.Solve(i) <= minimum) {
				if (sol.Solve(i) < minimum) {
					minimum = sol.Solve(i);
					minimaPoints->Clear();
				}
				chart->Series[6]->Points->AddXY(i, sol.Solve(i));
				minimaPoints->Add(chart->Series[6]->Points[count]);
				count++;
			}
		}
		return minimaPoints;
	}
}

List<DataPoint^>^ kurs1::MyForm::FindGlobalMaxima(List<DataPoint^>^ Points) {
	if (isGraph1Built) {
		List<DataPoint^>^ maximaPoints = gcnew List<DataPoint^>();
		Solver sol;
		char* expression = ConvertStringToCharArray(textBoxFunction1->Text);
		if (!sol.Load(expression)) {
			return nullptr;
		}
		int count = 0;
		double maximum = -DBL_MAX;
		for (double i = a; i <= b; i += h1) {
			double y = sol.Solve(i);
			bool pred = sol.Solve(i - h1) < y;
			bool now = sol.Solve(i + h1) < y;

			if (sol.Solve(i) >= maximum) {
				if (sol.Solve(i) > maximum) {
					maximum = sol.Solve(i);
					maximaPoints->Clear();
				}
				chart->Series[7]->Points->AddXY(i, sol.Solve(i));
				maximaPoints->Add(chart->Series[7]->Points[count]);
				count++;
			}
		}
		return maximaPoints;
	}
	else if (isGraph2Built) {
		List<DataPoint^>^ maximaPoints = gcnew List<DataPoint^>();
		Solver sol;
		char* expression = ConvertStringToCharArray(textBoxFunction2->Text);
		if (!sol.Load(expression)) {
			return nullptr;
		}
		int count = 0;
		double maximum = -DBL_MAX;
		for (double i = a; i <= b; i += h1) {
			double y = sol.Solve(i);
			bool pred = sol.Solve(i - h1) < y;
			bool now = sol.Solve(i + h1) < y;
			if (sol.Solve(i) >= maximum) {
				if (sol.Solve(i) > maximum) {
					maximum = sol.Solve(i);
					maximaPoints->Clear();
				}
				chart->Series[7]->Points->AddXY(i, sol.Solve(i));
				maximaPoints->Add(chart->Series[7]->Points[count]);
				count++;
			}
		}
		return maximaPoints;
	}
}





void kurs1::MyForm::checkBox_globminmax1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox_globminmax1->Checked) {
		List<DataPoint^>^ allPoints = gcnew List<DataPoint^>();

		if (isGraph1Built) {
			// Собираем все точки с графика в один список
			for each (Series ^ series in chart->Series) {
				allPoints->AddRange(series->Points);
			}
			// Разделяем минимумы и максимумы
			List<DataPoint^>^ minima = FindGlobalMinima(allPoints);
			List<DataPoint^>^ maxima = FindGlobalMaxima(allPoints);

			// Подсветка минимумов и максимумов
			HighlightPoints(minima, System::Drawing::Color::Blue);
			HighlightPoints(maxima, System::Drawing::Color::Green);

			// Вывод результатов в MessageBox
			ShowMinMaxMessage(minima, maxima);
		}
		else {
			checkBox_globminmax1->Checked = false;
			MessageBox::Show("График не построен.", "Внимание!");
		}
	}
	else {
		List<DataPoint^>^ allPoints = gcnew List<DataPoint^>();
		for each (Series ^ series in chart->Series) {
			allPoints->AddRange(series->Points);
		}
		List<DataPoint^>^ minima = FindGlobalMinima(allPoints);
		List<DataPoint^>^ maxima = FindGlobalMaxima(allPoints);
		HighlightPoints(minima, System::Drawing::Color::Transparent);
		HighlightPoints(maxima, System::Drawing::Color::Transparent);
	}
}


void kurs1::MyForm::checkBox_globminmax2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox_globminmax2->Checked) {
		List<DataPoint^>^ allPoints = gcnew List<DataPoint^>();

		if (isGraph2Built) {
			// Собираем все точки с графика в один список
			for each (Series ^ series in chart->Series) {
				allPoints->AddRange(series->Points);
			}
			// Разделяем минимумы и максимумы
			List<DataPoint^>^ minima = FindGlobalMinima(allPoints);
			List<DataPoint^>^ maxima = FindGlobalMaxima(allPoints);

			// Подсветка минимумов и максимумов
			HighlightPoints(minima, System::Drawing::Color::Blue);
			HighlightPoints(maxima, System::Drawing::Color::Green);

			// Вывод результатов в MessageBox
			ShowMinMaxMessage(minima, maxima);
		}
		else {
			checkBox_globminmax2->Checked = false;
			MessageBox::Show("График не построен.", "Внимание!");
		}
	}
	else {
		List<DataPoint^>^ allPoints = gcnew List<DataPoint^>();
		for each (Series ^ series in chart->Series) {
			allPoints->AddRange(series->Points);
		}
		List<DataPoint^>^ minima = FindGlobalMinima(allPoints);
		List<DataPoint^>^ maxima = FindGlobalMaxima(allPoints);
		HighlightPoints(minima, System::Drawing::Color::Transparent);
		HighlightPoints(maxima, System::Drawing::Color::Transparent);
	}
}








List<DataPoint^>^ kurs1::MyForm::FindIntersectionPoints(Series^ series1, Series^ series2, double epsilon) {
	List<DataPoint^>^ intersectPoints = gcnew List<DataPoint^>();
	Solver difference;
	Solver sol;
	char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);
	char* expression = ConvertStringToCharArray(textBoxFunction1->Text + " - ( " + textBoxFunction2->Text + ")");
	if (!difference.Load(expression)) {
		return nullptr;
	}
	if (!sol.Load(expression1)) {
		return nullptr;
	}

	int count = 0;
	for (double i = a; i <= b; i += h1) {
		double y = abs(difference.Solve(i));
		bool pred = abs(difference.Solve(i-h1)) > y;
		bool now = abs(difference.Solve(i+h1)) > y;
		
		if (pred && now) {
			if (abs(difference.Solve(i)) < h1*10) {
				chart->Series[2]->Points->AddXY(i, sol.Solve(i));
				intersectPoints->Add(chart->Series[2]->Points[count]);
				count++;
			}
		}
	}
	return intersectPoints;
}




void kurs1::MyForm::HighlightIntersectionPoints(List<DataPoint^>^ intersectPoints, System::Drawing::Color color) {
	for each (DataPoint ^ point in intersectPoints) {
		point->MarkerColor = color;
		point->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle; // или другой стиль маркера
		point->MarkerSize = 10; // или другой размер маркера
	}
}


void kurs1::MyForm::ShowIntersectionMessage(List<DataPoint^>^ intersectionPoints) {
	// Вывод результатов в MessageBox
	String^ resultMessage = "Точки пересечения:\n";
	for each (DataPoint ^ point in intersectionPoints) {
		resultMessage += String::Format("X: {0:F2}, Y: {1:F2}\n", point->XValue, point->YValues[0]);
	}

	MessageBox::Show(resultMessage, "Точки пересечения");
}



System::Void kurs1::MyForm::checkBox_searchCross_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox_searchCross->Checked) {
		Series^ series1 = chart->Series[0];
		Series^ series2 = chart->Series[1];

		// Находим точки пересечения
		List<DataPoint^>^ intersectPoints = FindIntersectionPoints(series1, series2, 0.01); 

		// Подсветка точек пересечения
		HighlightIntersectionPoints(intersectPoints, System::Drawing::Color::Green);
		ShowIntersectionMessage(intersectPoints);
	}
	else {
		// Убираем подсветку при отключении опции
		chart->Series[2]->Points->Clear();
	}
}





bool isMouseOverChart = false;
// Обработчик события MouseMove 
System::Void kurs1::MyForm::chart_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (isMouseOverChart && (isGraph1Built || isGraph2Built)) {
		// Получение текущих координат мыши
		double xValue = chart->ChartAreas[0]->AxisX->PixelPositionToValue(e->X);
		double yValue = chart->ChartAreas[0]->AxisY->PixelPositionToValue(e->Y);

		// Проверка близости к какой-либо точке графика, только если график построен
		if (isGraph1Built || isGraph2Built) {
			for each (System::Windows::Forms::DataVisualization::Charting::Series ^ series in chart->Series) {
				for each (System::Windows::Forms::DataVisualization::Charting::DataPoint ^ point in series->Points) {
					double distance = Math::Sqrt(Math::Pow(point->XValue - xValue, 2) + Math::Pow(point->YValues[0] - yValue, 2));

					// Установка размера 
					double highlightSize = 0.1;

					// Если курсор близко к точке, подсветите ее
					if (distance < highlightSize) {
						point->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
						point->MarkerSize = 10;
						point->MarkerColor = System::Drawing::Color::Red;
					}
					else {
						// Если курсор не близко к точке, верните обычный стиль
						point->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::None;
						point->MarkerColor = System::Drawing::Color::Transparent;
					}
				}
			}
		}

		// Вывод координат в пользовательском интерфейсе
		labelCoordinates->Text = String::Format("X: {0:F2}, Y: {1:F2}", xValue, yValue);
	}
}



// Обработчик события MouseLeave для вашего Chart
System::Void kurs1::MyForm::chart_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	// Очистите текст при покидании области графика
	labelCoordinates->Text = "";
	isMouseOverChart = false;
}

// Обработчик события MouseEnter для вашего Chart
System::Void kurs1::MyForm::chart_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	// Установите флаг, когда мышь находится над областью графика
	isMouseOverChart = true;
}

//кнопки перемещения
System::Void kurs1::MyForm::buttonPanDown_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Перемещение вниз
	chart->ChartAreas[0]->AxisY->Minimum -= 1.0;
	chart->ChartAreas[0]->AxisY->Maximum -= 1.0;
	return System::Void();
}

//кнопки перемещения
System::Void kurs1::MyForm::buttonPanUp_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Перемещение вверх
	chart->ChartAreas[0]->AxisY->Minimum += 1.0;
	chart->ChartAreas[0]->AxisY->Maximum += 1.0;
	return System::Void();
}

//кнопки перемещения
System::Void kurs1::MyForm::buttonPanLeft_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Перемещение влево
	chart->ChartAreas[0]->AxisX->Minimum -= 1.0;
	chart->ChartAreas[0]->AxisX->Maximum -= 1.0;
	return System::Void();
}

//кнопки перемещения
System::Void kurs1::MyForm::buttonPanRight_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Перемещение вправо
	chart->ChartAreas[0]->AxisX->Minimum += 1.0;
	chart->ChartAreas[0]->AxisX->Maximum += 1.0;
	return System::Void();
}

System::Void kurs1::MyForm::buttonZoomIn_Click(System::Object^ sender, System::EventArgs^ e)
{
	chart->ChartAreas[0]->AxisX->ScaleView->Zoom(2, this->chart->ChartAreas[0]->AxisX->Minimum);
	chart->ChartAreas[0]->AxisY->ScaleView->Zoom(2, this->chart->ChartAreas[0]->AxisY->Minimum);
}

System::Void kurs1::MyForm::buttonZoomOut_Click(System::Object^ sender, System::EventArgs^ e)
{
	chart->ChartAreas[0]->AxisX->ScaleView->Zoom(0.5, chart->ChartAreas[0]->AxisX->Minimum);
	chart->ChartAreas[0]->AxisY->ScaleView->Zoom(0.5, chart->ChartAreas[0]->AxisY->Minimum);
}




