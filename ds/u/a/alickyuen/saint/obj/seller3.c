#include <ansi.h>
inherit ITEM;
inherit SELLMAN;

void create()
{
        set_name(HIY"�������"NOR, ({ "selling machine","machine"}));
        set("long","�o�O�@������,�i�H��list�h�ݬݦ�����F�F��C\n");
        set("sell_list",([
                "/open/always/newspaper" : 10,
__DIR__"eq/ecloth.c" : 10,
__DIR__"eq/mboots" : 10,
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
