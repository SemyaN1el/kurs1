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



System::Void kurs1::MyForm::построитьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (checkBox1->Checked == false) {
		MessageBox::Show("Выберите хотя бы один график!", "Внимание!");
		return;
	}
	if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
		MessageBox::Show("Параметры по умолчанию!", "Внимание!");
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

System::Void kurs1::MyForm::очиститьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox1->Checked == false) {
		MessageBox::Show("Выберите хотя бы один график!", "Внимание!");
		return;
	}
	if (checkBox1->Checked) {
		this->chart->Series[0]->Points->Clear();
	}
}

System::Void kurs1::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Выйти?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
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
		MessageBox::Show("Параметры по умолчанию!", "Внимание!");
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
		MessageBox::Show("Параметры по умолчанию!", "Внимание!");
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
		MessageBox::Show("Параметры по умолчанию!", "Внимание!");
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

	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();

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

	this->chart->Series[0]->Points->Clear();
	this->chart->Series[1]->Points->Clear();


	if (radioButton5->Checked) {
		if (textBoxFunction2->Text == "") {
			MessageBox::Show("Функция отсутствует", "Внимание!");
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

	// Задаем точность поиска
	const double epsilon = 1e-6;

	// Вычисляем начальные точки
	double x1 = b - (b - a) / goldenRatio;
	double x2 = a + (b - a) / goldenRatio;

	// Вычисляем значения функции в начальных точках
	double f1 = parseExpression(expression, x1);
	double f2 = parseExpression(expression, x2);

	// Проводим итерации метода золотого сечения
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







// Функция для поиска всех точек минимума
std::vector<double> findAllMinimaGoldenSection(char* expression, double a, double b, int numPoints) {
	const double goldenRatio = (1 + sqrt(5)) / 2;

	std::vector<double> minima;  // Список найденных минимумов
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

		// Добавляем найденные точки минимума в список
		minima.push_back((a + b) / 2);

		// Переходим к следующему интервалу
		a = x1;
		b = x2;
	}

	// Возвращаем список найденных минимумов
	return minima;
}

// Функция для поиска всех точек максимума
std::vector<double> findAllMaximaGoldenSection(char* expression, double a, double b, int numPoints) {
	const double goldenRatio = (1 + sqrt(5)) / 2;

	std::vector<double> maxima;  // Список найденных максимумов
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

		// Добавляем найденные точки максимума в список
		maxima.push_back((a + b) / 2);

		// Переходим к следующему интервалу
		a = x1;
		b = x2;
	}

	// Возвращаем список найденных максимумов
	return maxima;
}

System::Void kurs1::MyForm::checkBox_minmax1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox_minmax1->Checked && radioButton3->Checked) {
		try {
			// Проверяем наличие значений в текстбоксах
			if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
				MessageBox::Show("Введите параметры для поиска минимума и максимума.", "Внимание!");
				checkBox_minmax1->Checked = false; // Снимаем выбор чекбокса
				return;
			}

			// Получаем значения из текстбоксов
			double a = Convert::ToDouble(textBox1->Text);
			double b = Convert::ToDouble(textBox2->Text);

			// Получаем текст выражения из текстбокса
			char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);

			// Вызываем функции поиска всех точек минимума и максимума для первой функции
			std::vector<double> allMinima = findAllMinimaGoldenSection(expression1, a, b, 5);
			std::vector<double> allMaxima = findAllMaximaGoldenSection(expression1, a, b, 5);

			// Выводим результат в MessageBox или другой способ, который вы предпочитаете
			String^ resultMessage = "Все точки минимума функции 1: ";
			for (double minimum : allMinima) {
				resultMessage += minimum.ToString() + " ";
			}
			resultMessage += "\nВсе точки максимума функции 1: ";
			for (double maximum : allMaxima) {
				resultMessage += maximum.ToString() + " ";
			}

			MessageBox::Show(resultMessage, "Результат");
			checkBox_minmax1->Checked = false;
		}
		catch (System::FormatException^ ex) {
			// Обработка ошибки, связанной с некорректным форматом числа
			MessageBox::Show("Ошибка формата числа. Проверьте введенные значения.", "Ошибка");
		}
		catch (System::Exception^ ex) {
			// Обработка других исключений
			MessageBox::Show("Произошла ошибка: " + ex->Message, "Ошибка");
		}
	}
	else if (!radioButton3->Checked) {
		MessageBox::Show("График функции отсутствует / функция не задана", "Внимание!");
		checkBox_minmax1->Checked = false;
		return;
	}
}


//
//System::Void kurs1::MyForm::checkBox_minmax1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
//{
//	if (checkBox_minmax1->Checked && radioButton3->Checked) {
//		try {
//			// Проверяем наличие значений в текстбоксах
//			if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
//				MessageBox::Show("Введите параметры для поиска минимума и максимума.", "Внимание!");
//				checkBox_minmax1->Checked = false; // Снимаем выбор чекбокса
//				return;
//			}
//
//			// Получаем значения из текстбоксов
//			double a = Convert::ToDouble(textBox1->Text);
//			double b = Convert::ToDouble(textBox2->Text);
//
//			// Получаем текст выражения из текстбокса
//			char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);
//
//			// Вызываем функцию поиска минимума и максимума для первой функции
//			double minimum1 = FindMinimum(expression1, a, b);
//			double maximum1 = FindMaximum(expression1, a, b);
//
//			// Выводим результат в MessageBox или другой способ, который вы предпочитаете
//			MessageBox::Show("Минимум функции 1: " + minimum1 + "\nМаксимум функции 1: " + maximum1, "Результат");
//			checkBox_minmax1->Checked = false;
//		}
//		catch (System::FormatException^ ex) {
//			// Обработка ошибки, связанной с некорректным форматом числа
//			MessageBox::Show("Ошибка формата числа. Проверьте введенные значения.", "Ошибка");
//		}
//		catch (System::Exception^ ex) {
//			// Обработка других исключений
//			MessageBox::Show("Произошла ошибка: " + ex->Message, "Ошибка");
//		}
//	}
//	else if (!radioButton3->Checked) {
//		MessageBox::Show("График функции отсутствует / функция не задана", "Внимание!");
//		checkBox_minmax1->Checked = false;
//		return;
//	}
//}

System::Void kurs1::MyForm::checkBox_minmax2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox_minmax2->Checked && radioButton5->Checked) {
		try {
			// Проверяем наличие значений в текстбоксах
			if (textBox4->Text == "" || textBox5->Text == "" || textBox6->Text == "") {
				MessageBox::Show("Введите параметры для поиска минимума и максимума.", "Внимание!");
				checkBox_minmax2->Checked = false; // Снимаем выбор чекбокса
				return;
			}

			// Получаем значения из текстбоксов
			double с = Convert::ToDouble(textBox4->Text);
			double d = Convert::ToDouble(textBox5->Text);

			// Получаем текст выражения из текстбокса
			char* expression2 = ConvertStringToCharArray(textBoxFunction2->Text);

			// Вызываем функцию поиска минимума и максимума для первой функции
			double minimum2 = FindMinimum(expression2, c, d);
			double maximum2 = FindMaximum(expression2, c, d);

			// Выводим результат в MessageBox или другой способ, который вы предпочитаете
			MessageBox::Show("Минимум функции 2: " + minimum2 + "\nМаксимум функции 2: " + maximum2, "Результат");
			checkBox_minmax1->Checked = false;
		}
		catch (System::FormatException^ ex) {
			// Обработка ошибки, связанной с некорректным форматом числа
			MessageBox::Show("Ошибка формата числа. Проверьте введенные значения.", "Ошибка");
		}
		catch (System::Exception^ ex) {
			// Обработка других исключений
			MessageBox::Show("Произошла ошибка: " + ex->Message, "Ошибка");
		}
	}
	else if (!radioButton5->Checked) {
		MessageBox::Show("График функции отсутствует / функция не задана", "Внимание!");
		checkBox_minmax2->Checked = false;
		return;
	}
}

// Функция для поиска точки пересечения двух функций методом бисекции
double findIntersection(char* expression1, char* expression2, double a, double b) {
	const double EPSILON = 1e-9;

	double fa = parseExpression(expression1, a) - parseExpression(expression2, a);

	// Проверка, возможно, одна из точек уже является пересечением
	if (fabs(fa) < EPSILON) {
		return a;
	}

	double fb = parseExpression(expression1, b) - parseExpression(expression2, b);

	// Проверка, возможно, одна из точек уже является пересечением
	if (fabs(fb) < EPSILON) {
		return b;
	}

	// Проверка, возможно, начальные точки уже являются пересечением
	if (fa * fb > 0) {
		return std::numeric_limits<double>::quiet_NaN();  // Нет корня на данном интервале
	}

	while (b - a >= EPSILON) {
		double c = (a + b) / 2;
		double fc = parseExpression(expression1, c) - parseExpression(expression2, c);

		// Проверка, возможно, текущая точка уже является пересечением
		if (fabs(fc) < EPSILON) {
			return c;
		}

		// Ищем корень на половине интервала
		if (fc * fa < 0) {
			b = c;
		}
		else {
			a = c;
			fa = fc;
		}
	}

	return (a + b) / 2;  // Возвращаем середину найденного интервала
}

double kurs1::MyForm::MyFunction1(double x) {
	// Считываем текст функции из текстбокса
	char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);

	// Оцениваем функцию в заданной точке
	return parseExpression(expression1, x);
}


//std::vector<double> findAllIntersections(char* expression1, char* expression2, double a, double b, double step) {
//	std::vector<double> intersections;
//	double epsilon = 1e-9;
//	for (double x = a; x <= b; x += step) {
//		double y1 = parseExpression(expression1, x);
//		double y2 = parseExpression(expression2, x);
//
//		// Проверяем, произошло ли пересечение
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
//	// Поиск серии точек пересечения в существующих сериях
//	for each (System::Windows::Forms::DataVisualization::Charting::Series ^ series in chart->Series) {
//		if (series->Name == "IntersectionSeries") {
//			intersectionSeries = series;
//			break;
//		}
//	}
//	// Если серии точек пересечения нет, создайте новую серию
//	if (intersectionSeries == nullptr) {
//		intersectionSeries = gcnew System::Windows::Forms::DataVisualization::Charting::Series();
//		intersectionSeries->Name = "IntersectionSeries";
//		chart->Series->Add(intersectionSeries);
//	}
//
//	// Очистите предыдущие точки в серии точек пересечения
//	intersectionSeries->Points->Clear();
//
//	// Создайте новые точки пересечения и добавьте их к серии точек пересечения
//	for (double intersection : intersections) {
//		System::Windows::Forms::DataVisualization::Charting::DataPoint^ intersectionPoint = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(intersection, MyFunction1(intersection));
//		intersectionPoint->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
//		intersectionPoint->MarkerSize = 10;
//		intersectionPoint->Color = System::Drawing::Color::Red;
//		intersectionSeries->Points->Add(intersectionPoint);
//	}
//
//	// Обновите график
//	chart->Invalidate();
//}

void kurs1::MyForm::DisplayIntersectionPoint(double x) {
	// Предполагается, что у вас уже есть существующие графики в chart1

	System::Windows::Forms::DataVisualization::Charting::Series^ intersectionSeries = nullptr;

	// Поиск серии точек пересечения в существующих сериях
	for each (System::Windows::Forms::DataVisualization::Charting::Series ^ series in chart->Series) {
		if (series->Name == "IntersectionSeries") {
			intersectionSeries = series;
			break;
		}
	}

	// Если серии точек пересечения нет, создайте новую серию
	if (intersectionSeries == nullptr) {
		intersectionSeries = gcnew System::Windows::Forms::DataVisualization::Charting::Series();
		intersectionSeries->Name = "IntersectionSeries";
		chart->Series->Add(intersectionSeries);
	}

	// Очистите предыдущие точки в серии точек пересечения
	intersectionSeries->Points->Clear();

	// Создайте новую точку пересечения и добавьте ее к серии точек пересечения
	System::Windows::Forms::DataVisualization::Charting::DataPoint^ intersectionPoint = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(x, MyFunction1(x));
	intersectionPoint->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
	intersectionPoint->MarkerSize = 10;
	intersectionPoint->Color = System::Drawing::Color::Red;
	intersectionSeries->Points->Add(intersectionPoint);

	// Обновите график
	chart->Invalidate();
}







System::Void kurs1::MyForm::checkBox_searchCross_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox_searchCross->Checked && radioButton4->Checked) {
		try {
			// Проверяем наличие значений в текстбоксах
			if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "" || textBox4->Text == "" || textBox5->Text == "" || textBox6->Text == "") {
				MessageBox::Show("Введите параметры для поиска пересечения.", "Внимание!");
				checkBox_searchCross->Checked = false; // Снимаем выбор чекбокса
				return;
			}

			// Получаем значения из текстбоксов
			double a1 = Convert::ToDouble(textBox1->Text);
			double b1 = Convert::ToDouble(textBox2->Text);
			double h1 = Convert::ToDouble(textBox3->Text);

			double a2 = Convert::ToDouble(textBox4->Text);
			double b2 = Convert::ToDouble(textBox5->Text);
			double h2 = Convert::ToDouble(textBox6->Text);

			// Получаем текст выражений из текстбоксов
			char* expression1 = ConvertStringToCharArray(textBoxFunction1->Text);
			char* expression2 = ConvertStringToCharArray(textBoxFunction2->Text);
			// Вызываем функцию поиска всех точек пересечения
			/*std::vector<double> allIntersections = findAllIntersections(expression1, expression2, Math::Max(a1, a2), Math::Min(b1, b2), 0.01);*/
			// Вызываем функцию поиска точки пересечения
			double intersectionPoint = findIntersection(expression1, expression2, a1, b1);
			// Выводим результат в MessageBox или другой способ, который вы предпочитаете
			String^ resultMessage = "Все точки пересечения функций: ";
			//for (double intersection : allIntersections) {
			//	resultMessage += intersection.ToString() + " ";
			//}
			// Создаем график и отображаем точку пересечения
			DisplayIntersectionPoint(intersectionPoint);

			//MessageBox::Show(resultMessage, "Результат");
			MessageBox::Show("Точка пересечения функций: " + intersectionPoint.ToString(), "Результат");
		}
		catch (System::FormatException^ ex) {
			// Обработка ошибки, связанной с некорректным форматом числа
			MessageBox::Show("Ошибка формата числа. Проверьте введенные значения.", "Ошибка");
		}
		catch (System::Exception^ ex) {
			// Обработка других исключений
			MessageBox::Show("Произошла ошибка: " + ex->Message, "Ошибка");
		}
	}
	else if (!radioButton4->Checked) {
		MessageBox::Show("График функций отсутствует / функции не задана", "Внимание!");
		checkBox_searchCross->Checked = false;
		return;
	}
}


