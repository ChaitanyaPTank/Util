/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
UtilAudioProcessorEditor::UtilAudioProcessorEditor(UtilAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(300, 300);
	mGainSlider.setBounds(100, 100, 100, 100);
	mGainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	mGainSlider.setRange(0.0, 1.0, 0.01);
	mGainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 360, 0);
	mGainSlider.setTextValueSuffix("Gain");
	mGainSlider.setValue(1.0);

	addAndMakeVisible(&mGainSlider);
	mGainSlider.addListener(this);
}

UtilAudioProcessorEditor::~UtilAudioProcessorEditor()
{
}

//==============================================================================
void UtilAudioProcessorEditor::paint(juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

	g.setColour(juce::Colours::white);
	g.setFont(15.0f);
	//g.drawFittedText("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void UtilAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..
}

void UtilAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
	float gainVal = mGainSlider.getValue();
	audioProcessor.setParameter(0, gainVal);
	DBG(processor.getParameter(0));
}
