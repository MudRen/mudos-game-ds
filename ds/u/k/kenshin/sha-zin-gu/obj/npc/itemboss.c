#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("�D��ӤH", ({ "item boss","boss" }) );
        set("gender", "�k��" );
        set("level",1);
        set("age", 44); 
        set("title",HIY"�v�騦"NOR);        
        set("long", 
            "�v�騦���D���E������,ť���E�����D�㳣�O�W���f�A\n"            "�@�w�n�ʶR(buy)�F�~���D!!\n"                        );
        set("combat_exp", 5);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
             "�D��ӤH��:�ӳ�!!�ڭ̽檺�D��O�ڤۤC��̳̫K�y����!!\n",
                       }));
        set("sell_list",([    
                                                  
                 __DIR__"item/seal"      : 99,     
                 __DIR__"item/pearl"      : 99,   
                 __DIR__"item/superbag"     : 99, 
                 
                  
                                     ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}

