#include <ansi.h>
inherit ITEM;
inherit SELLMAN;

void create()
{
        set_name(HIY"�������"NOR, ({ "equip selling machine","machine"}));
        set("long","�o�O�@������,�i�H��list�h�ݬݦ�����F�F��C\n");
        set("sell_list",([
__DIR__"obj/cloth.c" : 10,
__DIR__"obj/boots" : 10,
__DIR__"obj/armor.c" : 10,
__DIR__"obj/face.c" : 10,
__DIR__"obj/finger.c" : 10,
__DIR__"obj/hands.c" : 10,
__DIR__"obj/helmet.c" : 10,
__DIR__"obj/legging.c" : 10,
__DIR__"obj/necklace.c" : 10,
__DIR__"obj/pants.c" : 10,
__DIR__"obj/shield.c" : 10,
__DIR__"obj/surcoat.c" : 10,
__DIR__"obj/waist.c" : 10,
__DIR__"obj/wrists.c" : 10,
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

