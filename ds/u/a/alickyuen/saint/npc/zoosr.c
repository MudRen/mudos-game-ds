//updated
#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name(HIW"�l��"NOR, ({ "Bad seller","seller"}));
        set("long","�A�@��L�h�N����L�b�l��,�ݰ_�Ӥ��j�͵�.......\n");
        set("sell_list",([
__DIR__"obj/ticket" : 10,
        ]) );
set("age", 30);
set("level", 10);
        set("chat_chance", 6);
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
