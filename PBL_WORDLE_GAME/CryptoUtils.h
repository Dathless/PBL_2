#pragma once
#include <fstream>
using namespace System;
using namespace System::IO;
using namespace System::Security::Cryptography;
using namespace System::Text;
using namespace System::Collections::Generic;

namespace PBLWORDLEGAME {
    public ref class CryptoUtils {
    private:
        static array<Byte>^ key;
        static array<Byte>^ iv;
        static Dictionary<String^, int>^ loginAttempts;
        static Dictionary<String^, DateTime>^ loginTimestamps;
        static Dictionary<String^, int>^ blockCount;
        static String^ fileLog;

        // Static constructor to initialize static variables
        static CryptoUtils() {
            key = Encoding::UTF8->GetBytes("1234567890123456");
            iv = Encoding::UTF8->GetBytes("6543219876543210");
            loginAttempts = gcnew Dictionary<String^, int>();
            loginTimestamps = gcnew Dictionary<String^, DateTime>();
            blockCount = gcnew Dictionary<String^, int>();
            fileLog = "UserList\\log.txt";
        }

    public:
        static String^ Encrypt(String^ plainText) {
            Aes^ aes = Aes::Create();
            try {
                aes->Key = key;
                aes->IV = iv;
                aes->Padding = PaddingMode::PKCS7;

                ICryptoTransform^ encryptor = aes->CreateEncryptor();
                array<Byte>^ plainBytes = Encoding::UTF8->GetBytes(plainText);
                array<Byte>^ encryptedBytes = encryptor->TransformFinalBlock(plainBytes, 0, plainBytes->Length);
                return Convert::ToBase64String(encryptedBytes);
            }
            finally {
                delete aes;
            }
        }

        static String^ Decrypt(String^ encryptedText) {
            Aes^ aes = Aes::Create();
            try {
                aes->Key = key;
                aes->IV = iv;
                aes->Padding = PaddingMode::PKCS7;

                ICryptoTransform^ decryptor = aes->CreateDecryptor();
                array<Byte>^ encryptedBytes = Convert::FromBase64String(encryptedText);
                array<Byte>^ decryptedBytes = decryptor->TransformFinalBlock(encryptedBytes, 0, encryptedBytes->Length);
                return Encoding::UTF8->GetString(decryptedBytes);
            }
            finally {
                delete aes;
            }
        }

        static String^ ComputeSHA256(String^ input) {
            array<Byte>^ inputBytes = Encoding::UTF8->GetBytes(input);
            SHA256^ sha256 = SHA256::Create();
            try {
                array<Byte>^ hashBytes = sha256->ComputeHash(inputBytes);
                StringBuilder^ sb = gcnew StringBuilder();
                for each (Byte b in hashBytes) {
                    sb->Append(b.ToString("x2"));
                }
                return sb->ToString();
            }
            finally {
                delete sha256;
            }
        }

        static void LoadLoginAttempts() {
            loginAttempts->Clear();
            loginTimestamps->Clear();
            blockCount->Clear();
            if (File::Exists(fileLog)) {
                try {
                    array<String^>^ lines = File::ReadAllLines(fileLog);
                    for each (String ^ line in lines) {
                        array<String^>^ parts = line->Split(',');
                        if (parts->Length == 4) {
                            loginAttempts[parts[0]] = Int32::Parse(parts[1]);
                            loginTimestamps[parts[0]] = DateTime::Parse(parts[2]);
                            blockCount[parts[0]] = Int32::Parse(parts[3]);
                        }
                    }
                }
                catch (Exception^ ex) {
                    Console::WriteLine("Error loading login attempts: " + ex->Message);
                }
            }
        }

        static void SaveLoginAttempts() {
            try {
                List<String^>^ lines = gcnew List<String^>();
                for each (KeyValuePair<String^, int> entry in loginAttempts) {
                    String^ lastTime = loginTimestamps->ContainsKey(entry.Key) ? loginTimestamps[entry.Key].ToString() : "";
                    int blockNum = blockCount->ContainsKey(entry.Key) ? blockCount[entry.Key] : 0;
                    lines->Add(entry.Key + "," + entry.Value + "," + lastTime + "," + blockNum);
                }
                File::WriteAllLines(fileLog, lines);
            }
            catch (Exception^ ex) {
                Console::WriteLine("Error saving login attempts: " + ex->Message);
            }
        }

        static bool CanLogin(String^ username) {
            if (loginAttempts->ContainsKey(username) && loginAttempts[username] >= 5) {
                if (loginTimestamps->ContainsKey(username)) {
                    int blockNum = blockCount->ContainsKey(username) ? blockCount[username] : 0;
                    int waitTime = Math::Pow(2, blockNum); // 2^n minutes

                    TimeSpan diff = DateTime::Now - loginTimestamps[username];
                    if (diff.TotalMinutes < waitTime) {
                        return false;
                    }
                    else {
                        loginAttempts[username] = 0;
                        SaveLoginAttempts();
                    }
                }
            }
            return true;
        }

        static void RecordLoginAttempts(String^ usr, bool success) {
            if (!loginAttempts->ContainsKey(usr)) {
                loginAttempts->Add(usr, 0);
                blockCount->Add(usr, 0);
            }

            if (success) {
                loginAttempts[usr] = 0;
                blockCount[usr] = 0;
            }
            else {
                loginAttempts[usr] += 1;
                if (loginAttempts[usr] >= 5) {
                    loginTimestamps[usr] = DateTime::Now;
                    blockCount[usr] = blockCount->ContainsKey(usr) ? blockCount[usr] + 1 : 1;
                }
            }

            SaveLoginAttempts();
        }

        static int getLoginAttempts(String^ usr) {
            return loginAttempts->ContainsKey(usr) ? loginAttempts[usr] : 0;
        }
    };
}
