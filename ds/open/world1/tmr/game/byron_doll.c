#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("井空娃娃",({"byron death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",@LONG
一個長的很像倉(byron)的公仔，長的非常帥氣，眼神深遂
極具吸引人，不知道迷死了多少年輕少婦。
[2007/12/24 Birthday]
LONG
                );
                set("undead_msg",HIG"\n\t就在千鈞一髮之際，$N身上的$n突然衝出擋住了這致命一擊!!\n\n"NOR);

        setup();
}

