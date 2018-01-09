#pragma once


#include "DSPEffect.hpp"
#include "engine.hpp"
#include "DSPMath.hpp"

namespace rack {

    struct LadderFilter : DSPEffect {

        static const int OVERSAMPLE = 8;       // factor of internal oversampling
        static constexpr float NOISE_GAIN = 10e-10f; // internal noise gain used for self-oscillation

        enum FXChannel {
            LOWPASS
        };

    private:
        float f, p, q;
        float b0, b1, b2, b3, b4, b5;
        float t1, t2;
        float freqExp, freqHz, frequency, resExp, resonance, drive;
        float in, lpOut;

        OverSampler<OVERSAMPLE, 1> os;
        Noise noise;

        void updateResExp();

    public:
        LadderFilter();

        void invalidate() override;

        void process() override;

        float getFrequency() const;
        void setFrequency(float frequency);
        float getResonance() const;
        void setResonance(float resonance);
        float getDrive() const;
        void setDrive(float drive);
        float getFreqHz() const;

        void setIn(float in);
        float getLpOut();
    };
}