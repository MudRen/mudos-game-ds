#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name(HIW"�����N�h"NOR,({"doctor"}) );
       set("nick",HIW"���F�N�h"NOR);
        set("long","�@�W�֦����_�O�q�������H���A�ݰ�Ǧn�F�F�I\n");
        set("sell_list",([
__DIR__"obj/light-gun.c"     :10,
__DIR__"obj/light-clip.c"    : 10,
__DIR__"obj/pill.c"   :10,
__DIR__"obj/pill1.c"    :10,
        ]) );
set("age", 30);
set("level", 10);
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
