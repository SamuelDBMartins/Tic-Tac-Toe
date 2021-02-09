#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    // Ritorna lo stato della cella: "" (vuota), "O", "X"
    QString stato(int riga, int colonna);
    // Ritorna vero se le condizioni di vittoria sono soddisfatte
    bool vittoria();
    bool finePartita();
    // Array con puntatori ai widget dell'interfaccia grafica
    QPushButton* m_celle[3][3];
    Ui::MainWindow *ui;
    bool OTurn = true;


public slots:
    void gioca(int riga, int colonna);
};
#endif // MAINWINDOW_H
