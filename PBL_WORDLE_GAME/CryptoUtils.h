#pragma once
#include <fstream>
using namespace System;
using namespace System::IO;
using namespace System::Security::Cryptography;
using namespace System::Text;

namespace PBLWORDLEGAME {
	public ref class CryptoUtils
	{
		//AES encryption and decryption
	private: static array<Byte>^ key = Encoding::UTF8->GetBytes("1234567890123456");
	private: static array<Byte>^ iv = Encoding::UTF8->GetBytes("6543219876543210");
	private: static Dictionary<String^, int>^ loginAttempts = gcnew Dictionary<String^, int>();
	private: static Dictionary<String^, DateTime>^ loginTimestamps = gcnew Dictionary<String^, DateTime>();
	private: static Dictionary<String^, int>^ blockCount = gcnew Dictionary<String^, int>();
    private: static String^ fileLog = "UserList\\log.txt";
	public:
        // Encrypt text using AES
        static String^ Encrypt(String^ plainText) {
            Aes^ aes = Aes::Create();
            aes->Key = key;
            aes->IV = iv;
            aes->Padding = PaddingMode::PKCS7;

            ICryptoTransform^ encryptor = aes->CreateEncryptor();
            array<Byte>^ plainBytes = Encoding::UTF8->GetBytes(plainText);
            array<Byte>^ encryptedBytes = encryptor->TransformFinalBlock(plainBytes, 0, plainBytes->Length);

            return Convert::ToBase64String(encryptedBytes); // Convert to Base64 for easy storage
        }
        // Decrypt AES encrypted text
        static String^ Decrypt(String^ encryptedText) {
            Aes^ aes = Aes::Create();
            aes->Key = key;
            aes->IV = iv;
            aes->Padding = PaddingMode::PKCS7;

            ICryptoTransform^ decryptor = aes->CreateDecryptor();
            array<Byte>^ encryptedBytes = Convert::FromBase64String(encryptedText);
            array<Byte>^ decryptedBytes = decryptor->TransformFinalBlock(encryptedBytes, 0, encryptedBytes->Length);

            return Encoding::UTF8->GetString(decryptedBytes);
        }
        static String^ ComputeSHA256(String^ input) {
            array<Byte>^ inputBytes = Encoding::UTF8->GetBytes(input);
            SHA256^ sha256 = SHA256::Create();
            array<Byte>^ hashBytes = sha256->ComputeHash(inputBytes);

            // Convert to hexadecimal string
            StringBuilder^ sb = gcnew StringBuilder();
            for each (Byte b in hashBytes) {
                sb->Append(b.ToString("x2")); // Format as hexadecimal
            }
            return sb->ToString();
        }
        static System::Void LoadLoginAttemp() {
			loginAttempts->Clear();
			loginTimestamps->Clear();
			blockCount->Clear();
            if (File::Exists(fileLog)) {
				array<String^>^ lines = File::ReadAllLines(fileLog);\
                    for each (String ^ line in lines) {
                        array<String^>^ parts = line->Split(',');
                        if (parts->Length == 4) {
                            loginAttempts[parts[0]] = Int32::Parse(parts[1]);
                            loginTimestamps[parts[0]] = DateTime::Parse(parts[2]);
                            blockCount[parts[0]] = Int32::Parse(parts[3]);
                        }
                    }
            }
        }
        static System::Void SaveLoginAttempts() {
			List<String^>^ lines = gcnew List<String^>();
            for each (KeyValuePair<String^, int> entry in loginAttempts) {
                String^ lastTime = loginTimestamps->ContainsKey(entry.Key) ? loginTimestamps[entry.Key].ToString() : "";
                int blockNum = blockCount->ContainsKey(entry.Key) ? blockCount[entry.Key] : 0;
                lines->Add(entry.Key + "," + entry.Value + "," + lastTime + "," + blockNum);
            }
			File::WriteAllLines(fileLog, lines);
        }
		static bool CanLogin(String^ username) {
			if (loginAttempts->ContainsKey(username)) {
                if (loginAttempts[username] >= 5) {
                    if (loginTimestamps->ContainsKey(username)) {
                        int blockNum = blockCount->ContainsKey(username) ? blockCount[username] : 0;
                        int waitTime = Math::Pow(2, blockNum); // 2^n minutes

                        TimeSpan diff = DateTime::Now - loginTimestamps[username];
                        if (diff.TotalMinutes < waitTime) {
                            return false; // Still in timeout
                        }
                        else {
                            loginAttempts[username] = 0; // Reset attempts after timeout
                            SaveLoginAttempts();
                        }
                    }
                }
			}
			return true; // Allow login
		}
        static System::Void RecordLoginAttempts(String^ usr, bool success) {
            if (!loginAttempts->ContainsKey(usr)) {
                loginAttempts->Add(usr, 0);
                blockCount->Add(usr, 0);
            }

            if (success) {
                loginAttempts[usr] = 0; // Reset on success
                blockCount[usr] = 0;    // Reset block count
            }
            else {
                loginAttempts[usr] += 1;
                if (loginAttempts[usr] >= 5) {
                    loginTimestamps[usr] = DateTime::Now;

                    // Increase block count and waiting time
                    blockCount[usr] = blockCount->ContainsKey(usr) ? blockCount[usr] + 1 : 1;
                }
            }

            SaveLoginAttempts();
        }
    public:static int getLoginAttempts(String^ usr) {
		return loginAttempts[usr];
    }
	};
}
