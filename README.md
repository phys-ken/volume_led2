# 音を光で見る実験器具
マイク入力の大きさによって、LEDの明るさが変わります。

# 使用例
共鳴している透明なパイプにこの装置を入れれば、共鳴の様子を見ることができます。  

[![](http://img.youtube.com/vi/J2FA-ZiDZbw/0.jpg)](http://www.youtube.com/watch?v=J2FA-ZiDZbw "気柱の共鳴を音で見る")


# 機材
* [ESP32 devkitC](https://akizukidenshi.com/catalog/g/gM-11819/)
* LED (高輝度だと良い。)
* [高感度マイクアンプキット](https://akizukidenshi.com/catalog/g/gK-05757/)

# 雑感
* マイコンを覚えて最初に作った実験器具。たかがこれだけのためにESP32を使うのはもったいない。Arduino nanoで十分
  →Arduinoで描き直す。
* 変数型にミスがあるか? とりあえずこれでも動きますが、細かいコードの修正を続けています。

2020/4/13