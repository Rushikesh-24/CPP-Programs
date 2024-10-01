#include <iostream>
using namespace std;

class Media {
public:
    virtual void play() {
        cout << "Playing media." << endl;
    }
};

class Video : public Media {
public:
    void play() {
        cout << "Playing video." << endl;
        system("open test.mov");
    }
};

class Audio : public Media {
public:
    void play() {
        cout << "Playing audio." << endl;
        system("afplay test.wav");
    }
};

int main() {
    Media* video_instance = new Video();
    Media* audio_instance = new Audio();

    audio_instance->play();
    video_instance->play();

    delete video_instance;
    delete audio_instance;

    return 0;
}
