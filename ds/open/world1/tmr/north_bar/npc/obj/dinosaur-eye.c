#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("龍眼",({"longan"}));
        set_weight(500);
                set("value", 100);
                set("unit","粒");
                set("long",@LONG
這是一粒香甜好吃的龍眼。
LONG);
setup();
}
