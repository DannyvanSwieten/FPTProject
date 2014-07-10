//
//  APAudioFileManagerCPP.h
//  APAudioEngine
//
//  Created by Danny van Swieten on 07-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __APAudioEngine__APAudioFileManagerCPP__
#define __APAudioEngine__APAudioFileManagerCPP__

#include "APAudioProcessorCPP.h"

struct AudioFile
{
    SampleBuffer    leftData;
    SampleBuffer    rightData;
    UInt64          numFrames;
    bool            isStereo;
    std::string     name;
};

class APAudioFileManagerCPP
{
public:
    
    APAudioFileManagerCPP();
    OSStatus getAvailableSoundFileLibraries();
    OSStatus getFileListForSoundFileLibrary(NSString* libraryName);
    OSStatus loadFile(NSString* fileName, NSString* libraryName);
    OSStatus setupMonoStreamFormat();
    OSStatus setupStereoStreamFormat();
    
    AudioFile* findFile(std::string fileName);
    
private:
    
    NSString*               soundFileLibrariesPathName;
    NSArray*                availableSoundFileLibraries;
    NSMutableArray*         soundFileLibraries;
    NSMutableArray*         audioFileList;

    AudioStreamBasicDescription     stereoStreamDescription;

    AudioStreamBasicDescription     monoStreamDescription;
    
    std::vector<AudioFile>               audioFiles;
};

#endif /* defined(__APAudioEngine__APAudioFileManagerCPP__) */
