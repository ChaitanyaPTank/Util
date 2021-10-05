/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;


//==============================================================================
/**
*/
class UtilAudioProcessorEditor : public juce::AudioProcessorEditor,
	private juce::Slider::Listener
{
public:
	UtilAudioProcessorEditor(UtilAudioProcessor&, juce::AudioProcessorValueTreeState& vts);
	~UtilAudioProcessorEditor() override;

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;
private:
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	UtilAudioProcessor& audioProcessor;
	juce::AudioProcessorValueTreeState& valueTreeState;

	juce::Slider mGainSlider;
	std::unique_ptr<SliderAttachment> gainAttachment;

	juce::Slider mPanSlider;
	std::unique_ptr<SliderAttachment> panAttachment;

	// callback function
	void sliderValueChanged(juce::Slider* slider) override;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UtilAudioProcessorEditor)
};
