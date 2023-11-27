/*
 * stegano.c
 *
 *  Created on: Nov 6, 2011
 *      Author: J. Geurts
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"
#include "resource_detector.h"
#include "stegano.h"

#define MAX_FILENAME 80

extern uint8_t SteganoGetSubstring(
            uint8_t Src, uint8_t SrcPos, uint8_t NrOfBits, uint8_t DestPos)
/* description: get a substring of bits from a uint8_t (i.e. a byte)
 *
 * example: SteganoGetSubstring (Src, 3, 4, 1) with Src=ABCDEFGH (bit H is LSB)
 *          = 000BCDE0
 *
 * parameters:
 *      Src:       byte to get the substring from
 *      SrcPos:    position of the first bit of the substring (LSB=0)
 *      NrOfBits:  length of the substring
 *      DestPos:   position of the first bits of the destination substring
 *
 * return:
 *      substring, starting at DestPos
 */
{
    //remove all the values right of the first bit that needs to be returned
    uint8_t returnSubString = Src >> SrcPos;

    //remove all of the values left of the last bit that needs to be returned
    returnSubString <<= (8 - NrOfBits);

    //at this point all the relevant bits are on the most left side of the byte
    //we need to shift them to the destination position
    returnSubString >>= ((8 - NrOfBits) - DestPos);

    //at last we return the new substring
    return returnSubString;
}


// should be static in real life, but would give a compiling error in the
// unchanged code because this function is not yet used
static void ReadHdr(
            FILE* FilePtr, BMP_MAGIC_t* Magic, BMP_FILE_t* File,
            BMP_INFO_t* Info) 
/*
 * description: read the header of a bmp File, and store the data in the
 * provided parameters
 *
 * parameters:
 *         FilePtr: file, opened for reading
 *         Magic:   output-parameter to store the read BMP_MAGIC_t structure
 *         File:    output-parameter to store the read BMP_FILE_t structure
 *         Info:    output-parameter to store the read BMP_INFO_t structure
 *
 * Note: caller should provide enough memory for parameters 'Magic', 'File' and
 * 'Info'
 */
{
    //if any of the pointers are NULL we should exit the function
    if(FilePtr == NULL || Magic == NULL || File == NULL || Info == NULL)
    {
        return;
    }

    //reseting the file reading pointer to the beginning of the file
    fseek(FilePtr, 0, SEEK_SET);

    //============== Magic ==============

    //reading the first two bytes of the header
    fread(&Magic->magic, sizeof(Magic->magic), 1, FilePtr);


    //============== File ==============

    //reading file size
    fread(&File->filesz, sizeof(File->filesz), 1, FilePtr);

    //reading creators
    fread(&File->creator1, sizeof(File->creator1), 1, FilePtr);
    fread(&File->creator2, sizeof(File->creator2), 1, FilePtr);

    //reading bmp offset
    fread(&File->bmp_offset, sizeof(File->bmp_offset), 1, FilePtr);


    //============== Info ==============

    //reading header size
    fread(&Info->header_sz, sizeof(Info->header_sz), 1, FilePtr);

    //reading height & width
    fread(&Info->width, sizeof(Info->width), 1, FilePtr);
    fread(&Info->height, sizeof(Info->height), 1, FilePtr);

    //reading number of colour planes
    fread(&Info->nplanes, sizeof(Info->nplanes), 1, FilePtr);

    //reading bits per pixel
    fread(&Info->bitspp, sizeof(Info->bitspp), 1, FilePtr);

    //reading compression type
    fread(&Info->compress_type, sizeof(Info->compress_type), 1, FilePtr);

    //reading image size
    fread(&Info->bmp_bytesz, sizeof(Info->bmp_bytesz), 1, FilePtr);

    //reading horizontal and vertical resolution
    fread(&Info->hres, sizeof(Info->hres), 1, FilePtr);
    fread(&Info->vres, sizeof(Info->vres), 1, FilePtr);

    //reading number of colours
    fread(&Info->ncolors, sizeof(Info->ncolors), 1, FilePtr);

    //reading number of important colours
    fread(&Info->nimpcolors, sizeof(Info->nimpcolors), 1, FilePtr);
}


// should be static in real life, but would give a compiling error in the
// unchanged code because this function is not yet used
static void WriteHdr(
            FILE* FilePtr, BMP_MAGIC_t* Magic, BMP_FILE_t* File,
            BMP_INFO_t* Info)
/*
 * description: write the header of a bmp File, where the data comes from the
 * provided parameters
 *
 * parameters:
 *         FilePtr: file, opened for writing
 *         Magic:   input-parameter with a BMP_MAGIC_t structure
 *         File:    input-parameter with a BMP_FILE_t structure
 *         Info:    input-parameter with a BMP_INFO_t structure
 *
 */
{
    //if any of the pointers are NULL we should exit the function
    if(FilePtr == NULL || Magic == NULL || File == NULL || Info == NULL)
    {
        return;
    }

    //reseting the file writing pointer to the beginning of the file
    fseek(FilePtr, 0, SEEK_SET);

    //============== Magic ==============

    //writing the first two bytes of the header
    fwrite(&Magic->magic, sizeof(Magic->magic), 1, FilePtr);


    //============== File ==============

    //writing file size
    fwrite(&File->filesz, sizeof(File->filesz), 1, FilePtr);

    //writing creators
    fwrite(&File->creator1, sizeof(File->creator1), 1, FilePtr);
    fwrite(&File->creator2, sizeof(File->creator2), 1, FilePtr);

    //writing bmp offset
    fwrite(&File->bmp_offset, sizeof(File->bmp_offset), 1, FilePtr);


    //============== Info ==============

    //writing header size
    fwrite(&Info->header_sz, sizeof(Info->header_sz), 1, FilePtr);

    //writing height & width
    fwrite(&Info->width, sizeof(Info->width), 1, FilePtr);
    fwrite(&Info->height, sizeof(Info->height), 1, FilePtr);

    //writing number of colour planes
    fwrite(&Info->nplanes, sizeof(Info->nplanes), 1, FilePtr);

    //writing bits per pixel
    fwrite(&Info->bitspp, sizeof(Info->bitspp), 1, FilePtr);

    //writing compression type
    fwrite(&Info->compress_type, sizeof(Info->compress_type), 1, FilePtr);

    //writing image size
    fwrite(&Info->bmp_bytesz, sizeof(Info->bmp_bytesz), 1, FilePtr);

    //writing horizontal and vertical resolution
    fwrite(&Info->hres, sizeof(Info->hres), 1, FilePtr);
    fwrite(&Info->vres, sizeof(Info->vres), 1, FilePtr);

    //writing number of colours
    fwrite(&Info->ncolors, sizeof(Info->ncolors), 1, FilePtr);

    //writing number of important colours
    fwrite(&Info->nimpcolors, sizeof(Info->nimpcolors), 1, FilePtr);
}


extern void SteganoMultiplex(const char* File0, const char* File1)
{
    FILE* FilePtr0 = NULL;
    FILE* FilePtr1 = NULL;
    FILE* FilePtr2 = NULL;
    char buf[MAX_FILENAME];

    for (int NrBits = 0; NrBits <= 8; NrBits++)
    {
        // NrBits: number of bits for the hidden image
        sprintf(buf, "mux_%s_%s_%d.bmp", File0, File1, NrBits);
        FilePtr0 = fopen(File0, "rb");
        FilePtr1 = fopen(File1, "rb");
        FilePtr2 = fopen(buf, "wb");

        //header structs for file 0
        BMP_MAGIC_t magicFile0;
        BMP_FILE_t fileFile0;
        BMP_INFO_t infoFile0;
        //header structs for file 1
        BMP_MAGIC_t magicFile1;
        BMP_FILE_t fileFile1;
        BMP_INFO_t infoFile1;

        //reading file headers
        ReadHdr(FilePtr0, &magicFile0, &fileFile0, &infoFile0);
        ReadHdr(FilePtr1, &magicFile1, &fileFile1, &infoFile1);
        
        //assigning new values to creator1, creator2 and nimpcoors variables
        fileFile0.creator1 = infoFile1.width;
        fileFile0.creator2 = infoFile1.height;
        infoFile0.nimpcolors = NrBits;

        //writing the header for the new file
        WriteHdr(FilePtr2, &magicFile0, &fileFile0, &infoFile0);

        //filling buffer of all pixel data from file 0
        uint8_t file0Data[fileFile0.filesz-HEADERSIZE];
        uint32_t file0DateSize = fread(file0Data, 1, fileFile0.filesz-HEADERSIZE, FilePtr0);

        //filling buffer of all pixel data from file 1
        uint8_t file1Data[fileFile1.filesz-HEADERSIZE];
        fread(file1Data, sizeof(uint8_t), fileFile1.filesz-HEADERSIZE, FilePtr1);

        //making buffer to add to the new file
        uint8_t file2Data[file0DateSize];

        //steganoing the hell out of the data
        for(uint32_t i = 0; i < file0DateSize; i++)
        {
            uint8_t file0PixelSubstring = SteganoGetSubstring(file0Data[i], NrBits, 8 - NrBits, NrBits);
            uint8_t file1PixelSubstring = SteganoGetSubstring(file1Data[i], 8 - NrBits, NrBits, 0);
            //add the newly aquired data to the data buffer for the new file
            file2Data[i] = file0PixelSubstring | file1PixelSubstring;
        }

        //actually writing the data
        fwrite(file2Data, sizeof(uint8_t), file0DateSize, FilePtr2);
        fflush(FilePtr2);

        fclose(FilePtr0);
        fclose(FilePtr1);
        fclose(FilePtr2);
    }
}


extern void SteganoMultiplexText(const char* File0, const char* File1)
{
    FILE* FilePtr0 = NULL;
    FILE* FilePtr1 = NULL;
    FILE* FilePtr2 = NULL;
    char buf[MAX_FILENAME];

    sprintf(buf, "mux_%s_%s.bmp", File0, File1);
    FilePtr0 = fopen(File0, "rb");
    FilePtr1 = fopen(File1, "rb");
    FilePtr2 = fopen(buf, "wb");

    


    fclose(FilePtr0);
    fclose(FilePtr1);
    fclose(FilePtr2);
}


extern void
SteganoDemultiplex(const char* File0, const char* File1, const char* File2)
{
    FILE* FilePtr0 = NULL;
    FILE* FilePtr1 = NULL;
    FILE* FilePtr2 = NULL;

    FilePtr0 = fopen(File0, "rb");
    FilePtr1 = fopen(File1, "wb");
    FilePtr2 = fopen(File2, "wb");

    //Header values of the input file
    BMP_MAGIC_t file0Magic;
    BMP_FILE_t file0File;
    BMP_INFO_t file0Info;

    //reading input file header
    ReadHdr(FilePtr0, &file0Magic, &file0File, &file0Info);

    //saving nr of bits multiplexed
    uint8_t nrOfBits = file0Info.nimpcolors;

    //saving sizes for second output file, to be used later
    uint16_t file2Width = file0File.creator1;
    uint16_t file2Height = file0File.creator2;

    //reseting multiplex values
    file0File.creator1 = 0;
    file0File.creator2 = 0;
    file0Info.nimpcolors = 0;

    //writing header of output file 1
    WriteHdr(FilePtr1, &file0Magic, &file0File, &file0Info);

    //setting the width & height correctly for second file
    file0Info.width = file2Width;
    file0Info.height = file2Height;

    //writing header of output file 2
    WriteHdr(FilePtr2, &file0Magic, &file0File, &file0Info);

    //reading all the data from input file into a data buffer
    uint8_t file0Data[file0File.filesz - HEADERSIZE];
    uint32_t file0DataSize = fread(file0Data, 1, file0File.filesz-HEADERSIZE, FilePtr0);

    //making data buffers for the 2 output files
    uint8_t file1Data[file0DataSize];
    uint8_t file2Data[file0DataSize];

    for(uint32_t i = 0; i < file0DataSize; i++)
    {
        //output pixel 1
        file1Data[i] = file0Data[i];
        file1Data[i] >>= nrOfBits;
        file1Data[i] <<= nrOfBits;

        //output pixel 2
        file2Data[i] = file0Data[i];
        file2Data[i] <<= 8-nrOfBits;
    }

    //writing data buffers to their respective output files
    fwrite(file1Data, 1, file0DataSize, FilePtr1);
    fflush(FilePtr1);
    fwrite(file2Data, 1, file0DataSize, FilePtr2);
    fflush(FilePtr2);

    fclose(FilePtr0);
    fclose(FilePtr1);
    fclose(FilePtr2);
}


extern void
SteganoDemultiplexText(const char* File0, const char* File1, const char* File2)
{
    FILE* FilePtr0 = NULL;
    FILE* FilePtr1 = NULL;
    FILE* FilePtr2 = NULL;

    FilePtr0 = fopen(File0, "rb"); /* binair lezen */
    FilePtr1 = fopen(File1, "wb"); /* binair schrijven */
    FilePtr2 = fopen(File2, "wb"); /* binair schrijven */

    // to be implemented


    fclose(FilePtr0);
    fclose(FilePtr1);
    fclose(FilePtr2);
}
