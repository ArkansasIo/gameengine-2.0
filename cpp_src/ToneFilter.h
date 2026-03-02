#ifndef TONEFILTER_H
#define TONEFILTER_H

class ToneFilter {
public:
    ToneFilter();
    ~ToneFilter();

    void initialize();
    void update();
    
    void setTone(int r, int g, int b, int gray);
    void setToneDuration(int duration);
    
private:
    int _red, _green, _blue, _gray;
    int _duration;
};

#endif // TONEFILTER_H
