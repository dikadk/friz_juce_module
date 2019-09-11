/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2017 - ROLI Ltd.

   JUCE is an open source library subject to commercial or open-source
   licensing.

   By using JUCE, you agree to the terms of both the JUCE 5 End-User License
   Agreement and JUCE 5 Privacy Policy (both updated and effective as of the
   27th April 2017).

   End User License Agreement: www.juce.com/juce-5-licence
   Privacy Policy: www.juce.com/juce-5-privacy-policy

   Or: You may also use this code under the terms of the GPL v3 (see
   www.gnu.org/licenses).

   JUCE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
   EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
   DISCLAIMED.

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this module, and is read by
 the Projucer to automatically generate project code that uses it.
 For details about the syntax and how to create or use a module, see the
 JUCE Module Format.txt file.


 BEGIN_JUCE_MODULE_DECLARATION

 ID:             friz
 vendor:         Brett g Porter
 version:        0.0.1
 name:           friz
 description:    A generic UI animation controller for JUCE projects.
 website:        https://github.com/bgporter/animator
 license:        MIT (https://github.com/bgporter/animator/blob/master/LICENSE)

  dependencies:   juce_gui_basics
  OSXFrameworks:    WebKit

 END_JUCE_MODULE_DECLARATION

*******************************************************************************/


#pragma once
#define JUCE_GUI_BASICS_H_INCLUDED

#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_events/juce_events.h>

//==============================================================================
#include "animator/friz_AnimatedValue.h"
#include "animator/friz_Animation.h"
#include "animator/friz_Animator.h"
#include "animator/friz_Constant.h"
#include "value/friz_Easing.h"
#include "value/friz_Linear.h"
#include "value/friz_Sequence.h"
#include "value/friz_Sinusoid.h"
#include "value/friz_Spring.h"
