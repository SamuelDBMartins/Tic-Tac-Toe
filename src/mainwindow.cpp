#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "msgdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_celle[0][0] = ui->cella_00;
    m_celle[0][1] = ui->cella_01;
    m_celle[0][2] = ui->cella_02;
    m_celle[1][0] = ui->cella_10;
    m_celle[1][1] = ui->cella_11;
    m_celle[1][2] = ui->cella_12;
    m_celle[2][0] = ui->cella_20;
    m_celle[2][1] = ui->cella_21;
    m_celle[2][2] = ui->cella_22;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            connect(m_celle[i][j], &QPushButton::released, [=]{gioca(i, j);});
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Ritorna vero se le condizioni di vittoria sono soddisfatte
bool MainWindow::vittoria()
{
    return (stato(0,0) == stato(0,1) && stato(0,1) == stato(0,2) &&
            stato(0,2) != ""
            || stato(1,0) == stato(1,1) && stato(1,1) == stato(1,2) &&
            stato(1,2) != ""
            || stato(2,0) == stato(2,1) && stato(2,1) == stato(2,2) &&
            stato(2,2) != ""
            || stato(0,0) == stato(1,0) && stato(1,0) == stato(2,0) &&
            stato(2,0) != ""
            || stato(0,1) == stato(1,1) && stato(1,1) == stato(2,1) &&
            stato(2,1) != ""
            || stato(0,2) == stato(1,2) && stato(1,2) == stato(2,2) &&
            stato(2,2) != ""
            || stato(0,0) == stato(1,1) && stato(1,1) == stato(2,2) &&
            stato(2,2) != ""
            || stato(2,0) == stato(1,1) && stato(1,1) == stato(0,2) &&
            stato(0,2) != "");
}

bool MainWindow::finePartita()
{
    for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!stato(i, j).compare(""))
                    return false;
        }
    }
    return true;
}

// Ritorna lo stato della cella: "" (vuota), "O", "X"
QString MainWindow::stato(int riga, int colonna)
{
    return m_celle[riga][colonna]->text();
}

void MainWindow::gioca(int riga, int colonna) {
    if(m_celle[riga][colonna]->text().compare(""))
        return;

    QString symbol = OTurn ? "O" : "X";
    m_celle[riga][colonna]->setText(symbol);

    OTurn = !OTurn;

    if(vittoria()) {
        for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    m_celle[i][j]->setText("");
            }
        }
        MsgDialog *msgdialog = new MsgDialog(symbol.append(" ha vinto"), this);
        msgdialog->show();
    }

    if(finePartita()) {
        for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    m_celle[i][j]->setText("");
            }
        }
        MsgDialog *msgdialog = new MsgDialog("Fine partita", this);
        msgdialog->show();
    }
}
