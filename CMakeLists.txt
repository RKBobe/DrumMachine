# Standard CMake setup
cmake_minimum_required(VERSION 3.22)
project(DrumMachine VERSION 1.0.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the JUCE library using the path provided from the command line.
# This makes the JUCE CMake functions available.
add_subdirectory(${JUCE_SOURCE_DIR} ${CMAKE_BINARY_DIR}/JUCE)

# Use JUCE's function to create a GUI application target and
# declare which optional modules it needs.
juce_add_gui_app(DrumMachine
    REQUIRED_MODULES
        juce_audio_processors
        juce_dsp)

# Add your source files to the target
target_sources(DrumMachine PRIVATE
    Source/Main.cpp
    Source/MainComponent.h
    Source/MainComponent.cpp
)

# Link the required JUCE modules to the target (using lowercase juce::)
target_link_libraries(DrumMachine PRIVATE
    juce::juce_audio_processors
    juce::juce_dsp
)

# Apply JUCE's recommended compiler settings and optimizations (using lowercase juce::)
target_link_libraries(DrumMachine PRIVATE
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
)