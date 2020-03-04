#include <ansi.h>
inherit NPC;
void create()
{
 set_name("帶刀護衛",({"advance guard","guard"}));
 set("long",@LONG
這是一個在海政司中心當守衛的高等護衛, 階級有比平常
守衛高了數等, 當然囂張程度也更為高段.
LONG
    );
 set("attitude", "peaceful");
 set("nickname",HIG"海政司"NOR);
 set("age",42);
 set("gender","男性");
 set("level",27);
 set_skill("blade", 60);
 set("chat_chance", 9);
 set("chat_msg", ({
           (: random_move :),
        }) );

 setup();
 carry_object(__DIR__"eq/sea_uniform")->wear();
 carry_object(__DIR__"eq/steel_blade")->wield();
 carry_object(__DIR__"eq/soldier_boots")->wear();
}
