#include <ansi.h>
inherit NPC;
inherit SELLMAN;
//updated by alickyuen on /26/12

void create()
{
        set_name(HIW"偷獵者"NOR, ({ "Bad hunter","hunter"}));
        set("long","你一望過去就見到他在奸笑,看起來不大友善.......\n");
        set("sell_list",([
__DIR__"wildanimal.c" : 1,
        ]) );
set("age", 30);
set("level", 10);
        set("chat_chance", 6);
set("chat_msg", ({
  //              (: this_object(), "random_move" :),
}) );
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
