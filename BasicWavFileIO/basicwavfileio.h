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
		unsigned short bitsPerSample;

		char chunkID[4]; // ALWAYS "data" for FormatChunk
		unsigned int chunkSize;
	}; // sizeof(WavHeader) should return 44bytes

	// KEEP IT SIMPLE, it needs to be pure P.O.D.
	class WavFileData
	{
	public:
		WavHeader head;
		unsigned short* shortDataArray; // for 16bit data
		// 32bit file types not supported

		__declspec(dllexport) void ConstructFromFinstream(std::string filepath);

		static __declspec(dllexport) void OutputWavObjToFile(WavFileData &wavfile, std::string filepath);

		__declspec(dllexport) void PrintInfo();

		__declspec(dllexport) void DestroyDynamicVars();

		__declspec(dllexport) void SilenceChannel(char channelToSilence);

	};
}