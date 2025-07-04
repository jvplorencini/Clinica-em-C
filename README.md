# Clinica-em-C
# Sistema de Agendamento de Consultas Médicas

Este é um sistema simples em linguagem C para gerenciamento de **pacientes**, **médicos** e **consultas médicas**. Ele permite cadastrar pacientes e médicos, listar os cadastros, agendar consultas com verificação de disponibilidade e consultar a agenda de cada médico ou paciente.

---

## ✅ Funcionalidades

1. **Cadastro de Pacientes**
   - Nome, idade, CPF (único), plano de saúde (sim/não).
   - Verifica se o CPF já foi cadastrado.

2. **Cadastro de Médicos**
   - Nome, CRM (único), especialidade e disponibilidade (manhã ou noite).
   - Verifica se o CRM já foi cadastrado.

3. **Listagem de Médicos e Pacientes**
   - Mostra todos os médicos e pacientes cadastrados com seus dados.

4. **Agendamento de Consultas**
   - Relaciona paciente, médico e data/hora.
   - Verifica conflitos de agendamento (um médico não pode ter duas consultas no mesmo horário).

5. **Consulta de Agenda**
   - Permite consultar as consultas de um médico ou paciente por meio de seus IDs.

6. **Cancelamento de Consultas**
   - Permite cancelar uma consulta com base no ID.
   - Remove a consulta da lista e reorganiza o vetor.
---

## 🧠 Estrutura de Dados

- `Paciente`: ID, nome, idade, CPF, plano de saúde.
- `Medico`: ID, nome, CRM, especialidade, disponibilidade.
- `Data`: Dia, mês, ano, hora.
- `Consulta`: ID da consulta, paciente, médico e data.

---

## 📌 Limites

- Máximo de **20 pacientes**
- Máximo de **10 médicos**
- Máximo de **50 consultas**
