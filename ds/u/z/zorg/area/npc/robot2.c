#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name( "�^�d��", ({ "Kang Wei Ping","ping","kang","wei"}));
        set("long", "He is a robot seller,you can buy things from him.�C\n");
        set("level",5);
        set("title",HIW"�i"HIG"�����H"HIR"����"HIC"����"HIW"�j"NOR);
        set("gender", "�k��");
        set("race", "�����H");
        set("age", 40);
        set("combat_exp",400);      
        set("evil",-20);     
        set_skill("unarmed",20);       
        set_skill("parry",10);      
        set_skill("dodge",14);        
   set("attitude", "peaceful"); 
   set("talk_reply","WEll!!That one is really good, if you want to buy it I can sell you in 20 precent!!");
  set("storeroom",__DIR__"wp"); //�`�N. �n�إߤ@��room��F��??????
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










