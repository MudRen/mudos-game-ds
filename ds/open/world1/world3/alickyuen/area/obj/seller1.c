#include <ansi.h>
inherit ITEM;
inherit SELLMAN;

void create()
{
        set_name(HIY"自動售賣機"NOR, ({ "selling machine","machine"}));
        set("long","這是一部售賣機,可以打list去看看有什麼東東賣。\n");
        set("sell_list",([
                "/open/always/newspaper" : 10,
__DIR__"water.c" : 10,
//__DIR__"water2.c" : 10,
__DIR__"pin.c" : 10,
__DIR__"rubber.c" : 10,
//__DIR__"torch.c" : 10, 改解quest
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
