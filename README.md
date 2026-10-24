# Quản lý khách hàng nhà xe (C++ Console)

Chương trình console viết bằng C++ để quản lý khách hàng đặt vé xe khách xuất phát từ **Đà Nẵng**.
Đây là dự án năm nhất, giao diện vẽ bằng ký tự trong cửa sổ console và điều khiển bằng phím mũi tên.

## Chức năng

- Đặt vé: nhập số điện thoại, họ tên, tuyến đi, chọn ngày (lịch 30 ngày) và ghế (giường A/B, khung giờ 8h/10h).
- Xuất danh sách khách theo ngày xuất phát và tuyến đi.
- Tìm khách theo tên, sau đó chỉnh sửa thông tin hoặc xoá khách.
- Xuất toàn bộ dữ liệu khách hàng.

Các tuyến: Đà Nẵng - Quảng Nam, Đà Nẵng - Thừa Thiên Huế, Đà Nẵng - Hồ Chí Minh. Giờ xuất phát: 8h và 10h.

## Cấu trúc thư mục

```
bus-customer-management/
├── src/
│   ├── quanli/
│   │   ├── quanlikhachhang.cpp   # Chương trình quản lý đầy đủ (menu, tìm kiếm, sửa, xoá, xuất danh sách)
│   │   └── xuli.h                # Struct khách hàng và các hàm xử lý chuỗi, xoá dữ liệu
│   └── datvexe/
│       ├── datve.cpp             # Phiên bản chỉ dùng cho đặt vé (có ghi dữ liệu ra file)
│       └── xuli1.h               # Struct khách hàng và hàm phân loại cho phần đặt vé
├── data/
│   ├── dulieu.txt                # Dữ liệu khách hàng (mỗi khách 5 dòng)
│   └── count.txt                 # Số lượng khách hàng trong dulieu.txt
├── .gitignore
└── README.md
```

Định dạng mỗi khách trong `dulieu.txt` (5 dòng): họ tên, số điện thoại, tuyến đi, mã số chuyến đi (ví dụ `8h-A12`), ngày xuất phát.

## Yêu cầu

- **Windows** (code dùng `windows.h` và `conio.h`).
- Trình biên dịch g++ (MinGW) hoặc Dev-C++.
- Nên phóng to cửa sổ console, vì giao diện vẽ ở toạ độ lớn (cột đến khoảng 150).

## Biên dịch và chạy

Chương trình đọc `dulieu.txt` và `count.txt` theo đường dẫn tương đối, nên cần chạy từ thư mục `data/`.

```bash
mkdir build
g++ src/quanli/quanlikhachhang.cpp -o build/quanli.exe
cd data
../build/quanli.exe
```

Phiên bản đặt vé:

```bash
g++ src/datvexe/datve.cpp -o build/datve.exe
```

## Cách dùng

- Phím mũi tên lên/xuống: di chuyển trong menu.
- Enter: chọn.
- Khi chọn ngày: mũi tên để di chuyển, **Enter** để xem ghế của ngày đó, phím **s** để lưu ngày rồi nhập mã số chuyến đi.
- Phím mũi tên trái: quay lại menu, **Esc**: thoát.

## Lưu ý

- `datve.cpp` còn đường dẫn tuyệt đối trên máy tác giả (`C:\Users\ADMIN\...`) và đường dẫn OneDrive trong `main`. Muốn chạy trên máy khác cần đổi lại thành đường dẫn tương đối như `quanlikhachhang.cpp`.
- Giá trị trong `count.txt` hiện nhỏ hơn số khách thực tế trong `dulieu.txt`, nên chương trình chỉ nạp phần đầu danh sách.
- Chức năng "Xoá khách hàng" ở menu chính và "In hoá đơn" chưa hoàn thiện. Có thể xoá khách qua mục "Tìm theo tên".

## Hướng phát triển

- Lưu dữ liệu từ `quanlikhachhang.cpp` ra file sau khi thêm, sửa, xoá.
- Gom các hàm đồ hoạ console dùng chung (`gotoxy`, `TextColor`...) vào một header riêng.
- Kiểm tra ghế đã có người đặt khi đặt vé.
