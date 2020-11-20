#ifndef __NB_GPI
#define __NB_GPI

#include "nworkbench.h"

class nBlock_ConstTrigger: public nBlockSimpleNode<1> {
public:
    nBlock_ConstTrigger(float value, nBlocks_OutputType value_type);
    void triggerInput(nBlocks_Message message);
    void endFrame(void);
private:
    float _value_float;
    uint32_t _was_triggered;
};


#endif
