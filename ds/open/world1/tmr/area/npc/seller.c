#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("�p�ĳc", ({ "seller" }) );
        set("gender", "�k��" );
        set("age", 22);
        set("long","�o���ĳc�����}�}�a���۾�z�Ľc�A�٤��ɮ��_���b��l�W���٥����y�C\n");
        set("level",1);
        set("attitude", "friendly");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "�p�ĳc�����F��S�A���F���y�W�����C\n",
                "�p�ĳc���n�۹D�G�u���~���ֻI�ġA�ΤW�n�Ѫ��ֻs���A�O�����ġ��v\n" 
        }) );

        set("sell_list",([
        __DIR__"obj/plaster" : 5,
         __DIR__"obj/pill3" : 5,
        TMR_PAST"bagi/npc/obj/furnace":  1,
        TMR_PAST"bagi/npc/obj/firewood": 1,
          TMR_PAST"bagi/npc/obj/firewood2": 1,
            TMR_PAST"bagi/npc/obj/firewood1": 1,
        TMR_PAST"bagi/npc/obj/roxb": 1,
        TMR_PAST"bagi/npc/obj/benth": 1,
        TMR_PAST"bagi/npc/obj/linn": 1,
        ]) );
        setup();
}

void init()
{
           add_action("do_list","list");
           add_action("do_buy","buy");
}

