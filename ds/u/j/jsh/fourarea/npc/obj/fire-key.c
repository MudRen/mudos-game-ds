#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"火燄"HIW"之鑰"NOR,({"key of fire","key"}));
        set("long",@long
從火元素身上掉下來的一把鑰匙，聽祭司講，似乎有特別的功用。
long
                );

        set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "支");
                set("door","firekey");
                set("value", 1);
        }
        setup();
}

