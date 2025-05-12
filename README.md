# 📘 Topolojik Sıralama (Topological Sorting)

## 🔍 Algoritma Ne Yapar?

Topolojik sıralama,ağırlıklı olmayan,tek yönlü döngüsüz graflarda (DAG - Directed Acyclic Graph) düğümlerin sıralanmasıdır. Bu sıralamada, her kenar **(u → v)** için **u**, **v**'den önce gelir. Başka bir deyişle, bir görev başka bir görevden önce yapılmak zorundaysa bu algoritma ile doğru sıralama elde edilir.Örneğin,çamaşır yıkarken çamaşırları kurutucuya koymadan önce çamaşır makinesi işi bitirmelidir.

---

## 📂 Kategori

- 📌 **Graf Teorisi**
- 📌 **Sıralama Algoritmaları**
- 📌 **Veri Yapıları ve Algoritmalar**

---

## ⚙️ Çözüm Yaklaşımı

Topolojik sıralama için iki temel çözüm yöntemi vardır:

### 1. Derinlik Öncelikli Arama (DFS) Tabanlı Yaklaşım

1. Ziyaret edilmeyen her düğüm için DFS başlatılır.
2. Her DFS çağrısı sırasında, düğümün bağlı olduğu komşular ziyaret edilir.
3. Tüm komşular ziyaret edildikten sonra düğüm bir yığına (stack) eklenir.
4. DFS tamamlandığında, yığın ters çevrilerek sıralama elde edilir.

### 2. Kahn'nın Algoritması (BFS Tabanlı)

1. Tüm düğümlerin **giriş dereceleri (in-degree)** hesaplanır.
2. Giriş derecesi 0 olan düğümler bir kuyruğa eklenir.
3. Kuyruktan düğümler çekilip, bağlı oldukları düğümlerin giriş dereceleri azaltılır.
4. Yeni giriş derecesi 0 olanlar kuyruğa eklenir.
5. Tüm düğümler işleninceye kadar bu işlem devam eder.

---

## 📆 Ne Zaman ve Neden Kullanılır?

- Ders programı oluşturma (ön koşullu derslerde sıralama)
- Görev zamanlama sistemleri (task scheduling)
- Yazılım projelerinde modül bağımlılıklarının çözümü
- Derleme sistemlerinde dosya derleme sırası
- Kurulum sihirbazlarında adım sıralama

---

## ⏱ Karmaşıklık Analizi

| Ölçüt | DFS Tabanlı | Kahn's Algoritması |
|-------|-------------|--------------------|
| Zaman | O(V + E)    | O(V + E)           |
| Bellek| O(V)        | O(V + E)           |

- **V:** Düğüm sayısı
- **E:** Kenar sayısı

---

## 🧩 Algoritmanın Adımları

**🔸 DFS ile Topolojik Sıralama**:

1. Tüm düğümler "ziyaret edilmedi" olarak işaretlenir.

2. Her düğüm için:

3. Eğer ziyaret edilmemişse DFS başlatılır.

4. DFS içinde komşular ziyaret edilir.

5. Her DFS tamamlandığında düğüm bir yığına (stack) eklenir.

6. DFS tamamlandıktan sonra yığın ters çevrilerek topolojik sıralama elde edilir.

**🔸 BFS ile Topolojik Sıralama (Kahn's Algorithm)**:

1. Tüm düğümlerin giriş dereceleri hesaplanır.

2. Giriş derecesi 0 olan düğümler kuyruğa eklenir.

3. Kuyruktan bir düğüm çekilip sıraya alınır.

4. Bu düğümün komşularının giriş dereceleri 1 azaltılır.

5. Giriş derecesi 0 olan yeni düğümler kuyruğa eklenir.

6. Tüm düğümler işlenene kadar bu adımlar devam eder.


---

## 💡 Kullanım Yerlerine Ait Örnekler

- Üniversite ders planlamasında (Örneğin: Calculus 1 dersi alınmadan Calculus 2 dersine geçiş yapılamaz.)
- Projelerde bağımlı görevlerin sıralanması (Örneğin: Veritabanı kurulmadan uygulama başlatılamaz)
- Derleyici sistemleri (Örneğin: gcc, clang gibi)
- Paket yöneticileri (Örneğin: npm, apt, pip)

---

## ⚖️ Algoritmanın Avantaj ve Dezavantajları

### ✅ Avantajlar:
- Hızlı ve etkili çözüm sunar.
- Döngüsüz graflarda net ve tutarlı sıralama verir.
- Pek çok pratik probleme uygundur.

### ❌ Dezavantajlar:
- Yalnızca ağırlıksız ve tek yönlü döngüsüz graflarda çalışır.
- Döngü kontrolü gereklidir (graf döngü içerirse sıralama mümkün değildir).
- Yönsüz graflarda kullanılamaz.
- Ağırlıklı graflarda kullanılamaz

---

## 🔗 Kaynakça

- [Wikipedia - Topological Sorting] https://en.wikipedia.org/wiki/Topological_sorting
- [GeeksforGeeks - Topological Sorting Algorithms] https://www.geeksforgeeks.org/topological-sorting/

---

> 📌 **Not:** Bu belge GitHub veya GitLab üzerinden bir repository içinde README.md olarak kaydedilmelidir. Kod ve test dosyaları bu repo içinde yer almalıdır.
