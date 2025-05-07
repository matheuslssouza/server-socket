# 🖧 Winsock TCP Server em C++

Este projeto implementa um **servidor TCP simples em C++ utilizando a API do Windows Sockets (Winsock)**. Ele inicializa o sistema de sockets do Windows, escuta conexões em uma porta específica e aceita clientes que se conectem ao servidor.

---

## 📁 Estrutura do Projeto

/project-root
├── main.cpp
├── WinsockServer.h
└── WinsockServer.cpp

yaml
Copiar
Editar

---

## ▶️ Como Compilar

### 🧰 Pré-requisitos

- Windows
- Compilador C++ (Visual Studio ou MSVC com suporte a Winsock)
- Biblioteca `Ws2_32.lib`

### 🛠️ Comando de compilação (via linha de comando MSVC):

```bash
cl main.cpp WinsockServer.cpp /link Ws2_32.lib
```

🚀 Como Executar
Após compilar:

```bash
main.exe
```
O servidor escutará na porta 4000 no endereço 127.0.0.1.

🧠 Explicação do Código
main.cpp
```cpp
WinsockServer WinsockServer(L"127.0.0.1", 4000);
```
Cria um objeto da classe WinsockServer passando o IP e a porta.

Isso automaticamente inicia o servidor via o construtor da classe.

WinsockServer.cpp — Implementação do Servidor
🔧 Construtor

```cpp
WinsockServer::WinsockServer(const wchar_t* ip, unsigned int port)
```
Recebe o IP e porta, e chama:

initWinDependencies() → Inicializa a DLL do Winsock.

startServer() → Começa o ciclo do servidor.

initWinDependencies()
```cpp
WSAStartup(MAKEWORD(2, 2), &wsa_data);
```

Inicializa o Winsock com a versão 2.2.

Se falhar, mostra o erro.

startServer()
Chama as etapas principais:

createSocket() → Cria um socket TCP.

bindSocket() → Associa o socket ao IP e porta.

listenSocket() → Coloca o socket em modo escuta.

acceptSocket() → Aceita uma conexão de cliente.

createSocket()
```cpp
socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
```
Cria um socket para conexões IPv4 e protocolo TCP.

bindSocket()
```cpp
bind(socket_server, (const sockaddr*)&socket_configs, sizeof(socket_configs))
```
Preenche a estrutura com IP e porta e a associa ao socket.

listenSocket()
```cpp
listen(socket_server, SOMAXCONN);
```
Coloca o socket em modo escuta para aceitar conexões.

acceptSocket()
```cpp
SOCKET accept_socket = accept(socket_server, ...);
```
Espera e aceita a conexão de um cliente.

Imprime o IP e porta do cliente conectado.


WinsockServer atualmente aceita apenas um cliente por execução. Para múltiplos clientes, seria necessário usar threads.

📚 Referências
Documentação do Winsock (MSDN)
