#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
       set_name(HIC"武器商人"NOR, ({ "weapon seller","seller"}));
        set("long","這是一位長期定居在情城池的武器商人(list)。\n");
        set("sell_list",([
__DIR__"obj/whip0.c" : 2,
__DIR__"obj/whip1.c" : 2,
__DIR__"obj/whip2.c" : 2,
__DIR__"obj/whip3.c" : 2,
__DIR__"obj/whip4.c" : 2,
__DIR__"obj/whip5.c" : 2,
__DIR__"obj/whip6.c" : 2,
__DIR__"obj/whip7.c" : 2,
        ]) );
                set("gender","女性");
                set("no_kill",1);
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}

