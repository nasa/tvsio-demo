/* Created : Tue Jun 11 15:18:18 CDT 2019
   User    : aes
   Project : cert_cfe_v6_6
   Script  : /virtualpcs/repos/um/fcc/fcc_fsw/ccdd/scripts/CCSDS_V2_Mids.js
   Group(s): cfe_mids
*/

#ifndef _auto_cfe_mids_h_
#define _auto_cfe_mids_h_

/* SubSystem Macros */
#define GRP1_CFE_ID                                    0x01
#define GRP2_CFE_ID                                    0x02
#define GRP3_CFE_ID                                    0x03
#define GRP4_CFE_ID                                    0x04

/* Command message IDs */
#define GRP1_CFE_MIN_CMD_MID                           0x8201
#define GRP1_CFE_ES_CMD_MID                            0x8201
#define GRP1_CFE_ES_SEND_HK_MID                        0x8202
#define GRP1_CFE_EVS_CMD_MID                           0x8203
#define GRP1_CFE_EVS_SEND_HK_MID                       0x8204
#define GRP1_CFE_SB_CMD_MID                            0x8205
#define GRP1_CFE_SB_SEND_HK_MID                        0x8206
#define GRP1_CFE_TBL_CMD_MID                           0x8207
#define GRP1_CFE_TBL_SEND_HK_MID                       0x8208
#define GRP1_CFE_TIME_CMD_MID                          0x8209
#define GRP1_CFE_TIME_SEND_HK_MID                      0x820A
#define GRP1_CFE_TIME_TONE_CMD_MID                     0x820B
#define GRP1_CFE_TIME_HZ_CMD_MID                       0x820C
#define GRP1_CFE_TIME_DATA_CMD_MID                     0x820D
#define GRP1_CFE_TIME_SEND_CMD_MID                     0x820E
#define GRP1_CFE_EVS_EVENT_MSG_MID                     0x820F
#define GRP1_CFE_MAX_CMD_MID                           0x820F


#define GRP2_CFE_MIN_CMD_MID                           0x8401
#define GRP2_CFE_ES_CMD_MID                            0x8401
#define GRP2_CFE_ES_SEND_HK_MID                        0x8402
#define GRP2_CFE_EVS_CMD_MID                           0x8403
#define GRP2_CFE_EVS_SEND_HK_MID                       0x8404
#define GRP2_CFE_SB_CMD_MID                            0x8405
#define GRP2_CFE_SB_SEND_HK_MID                        0x8406
#define GRP2_CFE_TBL_CMD_MID                           0x8407
#define GRP2_CFE_TBL_SEND_HK_MID                       0x8408
#define GRP2_CFE_TIME_CMD_MID                          0x8409
#define GRP2_CFE_TIME_SEND_HK_MID                      0x840A
#define GRP2_CFE_TIME_TONE_CMD_MID                     0x840B
#define GRP2_CFE_TIME_HZ_CMD_MID                       0x840C
#define GRP2_CFE_TIME_DATA_CMD_MID                     0x840D
#define GRP2_CFE_TIME_SEND_CMD_MID                     0x840E
#define GRP2_CFE_EVS_EVENT_MSG_MID                     0x840F
#define GRP2_CFE_MAX_CMD_MID                           0x840F

#define GRP3_CFE_MIN_CMD_MID                           0x8601
#define GRP3_CFE_ES_CMD_MID                            0x8601
#define GRP3_CFE_ES_SEND_HK_MID                        0x8602
#define GRP3_CFE_EVS_CMD_MID                           0x8603
#define GRP3_CFE_EVS_SEND_HK_MID                       0x8604
#define GRP3_CFE_SB_CMD_MID                            0x8605
#define GRP3_CFE_SB_SEND_HK_MID                        0x8606
#define GRP3_CFE_TBL_CMD_MID                           0x8607
#define GRP3_CFE_TBL_SEND_HK_MID                       0x8608
#define GRP3_CFE_TIME_CMD_MID                          0x8609
#define GRP3_CFE_TIME_SEND_HK_MID                      0x860A
#define GRP3_CFE_TIME_TONE_CMD_MID                     0x860B
#define GRP3_CFE_TIME_HZ_CMD_MID                       0x860C
#define GRP3_CFE_TIME_DATA_CMD_MID                     0x860D
#define GRP3_CFE_TIME_SEND_CMD_MID                     0x860E
#define GRP3_CFE_MAX_CMD_MID                           0x860E

#define GRP4_CFE_MIN_CMD_MID                           0x8801
#define GRP4_CFE_ES_CMD_MID                            0x8801
#define GRP4_CFE_ES_SEND_HK_MID                        0x8802
#define GRP4_CFE_EVS_CMD_MID                           0x8803
#define GRP4_CFE_EVS_SEND_HK_MID                       0x8804
#define GRP4_CFE_SB_CMD_MID                            0x8805
#define GRP4_CFE_SB_SEND_HK_MID                        0x8806
#define GRP4_CFE_TBL_CMD_MID                           0x8807
#define GRP4_CFE_TBL_SEND_HK_MID                       0x8808
#define GRP4_CFE_TIME_CMD_MID                          0x8809
#define GRP4_CFE_TIME_SEND_HK_MID                      0x880A
#define GRP4_CFE_TIME_TONE_CMD_MID                     0x880B
#define GRP4_CFE_TIME_HZ_CMD_MID                       0x880C
#define GRP4_CFE_TIME_DATA_CMD_MID                     0x880D
#define GRP4_CFE_TIME_SEND_CMD_MID                     0x880E
#define GRP4_CFE_MAX_CMD_MID                           0x880E

/* Telemetry message IDs */
#define GRP1_CFE_MIN_TLM_MID                           0x0201
#define GRP1_CFE_ES_HK_TLM_MID                         0x0201
#define GRP1_CFE_ES_SHELL_TLM_MID                      0x0202
#define GRP1_CFE_ES_MEMSTATS_TLM_MID                   0x0203
#define GRP1_CFE_ES_APP_TLM_MID                        0x0204
#define GRP1_CFE_EVS_HK_TLM_MID                        0x0205
#define GRP1_CFE_EVS_LONG_EVENT_MSG_MID                0x0206
#define GRP1_CFE_EVS_SHORT_EVENT_MSG_MID               0x0207
#define GRP1_CFE_SB_HK_TLM_MID                         0x0208
#define GRP1_CFE_SB_STATS_TLM_MID                      0x0209
#define GRP1_CFE_SB_ALLSUBS_TLM_MID                    0x020A
#define GRP1_CFE_SB_ONESUB_TLM_MID                     0x020B
#define GRP1_CFE_TBL_HK_TLM_MID                        0x020C
#define GRP1_CFE_TBL_REG_TLM_MID                       0x020D
#define GRP1_CFE_TIME_HK_TLM_MID                       0x020E
#define GRP1_CFE_TIME_DIAG_TLM_MID                     0x020F
#define GRP1_CFE_MAX_TLM_MID                           0x020F

#define GRP2_CFE_MIN_TLM_MID                           0x0401
#define GRP2_CFE_ES_HK_TLM_MID                         0x0401
#define GRP2_CFE_ES_SHELL_TLM_MID                      0x0402
#define GRP2_CFE_ES_MEMSTATS_TLM_MID                   0x0403
#define GRP2_CFE_ES_APP_TLM_MID                        0x0404
#define GRP2_CFE_EVS_HK_TLM_MID                        0x0405
#define GRP2_CFE_EVS_LONG_EVENT_MSG_MID                0x0406
#define GRP2_CFE_EVS_SHORT_EVENT_MSG_MID               0x0407
#define GRP2_CFE_SB_HK_TLM_MID                         0x0408
#define GRP2_CFE_SB_STATS_TLM_MID                      0x0409
#define GRP2_CFE_SB_ALLSUBS_TLM_MID                    0x040A
#define GRP2_CFE_SB_ONESUB_TLM_MID                     0x040B
#define GRP2_CFE_TBL_HK_TLM_MID                        0x040C
#define GRP2_CFE_TBL_REG_TLM_MID                       0x040D
#define GRP2_CFE_TIME_HK_TLM_MID                       0x040E
#define GRP2_CFE_TIME_DIAG_TLM_MID                     0x040F
#define GRP2_CFE_MAX_TLM_MID                           0x040F

#define GRP3_CFE_MIN_TLM_MID                           0x0601
#define GRP3_CFE_ES_HK_TLM_MID                         0x0601
#define GRP3_CFE_ES_SHELL_TLM_MID                      0x0602
#define GRP3_CFE_ES_MEMSTATS_TLM_MID                   0x0603
#define GRP3_CFE_ES_APP_TLM_MID                        0x0604
#define GRP3_CFE_EVS_HK_TLM_MID                        0x0605
#define GRP3_CFE_EVS_LONG_EVENT_MSG_MID                0x0606
#define GRP3_CFE_EVS_SHORT_EVENT_MSG_MID               0x0607
#define GRP3_CFE_SB_HK_TLM_MID                         0x0608
#define GRP3_CFE_SB_STATS_TLM_MID                      0x0609
#define GRP3_CFE_SB_ALLSUBS_TLM_MID                    0x060A
#define GRP3_CFE_SB_ONESUB_TLM_MID                     0x060B
#define GRP3_CFE_TBL_HK_TLM_MID                        0x060C
#define GRP3_CFE_TBL_REG_TLM_MID                       0x060D
#define GRP3_CFE_TIME_HK_TLM_MID                       0x060E
#define GRP3_CFE_TIME_DIAG_TLM_MID                     0x060F
#define GRP3_CFE_MAX_TLM_MID                           0x060F

#define GRP4_CFE_MIN_TLM_MID                           0x0801
#define GRP4_CFE_ES_HK_TLM_MID                         0x0801
#define GRP4_CFE_ES_SHELL_TLM_MID                      0x0802
#define GRP4_CFE_ES_MEMSTATS_TLM_MID                   0x0803
#define GRP4_CFE_ES_APP_TLM_MID                        0x0804
#define GRP4_CFE_EVS_HK_TLM_MID                        0x0805
#define GRP4_CFE_EVS_LONG_EVENT_MSG_MID                0x0806
#define GRP4_CFE_EVS_SHORT_EVENT_MSG_MID               0x0807
#define GRP4_CFE_SB_HK_TLM_MID                         0x0808
#define GRP4_CFE_SB_STATS_TLM_MID                      0x0809
#define GRP4_CFE_SB_ALLSUBS_TLM_MID                    0x080A
#define GRP4_CFE_SB_ONESUB_TLM_MID                     0x080B
#define GRP4_CFE_TBL_HK_TLM_MID                        0x080C
#define GRP4_CFE_TBL_REG_TLM_MID                       0x080D
#define GRP4_CFE_TIME_HK_TLM_MID                       0x080E
#define GRP4_CFE_TIME_DIAG_TLM_MID                     0x080F
#define GRP4_CFE_MAX_TLM_MID                           0x080F

#endif /* _auto_cfe_mids_h_ */

