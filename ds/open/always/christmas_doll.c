// An example doll.c
// "undead_item" 此name請勿亂用.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"聖誕"HIW"娃娃"NOR,({"christmas doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",@LONG
一個可愛的娃娃，看不出多大年紀，留著一大把白鬍子，滿
臉紅通通的甚是溫和，身著大紅色的大衣，樣式奇特，不是這時代的衣著
，背上負著一個大紅色的袋子，看起來鼓鼓的，不知裝了啥玩意。
LONG
                );
                set("undead_msg", HIG"\n\t就在千鈞一髮之際，$N身上的$n突然變成一陣"HIW"雪花"HIG"將$N緊緊圍住！！\n\n"NOR);

setup();
}
int query_autoload() { return 1; }

