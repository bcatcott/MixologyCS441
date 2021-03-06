#include <QDebug>
#include "ui_mainwindow.h"
#include "mainwindow.h"

// Externs
Cabinet *Cab;
IngredientDatabase *IngDB;
CocktailDB *CDB;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Ryan
void MainWindow::on_cabinetSearch_textChanged(const QString &arg1)
{
	ui->possibleIngredients->clear();
	if (arg1.toLower().startsWith("c"))
	{
		ui->possibleIngredients->addItem("Coke");
		ui->possibleIngredients->addItem("Cat");
		return;
	}
	if (arg1.toLower().startsWith("r"))
	{
		ui->possibleIngredients->addItem("Rum");
		return;
	}
	ui->possibleIngredients->addItem("Nothing!!!");
}

//Jacob - Most finished
void MainWindow::on_possibleIngredients_currentTextChanged(const QString &currentText)
{
    if(currentText == "")
    {
        ui->clearSelectedIngredients->setEnabled(false);
        return;
    }
    Ingredient ingToCabinet(currentText.toStdString());
    Cab->AddIng(ingToCabinet, *IngDB);
    ui->myCabinet->addItem(currentText);
    ui->clearSelectedIngredients->setEnabled(true);
}

//Complete - Do Not Change
void MainWindow::on_clearCabinet_clicked()
{
	Cab->ClearIngs();
	ui->myCabinet->clear();
}

// Curtis
void MainWindow::on_myCabinet_currentTextChanged(const QString &currentText)
{
    if(currentText.toLower() == "coke")
    {
        ui->cocktailResults->setText("Coke is bad for your teeth!");
        return;
    }
    ui->cocktailResults->setText("????");

	//ui->possibleIngredients->clear();
	//int count = 0;
	//    vector<Ingredient> ingredients = IngDB->SearchDB(arg1.toStdString());
	//    vector<Ingredient>::iterator it;
	//qInfo("%d",ingredients.size());
	//    for(it = ingredients.begin(); it != ingredients.end(); it++)
	//    {
	//        count++;
	//        qInfo( "C Style Info Message" );
	//ui->possibleIngredients->addItem(QString::fromStdString((*it).GetName()));
	//  }
	/*
	if(arg1.toLower().startsWith("c"))
	{
	ui->possibleIngredients->addItem("Coke");
	ui->possibleIngredients->addItem("Cat");
	return;
	}
	if(arg1.toLower().startsWith("r"))
	{
	ui->possibleIngredients->addItem("Rum");
	return;
	}
	*/
}

void MainWindow::on_clearSelectedIngredients_clicked()
{
    qDebug() << "Please clear" ;
    int row = ui->myCabinet->currentRow();
    if(row == -1)
        return;
    Ingredient ingToRemove(ui->myCabinet->item(row)->text().toStdString());
    Cab->RemoveIng(ingToRemove);
    ui->myCabinet->takeItem(row);
}

void MainWindow::on_possibleIngredients_itemClicked(QListWidgetItem *item)
{
    if(!item)
        return;
    on_possibleIngredients_currentTextChanged(item->text());
}

//Rajack - you don't have a function created yet
