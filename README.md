# Strassen Matrix Multiplication (C++)

An educational implementation of the **Strassen matrix multiplication algorithm** in C++. This algorithm improves the performance of matrix multiplication by reducing the number of recursive multiplications required, making it faster than the conventional method for large matrices.

## ✨ Features

- Matrix multiplication using the Strassen algorithm
- Works with matrices of size `n x n` where `n = 2^k`
- Random matrix generation
- Console output of matrices

## 🧪 Usage

Compile and run using a C++ compiler (Windows specific due to headers like `<dos.h>`, `<conio.h>`):

```bash
g++ strassen.cpp -o strassen.exe
./strassen.exe
```

Enter a value for `n` such that `n = 2^k` (e.g., 2, 4, 8, ...), and the program will generate two random matrices and output their product using Strassen's method.

---

# 🇮🇷 ضرب ماتریسی به روش استراسن (C++)

این پروژه یک پیاده‌سازی آموزشی از الگوریتم استراسن برای ضرب ماتریسی در زبان ++C است. این الگوریتم با کاهش تعداد ضرب‌های بازگشتی نسبت به روش سنتی سریع‌تر عمل می‌کند، به‌ویژه برای ماتریس‌های بزرگ.

## ✨ ویژگی‌ها

- ضرب ماتریسی با استفاده از الگوریتم استراسن
- پشتیبانی از ماتریس‌های مربعی با اندازه `n x n` که `n = 2^k` باشد
- تولید ماتریس‌های تصادفی
- نمایش خروجی ماتریس‌ها در کنسول

## 🚀 نحوه اجرا

کد را با یک کامپایلر ++C روی ویندوز اجرا کنید (به علت استفاده از `<dos.h>` و `<conio.h>` مخصوص ویندوز است):

```bash
g++ strassen.cpp -o strassen.exe
./strassen.exe
```

پس از اجرای برنامه، عددی مثل 2 یا 4 یا 8 وارد کنید (توانی از ۲) تا برنامه دو ماتریس تصادفی تولید کرده و حاصل ضرب آن‌ها را با روش استراسن نمایش دهد.

---

## 📎 License

Apache License 2.0 — Free for personal or commercial use. See [LICENSE](./LICENSE).

