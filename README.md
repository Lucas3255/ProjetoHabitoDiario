# Gerenciador de Hábitos Diários

Um programa em linguagem C para gerenciar hábitos diários, com funcionalidades completas de CRUD (Create, Read, Update, Delete) através de uma interface de linha de comando.

## 📋 Sobre o Projeto

Este foi meu primeiro projeto desenvolvido em linguagem C, com o objetivo de criar um sistema simples mas eficiente para acompanhar hábitos diários. O programa permite registrar, acompanhar e gerenciar hábitos com marcação diária até sua conclusão.

## ✨ Funcionalidades

- **Criar hábitos**: defina novos hábitos com nome, categoria, duração e descrição
- **Visualizar hábitos**: liste todos os hábitos em andamento
- **Histórico completo**: acesse o histórico de hábitos criados e concluídos
- **Marcação diária**: registre o progresso diário de cada hábito
- **Excluir hábitos**: remova hábitos do seu registro
- **Personalização**: customize a cor da interface do programa

## 📝 Detalhes Técnicos

- Desenvolvido em **C puro**
- Sistema baseado em **structs** para organização dos dados
- Armazenamento local em memória durante a execução
- Interface de linha de comando (CLI)
- Controle de progresso diário através de cálculo percentual

## 📁 Estrutura do Projeto

```
gerenciador-habitos-diarios/
├── include/          # Arquivos de cabeçalho (.h)
│   ├── configuracao.h
│   ├── criarHabito.h
│   ├── historico.h
│   ├── main.h
│   ├── telaInicial.h
│   └── verHabito.h
├── src/               # Implementação das funcionalidades (.c)
│   ├── configuracao.c
│   ├── criarHabito.c
│   ├── historico.c
│   ├── telaInicial.c
│   └── verHabito.c
└── main.c             # Ponto de entrada do programa
```

## 🚀 Como Rodar o Projeto

### 1. Instalar o compilador

Baixe e instale o **Dev-C++** (Embarcadero_Dev-Cpp_6.3_TDM-GCC_9.2_Setup.exe):

➡️ [Download Dev-C++](https://github.com/Embarcadero/Dev-Cpp/releases)

### 2. Clonar o repositório

```bash
git clone https://github.com/lucas-henriquedias/gerenciador-habitos-diarios.git
```

### 3. Abrir o projeto

No Dev-C++, vá em **Arquivo → Abrir Documento** e selecione o arquivo `gerenciador-habitos-diarios.dev`.

### 4. Configurar a pasta de Include (se necessário)

Caso o compilador não encontre algum arquivo `.h`:

1. Vá em **Project → Project Options → Arquivos/Diretórios → Diretórios de Include**
2. Adicione o caminho completo da pasta `include/` do projeto
3. Clique em **OK**

### 5. Compilar e executar

Aperte **F9** para compilar ou **F11** para compilar e executar o programa.

## 📊 Exemplo de Uso

```
=== App Hábito Diário ===

1 - Novo Hábito.
2 - Seus Hábitos.
3 - Editar Hábito.
4 - Deletar Hábito
5 - Histórico.
0 - Sair.

Escolha uma opção:
```

## 📄 Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE) — veja o arquivo [LICENSE](LICENSE) para mais detalhes.

[![Licença MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## 👨‍💻 Autor

- Lucas Henrique Dias de Medeiros.
- Arthur Lopes Holanda.
- Nayara Karla.
- Amanda Marta.
- Daniel José Conrdeiro.

## 📞 Contato
- E-mail: lucasfaculdade2025@gmail.com
- LinkedIn: [linkedin.com/in/lucas-henrique-dias-345666346](https://www.linkedin.com/in/lucas-henrique-dias-345666346/)
