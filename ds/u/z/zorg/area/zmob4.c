#include <ansi.h>
inherit NPC;

void create()
{
        set_name( HIY "Zorg-Mob 4" NOR , ({"zorgmob4", "zmob4","zorgmob4","zorg-mob4" }) );
        set("long", ""HIY"What you can see is a mob."NOR"！\n");
        set("race", "人類");
        set("gender", "女性"); 
        set("exp",999999);         set("age", 100);
        set("attitude", "killer");
        set("level", 50);
        set("str", 150);
        set("con", 100);
        set("int", 20);
        set("dex", 20);
        set("evil", 999);
        set("combat_exp",5000);
        set_skill("sword", 50);
        set_skill("sorgi_sword", 100); 
        set_skill("unarmed", 700);
        set("title",HIW"【"HIG"Zorg's "HIR"Forth "HIC"Mob"HIW"】"NOR);
        set_skill("bagi_fist", 100);
        set_skill("mirage-steps", 100);
        set_skill("dodge", 50);
        set_skill("parry", 50);  
        set("chat_chance", 3 );  
        set("chat_msg", ({   
        (: this_object(), "random_move" :),     //會自己走動 
}) );
        set("chat_chance_combat",170);
        set("chat_msg_combat", ({ 
        (:command("exert bagi_fist"):),
        (:command("exert sorgi_sword"):),
        (:command("unwield sword"):),
        (:command("exert bagi_fist"):),
        (:command("exert sorgi_sword"):),
        (:command("unwield sword;exert bagi_fist"):),
        (:command("exert bagi_fist"):),
        (:command("wield sword"):),
        (:command("exert sorgi_sword"):),
        (:command("exert mirage-steps"):),
         }) );
       setup(); 
      add_money("dollar", 500);           //帶的錢
      carry_object("u/z/zorg/test/lightsaber.c");
   
}







