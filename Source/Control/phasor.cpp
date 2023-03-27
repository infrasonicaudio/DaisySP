#include <math.h>
#include "phasor.h"
#include "dsp.h"

using namespace daisysp;

void Phasor::SetFreq(float freq)
{
    freq_ = fmax(freq, 0.0f);
    inc_  = freq_ / sample_rate_;
}

float Phasor::Process()
{
    float out;
    out = phs_;
    phs_ += inc_;
    if(phs_ > 1.0f)
    {
        phs_ -= 1.0f;
    }
    return out;
}
