## Proje2---Mahrek


ASCII yörünge simülasyonu.

2 cismin birbirine etki eden çekim kuvveti newtonun formülüyle hesaplanır (F=G*m1*m2/r^2). Her 2 noktada "dots" isimli sınıftan birer nesne olarak oluşturulur ve kordinat değerleri x'deki (Cx) ve y^deki (Cy) olmak üzeredir. Cisimler arasındaki mesafe noktaların Cx ve Cy değerleri farklarının hesaplanması, sonrasında pisagor formülü uygulanmasıyla hesaplanır. Kütle, mesafe ve G sabit değerleri formülünden kuvvet hesaplanır. Bu kuvvet cisimlerin ikisinede etki eder fakat nokta1'e etki eden kuvvet F ise nokta2'ye etki eden de -F olacaktır. Bu kuvvetin iki bileşeni vardır Fx ve Fy olmak üzere. Bu bileşenleri bulabilmek için noktaların birbirine göre olan konum vektörlerini birimleştiririz (bunu yapabilmek için Cx ve Cy farklarını, cisimler arasındaki uzaklık değerine böleriz) ve sonrasında yatay ve düşeydeki bileşenleri F değeriyle çarparız. bir noktada değerler Fx ve Fy iken diğerinde -Fx ve -Fy'dir. Kuvvet etki etmesiyle cisimlerin ikiside ivme kazanır (F=m*a) formülüne göre. Bizim ihtiyacımız olan ivme değil hız. Ama hız ivme ilişkisi kurabilmemiz için zaman değerine ihtiyacımız var. Bu değer kodda Diferansiyel zaman değeri olarak tanımlanmıştır (tamamen keyfi bir değerdir. Ne kadar küçük olursa simülasyon o kadar gerçekçi olur. Fark şu şekil düşünülebilir, bu değer ne kadar az olursa hız*zaman dolayısıyla  cisimlerin aldıkları konumlar daha az olur bu sayede birim zamanda daha fazla görüntü görülür. Başka bir değişle zaman değeri küçülürse birim zamandaki FPS artar). Hızı hesaplayabilmek için ivmeyi hızın türevi biçminde yazabiliriz (a=dv/dt). Formül F = m*dv/dt olur denklemin iki tarafınıda dt ile çarparsak F*dt=m*dv olur. İki tarafında integrallerini alırsak soldaki zaman sınırları 0'dan t'ye şeklinde ifade edilir. Sağdaki hız integral sınırları ise V0'dan V'ye şeklinde ifade edilir. İntegraller çözülürse F*t= (m*v-m*v0) denklemi elde edilir. Burada V değerini yanlız bırakırsak V = (F*t + m*v0)/m ifadesi elde edilir. Burada V güncel hızı ifade eder V0 ise bir önceki iterasyondaki hız değeridir. Bu yüzden t değeri başlangıçtan itibaren geçen süre değilde bir önceki iterasyonla şimdiki iterasyon arası zaman farkı olarak tanımlanmıştır diferansiyel zaman olarak tanımlanmasının sebebi budur. Cisimlerin yatay ve düşey hızlarını hesaplamak için ise denklemde F yazan yere Fx yada Fy bileşenlerini yazarız. Bu işlemler sayesinde hesaplamaya çalıştığımız hız değerlerini her bir iterasyonda güncelleyerek cisimleri ekrana bastırabiliriz ve hareketlerini inceleyebiliriz. Anlatılan işlemi Calculate fonksiyonu yapmaktadır. Mesafeyi dist fonksiyonu hesaplar ve bastırma işlemini printf fonksiyonu üstlenir. Sim fonksiyonu ise bu fonksiyonları kullanıp bir döngü içerisinde simülasyonu gerçekleştirip ekrana basılmasını sağlar. Move fonksiyonu cisimlerin terminal sınırlanıra çarpması durumunda çarpılan duvara göre hız değerlerini -1 ile çarparak yönünü değiştirir ve çıkmasını engeller. updateConsoleDimensions fonksiyonu ise terminalin yatay ve dikey boyutlarını referans olarak aldığı parametreler üzerinde günceller. Bu parametreler W(width) ve H(height) olan global değişeknlerdir. Cisimlerin hareketleri boyunca iz bırakılması isteniyorsa iz izni değeri 1 yapılmalıdır. Noktaların kordinatları, ilk hızları, kütleleri, görüntüleri, Difzaman ve G sabit değerinin rastgele belirlenmesi isteniyorsa rastgele mod, 1 yapılmalıdır. Eğer değerler el ile girilecekse 0 yapılır ve devam edilir.

İlginç çıktılar için girdiler:

1. ZigZag
  * iz = 1
  * rastgele mod = 0
  * nokta1 = 1 1 1 @ 1 1
  * nokta2 = 1 1 1 @ 1 1
  * zaman = 1
  * G = 1

2. Rastgele
  * iz = 0 veya 1
  * rasgele mod = 1

3. Yörünge
  * iz = 0 veya 1
  * rastgele mod = 0
  * nokta1 = 80 15 4000 * 0 0
  * nokta2 = 80 15 1 + 0 20
  * zaman = 0.05
  * G = 1
4. Çarpışma
  * iz = 0
  * rastgele mod = 0
  * nokta1 = 70 10 20000 @ 0 0
  * nokta2 = 85 15 20000 @ 0 0
  * zaman  = 0.05
  * G = 1

    Gibi örnekler mevcut. Semboller rastgele verilebilir tamamen keyfi. Daha fazla hareket modeli denenerek bulunabilir. Girdiler README'de yazıldığı formatta girilir. Kod içerisinde de zaten girdiler için yönlendirmeler mevcuttur.
