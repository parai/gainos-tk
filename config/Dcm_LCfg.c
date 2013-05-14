
#include "Dcm.h"
#include "Rte_Dcm.h"




/*********************
 * DCM Configuration *
 *********************/

/*
 * DSP configurations
 */
const Dcm_DspType Dsp = {
		/* DspDid = */ 0,
		/* DspDidInfo = */ NULL,
		/* DspEcuReset = */ NULL,
		/* DspPid = */ NULL,
		/* DspReadDTC = */ NULL,
		/* DspRequestControl = */ NULL,
		/* DspRoutine = */ NULL,
		/* DspRoutineInfo = */ NULL,
		/* DspSecurity = */ NULL,
		/* DspSession = */ NULL,
		/* DspTestResultByObdmid = */ NULL,
		/* DspVehInfo = */ NULL,
};


/*
 * DSD configurations
 */
const Dcm_DsdType Dsd = {
		/* DsdServiceTable = */ NULL
};


/*
 * DSL configurations
 */
const Dcm_DslType Dsl = {
		/* DslBuffer = */ NULL,
		/* DslCallbackDCMRequestService = */ NULL,
		/* DslDiagResp = */ NULL,
		/* DslProtocol = */ NULL,
		/* DslProtocolTiming = */ NULL,
		/* DslServiceRequestIndication = */ NULL,
		/* DslSessionControl = */ NULL
};

/*
 * DCM configurations
 */
const Dcm_ConfigType DCM_Config = {
		/* Dsp = */ &Dsp,
		/* Dsd = */ &Dsd,
		/* Dsl = */ &Dsl
};
