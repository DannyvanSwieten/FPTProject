/*
  ==============================================================================

    FPTMidiDatabase.cpp
    Created: 3 Jul 2014 4:16:15pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#include "FPTMidiDatabase.h"

FPTMidiDatabase::FPTMidiDatabase()
{
    loader = new FPTMidiLoader(16, 8);
}

FPTMidiDatabase::~FPTMidiDatabase()
{
    delete loader;
}

void FPTMidiDatabase::load()
{
    FileChooser loadFile("Select midi data file",
                         File::getSpecialLocation(File::userHomeDirectory),
                         "*.txt");
    if(loadFile.browseForFileToOpen())
    {
        database.emplace_back(loader->loadData(loadFile.getResult()));
    }
}

void FPTMidiDatabase::loadComposition()
{
    FileChooser loadFile("Select midi data file",
                         File::getSpecialLocation(File::userHomeDirectory),
                         "*.txt");
    if(loadFile.browseForFileToOpen())
    {
        composition = loader->loadData(loadFile.getResult());
    }
}