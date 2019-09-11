/*
 * Copyright (c) 2019 Brett g Porter. 
 */
/** BEGIN_JUCE_MODULE_DECLARATION

    ID:             friz
    vendor:         Brett g Porter
    version:        0.0.1
    name:           friz
    description:    A generic UI animation controller for JUCE projects.
    website:        https://github.com/bgporter/animator
    license:        MIT (https://github.com/bgporter/animator/blob/master/LICENSE)

    dependencies:   juce_gui_basics

    END_JUCE_MODULE_DECLARATION
*/

#pragma once

#include "../friz.h"

namespace friz {

/**
 * @class AmimatedValue
 * @brief Abstract base class for objects that can generate a useful series
 *        of values to drive UI animations. 
 */

    class AnimatedValue {
    public:
        /**
         * Base class init for the animated value classes.
         * @param startVal  Initial Value
         * @param endVal    Target/end value.
         * @param tolerance Toleerance for when we've reached the target value.
         */
        AnimatedValue(float startVal, float endVal);

        virtual ~AnimatedValue();

        /**
         * Derived classes should do whatever is needed to generate and
         * return the next value.
         * @return        next value (or last value if we're finished)
         */
        float GetNextValue();

        /**
         * Have we reached the end of this animation sequence? By default,
         * we're done when the current value is within `fTolerance` of the endValue
         * (or if we've been canceled...)
         * @return [description]
         */
        virtual bool IsFinished() = 0;


        void Cancel(bool moveToEndPosition);


    private:

        /**
         * Implemented in base classes to generate the next value in the sequence.
         * @return      next value.
         */
        virtual float GenerateNextValue() = 0;


        /**
         * Override in derived classes to perform any unusual cancellation logic.
         */
        virtual void DoCancel(bool moveToEndPosition);


    protected:
        float fStartVal;
        float fEndVal;
        float fCurrentVal;

        int fFrameCount;
        bool fCanceled;
    };

    class ToleranceValue : public AnimatedValue {
    public:
        ToleranceValue(float startVal, float endVal, float tolerance);

        bool IsFinished() override;

    protected:
        float fTolerance;
    };

    class TimedValue : public AnimatedValue {
    public:
        TimedValue(float startVal, float endVal, int duration);

        bool IsFinished() override;

    protected:
        int fDuration;
    };

} // namespace friz
