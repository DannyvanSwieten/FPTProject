//
//  APAudioSourceManager.cpp
//  FPT
//
//  Created by Danny van Swieten on 13-07-14.
//
//

#include "APAudioSourceManager.h"

APAudioSourceManager::APAudioSourceManager()
{
    formatManager.registerBasicFormats();
}

APAudioSourceManager::~APAudioSourceManager()
{
    
}

void APAudioSourceManager::loadFile()
{
    FileChooser loadFile("Select audio file",
                         File::getSpecialLocation(File::userHomeDirectory),
                         "*.wav");
    if(loadFile.browseForFileToOpen())
    {
        File audioFile = loadFile.getResult();
        formatReader = formatManager.createReaderFor(audioFile);
        AudioSampleBuffer buffer;
        formatReader->read(&buffer, 0, formatReader->lengthInSamples, 0, 1, 1);
        APAudioSoundDescription* desc = new APAudioSampleSound();
        desc->setData(buffer);
    }
}