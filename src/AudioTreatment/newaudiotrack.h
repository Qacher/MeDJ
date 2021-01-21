#ifndef NEWAUDIOTRACK_H
#define NEWAUDIOTRACK_H

#include "audiodecoding.h"

class NewAudioTrack
{
private:
    char *filename;
    char *outFilename;
    char *encoding;
    audioDecoding *decoder ;

public:
    NewAudioTrack(char *filename, char *outFilename);

    virtual ~NewAudioTrack();

    char *getFilename();
    char *getOutFilename();
    char *getEncoding();

    void setFilename(char* filename);
    void setOutFilename(char* outFilename);
    void setGetEncoding(char* encodingName);

    void decode();

};

#endif // NEWAUDIOTRACK_H
