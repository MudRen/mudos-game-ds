#include <ansi.h>
inherit NPC;

void create()
{
        set_name( HIY "Zorg-Mob" NOR , ({"zorgmob", "zmob","zorgmob","zorg-mob" }) );
        set("long", ""HIY"What you can see is a mob."NOR"�I\n");
        set("race", "�H��");
        set("gender", "�k��"); 
        set("exp",999999);         set("age", 50);
        set("attitude", "friendly");
        set("level", 20);
        set("evil", 999);
        set("combat_exp",5000);
        set_skill("sword", 70);
        set_skill("thundersword", 70); 
        set_skill("blade", 10);
        set_skill("unarmed", 10);
        set("title",HIW"�i"HIG"Zorg's "HIR"First "HIC"Mob"HIW"�j"NOR);
        set_skill("mirage-steps", 100);
        set_skill("dodge", 70);
        set_skill("parry", 50);  
        set("chat_chance", 9 );  
        set("chat_msg", ({   
        (: this_object(), "random_move" :),     //�|�ۤv���� 
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command("exert thundersword"):),
        (:command("exert mirage-steps"):),
        (:command("cac"):),
        }) );
        setup(); 
      add_money("dollar", 500);           //�a����
      carry_object(__DIR__"lightsaber.c")->wield();
    
}



