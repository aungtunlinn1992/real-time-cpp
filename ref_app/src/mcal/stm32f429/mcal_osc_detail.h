///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2014.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef _MCAL_OSC_DETAIL_2014_10_30_H_
  #define _MCAL_OSC_DETAIL_2014_10_30_H_

  #include <algorithm>
  #include <cstdint>
  #include <util/utility/util_noncopyable.h>

  namespace mcal
  {
    namespace osc
    {
      namespace detail
      {
        class stm32f4xx_clock_settings : private util::noncopyable
        {
        public:
          stm32f4xx_clock_settings(const std::uint16_t f_pll,
                                   const std::uint8_t  f_hsx);

          ~stm32f4xx_clock_settings();

          std::uint32_t get_param_m() const { return static_cast<std::uint32_t>(param_m); }
          std::uint32_t get_param_n() const { return static_cast<std::uint32_t>(param_n); }
          std::uint32_t get_param_p() const { return static_cast<std::uint32_t>(param_p); }
          std::uint32_t get_param_q() const { return static_cast<std::uint32_t>(param_q); }

          bool get_f_usb_is_exactly_48() const { return f_usb_is_exactly_48; }

          bool get_clock_settings_are_valid() const { return clock_settings_are_valid; }

        private:
          bool          clock_settings_are_valid;
          bool          f_usb_is_exactly_48;
          std::uint8_t  param_m;
          std::uint16_t param_n;
          std::uint8_t  param_p;
          std::uint8_t  param_q;
        };
      }
    }
  } // namespace mcal::osc::detail

#endif // _MCAL_OSC_DETAIL_2014_10_30_H_
