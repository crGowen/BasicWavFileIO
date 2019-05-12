#include "stdafx.h"
#include <string>

namespace wavio
{
	class WavHeader
	{
	public:
		char groupID[4]; // always "RIFF"
		unsigned int length;
		char typeRIFF[4]; // always "WAVE"
	};

	class FormatChunk
	{
	public:
		char chunkID[4]; // ALWAYS "fmt " for FormatChunk
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
		char chunkID[4]; // ALWAYS "data" for FormatChunk
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

		static void ConstructFromFinstream(WavFileData wavfile, const char* filepath)
		{
			//stub
		}
	};
}

