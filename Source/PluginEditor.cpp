/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
UtilAudioProcessorEditor::UtilAudioProcessorEditor(UtilAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
	: AudioProcessorEditor(&p), audioProcessor(p),
	valueTreeState(vts)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(300, 300);
	mGainSlider.setBounds(100, 0, 100, 100);
	mGainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	mGainSlider.setRange(0.0, 1.0, 0.01);
	mGainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 360, 0);
	mGainSlider.setTextValueSuffix("Gain");
	mGainSlider.setValue(1.0);

	mPanSlider.setBounds(50, 100, 200, 100);
	mPanSlider.setSliderStyle(juce::Slider::LinearHorizontal);
	mPanSlider.setRange(0.0, 1.0, 0.01);
	mPanSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 360, 0);
	mPanSlider.setTextValueSuffix("Pan");
	mPanSlider.setValue(0.5);

	addAndMakeVisible(&mGainSlider);
	addAndMakeVisible(&mPanSlider);
	mGainSlider.addListener(this);
	mPanSlider.addListener(this);

	gainAttachment = std::make_unique<SliderAttachment>(valueTreeState, "gain", mGainSlider);
	panAttachment = std::make_unique<SliderAttachment>(valueTreeState, "pan", mPanSlider);
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

}