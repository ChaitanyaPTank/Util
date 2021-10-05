/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

// variables for constant power panning
#define PI = 4.0 * atan(1.0);
#define PI_OVER_2 = PI / 2;
#define ROOT_2_OVER_2 = sqrt(2.0) * 0.5;

//==============================================================================
/**
*/
class UtilAudioProcessor : public juce::AudioProcessor
{
public:
	//==============================================================================
	UtilAudioProcessor();
	~UtilAudioProcessor() override;

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

	//==============================================================================
	juce::AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const juce::String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const juce::String getProgramName(int index) override;
	void changeProgramName(int index, const juce::String& newName) override;

	//==============================================================================
	void getStateInformation(juce::MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

private:

	//float prevGainL = 0.05f; // storing previous gain value left channel
	//float prevGainR = 0.05f; // storing previous gain value left channel

	float prevGain = 0.05f;
	float prevPan = 0.05f;

	// Param tree implementation
	juce::AudioProcessorValueTreeState parameters; // parameter tree
	std::atomic<float>* mGain; // gain param
	std::atomic<float>* mPan; // panning param

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UtilAudioProcessor)
};
