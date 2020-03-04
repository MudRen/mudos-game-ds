
inherit F_CLEAN_UP;
#include <localtime.h>
#include <ansi.h>
int main(object me,string arg)
{
	mixed *local;
	string week;
//        write(sprintf("現在時刻是﹕【%s】。\n",ctime(time()) ) );
        local = localtime(time());
        switch(local[LT_WDAY])
        {	
        	case 0: week=HIR+"日"; break;
        	case 1: week="一"; break;
        	case 2: week="二"; break;
        	case 3: week="三"; break;
        	case 4: week="四"; break;
        	case 5: week="五"; break;
        	case 6: week=HIR+"六"; break;
        	default: week="??"; break;
        }
	write(sprintf(HIC"現在時刻是﹕"HIM"【"HIG"西元%d年%d月%d日 "HIY"星期%s"HIW" %d[1;5m:[0m"HIW"%2d"HIM"】"NOR"\n",
		local[LT_YEAR],local[LT_MON]+1,local[LT_MDAY],week,
		local[LT_HOUR],local[LT_MIN] ) );
        return 1;
}

int help(object me)
{
     write(@HELP
指令格式: date

這個指令讓你(妳)知道現在的系統時間

HELP
    );
    return 1;
}
