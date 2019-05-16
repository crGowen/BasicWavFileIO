#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

#include "basicwavfileio.h"

namespace wavio
{
	void WavFileData::ConstructFromFinstream(std::string filepath)
		{
			std::ifstream finstream;
			finstream.open(filepath, std::ios::binary);
			finstream.read((char*)&this->head, sizeof(WavHeader));

			finstream.seekg(sizeof(WavHeader), std::ios::beg);
			switch (this->head.bitsPerSample)
			{
			case 8:
				this->byteDataArray = new char[this->head.chunkSize];
				finstream.read((char*)&this->byteDataArray[0], this->head.chunkSize);
				break;
			case 16:
				this->shortDataArray = new short[this->head.chunkSize / 2];
				finstream.read((char*)&this->shortDataArray[0], this->head.chunkSize);
				break;
			case 32:
				this->floatDataArray = new float[this->head.chunkSize / 4];
				finstream.read((char*)&this->floatDataArray[0], this->head.chunkSize);
				break;
			default:
				//throw exception
				std::cout << "EXCEPTION!";
				break;
			}
			
			finstream.close();
		}

	void WavFileData::OutputWavObjToFile(WavFileData &wavfile, std::string filepath)
	{
		std::ofstream foutstream;
		foutstream.open(filepath, std::ios::binary);
		foutstream.write((char*)&wavfile.head, sizeof(WavHeader));
		switch (wavfile.head.bitsPerSample)
		{
		case 8:
			foutstream.write((char*)&wavfile.byteDataArray[0], wavfile.head.chunkSize);
			break;
		case 16:
			foutstream.write((char*)&wavfile.shortDataArray[0], wavfile.head.chunkSize);
			break;
		case 32:
			foutstream.write((char*)&wavfile.floatDataArray[0], wavfile.head.chunkSize);
			break;
		default:
			//throw exception
			std::cout << "exceptioN!";
			break;
		}
		foutstream.close();
	}

	void WavFileData::PrintInfo()
	{
		std::cout << "Group ID: " << this->head.groupID[0] << this->head.groupID[1] << this->head.groupID[2] << this->head.groupID[3] << std::endl
			<< "File Bytes ( -8): " << this->head.fileBytes << std::endl
			<< "Type RIFF: " << this->head.typeRIFF[0] << this->head.typeRIFF[1] << this->head.typeRIFF[2] << this->head.typeRIFF[3] << std::endl << std::endl

			<< "Format ID: " << this->head.fmtID[0] << this->head.fmtID[1] << this->head.fmtID[2] << this->head.fmtID[3] << std::endl
			<< "Format Size: " << this->head.fmtSize << std::endl
			<< "Format Type: " << this->head.formatType << std::endl
			<< "Number of Channels: " << this->head.nChannels << std::endl
			<< "Sample Freq: " << this->head.sampleFreq << std::endl
			<< "Est. Bytes Freq: " << this->head.estBytesFreq << std::endl
			<< "Sample Frame Size: " << this->head.sampleFrameSize << std::endl
			<< "Bits Per Sample: " << this->head.bitsPerSample << std::endl << std::endl

			<< "Chunk ID: " << this->head.chunkID[0] << this->head.chunkID[1] << this->head.chunkID[2] << this->head.chunkID[3] << std::endl
			<< "Chunk Size (Bytes): " << this->head.chunkSize;
	}

	void WavFileData::DestroyDynamicVars()
	{
		if (this->head.chunkSize > 0)
		{
			switch (this->head.bitsPerSample)
			{
			case 8:
				delete[] byteDataArray;
				break;
			case 16:
				delete[] shortDataArray;
				break;
			case 32:
				delete[] floatDataArray;
				break;
			default:
				//throw exception
				break;
			}
		}
	}
}

