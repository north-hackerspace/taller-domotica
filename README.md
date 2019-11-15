![img/domotica.jpg](img/domotica.jpg)

# Kit de Taller

- [ESP8266 NodeMCU v3](https://es.aliexpress.com/item/32965623530.html?spm=a2g0s.9042311.0.0.465063c0ZkESIK)
- [USB Cable](https://es.aliexpress.com/item/33063307001.html?spm=a2g0s.9042311.0.0.274263c06676gq)
- [Mini Breadboard](https://es.aliexpress.com/item/32655910710.html?spm=a2g0o.productlist.0.0.24663c53hgrOIp)
- [Jumper Cables](https://es.aliexpress.com/item/33038355606.html?spm=a2g0s.9042311.0.0.274263c0XEySyf)
- [LEDs](https://es.aliexpress.com/item/32886530132.html?spm=a2g0s.9042311.0.0.274263c0LKVxhL)
- [PIR Sensor HC-SR501](https://es.aliexpress.com/item/32733268757.html?spm=a2g0o.productlist.0.0.3ad361eaJmPVh6)
- [4.5V AAA Battery Case](https://es.aliexpress.com/item/32788925539.html?spm=a2g0o.productlist.0.0.72de6097ZVvz3G)
- [AAA Batteries](https://www.amazon.es/AmazonBasics-Pilas-alcalinas-industrial-unidades/dp/B07MLDJF3B)
- [5V Relay](https://es.aliexpress.com/item/32787576149.html?spm=a2g0o.productlist.0.0.550d43e1WM2Jas)

# Instalacion

Instala el [IDE de Arduino](https://www.arduino.cc/en/main/software) si no lo has hecho ya.

Si tienes Windows o Max OSC baja e instala los [drivers](/drivers) para conexion por USB usando el chip [CH341](https://www.rubinolab.com/clone-arduino-driver-chip-ch340-ch340g-ch341/). Ya tienes los drivers de otro taller? no hace falta instalarlos otra vez.

Si tienes Linux no hace falta instalar los drivers, ya viene instalados con la mayoria de las distribuciones linux.

## Anadir la placa ESP8266 al Arduino IDE

1. Herramientas > Placa > Gestor de tarjetas...
2. Buscar "esp8266" y elegir "esp8266 by ESP8266 Community"
3. Instalar
4. Herramientas > Placa .. > "NodeMCU v1.0 (ESP-12E Module)"
5. Herramientas > Puerto > (lo que aparezca, por ejemplo COM5)

![img/board.manager.png](img/board.manager.png)

![img/esp8266.board.png](img/esp8266.board.png)

![img/nodemcu.v.1.0.png](img/nodemcu.v.1.0.png)

# Desafio 1: Como controlar los pines.

![img/desafio1.png](img/desafio1.png)

# Desafio 2: Conectar el ESP8266 a nuestro Wi-Fi.

# Desafio 3: Encender y apagar un LED desde el móvil con MQTT.

![img/desafio1.png](img/desafio1.png)

# Desafio 4: Saber el estado de un sensor en tu dispositivo desde cualquier lugar.

![img/desafio4.png](img/desafio4.png)

# Desafio 5: Encender y apagar un relé de alta potencia a través de internet.

![img/desafio5.png](img/desafio5.png)

