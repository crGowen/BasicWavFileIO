#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

#include "basicwavfileio.h"

namespace wavio
{
	void WavFileData::ConstructFromFinstream(WavFileData &wavfile, std::string filepath)
		{
			std::ifstream finstream;
			finstream.open(filepath, std::ios::binary);
			finstream.read((char*)&wavfile.head, sizeof(WavHeader));

			finstream.seekg(sizeof(WavHeader), std::ios::beg);
			wavfile.byteDataArray = new char[wavfile.head.chunkSize];
			finstream.read((char*)&wavfile.byteDataArray[0], sizeof(wavfile.head.chunkSize));
			finstream.close();
		}

	void WavFileData::PrintInfo()
	{
		std::cout << "Group ID: " << this->head.groupID[0] << this->head.groupID[1] << this->head.groupID[2] << this->head.groupID[3] << std::endl
			<< "File Bytes ( -8): " << this->head.fileBytes << std::endl
			<< "Type RIFF: " << this->head.typeRIFF[0] << this->head.typeRIFF[1] << this->head.typeRIFF[2] << this->head.typeRIFF[3] << std::endl << std::endl
			<< "Format ID: " << this->head.fmtID[0] << this->head.fmtID[1] << this->head.fmtID[2] << this->head.fmtID[3] << std::endl
			<< "Format Type: " << this->head.formatType << std::endl
			<< "Number of Channels: " << this->head.nChannels << std::endl;
	}
}

