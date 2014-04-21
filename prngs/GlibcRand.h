/*
 * GlibcRand.h
 *
 *  Created on: Feb 19, 2014
 *      Author: moloch
 */

#ifndef GLIBCRAND_H_
#define GLIBCRAND_H_

#include <random>
#include "PRNG.h"

static const std::string GLIBC_RAND = "glibc-rand";
static const uint32_t GLIBC_RAND_STATE_SIZE = 32;

class GlibcRand: public PRNG
{
public:
    GlibcRand();
    virtual ~GlibcRand();

    const std::string getName(void);
    void seed(uint32_t value);
    uint32_t getSeed(void);
    uint32_t random(void);

private:
    uint32_t seedValue;
    uint32_t getStateSize(void);
    void setState(std::vector<uint32_t> inState);
    std::vector<uint32_t> getState(void);

    std::vector<uint32_t> predictForward(uint32_t);
    std::vector<uint32_t> predictBackward(uint32_t);
    void tune(std::vector<uint32_t>, std::vector<uint32_t>);

};

#endif /* GLIBCRAND_H_ */
