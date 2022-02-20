#include <time.h>

typedef int64_t nanoclock_t;

const nanoclock_t GIGA = 1000000000LL;
const nanoclock_t NNCL_SECOND = GIGA;

nanoclock_t nanoclock_getTimeZoneTime()
{
	struct tm tmdate;
	tmdate.tm_year  = 70;
	tmdate.tm_mon   = 0;
	tmdate.tm_mday  = 1;
	tmdate.tm_hour  = 0;
	tmdate.tm_min   = 0;
	tmdate.tm_sec   = 0;
	tmdate.tm_isdst = 0;
	return -mktime( &tmdate )*NNCL_SECOND;
}

nanoclock_t nanoclock_gettime()
{
  struct timespec t;
  clock_gettime(CLOCK_REALTIME, &t);
  nanoclock_t nanoclock_epochDelta = 0;

  struct tm tmdate;

  tmdate.tm_year  = 2000 - 1900;
  tmdate.tm_mon   = 1 - 1;
  tmdate.tm_mday  = 1;
  tmdate.tm_hour  = 0;
  tmdate.tm_min   = 0;
  tmdate.tm_sec   = 0;
  tmdate.tm_isdst = 0;

  nanoclock_epochdelta -= mktime( &tmdate )*NNCL_SECOND + nanoclock_getTimeZoneTime();
  return ((nanoclock_t)t.tv_sec)*GIGA + nanoclock_epochDelta;
}
