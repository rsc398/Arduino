
void loop() {
    if ( ! mfrc522.PICC_IsNewCardPresent()) return;

    if ( ! mfrc522.PICC_ReadCardSerial()) return;

    Serial.print("Card UID:");
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    Serial.println();
    Serial.print("PICC type: ");
    byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.println(mfrc522.PICC_GetTypeName(piccType));

    if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
        Serial.println("This sample only works with MIFARE Classic cards.");
        return;
    }


    byte sector         = 1;
    byte blockAddr      = 4;
    byte dataBlock[]    = {
        0x01, 0x02, 0x03, 0x04,
        0x05, 0x06, 0x07, 0x08,
        0x08, 0x09, 0xff, 0x0b,
        0x0c, 0x0d, 0x0e, 0x0f
    };
    byte trailerBlock   = 7;
    byte status;
    byte buffer[18];
    byte size = sizeof(buffer);

    Serial.println("Authenticating using key A...");
    status = mfrc522.PCD_Authenticate(
        MFRC522::PICC_CMD_MF_AUTH_KEY_A,
        trailerBlock,
        &key,
        &(mfrc522.uid)
    );
    if (status != MFRC522::STATUS_OK) return;

    Serial.println("Current data in sector:");
    mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector);
    Serial.println();

    Serial.print("Reading data from block "); Serial.println(blockAddr);
    mfrc522.MIFARE_Read(blockAddr, buffer, &size);
    Serial.print("Data in block "); Serial.print(blockAddr); Serial.println(":");
    dump_byte_array(buffer, 16); Serial.println(); Serial.println();

    Serial.println("Authenticating again using key B...");
    status = mfrc522.PCD_Authenticate(
        MFRC522::PICC_CMD_MF_AUTH_KEY_B,
        trailerBlock,
        &key,
        &(mfrc522.uid)
    );
    if (status != MFRC522::STATUS_OK) return;

    Serial.print("Writing data into block "); Serial.println(blockAddr);
    dump_byte_array(dataBlock, 16); Serial.println();
    mfrc522.MIFARE_Write(blockAddr, dataBlock, 16);

    Serial.print("Reading data from block "); Serial.println(blockAddr);
    status = mfrc522.MIFARE_Read(blockAddr, buffer, &size);
    Serial.print("Data in block "); Serial.print(blockAddr); Serial.println(":");
    dump_byte_array(buffer, 16); Serial.println();
        

    Serial.println("Checking result...");
    byte count = 0;
    for (byte i = 0; i < 16; i++) if (buffer[i] == dataBlock[i]) count++;
    if (count == 16) Serial.println("Success :-)");
    else Serial.println("Failure, no match :-(");
    Serial.println();
        
    Serial.println("Current data in sector:");
    mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector);
    Serial.println();

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
}
