// ***************************************************************
//  AppUseFilePathAndName   version:  1.0   ·  date: 12/09/2007
//  -------------------------------------------------------------
//  车道程序使用的配置文件临时文件存储位置与路径！
//  -------------------------------------------------------------
//  Copyright (C) 2007 - All Rights Reserved
// ***************************************************************
//
// ***************************************************************

#ifndef _AppUseFilePathAndName_H_
#define _AppUseFilePathAndName_H_
#define PARAACCESSLEVE_FILE                 GetParameterFileList()->ACCESLVL
#define PARABLACKCARDOPPCARTER_FILE         GetParameterFileList()->OPPCARTE
#define PARABLACKCARDOPPABONNR_FILE         GetParameterFileList()->OPPABONN
#define PARABLACKCARDLSTORANGR_FILE         GetParameterFileList()->LSTORANG
#define PARACONSTANT_FILE                   GetParameterFileList()->CONSTANT
#define PARAFARERECORD_FILE                 GetParameterFileList()->TARI
#define PARAJOURNEYRECORD_FILE              GetParameterFileList()->TRAJ
#define PARAJOURNEYSERVICE_FILE             GetParameterFileList()->JOUSERVI
#define PARASERVICELIST_FILE                GetParameterFileList()->LSTSERVI
#define PARASTAFF_FILE                      GetParameterFileList()->LSTPERSO
#define PARABLACKPLATEOPPLAQUE_FILE         GetParameterFileList()->OPPLAQUE


#define PARAYHKLIST_FILE            GetParameterFileList()->YHKLIST //优惠卡表
#define PARACOLLECT_FILE            GetParameterFileList()->COLLECT //工号表
#define PARAFARELIST_FILE           GetParameterFileList()->FARELIST //费额表
#define PARAYHRATE_FILE             GetParameterFileList()->YHRATE //优惠率
#define PARAYPKLIST_FILE            GetParameterFileList()->YPKLIST //手输式月票卡表
#define PARACARKINDLIST_FILE        GetParameterFileList()->CARKIND_CONF  //车种表
#define PARAJOUCODE_FILE            GetParameterFileList()->JOUCODE //旅程代码表
#define PARASVRCARDLIST_FILE            GetParameterFileList()->SVRCARDLIST //ic卡参数表
#define PARAPUBLICKEY_FILE                   GetParameterFileList()->PUBLICKEY //IC卡密钥表
#define PARFREECARLIST_FILE				"/EMRCV3/PARAMETER/OfficeInfo.TXT"
#define CONFAPLAZARECORD_FILE               GetParameterFileList()->TOLLSYSTEM
#define FILEPATH_PARAMETER                  "/EMRCV3/PARAMETER/"
#define FILEPATH_PARAMETER_UPDATE           "/EMRCV3/PARAMETER/UPDATE"
#define FILEPATH_PARAMETER_ACTUAL           "/EMRCV3/PARAMETER/ACTUAL"
#define FILEPATH_PARAMETER_ERROR            "/EMRCV3/PARAMETER/ERROR"
#define FILEPATH_PARAMETER_FUTURE           "/EMRCV3/PARAMETER/FUTURE"
#define ICKEY_FILE							"/EMRCV3/PARAMETER/ICKEY"
#define FILEPATH_FTP_PARAMETER              "LDCPARAM"
#define FILEPATH_CONFIG                     "/EMRCV3/CONFIG/"
#define APPFUNCTIONFILENAMEFILE             "/EMRCV3/CONFIG/AppFunction.ini"
#define CONFCOMMUNCTION_FILE                "/EMRCV3/CONFIG/CommunctionConfig.ini"
#define FILENAME_PARAMETER_FILE_LIST        "/EMRCV3/CONFIG/ParameterFileList.ini"
#define LANECONFIGFILENAME_FILE             "/EMRCV3/CONFIG/Config.ini"
#define CONTROLLANEIPFILENAME_FILE             "/EMRCV3/CONFIG/ControlLanIP.ini"
#define LANEOLDCONFIG_FILE            		"/EMRCV3/CONFIG/BaseConfig.ini"

#define FILENAME_ASVE_EXITHT                "/EMRCV3/TEMP/ExitHT.TMP"
#define FILENAME_ASVE_EXITES                "/EMRCV3/TEMP/ExitES.TMP"
#define FILENAME_ASVE_EMRCFROM                "/EMRCV3/TEMP/EMRCFROM.TMP"
#define FILENAME_NO_SEND_MSG_FILE           "/EMRCV3/DATA/Send/"
#define FILENAME_SEND_MSG_BACKUP_FILE       "/EMRCV3/DATA/Send/Archive/"
#define FILENAME_CARDBOX                    "/EMRCV3/TEMP/CradBox.TMP"
#define FILENAME_SETTLEMENT_DATA_JOB_NO     "/EMRCV3/TEMP/SettlementDateAndJobNo.TMP"
#define FILENAME_SAVE_MEOJOB_FILE           "/EMRCV3/TEMP/JOBSUM.TMP"
#define FILENAME_SAVE_MEOJOB_FILE_REVEMOP   "/EMRCV3/TEMP/REVEMOP.TMP"
#define FILENAME_SAVE_MEOJOB_FILE_DISCOUNTMOP   "/EMRCV3/TEMP/DISCOUNTMOP.TMP"
#define FILENAME_SAVE_MEOJOB_FILE_OVERLOADMOP   "/EMRCV3/TEMP/OVERLOADMOP.TMP"
#define FILENAME_SAVE_TrafficDaily          "/EMRCV3/TEMP/TrafficDaily.TMP"
#define FILENAME_ASVE_NEWEXITES             "/EMRCV3/TEMP/NEWExitES.TMP"
#define FILENAME_SAVE_TrafficHour           "/EMRCV3/TEMP/TrafficHour.TMP"
#define FILENAME_ASVE_NEWEXITHT             "/EMRCV3/TEMP/NEWExitHT.TMP"
#define FILENAME_SAVE_WorkInfo              "/EMRCV3/TEMP/WorkInfo.TMP"
#define FILENAME_SAVE_ImageHeader           "/EMRCV3/TEMP/ImageHeader.TMP"
#define FILENAME_SAVE_ImageHeader           "/EMRCV3/TEMP/ImageHeader.TMP"
#define FILENAME_SAVE_ParameterVersion      "/EMRCV3/TEMP/PatameterVersion.TMP"
#define FILENAME_SAVE_ImageTEMP             "/EMRCV3/IMAGE/TEMP/"
#define FILENAME_SAVE_ImageUPLOAD           "/EMRCV3/IMAGE/UPLOAD/"
#define FILENAME_SAVE_ImageArchive           "/EMRCV3/IMAGE/Archive/"
#define FILENAME_LOG_FILE_PATH              "/EMRCV3/LOG/"
#define FILENAME_LOG_FILE_PATH_Archive      "/EMRCV3/LOG/Archive/"
#define FILENAME_SEND_MSG_BACKUP_FILE_Archive       "/EMRCV3/DATA/Send/Archive/"
#define FILENAME_SAVE_TEMP     "/EMRCV3/TEMP/"
#define FILENAME_SAVE_BILLNUMBER     "/EMRCV3/TEMP/BillNumber.TMP"
//EMRC_DB
#define  FILENAME_EMRC_MSG_DB "/EMRCV3/DATA/EMRC_MSG_DB"
#define  FILENAME_EMRC_LOG_DB "/EMRCV3/LOG/EMRC_LOG_DB"
//USB挂载的目录
#define FILENAME_USBDIR  "/EMRCV3/USB/"
#define FILENAME_DISKQUEUE  "/EMRCV3/DATA/DiskQueue"
//USB上的导出数据的目标位置
#define FILENAME_ARCATUSB  "/EMRC-R2_EXPORTET_DATA/"

 
#endif




