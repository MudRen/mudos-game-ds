// An example doll.c
// "undead_item" 此name請勿亂用.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"火鳳凰"HIW"娃娃"NOR,({"phoenix doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",@LONG
在你眼前是一個火凰鳳造型的娃娃，它身上滿是紅色的羽毛，
全身像燃燒著紅色的火焰，非常漂亮。
LONG
                );
                set("undead_msg",HIG"\n\t就在千鈞一髮之際，$N身上的$n突然化做"HIR"熊熊火焰"HIG"將$N緊緊包住！！\n\n"NOR);

setup();
}

int query_autoload() { return 1; }


