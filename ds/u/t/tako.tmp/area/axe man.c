#include <ansi.h>
inherit NPC;
void create()
{
        set_name( MAG"巨魔"HIW"人"NOR, ({ "big-devil man ","man" }) );
        set("level",35);
        set("combat_exp",5000);
        set("exp",2000);
        set("evil",200);
        set("long","他是蚩尤的十妖之一\n"
                   "跟隨蚩尤已經非常久了\n"
                   "手持的巨人斧,威力驚人。\n"
            );
        set("age",13098);
        set("attitude","killer");
        set("gender","男性");
        set("title",YEL"十妖之 "NOR);
        set_skill("unarmed",80);
        set_skill("dodge",100);
        set_skill("parry",80);
        set_skill("axe",100);
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
(:command("hehe"):),
(:command("grin"):),   }) );
       setup();
       carry_object("/u/t/tako/axe.c")->wield();
}



