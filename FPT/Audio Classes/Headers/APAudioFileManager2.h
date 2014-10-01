//
//  APAudioFileManager2.h
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 10/1/14.
//
//

#ifndef __FPTAnalyzer__APAudioFileManager2__
#define __FPTAnalyzer__APAudioFileManager2__

#include "APAudioFile.h"
#include <vector>

class APAudioFileManager
{
public:
    APAudioFileManager();
    ~APAudioFileManager();
    
    void loadFile(File fileToLoad);
    APAudioFile getFile(String name);
    APAudioFile getFile(int index);
    void clearManager();
    int getNumberOfFiles();
    
private:
    
    std::vector<APAudioFile> _audioFiles;
    AudioFormatManager formatManager;
    int _filesLoaded = 0;
};

#endif /* defined(__FPTAnalyzer__APAudioFileManager2__) */
