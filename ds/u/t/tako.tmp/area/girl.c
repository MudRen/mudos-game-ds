#include <ansi.h>
inherit NPC;
void create()
{
        set_name( MAG"幽遊女"HIW"人"NOR, ({ "trip girl ","girl" }) );
        set("level",40);
        set("combat_exp",6000);
        set("exp",3124);
        set("evil",200);
        set("long","他是蚩尤的十妖之一\n"
                   "跟隨蚩尤已經非常久了\n"
                   "形蹤飄浮不定,是拿手的計兩。\n"
            );
        set("age",16081);
        set("attitude","killer");
        set("gender","女性");
        set("title",YEL"十妖之 "NOR);
        set_skill("unarmed",100);
        set_skill("dodge",160);
        set_skill("parry",80);
        set_skill("combat",100);
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
(:command("help!"):),
(:command("hehe"):), 
  }) );
       setup();
       carry_object("/u/t/tako/cloth.c")->wear();
}




