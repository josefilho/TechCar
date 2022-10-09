#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>

using namespace std;

namespace Ui {
class AddClient;
}

class AddClient : public QDialog
{
    Q_OBJECT

public:
    explicit AddClient(QWidget *parent = nullptr);
    ~AddClient();

    bool checkContains(QString src, QString search);

private slots:
    void on_button_save_clicked();

    void on_name_editingFinished();

    void on_cpf_editingFinished();

    void on_phone_editingFinished();

    void on_email_editingFinished();

    void on_address_cep_editingFinished();

    void on_address_street_editingFinished();

    void on_address_city_editingFinished();

    void on_address_uf_editingFinished();

    void on_address_number_editingFinished();

    void on_address_optional_editingFinished();

private:
    Ui::AddClient *ui;
    bool filledName;
    bool filledCPF;
    bool filledAddress;
    bool filledPhone;
    bool filledEmail;

    bool checkFields();
    bool checkAddress();
};

#endif // ADDCLIENT_H
