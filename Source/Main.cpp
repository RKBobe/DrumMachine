#include <JuceHeader.h>
#include "MainComponent.h"

//==============================================================================
class DrumMachineApplication  : public juce::JUCEApplication
{
public:
    DrumMachineApplication() {}
    const juce::String getApplicationName() override       { return juce::String (JucePlugin_Name); }
    const juce::String getApplicationVersion() override      { return juce::String (JucePlugin_VersionString); }
    bool moreThanOneInstanceAllowed() override             { return true; }

    void initialise (const juce::String& commandLine) override
    {
        mainWindow.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override
    {
        mainWindow = nullptr; // (deletes our window)
    }

private:
    class MainWindow    : public juce::DocumentWindow
    {
    public:
        MainWindow (juce::String name)  : DocumentWindow (name,
                                                          juce::Desktop::getInstance().getDefaultLookAndFeel()
                                                                     .findColour (juce::ResizableWindow::backgroundColourId),
                                                          DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new MainComponent(), true);
            setResizable (true, true);
            centreWithSize (getWidth(), getHeight());
            setVisible (true);
        }

        void closeButtonPressed() override
        {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

    std::unique_ptr<MainWindow> mainWindow;
};

// This macro generates the main() function that launches the app.
START_JUCE_APPLICATION (DrumMachineApplication)