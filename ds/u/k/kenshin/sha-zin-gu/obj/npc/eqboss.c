#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("�ӤH", ({ "boss" }) );
        set("gender", "�k��" );
        set("level",1);
        set("age", 22); 
        set("title",HIY"�v�騦"NOR);        set("long", 
            "�v�騦�������E���k����,ť���E�������㳣�O�W���f�A\n"            "�@�w�n�ʶR(buy)�F�~���D!!\n"                        );
        set("combat_exp", 5);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
             "�K�K��:�ӳ�!!�ڭ̽檺����O�ڤۤC��̳̫K�y����!!\n",
                       }));
        set("sell_list",([    
                                                  
                 __DIR__"eq/mask"      : 30,     
                 __DIR__"eq/boots"      : 30,   
                 __DIR__"eq/waist"     : 30, 
                 __DIR__"eq/surcoat"     : 30,  
                  
                                     ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}

