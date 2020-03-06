/**
 * The MIT License
 *
 * Copyright (c) 2020 Ilwoong Jeong (https://github.com/ilwoong)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __RANDOMNESS_SP800_90B_ENTROPY_ESTIMATOR_H__
#define __RANDOMNESS_SP800_90B_ENTROPY_ESTIMATOR_H__

#include <cstdint>
#include <string>
#include <sstream>

namespace randomness { namespace sp800_90b { namespace estimator {

    static constexpr double Zalpha = 2.5758293035489008;

    class EntropyEstimator 
    {
    protected:
        std::ostringstream logstream;

    public:
        virtual std::string Name() const = 0;
        virtual double Estimate(const uint8_t* data, size_t len, size_t count_alphabets) = 0;
        std::string Log() const;

    protected:
        double UpperBoundProbability(double prob, size_t length) const;
        double BinarySearch(double arg, double ldomain, double hdomain, double optional = 0.0);
        virtual double EvaluateBinarySearch(double arg1, double arg2) const;
    };
}}}

#endif
