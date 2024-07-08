# IC - Horta Vertical IoT

## Descrição

O projeto "IC - Horta Vertical IoT" tem como objetivo a criação de uma horta vertical utilizando materiais recicláveis, como canos de PVC e garrafas PET, para o plantio de pequenas hortaliças caseiras. Esse cultivo será monitorado por sensores de umidade do solo, umidade e temperatura do ar, além de uma câmera com IA.

## Experiência no NEXT

Os usuários terão acesso a um painel interativo onde poderão escolher qual hortaliça querem monitorar e/ou acionar a irrigação. Um dashboard será apresentado contendo dados atualizados em tempo real da planta, assim como a descrição de sua saúde.

### Exemplo de Experiência

Maria pode escolher entre hortelã e cebolinha. Ao clicar no dashboard da hortelã, ela verá vários dados, como histórico de irrigação, temperatura do ar, percentual de umidade do ar e do solo e qualidade da saúde da planta. Maria pode ver "ao vivo" a imagem da câmera e acionar um botão para irrigar a hortelã.

## Componentes do Sistema

- **Hardware:**
  - Placa ESP32
  - Sensores de umidade do solo (2)
  - Sensor de temperatura e umidade do ar (DHT11)
  - Válvulas solenoides (2)
  - Relês (2)

- **Software:**
  - Protocolo MQTT para comunicação com o broker na nuvem (https://test.mosquitto.org/)
  - Aplicação Node-RED para visualização dos dados e controle da irrigação
  - Aplicação Python utilizando OpenCV e Keras para monitoramento da saúde das plantas

## Funcionamento

1. **Coleta de Dados:**
   - A ESP32 coleta dados dos sensores e envia para o broker na nuvem via MQTT.
   - O Node-RED se conecta ao broker, lê os dados e publica no dashboard com gráficos e indicadores.

2. **Controle de Irrigação:**
   - Dois botões no dashboard permitem enviar um sinal para a ESP32 acionar as válvulas solenoides e irrigar as plantas.

3. **Monitoramento de Saúde:**
   - A aplicação Python coleta imagens de uma webcam posicionada de frente para as plantas.
   - Usando OpenCV e Keras, as imagens são analisadas para detectar doenças ou ressecamento.
   - As informações são publicadas via HTTP para o Node-RED, que as exibe no dashboard.

## Tecnologias Utilizadas

- **Node-RED:** Para criação do dashboard interativo e controle das ações.
- **ESP32:** Microcontrolador para coleta e envio de dados.
- **MQTT:** Protocolo de comunicação para transmissão de dados.
- **Python:** Para processamento de imagens com OpenCV e Keras.
- **OpenCV e Keras:** Para análise de imagens e monitoramento da saúde das plantas.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir uma issue ou enviar um pull request.

## Licença

Este projeto está licenciado sob a MIT License - veja o arquivo LICENSE.md para detalhes.
