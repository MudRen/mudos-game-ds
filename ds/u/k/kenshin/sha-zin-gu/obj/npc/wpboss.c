#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("�K�K", ({ "smith" }) );
        set("gender", "�k��" );
        set("level",1);
        set("age", 22); 
        set("title",HIY"�v�騦"NOR);        set("long", 
            "�v�騦���Z���E������,ť���E�����Z�����O�W���f�A\n"            "�@�w�n�ʶR(buy)�F�~���D!!\n"                        );
        set("combat_exp", 5);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
             "�K�K��:�ӳ�!!�ڭ̽檺�Z���O�ڤۤC��̳̫K�y����!!\n",
                       }));
        set("sell_list",([      
                 __DIR__"wp/watersword"  : 30, 
                 __DIR__"wp/fireblade"   : 30, 
                 __DIR__"wp/woodaxe"     : 30, 
                 __DIR__"wp/goldwhip"    : 30,         
                 __DIR__"wp/tofist"      : 30,     
                 __DIR__"wp/bigcape"     : 30,  

        ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}

