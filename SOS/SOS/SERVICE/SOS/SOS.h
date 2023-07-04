/*
 * SOS.h
 *
 * Created: 5/29/2023 9:31:44 PM
 *  Author: mohab
 */ 


#ifndef SOS_H_
#define SOS_H_

#include "../../UTILITIES/bit_manipulation.h"
#include "../../UTILITIES/standard_types.h"
#include "../../UTILITIES/registers.h"

extern void (*ptr_func_task_define[10]) (void);

typedef enum enu_system_status_t
{
	SOS_STATUS_SUCCESS, SOS_STATUS_INVALID_STATE
}
enu_system_status_t;

typedef enum enu_creat_status_t
{
	CREAT_SUCCESS, CREAT_FAIL
}
enu_creat_status_t;

typedef enum enu_delete_status_t
{
	DELETE_SUCCESS, DELETE_FAIL
}
enu_delete_status_t;

typedef enum enu_modify_status_t
{
	MODIFY_SUCCESS, MODIFY_FAIL
}
enu_modify_status_t;

typedef struct  str_sos_task_t
{
	uint8_t		task_ID;
	uint8_t		task_priority;
	uint16_t	task_priodicity;
	void (*ptr_func_task) (void);
}str_sos_task_t;


enu_system_status_t sos_init(void);

enu_system_status_t sos_deinit(void);

enu_creat_status_t sos_create_task(uint8_t ar_task_ID, uint8_t ar_task_priorty, uint8_t ar_task_priodicity);

enu_delete_status_t sos_delete_task(uint8_t ar_task_ID);

enu_modify_status_t sos_modify_task(uint8_t ar_task_ID, uint8_t ar_task_priorty, uint8_t ar_task_priodicity);

void sos_run(void);

#endif /* SOS_H_ */