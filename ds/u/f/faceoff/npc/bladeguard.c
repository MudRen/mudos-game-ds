#include <ansi.h>
inherit NPC;
void create()
{
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
 carry_object(__DIR__"eq/steel_blade")->wield();
 carry_object(__DIR__"eq/soldier_boots")->wear();
}
