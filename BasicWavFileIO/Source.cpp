#include "stdafx.h"
#include <string>

namespace wavio
{
	class WavHeader
	{
	public:
		char groupID[4]; // always "RIFF"
		unsigned int fileBytes; // size of file in minus 8 bytes
		char typeRIFF[4]; // always "WAVE"
	}; //sizeof should return 12 bytes

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
		unsigned int bitsPerSample; // padded by 2 bytes to the 24th byte in Format chunk (total size of chunk is 28bytes).
	}; // size of should return 28bytes

	class DataChunk
	{
	public:
		char chunkID[4]; // ALWAYS "data" for FormatChunk
		unsigned int chunkSize;
		unsigned char* byteDataArray; //unsigned data / char 8bit (perhaps with 16bit data, skip all even bytes to get the 2 least signifs from 16 bit data chunks)
		// padding isn't an issue here, because when writing the data chunk we'll write the first two vars first, then since the byteDataArray is dynamic memory, write it 1 byte at a time
		// so we don't write DataChunk to a file, we write chunkID, chunkSize, then byteDataArray (however big it will be)
	}; // sizeof should return 16 bytes (8 of which are the just the 64b pointer).

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

