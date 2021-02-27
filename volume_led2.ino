//2020.1.3作成
//ESP32での動作を想定しています。
//周波数特性は考慮していません。

int sensorPin = 25;        //esp32の25pinにマイクのout マイクアンプのVccは3.3V
int sensorValue = 0;       //初期値
int ledbit = 3;            //3ビット8段階でLEDを発光
int ledLevel = 2 ^ ledbit; //LEDの輝度量子化。ledbit変数に依存させる。//これがうまく動かない！！！！

float presensorValue = 0; //フィルターの初期値
const int ledPin = A19;   //A19は、ESP32の26ピン,LEDのPWM制御

void setup()
{
  pinMode(ledPin, OUTPUT);
  //以下の処理は、正直よくわかっていない。3ビットでpmw出力を制御?
  ledcSetup(0, 12800, ledbit);
  // ledPinをチャネル0へ接続
  ledcAttachPin(ledPin, 0);
  Serial.begin(9600);
}

void loop()
{
  //LEDの値を入力
  sensorValue = analogRead(sensorPin); //sensorPinの値をアナログ値で入力
  sensorValue = sensorValue - 1870;    //入力した値の直流成分を除去、1870は、ESP32,Vcc = 3.3Vのとき
  sensorValue = abs(sensorValue);      //絶対値をとる。

  //入力値を平滑化
  sensorValue = 0.9 * presensorValue + 0.1 * sensorValue; // ローパスフィルター適用 0.9はなんとなく。
  presensorValue = sensorValue;                           // 前回値の保存

  sensorValue = map(sensorValue, 0, 1870, 0, ledLevel); //ledLevel 段階に丸める
  Serial.println(sensorValue);                   //シリアルモニタに表示、シリアルプロッタで見るのがおすすめ

  ledcWrite(0, sensorValue); //Ledには、200Ωの抵抗を接続  //PMWで出力

  delay(5); //5ミリ秒待ってから次のループへ。これがあるとうまくいくらしい。
}
