// StratifiedSampler class
// Written by Sergey Kosov in 2019 for Project X
#pragma once

#include "Sampler.h"

// ================================ Stratified Sampler Class ================================
/**
* @brief Stratified Sampler class
* @note This class is not thread-safe
* @author Sergey G. Kosov, sergey.kosov@project-10.de
*/
class CSamplerStratified : public CSampler {
public:
	/**
	* @brief Constructor
	* @param nSamples Square root of number of samples in one series
	*/
	CSamplerStratified(size_t nSamples) : CSampler(nSamples) {}
	virtual ~CSamplerStratified(void) = default;

	virtual Vec2f	getSample(size_t s) const
	{
		// --- PUT YOUR CODE HERE ---
		size_t nSamples = static_cast<size_t>(sqrt(getNumSamples()));
        return Vec2f((static_cast<float>(s / nSamples) + Random::U<float>()) / nSamples, (static_cast<float>(s % nSamples) + Random::U<float>()) / nSamples);
	}

};