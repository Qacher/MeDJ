#ifndef AUDIODECODING_H
#define AUDIODECODING_H

#include <QProcess>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef WRAPPER_H_
#define WRAPPER_H_

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavutil/avutil.h"
}


#include <./libavutil/frame.h>
#include <./libavutil/mem.h>
#include <./libavcodec/avcodec.h>
#define AUDIO_INBUF_SIZE 20480
#define AUDIO_REFILL_THRESH 4096

#endif

#ifdef HAVE_AV_CONFIG_H
#undef HAVE_AV_CONFIG_H
#endif

#define INBUF_SIZE

class audioDecoding
{
protected:
    void decode(AVCodecContext *dec_ctx, AVPacket *pkt, AVFrame *frame,
                FILE *outfile);
public:
    audioDecoding();
    int decodeAudio(const char *filename, const char *outfilename);
};

#endif // AUDIODECODING_H
