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
指令格式: newstitle [次數]  預設為30次

這個指令能讓你收聽新聞頭條，大概約15秒會播出一則新聞。

HELP
);
        return 1;
}

