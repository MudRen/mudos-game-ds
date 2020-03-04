#include <ansi.h>
#include <skill.h>

inherit NPC;
inherit __DIR__"inherit/do_fight_ai.c";

void create()
{
    set_name("�G�ꪺ�e��", ({ "unquiet skeleton", "skeleton", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
�o�O�@��G�ꪺ�e���A�������󳺵M�ٯਫ�ʡC�����Ŭ}����
���G����ۧA�A�@�ƭn�����A���ˤl�C		
LONG);

	set("title",HIG"�L�����"NOR);
    set("age", 23);
	set("level", 35);
    set("race","celestial");
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
    set("attitude", "aggressive");
    setup();
    set_living_name("_UNQUIET_MANOR_NPC_");
    if( random(100) < 10 ) carry_object(__DIR__"obj/q_plate");
    if( random(100) < 10 )	carry_object(__DIR__"obj/blood_meat");
}
