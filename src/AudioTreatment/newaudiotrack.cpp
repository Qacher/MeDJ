#include "newaudiotrack.h"
#include "audiodecoding.h"

#include "./MeDJ/src/lib/ffmpeg/libavutil/avconfig.h"



NewAudioTrack::NewAudioTrack(char *filename, char *outFilename)
{
    this->filename = filename;
    this->outFilename = outFilename;
    decoder = new audioDecoding();
}

NewAudioTrack::~NewAudioTrack()
{
    free(decoder);
    free(filename);
    free(outFilename);
    free(encoding);
}


char *NewAudioTrack::getFilename()
{
    return filename;
}

char *NewAudioTrack::getOutFilename()
{
    return outFilename;
}

char *NewAudioTrack::getEncoding()
{
    return encoding;
}

void NewAudioTrack::setFilename(char *fileName)
{
    this->filename = fileName;
}

void NewAudioTrack::setOutFilename(char *outFilename)
{
    this->outFilename = outFilename;
}

void NewAudioTrack::setGetEncoding(char *encodingName)
{
    this->encoding = encodingName;
}


void NewAudioTrack::decode()
{
    //NewAudioTrack create an easiest way to decode without multi definition

    decoder->decodeAudio(filename, outFilename);

}


