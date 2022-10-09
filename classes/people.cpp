#include "people.h"

People::People(string name, string cpf, string address, string phone, 
               string email)
{
  // TODO: Gerar ID
  _id = "1";
  if(name == "" || cpf == "" || address == "" || phone == "" || email == "")
    throw invalid_argument("Todos os campos devem ser preenchidos");
  if(name.length() > 248)
    throw invalid_argument("Nome deve ter no máximo 248 caracteres");
  if(cpf.length() != 15)
    throw invalid_argument("CPF deve ter 11 dígitos, com pontos e traço");
  
  _name = name;
  _CPF = cpf;
  _address = address;
  _phone = phone;
  _email = email;  
}

void People::setName(string name)
{
  if(name == "")
    throw invalid_argument("Nome não pode ser vazio");
  if(name.length() > 248)
    throw invalid_argument("Nome deve ter no máximo 248 caracteres");
  _name = name;
}

void People::setAddress(string address)
{
  if(address == "")
    throw invalid_argument("Endereço não pode ser vazio");
  _address = address;
}

void People::setPhone(string phone)
{
  if(phone == "")
    throw invalid_argument("Telefone não pode ser vazio");
  _phone = phone;
}

void People::setEmail(string email)
{
  if(email == "")
    throw invalid_argument("Email não pode ser vazio");
  _email = email;
}

string People::getId()
{
  return _id;
}

string People::getName()
{
  return _name;
}

string People::getCpf()
{
  return _CPF;
}

string People::getAddress()
{
  return _address;
}

string People::getPhone()
{
  return _phone;
}

string People::getEmail()
{
  return _email;
}
