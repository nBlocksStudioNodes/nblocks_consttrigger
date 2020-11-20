#include "consttrigger.h"


uint32_t convert_value(float value, nBlocks_OutputType value_type) {
   switch (value_type) {
        case OUTPUT_TYPE_FLOAT:
            uint32_t result;
            memcpy(&(result), &(value), sizeof(value));
            return result;
        
        case OUTPUT_TYPE_INT:
            return (int)value;
    }
    return 0; // Failsafe catch-all
}


 

nBlock_ConstTrigger::nBlock_ConstTrigger(float value, nBlocks_OutputType value_type) {
    _value_float = value;
    outputType[0] = value_type;
    _was_triggered = 0;
    return;
}

void nBlock_ConstTrigger::triggerInput(nBlocks_Message message) {
    _was_triggered = 1;
}

void nBlock_ConstTrigger::endFrame(void) {    
    if (_was_triggered) {
        _was_triggered = 0;
        available[0] = 1;
        
        output[0] = convert_value( _value_float, outputType[0]);
    }
    return;
}
