
#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�a�M�@��",({"advance guard","guard"}));
    set("attitude", "peaceful");
        set("long",@LONG
�o�O�@�Ӧb���F�q���߷�u�ê������@��, ���Ŧ��񥭱`
�u�ð��F�Ƶ�, ��M�۱i�{�פ]�󬰰��q.
LONG
    );
    set("title", "���F�q" );
    set("age",42);
    set("gender","�k��");
    set("level",27);
    set_skill("blade", 60);
    set("chat_chance", 9);
    set("chat_msg", ({
                     (: random_move :),
                         }) );

    setup();
    carry_object(__DIR__"../eq/sea_uniform")->wear();
    carry_object(__DIR__"../eq/soldier_boots")->wear();

    if ( random(30) < 2 )
        carry_object(__DIR__"../eq/white_blade")->wield();
    else if ( random(25) < 2 )
        carry_object(__DIR__"../eq/bronze_blade")->wield();
    else if ( random(20) < 2 )
        carry_object(__DIR__"../eq/sun_blade")->wield();
    else if ( random(15) < 2 )
        carry_object(__DIR__"../eq/ghost_blade")->wield();
    else if ( random(10) < 2 )
        carry_object(__DIR__"../eq/nine_blade")->wield();
    else {
        carry_object(__DIR__"../eq/steel_blade")->wield();
    }
}

