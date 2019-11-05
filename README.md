# +8_UTC_ESP8266_NTP_i2C_OLED

 PRINCIPAL CITIES : TIMEZONE/GMT/UTC +8 
 As standard time (all year round)
 
 (Northern to Southern Order)
 
 - Irkutsk,RUSSIA.			** No DST
 - Shanghai, CHINA. 		** No DST
 - Beijing, CHINA.			** No DST
 - Taipei, TAIWAN.			** No DST
 - Hong Kong, CHINA.		** No DST
 - Manila, PHILIPPINES.		** No DST
 - Kuala Lumpur, MALAYSIA.	** No DST
 - Singapore, SINGAPORE.	** No DST
 - Makassar, INDONESIA.		** No DST
 - Perth, AUSTRALIA.		** No DST
 
 REFERENCE 		: https://en.wikipedia.org/wiki/UTC%2B08:00
 DST REFERENCE 	: https://en.wikipedia.org/wiki/List_of_tz_database_time_zones
 
=======================================================================================


  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600 
--// GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0

//UTC Offset count ,GREENWICH LONDON UTC = 0 ,IF +1 = 3600 sec THAN UTC +8 x 3600 = 28800 utcOffsetInSeconds
//sample2 , NEW YORK UTC = -5 x 3600 = -18000

Greenwich Mean Time (GMT) is the mean solar time at the Royal Observatory in Greenwich, London, reckoned from midnight. At different times in the past, it has been calculated in different ways, including being calculated from noon;[1] as a consequence, it cannot be used to specify a precise time unless a context is given.

English speakers often use GMT as a synonym for Coordinated Universal Time (UTC).[2] For navigation, it is considered equivalent to UT1 (the modern form of mean solar time at 0° longitude); but this meaning can differ from UTC by up to 0.9 s. The term GMT should not thus be used for technical purposes.[3]

Because of Earth's uneven speed in its elliptical orbit and its axial tilt, noon (12:00:00) GMT is rarely the exact moment the sun crosses the Greenwich meridian and reaches its highest point in the sky there. This event may occur up to 16 minutes before or after noon GMT, a discrepancy calculated by the equation of time. Noon GMT is the annual average (i.e. "mean") moment of this event, which accounts for the word "mean" in "Greenwich Mean Time".

Originally, astronomers considered a GMT day to start at noon, while for almost everyone else it started at midnight. To avoid confusion, the name Universal Time was introduced to denote GMT as counted from midnight.[4] Astronomers preferred the old convention to simplify their observational data, so that each night was logged under a single calendar date. Today Universal Time usually refers to UTC or UT1.[5]
Source : https://en.wikipedia.org/wiki/Greenwich_Mean_Time
Code Reference : https://lastminuteengineers.com/esp8266-ntp-server-date-time-tutorial/
