
#ifndef __UIFlowWndMovieIcons_H
#define __UIFlowWndMovieIcons_H
#include "UIFlow.h"
#include "type.h"
extern void FlowMovie_IconDrawStorage(void);
extern void FlowMovie_IconHideStorage(void);
extern void FlowMovie_IconDrawDateTime(void);
extern void FlowMovie_IconHideDateTime(void);
extern void FlowMovie_IconDrawSize(void);
extern void FlowMovie_IconHideSize(void);
extern void FlowMovie_UpdateIcons(BOOL bShow);
#if 1
extern void FlowMovie_IconDrawDscMode(void);
extern void FlowMovie_IconHideDscMode(void);
extern void FlowMovie_IconDrawMaxRecTime(void);
extern void FlowMovie_IconHideMaxRecTime(void);
extern void FlowMovie_IconDrawRecTime(void);


extern void FlowMovie_IconDrawEV(void);
extern void FlowMovie_IconHideEV(void);
extern void FlowMovie_IconDrawBattery(void);
extern void FlowMovie_IconHideBattery(void);
extern void FlowMovie_DrawPIM(BOOL bDraw);
extern void FlowMovie_IconDrawDZoom(void);
extern void FlowMovie_IconHideDZoom(void);
extern void FlowMovie_IconDrawDateTime(void);
extern void FlowMovie_IconHideDateTime(void);

extern void FlowMovie_DrawEdogGPSStatusIcon(EDOG_INFO *pEdogInfo);
extern void FlowMovie_HideEdogGPSStatusIcon(void);
extern void FlowMovie_DrawEdogSpeedIcon(EDOG_INFO *pEdogInfo);
extern void FlowMovie_HideEdogSpeedIcon(void);
extern void FlowMovie_DrawEdogWarningTypeIocn(EDOG_INFO *pEdogInfo);
extern void FlowMovie_HideEdogWarningTypeIocn();
extern void FlowMovie_DrawEdogSpeedLimitIocn(EDOG_INFO *pEdogInfo);
extern void FlowMovie_HideEdogSpeedLimitIocn();
extern void FlowMovie_DrawEdogDistanceIocn(EDOG_INFO *pEdogInfo);
extern void FlowMovie_HideEdogDistanceIocn();
extern void FlowMovie_DrawEdogDerectionIocn(EDOG_INFO *pEdogInfo);
extern void FlowMovie_HideEdogDerectionIocn();
extern void FlowMovie_ClearAllEdogIcon();

extern void FlowMovie_UpdateEdogInfo_G(EDOG_INFO *pEdogInfo);
extern void FlowMovie_UpgradeCode(EDOG_INFO *pEdogInfo);
extern void FlowMovie_UpdateErrorCode(EDOG_INFO *pEdogInfo);


#endif
#endif //__UIFlowWndMovieIcons_H
