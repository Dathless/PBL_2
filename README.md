
# 🎮 Wordle Game Center

Wordle Game Center là một hệ thống chơi trò chơi Wordle đa dạng, hướng đến việc hỗ trợ người chơi rèn luyện kỹ năng tiếng Anh.Giao diện thân thiện, nhạc nền hấp dẫn và hỗ trợ mở rộng thêm rất nhiều
mini game khác. Đồng thời người dùng cũng có thể tự thiết kế giao diện thuộc về riêng bản thân.




## Mục lục
- Tính năng.
- Cấu trúc thư mục.
- Cấu trúc class và form.
- Thư viện & API sử dụng.
- Cách chạy dự án.
- Đóng góp.
 
## Tính năng

- Đăng nhập và đăng ký tài khoản người dùng.
- Hệ thống phân quyền.
- Giao diện người chơi đơn giản, thân thiện.
- Admin có thể quản lý tài khoản: xem điểm, sửa mật khẩu, xoá người dùng, thêm người dùng hoặc admin mới.
- Hệ thống game đa dạng.
- Hỗ trợ đa dạng file nhạc nền với AxWindowMediaPlayer.
- Các popup chức năng: đổi mật khẩu, thêm/xoá tài khoản.
- Cập nhật từ vựng với Datamuse API.
- Hệ thống animation và quản lý file hình nền, âm thanh, ...
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
├── setting.txt        # Lưu đường dẫn nhạc nền, ảnh nền
├── *.h                # Các file header chứa code của dự án
└──README.md          # File mô tả dự án
### Thư mục tổng:
/PBL_WORDLE_GAME  
│
├── /PBL_WORDLE_GAME    # Thư mục source code ở trên
│
├── /x64              # Thư mục để chạy dự án
│   ├── /Debug         # Thư mục chứa các thư viện động và  file exe để chạy dự án
|           ├── PBL_WORDLE_GAME.exe # file thực thi của dự án
└──PBL_WORDLE_GAME.sln  #File khởi chạy dự án trong visual studio 2022
## Cấu trúc form và class
- Form chính: 
    - GameCenter: trống và dùng để load UC Landing
- Điều hướng:
    - Landing: chứa link tới Login, Register, Setting, Credit, Quit.
- User Controls:
    - Login, Register, Setting, Credit: xử lý chức năng tương ứng.
- Dashboard:
    - Dashboard: cho người dùng ( hiển thị game, xoá tài khoản, đổi mật khẩu, log out).
    - Dashboard_Admin: cho admin ( quản trị User thông qua DataGridView, tạo tài khoản mới, ...).
- Game Form:
    - Game1, Game2: các trò chơi hiện tại.
-Popup Form:
    - ChangePass, AddAccount, Delete_Acc,...: Các form chức năng phụ trợ.
-Class:
    - Game: Base class của Game1, Game2. Chứa các hàm tương đồng của 2 form.
    - Account: Base class của Admin, User. Chứa các phương thức và thuộc tính chung của Admin và User.
    - CrytoUtils: quản lý bảo mật.
    - AnimationManager: quản lý hoạt ảnh.
    - SettingManager: quản lý các file trong setting.txt vận hành.
    - BrowsePopup: quản lý việc đọc file với hệ thống.
## Thư viện & API
- AxWMPLib.AxWindowMediaPlayer: phụ trách nhạc nền.
- fstream: hỗ trợ đọc/ghi file.
- System::Sercurity::CryptoGraphy: phụ trách xây dựng bảo mật.
- DataMuse API: lưu trữ từ vựng để vận hành game.
- Window::Form: namespace phụ trách việc tạo Form, UserControl,...
## Chạy dự án
### Yêu cầu hệ thống:
    - Microsoft Visual Studio 2022.
    - .NET FrameWork 4.7.2
    - AxWindowMediaPlayer (COM component)
    - /clr: Hỗ trợ cho dự án Window Form viết bằng CPP/CLI
### Các chạy:
    - Mở Microsoft Visual Studio 2022
    - Chạy file PBL_WORDLE_GAME.sln
    - Build and Run
## Feedback

Github repo: https://github.com/Dathless/PBL_2
Nếu có bất kì góp ý gì, hãy truy cập link repo trên và chia sẽ. Cảm ơn!

