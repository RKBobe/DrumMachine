# Standard CMake setup 
cmake_minimum_required(VERSION 3.22)
project(DrumMachine VERSION 1.0.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download JUCE using FetchContent
include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG 7.0.9
)

# Make JUCE available
FetchContent_MakeAvailable(JUCE)

# Enable JUCE's GUI features
juce_add_gui_app(DrumMachine
    PRODUCT_NAME "Drum Machine"
    VERSION "1.0.0"
    COMPANY_NAME "Treelight Innovations"
    COMPANY_WEBSITE "www.yourcompany.com"
    COMPANY_EMAIL "support@yourcompany.com"
    FORMATS Standalone
    PLUGIN_MANUFACTURER_CODE Ycom
    PLUGIN_CODE Drum
    BUNDLE_ID "com.yourcompany.DrumMachine"
)

# Generate JuceHeader.h
juce_generate_juce_header(DrumMachine)

# Add source files
target_sources(DrumMachine PRIVATE
    Source/Main.cpp
    Source/MainComponent.h
    Source/MainComponent.cpp
)

# Link required JUCE modules
target_compile_definitions(DrumMachine PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:DrumMachine,JUCE_PRODUCT_NAME>"
    JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:DrumMachine,JUCE_VERSION>"
)

target_link_libraries(DrumMachine PRIVATE
    juce::juce_audio_processors
    juce::juce_dsp
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)