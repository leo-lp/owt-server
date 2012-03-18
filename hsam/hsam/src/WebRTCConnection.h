/*
 * WebRTCConnection.h
 *
 *  Created on: Mar 14, 2012
 *      Author: pedro
 */

#ifndef WEBRTCCONNECTION_H_
#define WEBRTCCONNECTION_H_

#include "NiceConnection.h"
#include "Srtpchannel.h"
#include "sdpinfo.h"
#include "mediadefinitions.h"
#include <string>

class WebRTCConnection: public MediaReceiver, public NiceReceiver{
public:
	WebRTCConnection();
	virtual ~WebRTCConnection();
	bool init();
	bool setRemoteSDP(const std::string &sdp);
	const char* getLocalSDP();
	int receiveAudioData(char* buf, int len);
	int receiveVideoData(char* buf, int len);
	void setAudioReceiver(MediaReceiver *receiv);
	void setVideoReceiver(MediaReceiver *receiv);
	int receiveNiceData(char* buf,int len, NiceConnection *nice);


private:
	SDPInfo remote_sdp;
	SDPInfo local_sdp;
	NiceConnection *audio_nice;
	NiceConnection *video_nice;
	SrtpChannel *audio_srtp;
	SrtpChannel *video_srtp;

	MediaReceiver *audio_receiver;
	MediaReceiver *video_receiver;

};

#endif /* WEBRTCCONNECTION_H_ */
