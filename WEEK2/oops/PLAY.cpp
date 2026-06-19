

30 of 2,472
(no subject)
Inbox

Sanjeet Patel
Attachments
Jun 16, 2026, 8:29 PM (3 days ago)
to me


 2 Attachments
  •  Scanned by Gmail
#include <bits/stdc++.h>
using namespace std;

namespace music {
    class Playable {
    public:
        virtual void play() = 0;
        virtual ~Playable() {}
    };
}

namespace music {
namespace instrument {
    class Veena : public Playable {
    public:
        void play() override {
            cout<<"Playing Veena"<<endl;
        }
    };

}
}

namespace music {
namespace wind {

    class Saxophone : public Playable {
    public:
        void play() override {
            cout<<"Playing Saxophone"<<endl;
        }
    };

}
}

int main() {
    music::instrument::Veena veena;
    veena.play();

    music::wind::Saxophone saxophone;
    saxophone.play();

    music::Playable* p;

    p = &veena;
    p->play();

    p = &saxophone;
    p->play();

    return 0;
}