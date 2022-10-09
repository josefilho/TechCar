#include "addclient.h"
#include "ui_addclient.h"

AddClient::AddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);

    filledAddress = filledCPF = filledEmail = filledName = filledPhone = false;

    // Placeholders
    ui->cpf->setPlaceholderText("XXX.XXX.XXX-XX"),
    ui->phone->setPlaceholderText("(XX)XXXXX-XXXX"),
    ui->address_cep->setPlaceholderText("XXXXX-XXX");
}

AddClient::~AddClient()
{
    delete ui;
}

void AddClient::on_button_save_clicked()
{
    // TODO: Check if exists
    // TODO: Send to Data Bank
}

bool AddClient::checkContains(QString src, QString search){
    for(int i = 0; i < search.length(); i++){
        if(src.contains(search[i], Qt::CaseInsensitive)){
            return true;
        }
    }
    return false;
}

bool AddClient::checkFields()
{
    return filledName && filledCPF && checkAddress() && filledPhone && filledEmail;
}

bool AddClient::checkAddress(){
    if(!ui->address_cep->text().isEmpty() && !ui->address_city->text().isEmpty() &&
       !ui->address_number->text().isEmpty() && !ui->address_street->text().isEmpty() &&
       !ui->address_uf->text().isEmpty()){
        filledAddress = true;
    } else filledAddress = false;

    return filledAddress;
}


void AddClient::on_name_editingFinished()
{
    QLabel *labelName = ui->label_name;
    if(!ui->name->text().isEmpty() &&
       !checkContains(ui->name->text(), "1234567890'!@#$%¨&*()/*-+[]:;<>,.") &&
        ui->name->text().length() < 258){
        filledName = true;
        labelName->setPalette(QPalette(QPalette::Text, Qt::green));
    } else {
        filledName = false;
        labelName->setPalette(QPalette(QPalette::Text, Qt::red));
    }
    if(checkFields()){
        ui->button_save->setEnabled(true);
    } else ui->button_save->setEnabled(false);
}

void AddClient::on_cpf_editingFinished()
{
    if(!ui->cpf->text().isEmpty() &&
       !checkContains(ui->cpf->text(), "abcdefghijklmnopqrstuvwxyz'!@#$%¨&*()/*-+[]:;<>, ") &&
        ui->cpf->text().length() == 15){
        filledCPF = true;
    } else {
        filledCPF = false;
    }
    if(checkFields()){
        ui->button_save->setEnabled(true);
    } else ui->button_save->setEnabled(false);
}


void AddClient::on_phone_editingFinished()
{
    if(!ui->phone->text().isEmpty() &&
       !checkContains(ui->phone->text(), "abcdefghijklmnopqrstuvwxyz'!@#$%¨&*/*+[]:;<>, ") &&
        ui->cpf->text().length() == 14){
        filledPhone = true;
    } else {
        filledPhone = false;
    }
    if(checkFields()){
        ui->button_save->setEnabled(true);
    } else ui->button_save->setEnabled(false);

}


void AddClient::on_email_editingFinished()
{
    if(!ui->email->text().isEmpty() &&
        ui->email->text().contains('@') &&
        ui->email->text().endsWith(".com")){
        filledEmail = true;
    } else {
        filledEmail = false;
    }
    if(checkFields()){
        ui->button_save->setEnabled(true);
    } else ui->button_save->setEnabled(false);

}


void AddClient::on_address_cep_editingFinished()
{
    if(checkFields()){
        ui->button_save->setEnabled(true);
    } else ui->button_save->setEnabled(false);
}


void AddClient::on_address_street_editingFinished()
{
    if(checkFields()){
        ui->button_save->setEnabled(true);
    } else ui->button_save->setEnabled(false);
}


void AddClient::on_address_city_editingFinished()
{
    if(checkFields()){
        ui->button_save->setEnabled(true);
    } else ui->button_save->setEnabled(false);
}


void AddClient::on_address_uf_editingFinished()
{
    if(checkFields()){
        ui->button_save->setEnabled(true);
    } else ui->button_save->setEnabled(false);
}


void AddClient::on_address_number_editingFinished()
{
    if(checkFields()){
        ui->button_save->setEnabled(true);
    } else ui->button_save->setEnabled(false);
}


void AddClient::on_address_optional_editingFinished()
{
    if(checkFields()){
        ui->button_save->setEnabled(true);
    } else ui->button_save->setEnabled(false);
}

