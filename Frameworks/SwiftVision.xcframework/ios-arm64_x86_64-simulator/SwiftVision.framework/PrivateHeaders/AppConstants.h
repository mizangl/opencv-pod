//
//  AppConstants.h
//  Camera-oxilight
//
//  Created by Lucy Cheng on 2019-06-19.
//  Copyright © 2019 Oxilight. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum testType {
    oref,
    bref,
    wref,
    tref,
    reference,
    dtpi,
    bacteria,
    water,
    thermography,
    bacteria_live,
    callus
} testType;

// Bluetooth Constants

extern NSString *const oxilightID;
extern NSString *const commandCharID;
extern NSString *const imageOutCharID;
extern NSString *const batteryID;

extern UInt8 const wakeLepton;
extern UInt8 const captureImage;
extern UInt8 const transmitStart;
extern UInt8 const transmitNext;
extern UInt8 const transmitReset;
extern UInt8 const killLepton;
extern UInt8 const flashGreen;
extern UInt8 const turnOffSinatra;

extern const char oxygenationFlash[];
extern const char bacteriaFlash[];
extern const char waterFlash[];

extern const int oxyFlashSize;
extern const int bactFlashSize;
extern const int waterFlashSize;

// User Default Keys
extern NSString *const didSaveImagesKey;
//      Slider Keys
extern NSString *const rgbPercentageSliderKey;
extern NSString *const totalOverlitPercentageSliderKey;
extern NSString *const blePacketCountSliderKey;
extern NSString *const erythemaThresholdSliderKey;
extern NSString *const highTemperatureThresholdSliderKey;
extern NSString *const lowTemperatureThresholdSliderKey;
extern NSString *const thermalAlignmentXThresholdSliderKey;
extern NSString *const thermalAlignmentYThresholdSliderKey;

//      Switch Keys
extern NSString *const overlitSwitchKey;
extern NSString *const noFlashSwitchKey;
extern NSString *const bleSwitchKey;
extern NSString *const manualCaptureSwitchKey;
extern NSString *const erythemaSwitchKey;
extern NSString *const ARSwitchKey;

extern NSString *const DeepTissueScreeningSwitchKey;
extern NSString *const thermalSwitchKey;
extern NSString *const debridementSwitchKey;
extern NSString *const bacteriaSwitchKey;
extern NSString *const callusSwitchKey;

extern NSString *const temperatureUnitKey;

extern NSString *const swiftWebsiteURL;
extern NSString *const swiftAppID;
extern NSString *const swiftAppGroupID;
extern NSString *const swiftSharedKeychain;

extern NSString *const sinatraScheme;
extern NSString *const tempPayloadDirectory;
