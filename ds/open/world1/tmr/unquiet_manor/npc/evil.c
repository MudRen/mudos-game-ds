#include <ansi.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
    set_name("��y", ({ "evil spirit", "spirit", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
��y�A�Y��ǡA�ǻ����ѫh���y�A�ӥB�ٷ|�[�`��H�C�`��������y
����y�Τs���A�]�������Ϊ��W���~�Ѥ]�|����C
LONG);

    set("age", 500);
    set("level",35+random(5));
	set("title",HIG"�L�����"NOR);
    set("race","celestial");
    set("attitude", "aggressive");

    /* �H���ʧ@ */
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }) );

    /* �԰��ʧ@ */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
      (: do_fight_issue :),        
    }) );


    setup();
    set_living_name("_UNQUIET_MANOR_NPC_");
    if( random(100) < 30 ) carry_object(__DIR__"obj/q_plate");
    if( random(100) < 30 ) carry_object(__DIR__"obj/q_stone");
    if( random(100) < 50 )	carry_object(__DIR__"obj/blood_meat");
	if(random(100)<50)
		carry_object(__DIR__"obj/yellow-staff")->wield();
	else
		carry_object(__DIR__"obj/yellow-whip")->wield();
}

