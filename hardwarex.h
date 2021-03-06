#ifndef HARDWAREX_H
#define HARDWAREX_H

#ifdef _WIN32
#ifdef HARDWAREX_EXPORTS
#define HARDWAREX_API __declspec(dllexport) 
#else
#define HARDWAREX_API __declspec(dllimport) 
#endif // HARDWAREX_EXPORTS
#else
#define HARDWAREX_API 
#endif // _WIN32

// Uncomment the following line to enable MAVLink in MATLAB (requires corresponding headers and needs Visual Studio 2013 (to set in mex -setup and mex -setup C++)...).
//#define ENABLE_MAVLINK_SUPPORT

//#ifndef DISABLE_THREADS_OSNET
//#define DISABLE_THREADS_OSNET
//#endif // DISABLE_THREADS_OSNET

// To prevent some warnings in MATLAB...
#ifndef DISABLE_HOKUYOTHREAD
#define DISABLE_HOKUYOTHREAD
#endif // DISABLE_HOKUYOTHREAD
#ifndef DISABLE_MAESTROTHREAD
#define DISABLE_MAESTROTHREAD
#endif // DISABLE_MAESTROTHREAD
#ifndef DISABLE_MAVLINKDEVICETHREAD
#define DISABLE_MAVLINKDEVICETHREAD
#endif // DISABLE_MAVLINKDEVICETHREAD
#ifndef DISABLE_MTTHREAD
#define DISABLE_MTTHREAD
#endif // DISABLE_MTTHREAD
#ifndef DISABLE_NMEADEVICETHREAD
#define DISABLE_NMEADEVICETHREAD
#endif // DISABLE_NMEADEVICETHREAD
#ifndef DISABLE_RAZORAHRSTHREAD
#define DISABLE_RAZORAHRSTHREAD
#endif // DISABLE_RAZORAHRSTHREAD
#ifndef DISABLE_RPLIDARTHREAD
#define DISABLE_RPLIDARTHREAD
#endif // DISABLE_RPLIDARTHREAD
#ifndef DISABLE_SSC32THREAD
#define DISABLE_SSC32THREAD
#endif // DISABLE_SSC32THREAD
#ifndef DISABLE_UBLOXTHREAD
#define DISABLE_UBLOXTHREAD
#endif // DISABLE_UBLOXTHREAD

// Not sure why sometimes MATLAB gives errors without that...
#ifdef ENABLE_MAVLINK_SUPPORT
#ifdef __GNUC__
#include <stdint.h>
#endif // __GNUC__
#endif // ENABLE_MAVLINK_SUPPORT

#include "OSCriticalSection.h"
#include "MT.h"
#include "RazorAHRS.h"
#include "NMEADevice.h"
#include "ublox.h"
#include "SSC32.h"
#include "Maestro.h"
#include "Hokuyo.h"
#include "RPLIDAR.h"
#ifdef ENABLE_MAVLINK_SUPPORT
#include "MAVLinkDevice.h"
#endif // ENABLE_MAVLINK_SUPPORT

#ifdef __cplusplus
extern "C" {
#endif

	HARDWAREX_API MT* CreateMTx(void);
	HARDWAREX_API void DestroyMTx(MT* pMT);
	HARDWAREX_API MTDATA* CreateMTDatax(void);
	HARDWAREX_API void DestroyMTDatax(MTDATA* pMTData);
	HARDWAREX_API int GetLatestDataMTx(MT* pMT, MTDATA* pMTData);
	HARDWAREX_API int ConnectMTx(MT* pMT, char* szCfgFilePath);
	HARDWAREX_API int DisconnectMTx(MT* pMT);
	HARDWAREX_API int GetLatestDataFromThreadMTx(MT* pMT, MTDATA* pMTData);
	HARDWAREX_API int StartThreadMTx(MT* pMT);
	HARDWAREX_API int StopThreadMTx(MT* pMT);

	HARDWAREX_API RAZORAHRS* CreateRazorAHRSx(void);
	HARDWAREX_API void DestroyRazorAHRSx(RAZORAHRS* pRazorAHRS);
	HARDWAREX_API RAZORAHRSDATA* CreateRazorAHRSDatax(void);
	HARDWAREX_API void DestroyRazorAHRSDatax(RAZORAHRSDATA* pRazorAHRSData);
	HARDWAREX_API int GetLatestDataRazorAHRSx(RAZORAHRS* pRazorAHRS, RAZORAHRSDATA* pRazorAHRSData);
	HARDWAREX_API int ConnectRazorAHRSx(RAZORAHRS* pRazorAHRS, char* szCfgFilePath);
	HARDWAREX_API int DisconnectRazorAHRSx(RAZORAHRS* pRazorAHRS);
	HARDWAREX_API int GetLatestDataFromThreadRazorAHRSx(RAZORAHRS* pRazorAHRS, RAZORAHRSDATA* pRazorAHRSData);
	HARDWAREX_API int StartThreadRazorAHRSx(RAZORAHRS* pRazorAHRS);
	HARDWAREX_API int StopThreadRazorAHRSx(RAZORAHRS* pRazorAHRS);

	HARDWAREX_API NMEADEVICE* CreateNMEADevicex(void);
	HARDWAREX_API void DestroyNMEADevicex(NMEADEVICE* pNMEADevice);
	HARDWAREX_API NMEADATA* CreateNMEADatax(void);
	HARDWAREX_API void DestroyNMEADatax(NMEADATA* pNMEAData);
	HARDWAREX_API int GetLatestDataNMEADevicex(NMEADEVICE* pNMEADevice, NMEADATA* pNMEAData);
	HARDWAREX_API int ConnectNMEADevicex(NMEADEVICE* pNMEADevice, char* szCfgFilePath);
	HARDWAREX_API int DisconnectNMEADevicex(NMEADEVICE* pNMEADevice);
	HARDWAREX_API int GetLatestDataFromThreadNMEADevicex(NMEADEVICE* pNMEADevice, NMEADATA* pNMEAData);
	HARDWAREX_API int StartThreadNMEADevicex(NMEADEVICE* pNMEADevice);
	HARDWAREX_API int StopThreadNMEADevicex(NMEADEVICE* pNMEADevice);

	HARDWAREX_API UBLOX* Createubloxx(void);
	HARDWAREX_API void Destroyubloxx(UBLOX* publox);
	HARDWAREX_API UBXDATA* CreateUBXDatax(void);
	HARDWAREX_API void DestroyUBXDatax(UBXDATA* pUBXData);
	HARDWAREX_API int GetNMEASentenceubloxx(UBLOX* publox, NMEADATA* pNMEAData);
	HARDWAREX_API int GetUBXPacketubloxx(UBLOX* publox, UBXDATA* pUBXData);
	HARDWAREX_API int Connectubloxx(UBLOX* publox, char* szCfgFilePath);
	HARDWAREX_API int Disconnectubloxx(UBLOX* publox);
	HARDWAREX_API int GetNMEASentenceFromThreadubloxx(UBLOX* publox, NMEADATA* pNMEAData);
	HARDWAREX_API int GetUBXPacketFromThreadubloxx(UBLOX* publox, UBXDATA* pUBXData);
	HARDWAREX_API int StartNMEAThreadubloxx(UBLOX* publox);
	HARDWAREX_API int StopNMEAThreadubloxx(UBLOX* publox);
	HARDWAREX_API int StartUBXThreadubloxx(UBLOX* publox);
	HARDWAREX_API int StopUBXThreadubloxx(UBLOX* publox);

	HARDWAREX_API SSC32* CreateSSC32x(void);
	HARDWAREX_API void DestroySSC32x(SSC32* pSSC32);
	HARDWAREX_API int SetPWMSSC32x(SSC32* pSSC32, int channel, int pw);
	HARDWAREX_API int SetAllPWMsSSC32x(SSC32* pSSC32, int* selectedchannels, int* pws);
	HARDWAREX_API int ConnectSSC32x(SSC32* pSSC32, char* szCfgFilePath);
	HARDWAREX_API int DisconnectSSC32x(SSC32* pSSC32);
	HARDWAREX_API int SetAllPWMsFromThreadSSC32x(SSC32* pSSC32, int* selectedchannels, int* pws);
	HARDWAREX_API int StartThreadSSC32x(SSC32* pSSC32);
	HARDWAREX_API int StopThreadSSC32x(SSC32* pSSC32);

	HARDWAREX_API MAESTRO* CreateMaestrox(void);
	HARDWAREX_API void DestroyMaestrox(MAESTRO* pMaestro);
	HARDWAREX_API int GetValueMaestrox(MAESTRO* pMaestro, int channel, int* pValue);
	HARDWAREX_API int SetPWMMaestrox(MAESTRO* pMaestro, int channel, int pw);
	HARDWAREX_API int SetAllPWMsMaestrox(MAESTRO* pMaestro, int* selectedchannels, int* pws);
	HARDWAREX_API int ConnectMaestrox(MAESTRO* pMaestro, char* szCfgFilePath);
	HARDWAREX_API int DisconnectMaestrox(MAESTRO* pMaestro);
	HARDWAREX_API int SetAllPWMsFromThreadMaestrox(MAESTRO* pMaestro, int* selectedchannels, int* pws);
	HARDWAREX_API int GetValueFromThreadMaestrox(MAESTRO* pMaestro, int channel, int* pValue);
	HARDWAREX_API int StartThreadMaestrox(MAESTRO* pMaestro);
	HARDWAREX_API int StopThreadMaestrox(MAESTRO* pMaestro);

	HARDWAREX_API HOKUYO* CreateHokuyox(void);
	HARDWAREX_API void DestroyHokuyox(HOKUYO* pHokuyo);
	HARDWAREX_API double k2angleHokuyox(HOKUYO* pHokuyo, int k);
	HARDWAREX_API int angle2kHokuyox(HOKUYO* pHokuyo, double angle);
	HARDWAREX_API int GetLatestDataHokuyox(HOKUYO* pHokuyo, double* pDistances, double* pAngles);
	HARDWAREX_API int ConnectHokuyox(HOKUYO* pHokuyo, char* szCfgFilePath);
	HARDWAREX_API int DisconnectHokuyox(HOKUYO* pHokuyo);
	HARDWAREX_API int GetLatestDataFromThreadHokuyox(HOKUYO* pHokuyo, double* pDistances, double* pAngles);
	HARDWAREX_API int StartThreadHokuyox(HOKUYO* pHokuyo);
	HARDWAREX_API int StopThreadHokuyox(HOKUYO* pHokuyo);

	HARDWAREX_API RPLIDAR* CreateRPLIDARx(void);
	HARDWAREX_API void DestroyRPLIDARx(RPLIDAR* pRPLIDAR);
	HARDWAREX_API int GetExpressScanDataResponseRPLIDARx(RPLIDAR* pRPLIDAR, double* pDistances, double* pAngles, BOOL* pbNewScan);
	HARDWAREX_API int ConnectRPLIDARx(RPLIDAR* pRPLIDAR, char* szCfgFilePath);
	HARDWAREX_API int DisconnectRPLIDARx(RPLIDAR* pRPLIDAR);
	HARDWAREX_API int GetExpressScanDataResponseFromThreadRPLIDARx(RPLIDAR* pRPLIDAR, double* pDistances, double* pAngles, BOOL* pbNewScan);
	HARDWAREX_API int StartThreadRPLIDARx(RPLIDAR* pRPLIDAR);
	HARDWAREX_API int StopThreadRPLIDARx(RPLIDAR* pRPLIDAR);

#ifdef ENABLE_MAVLINK_SUPPORT
	HARDWAREX_API MAVLINKDEVICE* CreateMAVLinkDevicex(void);
	HARDWAREX_API void DestroyMAVLinkDevicex(MAVLINKDEVICE* pMAVLinkDevice);
	HARDWAREX_API MAVLINKDATA* CreateMAVLinkDatax(void);
	HARDWAREX_API void DestroyMAVLinkDatax(MAVLINKDATA* pMAVLinkData);
	HARDWAREX_API int GetLatestDataMAVLinkDevicex(MAVLINKDEVICE* pMAVLinkDevice, MAVLINKDATA* pMAVLinkData);
	HARDWAREX_API int SetAllPWMsMAVLinkDevicex(MAVLINKDEVICE* pMAVLinkDevice, int* selectedchannels, int* pws);
	HARDWAREX_API int ConnectMAVLinkDevicex(MAVLINKDEVICE* pMAVLinkDevice, char* szCfgFilePath);
	HARDWAREX_API int DisconnectMAVLinkDevicex(MAVLINKDEVICE* pMAVLinkDevice);
	HARDWAREX_API int SetAllPWMsFromThreadMAVLinkDevicex(MAVLINKDEVICE* pMAVLinkDevice, int* selectedchannels, int* pws);
	HARDWAREX_API int GetLatestDataFromThreadMAVLinkDevicex(MAVLINKDEVICE* pMAVLinkDevice, MAVLINKDATA* pMAVLinkData);
	HARDWAREX_API int StartThreadMAVLinkDevicex(MAVLINKDEVICE* pMAVLinkDevice);
	HARDWAREX_API int StopThreadMAVLinkDevicex(MAVLINKDEVICE* pMAVLinkDevice);
#endif // ENABLE_MAVLINK_SUPPORT

#ifdef __cplusplus
}
#endif

#endif // HARDWAREX_H
