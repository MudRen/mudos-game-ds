#include <ansi.h>
inherit ITEM;
inherit SELLMAN;

void create()
{
       set_name(HIY"特殊售賣機"NOR, ({ "weapon selling machine","machine"}));
        set("long","這是一部售賣機,可以打list去看看有什麼東東賣。\n");
        set("sell_list",([
__DIR__"obj/fire.c" : 1,
__DIR__"obj/boom.c"  :2,
        ]) );
set_weight(99999);
                set("no_get",1);
                set("no_sac",1);
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}


