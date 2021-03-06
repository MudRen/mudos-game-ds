#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        if(!arg) {
                message_vision(HIC+me->name()+"高舉雙手 從天上降下一道閃電就打在你身前一公尺的地方！\n"NOR, me);
                return 1;
        }
        
        ob = present(arg, environment(me));
        if (!ob) return notify_fail("找不到這個生物.\n");
        if( userp(ob) ) return notify_fail("這個指令不能用在玩家身上。\n");

        message_vision("$N高舉雙手大喝 去死吧！！ 只見天上一道閃電不偏不倚地擊中$n，將之化為一堆灰燼...\n", me, ob);
        ob->set_temp("temp/death_type","[落雷擊斃]"); 
        ob->die();
        return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: smash <生物>
 
讓一個生物立刻死亡(die).

HELP
   );
   return 1;
}

