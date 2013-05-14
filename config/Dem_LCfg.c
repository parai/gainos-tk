
#include "Dem.h"

/*********************
 * DEM Configuration *
 *********************/


/*
 * Classes of extended data record
 */


/*
 * Classes of extended data
 */


/*
 * Classes of freeze frames
 */


/*
 * Classes of PreDebounce algorithms
 */


/*
 * Classes of event
 */


/*
 * Event parameter list
 */
const Dem_EventParameterType EventParameter[] = {
		{
				0,
		}
};


/*
 * DEM's config set
 */
const Dem_ConfigSetType DEM_ConfigSet = {
		/*.EventParameter = */EventParameter,
//		.DTCClassType = NULL,		TODO: Add later
//		.GroupOfDtc = NULL,			TODO: Add later
//		.OemIdClass = NULL			TODO: Add later
};

/*
 * DEM's config
 */
const Dem_ConfigType DEM_Config = {
	/*.ConfigSet =*/ &DEM_ConfigSet,
};
