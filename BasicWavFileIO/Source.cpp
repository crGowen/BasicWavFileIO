#include "stdafx.h"
#include <string>

namespace wavio
{
	class WavHeader
	{
	public:
		std::string groupID;
		unsigned int length;
		std::string typeRFF;
	};

	class FormatChunk
	{
	public:
		std::string chunkID;
		unsigned int chunkSize;
		unsigned short formatType;
		unsigned short nChannels;
		unsigned int samplesFreq;
		unsigned int estBytesFreq;
		unsigned short sampleFrameSize;
		unsigned int bitsPerSample;
	};

	class DataChunk
	{
	public:
		std::string chunkID;
		unsigned int chunkSize;
		unsigned char* uDataArray; //unsigned data / char 8bit
		short* sDataArray; //signed data / short 16bit
	};

	// KEEP IT SIMPLE, it needs to be pure P.O.D.
	class WavFileData
	{
	public:
		WavHeader head;
		FormatChunk fmt;
		DataChunk data;
		std::string fileName;

		static void ConstructFromFinstream(WavFileData wavfile, const char* filepath)
		{
			//stub
		}
	};
}

