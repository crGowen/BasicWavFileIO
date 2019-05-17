#include <string>

namespace wavio
{
	class WavHeader
	{
	public:
		char groupID[4]; // always "RIFF"
		unsigned int fileBytes; // size of file in minus 8 bytes
		char typeRIFF[4]; // always "WAVE"

		char fmtID[4]; // ALWAYS "fmt " for FormatChunk
		unsigned int fmtSize; //investigate here, sometimes it's a little different
		unsigned short formatType;
		unsigned short nChannels;
		unsigned int sampleFreq;
		unsigned int estBytesFreq;
		unsigned short sampleFrameSize;
		unsigned short bitsPerSample; // padded by 2 bytes to the 24th byte in Format chunk (total size of chunk is 28bytes).

		char chunkID[4]; // ALWAYS "data" for FormatChunk
		unsigned int chunkSize;
	}; // size of should return 48bytes

	// KEEP IT SIMPLE, it needs to be pure P.O.D.
	class WavFileData
	{
	public:
		WavHeader head;
		char* byteDataArray; // for 8 bit data
		short* shortDataArray; // for 16bit data
		// 32bit file types not supported

		__declspec(dllexport) void ConstructFromFinstream(std::string filepath);

		__declspec(dllexport) void CrushBits();

		__declspec(dllexport) void CrushBits(unsigned short killBits);

		static __declspec(dllexport) void OutputWavObjToFile(WavFileData &wavfile, std::string filepath);

		__declspec(dllexport) void PrintInfo();

		__declspec(dllexport) void DestroyDynamicVars();

		__declspec(dllexport) void SilenceChannel(char channelToSilence);

	};
}