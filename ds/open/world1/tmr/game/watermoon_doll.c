#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("水雲齋娃娃",({"watermoon death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",@LONG
  一個長的很像水雲齋(watermoon)的漂亮洋娃娃。粉紅色的裙子上有著許多
白色的小圓點，充滿的神秘的靈氣...你似乎看到她在眨眼睛!? 這...
[SAVE] [ANY-TIME]
LONG
                );
                set("undead_msg",HIG"\n\t就在千鈞一髮之際，$N身上的$n突然衝出擋住了這致命一擊!!\n\n"NOR);

        setup();
}


int query_autoload() { return 1; }

