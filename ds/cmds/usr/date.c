
inherit F_CLEAN_UP;
#include <localtime.h>
#include <ansi.h>
int main(object me,string arg)
{
	mixed *local;
	string week;
//        write(sprintf("�{�b�ɨ�O�R�i%s�j�C\n",ctime(time()) ) );
        local = localtime(time());
        switch(local[LT_WDAY])
        {	
        	case 0: week=HIR+"��"; break;
        	case 1: week="�@"; break;
        	case 2: week="�G"; break;
        	case 3: week="�T"; break;
        	case 4: week="�|"; break;
        	case 5: week="��"; break;
        	case 6: week=HIR+"��"; break;
        	default: week="??"; break;
        }
	write(sprintf(HIC"�{�b�ɨ�O�R"HIM"�i"HIG"�褸%d�~%d��%d�� "HIY"�P��%s"HIW" %d[1;5m:[0m"HIW"%2d"HIM"�j"NOR"\n",
		local[LT_YEAR],local[LT_MON]+1,local[LT_MDAY],week,
		local[LT_HOUR],local[LT_MIN] ) );
        return 1;
}

int help(object me)
{
     write(@HELP
���O�榡: date

�o�ӫ��O���A(�p)���D�{�b���t�ήɶ�

HELP
    );
    return 1;
}
