#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name( "彭康偉", ({ "Kang Wei Ping","ping","kang","wei"}));
        set("long", "He is a robot seller,you can buy things from him.。\n");
        set("level",5);
        set("title",HIW"【"HIG"機器人"HIR"老闆"HIC"偉偉"HIW"】"NOR);
        set("gender", "男性");
        set("race", "機器人");
        set("age", 40);
        set("combat_exp",400);      
        set("evil",-20);     
        set_skill("unarmed",20);       
        set_skill("parry",10);      
        set_skill("dodge",14);        
   set("attitude", "peaceful"); 
   set("talk_reply","WEll!!That one is really good, if you want to buy it I can sell you in 20 precent!!");
  set("storeroom",__DIR__"wp"); //注意. 要建立一個room放東西??????
  set("chat_chance", 13 ); 
  set("chat_msg", ({       
(:command("smile   + RANK_D->query_respect(ob) +"):),
}) );
        setup();
}
void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}










