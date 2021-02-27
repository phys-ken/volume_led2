# 音を光で見る実験器具
マイク入力の大きさによって、LEDの明るさが変わります。

# 使用例
共鳴している透明なパイプにこの装置を入れれば、共鳴の様子を見ることができます。  
![test](resAnime.gif)

[動画はこちら](http://www.youtube.com/watch?v=J2FA-ZiDZbw "気柱の共鳴を音で見る")


# 機材
* [ESP32 devkitC](https://akizukidenshi.com/catalog/g/gM-11819/)
* LED (高輝度だと良い。)
* [高感度マイクアンプキット](https://akizukidenshi.com/catalog/g/gK-05757/)

# 雑感
* マイコンを覚えて最初に作った実験器具。たかがこれだけのためにESP32を使うのはもったいない。Arduino nanoで十分
  →Arduinoで描き直す。
* ~~変数型にミスがあるか? とりあえずこれでも動きますが、細かいコードの修正を続けています。~~
  * 修正できました！Arduinoだと$$ a^b $$ は、pow(a,b)って書くらしいです、知らなかった...。


[githubのコードはこちら](https://github.com/phys-ken/volume_led2)  
[github pagesはこちら](https://phys-ken.github.io/volume_led2/README.html)  

2020/4/13