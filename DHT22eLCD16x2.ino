// Show Temperature and Humidity from DHT22 sensor into 16x2 LCD. Also display temperature and humidity on Serial Monitor

#include <LiquidCrystal.h> // Load a LCD library
#include <DHT.h> // Load a DHT biblioteca 

//Constants
#define DHTPIN 13 // what pin we're connected to
#define DHTTYPE DHT22 // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

//Define os pinos que serão ligados ao LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Array simbolo grau
byte grau[8] = { B00001100,
                 B00010010,
                 B00010010,
                 B00001100,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000,
               };

void setup()
{
  Serial.begin(9600); //Inicializa a serial
  dht.begin(); // Inicia o sensor DHT22
  lcd.begin(16, 2); //Inicializa LCD
  lcd.clear(); //Limpa o LCD
  //Cria o caractere customizado com o simbolo do grau
  lcd.createChar(0, grau);
}

void loop()
{
  //Intervalo recomendado para leitura do sensor de 2 segundos
  delay(2000);

  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");

  //Exibe os dados no display
  lcd.setCursor(0, 0);
  lcd.print("Temp : ");
  lcd.print(" ");
  lcd.setCursor(7, 0);
  lcd.print(temp, 1);
  lcd.setCursor(12, 0);

  //Mostra o simbolo do grau formado pelo array
  lcd.write((byte)0);
  lcd.print("C");
  
  //Mostra o simbolo do grau quadrado
  //lcd.print((char)223);

  lcd.setCursor(0, 1);
  lcd.print("Umid : ");
  lcd.print(" ");
  lcd.setCursor(7, 1);
  lcd.print(hum, 1);
  lcd.setCursor(12, 1);
  lcd.print("%");


  delay(2000);
}
