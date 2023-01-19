/**
* Copyright (c) Microblink Ltd.
*
* BSD 3-Clause revised license:
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <std_fix/bit>
#include <std_fix/concepts>
#include <std_fix/memory>

#include <initializer_list>
#include <iterator>
#include <memory>
//------------------------------------------------------------------------------

static_assert
(
    std::bit_cast< int >( 0.f ) == 0
);

static_assert
(
    std::bit_width( 127U ) == 7U
);

static_assert
(
     std::convertible_to<          int, float > &&
    !std::convertible_to< char const *, float >
);

struct A     {           };
struct B : A { B( int ); };
static_assert
(
     std::derived_from< B, A >
);

static_assert
(
     std::destructible< B >
);

static_assert
(
     std::constructible_from< B, int >
);

static_assert
(
     std::integral< int   > &&
    !std::integral< float >
);

static_assert
(
    std::contiguous_iterator< std::initializer_list< int >::iterator >
);

static_assert
(
    std::input_iterator< std::initializer_list< int >::iterator >
);

struct Triplet
{
    int a;
    int b;
    int c;

    constexpr Triplet( int x, int y, int z ) : a{ x }, b{ y }, c{ z } {}

    [[ nodiscard ]] constexpr int sum() const noexcept { return a + b + c; }
};

// testing std::construct_at
static_assert
(
    []()
    {
        union Union {
            Triplet container;
            char    c;
            constexpr Union() : c{ 0 } {}
        };
        Union u;
        Triplet * t{ std::construct_at< Triplet >( &u.container, 1, 2, 3 ) };
        return t->sum();
    }() == 6
);

//------------------------------------------------------------------------------
