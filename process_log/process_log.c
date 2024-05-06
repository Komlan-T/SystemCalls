#include "process_log.h"

// Library Functions
int get_proc_log_level(){
    int getProcessLog = syscall(436);
    if(getProcessLog >= 0 && getProcessLog <= 7){
        return getProcessLog;
    }
    return -1;
}

int set_proc_log_level(int new_level){
    int status = syscall(435, new_level);
    if(status != -1){
        return new_level;
    }
    return -1;
}

int proc_log_message(int level, char* message){
    int return_val = syscall(PROC_LOG_CALL, message, level);
    if(return_val >= 0 && return_val <= 7){
        return level;
    }
    return -1;
}

// Harness Functions

int* retrieve_set_level_params(int new_level){
    int call_number = 435;
    int num_parameters = 1;
    int* array = malloc(3 * sizeof(int));
    array[0] = call_number;
    array[1] = num_parameters;
    array[2] = new_level;
    return array;
}

int* retrieve_get_level_params(){
    int call_number = 436;
    int num_parameters = 0;
    int* array = malloc(2 * sizeof(int));
    array[0] = call_number;
    array[1] = num_parameters;
    return array;
}

int interpret_set_level_result(int ret_value){
    return ret_value;
}

int interpret_get_level_result(int ret_value){
    return ret_value;
}

int interpret_log_message_result(int ret_value){
    return ret_value;
}