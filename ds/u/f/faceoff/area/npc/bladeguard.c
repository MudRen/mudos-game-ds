#include <ansi.h>
inherit NPC;
void create()
{
 int x;
      x = random(23);
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
 carry_object(__DIR__"eq/soldier_boots")->wear();
   if (x == 1 || x == 2)
	{
carry_object(__DIR__"eq/white_blade")->wield();
	}
    if (x == 3)
	{
carry_object(__DIR__"eq/bronze_blade")->wield();
	}
 if (x == 4)
	{
carry_object(__DIR__"eq/sun_blade")->wield();
	}
 if (x == 5)
	{
carry_object(__DIR__"eq/ghost_blade")->wield();
	}
 if (x == 6)
	{
carry_object(__DIR__"eq/nine_blade")->wield();
	}
else
	{
carry_object(__DIR__"eq/steel_blade")->wield();
}
}
