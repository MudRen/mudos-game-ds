// cal.c 類似 unix 上的 cal 命令
// 語法: cal 年 月
// 1997 3 10 wade@Fantasy.Space    jjchen@ice.ntnu.edu.tw
// 歡迎流傳本程式, 請保留本說明

#include <localtime.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string  *ani = ({ "鼠", "牛", "虎", "兔", "龍", "蛇",
                 "馬", "羊", "猴", "雞", "狗", "豬" });

// 這個雖然是 #define 來的, 可是只要更動其值, 會影響星期的算法
// 請見底下打十個星號的那一行的說明
#define FIRSTYEAR	1911

// 西曆年平年每月之日數
int *SolarCal = ({ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 });

// 求此西曆年是否為閏年, 返回 0 為平年, 1 為閏年
int GetLeap (int year)
{
  if ( year % 400 == 0 )        // 西曆年可被四百整除的話一定是潤年
    return 1;                   // 如 1600, 2000 為潤年
  else if ( year % 100 == 0 )   // 如果被一百整除卻不能被四百整除, 則為平年
    return 0;                   // 如 1800, 1900 為平年
  else if ( year % 4 == 0 )     // 不是一百的倍數卻是四的倍數, 則為潤年
    return 1;                   // 如 1992, 1996, 2000, 2004 為潤年
  else                          // 其餘皆為平年
    return 0;
}

int main(object me, string arg)
{
  mixed *local;
  int	leap;		// 是否潤年
  int	yy, mm, dd;	// 要查詢的日期
  int	ty, tm, td;	// 今天的日期
  int	acc;		// 累積天數, 用來算星期幾用的
  int	Weekday;	// 本月的第一天為星期幾
  int	d;		// 該月的天數
  int	i;

  // 取得今天的日期
  local = localtime(time());
  ty = local[LT_YEAR];
  tm = local[LT_MON]+1;
  td = local[LT_MDAY];

  if (!arg || arg == "") {	// 本月份
    yy = ty;
    mm = tm;
    dd = td;
  }
  else {			// 指定的月份
    if (!sscanf (arg, "%d%d", yy, mm) == 2) {
      printf ("語法: cal 年 月\n");
      return 1;
    }
    yy += 1911;
    dd = td;
  }
  if (yy < FIRSTYEAR) {
    printf ("對不起, 目前只提供中華民國 %d 年以後的月曆.\n", FIRSTYEAR-1911);
    return 1;
  }
  if (mm < 1 || mm > 12) {
    printf ("只能一月到十二月間.\n");
    return 1;
  }

  // 是否為潤年
  leap = GetLeap ( yy );
  // 由是否潤年計算該月的天數
  if ( mm == 1 )	// 二月
    d = leap + 28;
  else
    d = SolarCal[mm-1];

  acc = 0;
  // 計算累積到去年的日數 from 公元 FIRSTYEAR年
  for (i=FIRSTYEAR; i<yy; i++)
    acc = acc + 365 + GetLeap (i);
  // 計算累積到上個月的日數
  for (i=1; i<mm; i++)
    acc = acc + SolarCal[i-1];
  if (mm > 2 && GetLeap (yy)) acc++;	// 今年潤年加一天

  // 本月第一日的星期數
  // ********** 這邊的算法是因為 1911 年的 1 月 1 日是星期日 **********
  Weekday = acc % 7;

  printf ("【民國 %d 年 %d 月】-- 「%s年」\n\n日 一 二 三 四 五 六\n",
          yy-1911, mm, ani[(yy-112)%12]);
  for (i=0; i<Weekday; i++)
    printf ("   ");
  for (i=1; i<=d; i++) {
    if ((Weekday + i) % 7 == 1)
      printf ("\n%s%2d %s", HIR, i, NOR);
    else if (yy == ty && mm == tm && td == i)
      printf ("%s%2d %s", HIY, i, NOR);
    else
      printf ("%2d ", i);
  }

  printf ("\n\n");
  return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : cal 月 日
指令說明 :
	   本指令可以用來顯示月曆, 例如:
	   cal 86 3
 
特別感謝:
	- wade@Fantasy.Space
	- jjchen@ice.ntnu.edu.tw

HELP
    );
    return 1;
}
