/*
* This code example shows how to use the Facade pattern in C++.
*
* In this example, the MultimediaPlayer class encapsulates the complex operations 
* involved in decoding and playing audio and video files, and provides a simple 
* and easy-to-use interface for the client code.
*/


#include <iostream>
#include <string>

// Subsystem for audio decoding
class AudioDecoder {
public:
    void decodeAudio(const std::string& filename) {
        std::cout << "Decoding audio from " << filename << std::endl;
    }
};

// Subsystem for video decoding
class VideoDecoder {
public:
    void decodeVideo(const std::string& filename) {
        std::cout << "Decoding video from " << filename << std::endl;
    }
};

// Facade for the multimedia player
class MultimediaPlayer {
public:
    MultimediaPlayer() {
        audioDecoder = new AudioDecoder();
        videoDecoder = new VideoDecoder();
    }

    void play(const std::string& audioFile, const std::string& videoFile) {
        audioDecoder->decodeAudio(audioFile);
        videoDecoder->decodeVideo(videoFile);
        std::cout << "Playing " << audioFile << " and " << videoFile << std::endl;
    }

private:
    AudioDecoder* audioDecoder;
    VideoDecoder* videoDecoder;
};

int main() {
    MultimediaPlayer* player = new MultimediaPlayer();
    player->play("song.mp3", "video.mp4");

    // Clean up resources
    delete player;

    return 0;
}