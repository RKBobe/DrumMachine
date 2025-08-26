#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setFont (juce::Font (24.0f));
    g.setColour (juce::Colours::whitesmoke);
    g.drawText ("Drum Machine Goes Here!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
}