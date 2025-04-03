#pragma once
using namespace System;
using namespace System::Security::Cryptography;
using namespace System::Text;

namespace PBLWORDLEGAME {
	public ref class CryptoUtils
	{
		//AES encryption and decryption
	private: static array<Byte>^ key = Encoding::UTF8->GetBytes("1234567890123456");
	private: static array<Byte>^ iv = Encoding::UTF8->GetBytes("6543219876543210");
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

	};
}
