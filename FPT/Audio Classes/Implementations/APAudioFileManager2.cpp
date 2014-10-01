//
//  APAudioFileManager2.cpp
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 10/1/14.
//
//

#include "APAudioFileManager2.h"

APAudioFileManager::APAudioFileManager()
{
    formatManager.registerBasicFormats();
}

APAudioFileManager::~APAudioFileManager()
{

}

void APAudioFileManager::loadFile(File fileToLoad)
{
    AudioFormatReader* formatReader = formatManager.createReaderFor(fileToLoad);
    
    int numChannels = formatReader->numChannels;
    int numSamples = formatReader->lengthInSamples;
    
    APAudioFile file;
    AudioSampleBuffer buffer;
    buffer.setSize(numChannels, numSamples);
    
    formatReader->read(&buffer, 0, numSamples, 0, true, true);
    file.setAudio(buffer);
    file.setFileName(fileToLoad.getFileName());
    file.setNumChannels(numChannels);
    file.setNumSamples(numSamples);
    
    _audioFiles.emplace_back(file);
    _filesLoaded++;
    
    delete formatReader;
}

APAudioFile APAudioFileManager::getFile(juce::String name)
{
    APAudioFile audioFile;
    for(auto file: _audioFiles)
    {
        if (file.getName() == name)
            audioFile = file;
    }

    return audioFile;
}

APAudioFile APAudioFileManager::getFile(int index)
{
    return _audioFiles[index];
}

int APAudioFileManager::getNumberOfFiles()
{
    return _filesLoaded;
}

void APAudioFileManager::clearManager()
{
    _audioFiles.clear();
}

