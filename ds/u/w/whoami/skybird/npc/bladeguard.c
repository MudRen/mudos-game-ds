#include <ansi.h>
inherit NPC;
void create()
{
 int x;
      x = random(23);
 set_name("�a�M�@��",({"advance guard","guard"}));
 set("long",@LONG
�o�O�@�Ӧb���F�q���߷�u�ê������@��, ���Ŧ��񥭱`
�u�ð��F�Ƶ�, ��M�۱i�{�פ]�󬰰��q.
LONG
    );
 set("attitude", "peaceful");
 set("nickname",HIG"���F�q"NOR);
 set("age",42);
 set("gender","�k��");
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
