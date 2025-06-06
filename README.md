# 🎮 Wordle Game Center

Wordle Game Center là một hệ thống chơi trò chơi Wordle đa dạng, hướng đến việc hỗ trợ người chơi rèn luyện kỹ năng tiếng Anh. Giao diện thân thiện, nhạc nền hấp dẫn và hỗ trợ mở rộng thêm rất nhiều mini game khác. Đồng thời người dùng cũng có thể tự thiết kế giao diện thuộc về riêng bản thân.

## Mục lục
- Tính năng
- Cấu trúc thư mục
- Cấu trúc class và form
- Thư viện & API sử dụng
- Cách chạy dự án
- Đóng góp

## Tính năng

### Hệ thống người dùng
- Đăng nhập và đăng ký tài khoản người dùng
- Hệ thống phân quyền (Admin và User)
- Quản lý tài khoản:
  - Xem điểm số
  - Sửa mật khẩu
  - Xoá người dùng
  - Thêm người dùng mới
  - Thêm admin mới
- Bảo mật mật khẩu với mã hóa AES

### Game Features
- Ba chế độ chơi khác nhau (Game1, Game2, Game3)
- Nhiều cấp độ khó (Easy, Medium, Hard)
- Nhiều chủ đề từ vựng:
  - Animals
  - Food
  - Countries
  - Sports
  - Random
- Hệ thống tính điểm và xếp hạng
- Hệ thống gợi ý (Hints)
- Màn hình chúc mừng khi thắng
- Quy tắc chơi chi tiết

### Giao diện và Trải nghiệm
- Giao diện người chơi đơn giản, thân thiện
- Hệ thống animation mượt mà
- Hỗ trợ đa dạng file nhạc nền với AxWindowMediaPlayer
- Tùy chỉnh giao diện:
  - Thay đổi nhạc nền
  - Thay đổi hình nền
  - Tùy chỉnh màu sắc
- Các popup chức năng:
  - Đổi mật khẩu
  - Thêm/xoá tài khoản
  - Cài đặt game

## Cấu trúc thư mục
### Thư mục source code:
/PBL_WORDLE_GAME
│
├── /asset
│   ├── /sound         # File âm thanh nhạc nền
│   ├── /img           # Hình ảnh minh họa
│   └── /logo          # Logo ứng dụng
│
├── /UserList          # Chứa file ${SHA256(username)}.txt (username, AES password)
│
├── /Interop          # Thư viện COM components
│
├── setting.txt        # Lưu đường dẫn nhạc nền, ảnh nền
├── UserData.txt      # Lưu thông tin người dùng
├── UserScore.txt     # Lưu điểm số người chơi
├── *.h               # Các file header chứa code của dự án
└── README.md         # File mô tả dự án

### Thư mục tổng:
/PBL_WORDLE_GAME  
│
├── /PBL_WORDLE_GAME    # Thư mục source code ở trên
│
├── /x64              # Thư mục để chạy dự án
│   ├── /Debug        # Thư mục chứa các thư viện động và file exe để chạy dự án
│           ├── PBL_WORDLE_GAME.exe # file thực thi của dự án
└── PBL_WORDLE_GAME.sln  # File khởi chạy dự án trong visual studio 2022

## Cấu trúc form và class
### Form chính: 
- GameCenter: Form chính để load các UserControl
- Landing: Trang chủ với các link tới Login, Register, Setting, Credit, Quit

### User Controls:
- Login: Xử lý đăng nhập
- Register: Xử lý đăng ký
- Setting: Cài đặt game
- Credit: Thông tin về dự án
- GameRule: Hiển thị luật chơi

### Dashboard:
- Dashboard: Cho người dùng thường
  - Hiển thị game
  - Xoá tài khoản
  - Đổi mật khẩu
  - Log out
- Dashboard_Admin: Cho admin
  - Quản trị User qua DataGridView
  - Tạo tài khoản mới
  - Quản lý người dùng

### Game Forms:
- Game1: Chế độ chơi cơ bản
- Game2: Chế độ chơi nâng cao
- Game3: Chế độ chơi đặc biệt
- Player_Congratulation: Màn hình chúc mừng

### Popup Forms:
- ChangePass: Đổi mật khẩu
- AddAccount: Thêm tài khoản
- Delete_Acc: Xóa tài khoản
- BrowsePopup: Chọn file

### Core Classes:
- Game: Base class cho Game1, Game2, Game3
- Account: Base class cho Admin và User
- CryptoUtils: Quản lý bảo mật và mã hóa
- AnimationManager: Quản lý hoạt ảnh
- SettingManager: Quản lý cài đặt
- User: Quản lý thông tin người dùng

## Thư viện & API
- AxWMPLib.AxWindowMediaPlayer: Phát nhạc nền
- fstream: Đọc/ghi file
- System::Security::Cryptography: Bảo mật và mã hóa
- DataMuse API: Cung cấp từ vựng cho game
- Window::Form: Tạo Form và UserControl
- System::Drawing: Xử lý đồ họa và animation

## Chạy dự án
### Yêu cầu hệ thống:
- Microsoft Visual Studio 2022
- .NET Framework 4.7.2
- AxWindowMediaPlayer (COM component)
- /clr: Hỗ trợ cho dự án Window Form viết bằng CPP/CLI

### Cách chạy:
1. Mở Microsoft Visual Studio 2022
2. Chạy file PBL_WORDLE_GAME.sln
3. Build and Run

## Feedback

Github repo: https://github.com/Dathless/PBL_2
Nếu có bất kì góp ý gì, hãy truy cập link repo trên và chia sẻ. Cảm ơn!

