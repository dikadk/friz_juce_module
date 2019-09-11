/*
 * Copyright (c) 2019 Brett g Porter. 
 */

#include "friz_AnimatedValue.h"

friz::AnimatedValue::AnimatedValue(float startVal, float endVal)
        : fStartVal(startVal), fEndVal(endVal), fCurrentVal(startVal), fFrameCount(0), fCanceled(false) {

}

friz::AnimatedValue::~AnimatedValue() {

}

float friz::AnimatedValue::GetNextValue() {
    if (!fCanceled) {
        if (0 == fFrameCount++) {
            fCurrentVal = fStartVal;
        } else {
            fCurrentVal = this->GenerateNextValue();
        }
    }

    return fCurrentVal;
}

void friz::AnimatedValue::Cancel(bool moveToEndPosition) {
    fCanceled = true;
    this->DoCancel(moveToEndPosition);
}

void friz::AnimatedValue::DoCancel(bool moveToEndPosition) {
    if (moveToEndPosition) {
        fCurrentVal = fEndVal;
    }
}

friz::ToleranceValue::ToleranceValue(float startVal, float endVal, float tolerance) : AnimatedValue(startVal, endVal), fTolerance(tolerance){

}

bool friz::ToleranceValue::IsFinished() {
    return (std::fabs(fCurrentVal - fEndVal) < fTolerance) || fCanceled;
}

friz::TimedValue::TimedValue(float startVal, float endVal, int duration)
        : AnimatedValue(startVal, endVal), fDuration(duration)  {

}

bool friz::TimedValue::IsFinished() {
    return fFrameCount >= fDuration;
}
