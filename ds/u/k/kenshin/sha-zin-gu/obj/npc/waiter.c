#include <path.h>
#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("���p�G", ({ "waiter ccr","waiter","ccr" }) );
        set("gender", "�k��" );
        set("age", 200);
        set("long","DS���Ѱ��ǥN���@�A�]��Kenshin�L��A�Q���o�ӷ��p�G..XD\n");
        set("level",100);
        set("attitude", "friendly");
        set("title",HIW"[DS�`�n���aNPC�N���@]"NOR);
        set("rank_info/respect", "���Ǥp�G");
        set("sell_list",([
                 __DIR__"item/kaoliang" : 30,
                 __DIR__"item/white-wine" :30,
                 __DIR__"item/s_wine" :30,
                 __DIR__"item/leg" :100,
        ]) );
        setup();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy");
}

