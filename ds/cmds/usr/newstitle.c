#include <ansi.h>

void create() { seteuid(getuid()); }

int main(object me, string str)
{
        int times;
    if(!str) times = 30;
    else if(sscanf(str, "%d",times) != 1) times = 30;
        if(times<1) times = 1;

        me->apply_condition("news_listing",times);
        write("Ok!\n");
        return 1;
}

int help(object me)
{
        write(@HELP
���O�榡: newstitle [����]  �w�]��30��

�o�ӫ��O�����A��ť�s�D�Y���A�j����15��|���X�@�h�s�D�C

HELP
);
        return 1;
}

