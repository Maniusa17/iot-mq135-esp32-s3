# 🌐 Projeto IoT com ESP32-S3 + MQ135 + Node-RED

## 📌 Descrição

Este projeto implementa um sistema IoT completo utilizando o ESP32-S3 para monitoramento de qualidade do ar através do sensor MQ135, com comunicação via MQTT e visualização em Node-RED.

O sistema permite:

- Monitoramento em tempo real de gases (MQ135)
- Exibição local em display OLED
- Envio de dados para servidor MQTT (AWS EC2)
- Controle remoto de LED
- Interação via botão físico
- Dashboard com histórico e visualização

---

## 🧠 Arquitetura do Sistema

---

## ⚙️ Tecnologias Utilizadas

- ESP32-S3
- Sensor MQ135
- Display OLED I2C
- Protocolo MQTT
- Node-RED
- AWS EC2
- Arduino IDE

---

## 🔌 Hardware

- ESP32-S3 Dev Module
- Sensor MQ135
- Display OLED SSD1306 (I2C)
- LED + resistor
- Botão com pull-up interno

---

## 📡 Tópicos MQTT

| Função        | Tópico            |
|--------------|------------------|
| Sensor gás   | `sensor/gas`     |
| Botão        | `sensor/botao`   |
| Controle LED | `controle/led`   |

---

## 🌍 Servidor

Node-RED rodando em AWS EC2:

🔗 http://13.233.174.162:1880/dashboard

---

## 📊 Funcionalidades

- Leitura do sensor MQ135
- Envio contínuo via MQTT
- Dashboard com gráfico histórico
- Botão físico envia evento MQTT
- Controle remoto do LED via Node-RED
- Exibição de status no display OLED

---

## 🧪 Testes

- WiFi conectado com sucesso
- MQTT conectado
- Sensor enviando dados
- Botão detectado corretamente
- LED respondendo a comandos remotos

---

## 📷 Imagens do Projeto

*(adicione aqui depois)*

---

## 👨‍💻 Autor

Rozmani Cezar Viveiros  
Pós-graduação em Internet das Coisas (IoT) – IFSP | Prof. Dr. Marcos Aparecido Chaves Ferreira 30/04/2026

---

## 📌 Observações

O projeto demonstra um fluxo completo de IoT, desde aquisição de dados até visualização e atuação remota, utilizando arquitetura baseada em MQTT.
