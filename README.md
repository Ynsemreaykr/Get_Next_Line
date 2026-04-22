# get_next_line - Dosyadan Satır Satır Okuma

## 📝 Proje Hakkında

**get_next_line**, École 42 müfredatının temel projelerinden biridir. Bu projenin amacı, bir dosya tanımlayıcısından (file descriptor) okuma yaparak, her çağrıldığında bir sonraki satırı döndüren bir fonksiyon yazmaktır. Proje, statik değişkenlerin kullanımını, bellek yönetimini ve dosya okuma işlemlerini derinlemesine anlamayı sağlar.

## 🚀 Özellikler

- **Satır Satır Okuma**: Dosya sonuna gelene kadar her çağrıda yeni bir satır döndürür.
- **Dinamik Bellek Yönetimi**: Her satır için bellek dinamik olarak ayrılır ve sızıntıları önlemek için dikkatle yönetilir.
- **Esnek BUFFER_SIZE**: Derleme sırasında belirlenen herhangi bir `BUFFER_SIZE` değeri ile sorunsuz çalışır.
- **Bonus Özellikler**: Aynı anda birden fazla dosya tanımlayıcısını (fd) yönetebilir, birbirine karıştırmadan okuma yapabilir.

## 🛠️ Gereksinimler

Proje, standart C kütüphanesi fonksiyonlarından sadece `read`, `malloc` ve `free` kullanımına izin verir. Derleme işlemi sırasında `BUFFER_SIZE` makrosunun tanımlanması gerekir.

## 🏗️ Derleme ve Kullanım

### Projeye Dahil Etme

Fonksiyonu projenizde kullanmak için ilgili başlık dosyasını dahil etmelisiniz:

```c
#include "get_next_line.h"
```

### Derleme

Kodu derlemek için aşağıdaki komutu kullanabilirsiniz (örneğin `BUFFER_SIZE=42` için):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

### Örnek Kullanım

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 📂 Dosya Yapısı

- `get_next_line.c`: Ana mantığın bulunduğu dosya.
- `get_next_line_utils.c`: Yardımcı fonksiyonların bulunduğu dosya.
- `get_next_line.h`: Fonksiyon prototipleri ve makro tanımları.
- `get_next_line_bonus.c`: Çoklu fd desteği olan sürüm.
- `get_next_line_utils_bonus.c`: Bonus sürümü için yardımcı fonksiyonlar.
- `get_next_line_bonus.h`: Bonus sürümü için başlık dosyası.

## 👤 Hazırlayan

Bu proje **yayiker** tarafından École 42 standartlarına uygun olarak hazırlanmıştır.

---
*Başarılar!*
