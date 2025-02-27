# 🛠️ SQL Parser em C

Este projeto é um parser de comandos SQL escrito em C, capaz de interpretar e processar comandos como `INSERT`, `SELECT`, `DELETE` e `UPDATE`.

## 🚀 Funcionalidades
✅ Leitura de comandos SQL a partir de um arquivo (`comandos.txt`) ou entrada padrão.  
✅ Identificação e extração de informações de `INSERT INTO`, `SELECT`, `DELETE` e `UPDATE`.  
✅ Organização dos dados em estruturas apropriadas para armazenamento e manipulação.  
✅ Suporte apenas para comandos SQL nas tabelas `pessoa`, `pet` e `tipo_pet`.

## 🛠️ Tecnologias Utilizadas
- Linguagem C
- Estruturas de dados: listas duplamente encadeadas, filas, árvores binárias, structs, etc.

<img alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />

## 📌 Como Executar

1️⃣ Clone o repositório:
```sh
git clone https://github.com/NandoLuisz/Leitor-de-comandos-SQL.git
```
2️⃣ Compile o código:
```sh
gcc -o sql_parser main.c
```

3️⃣ Crie um arquivo comandos.txt ou deixe o programa criar automaticamente para você e adicione os comandos SQL que deseja processar.

4️⃣ Execute o programa passando o arquivo como entrada:
```sh
./sql_parser < comandos.txt
```
## 📥 Exemplo de Entrada (comandos.txt)
- insert into tipo_pet(codigo, descricao) values(1, 'cachorro');
- insert into pessoa(codigo, nome, fone) values(1, 'joão', '859995566');
- update pessoa set fone = '859998877' where codigo = 1;
- select * from pet where codigo = 3;
- delete from pet where codigo = 3;


## 🔥 Melhorias Futuras
- Criar um banco de dados em memória para armazenar os dados temporariamente.<br>
- Melhorar o tratamento de erros na análise de comandos.<br>
- Implementar suporte para mais tabelas e operações complexas.<br>