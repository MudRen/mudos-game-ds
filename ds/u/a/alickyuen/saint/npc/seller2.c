#include <ansi.h>
inherit NPC;
inherit SELLMAN;
//updated by alickyuen on /26/12

void create()
{
        set_name(HIW"���y��"NOR, ({ "Bad hunter","hunter"}));
        set("long","�A�@��L�h�N����L�b�l��,�ݰ_�Ӥ��j�͵�.......\n");
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
