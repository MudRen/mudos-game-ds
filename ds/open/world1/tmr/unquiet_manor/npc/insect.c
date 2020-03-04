#include <ansi2.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
     set_name(RED "�������" NOR, ({ "bloody insect", "insect", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
������άO�إͪ��b����������ΡA�����l�m�H��A�f�̧G�������O�ˤĦy���A
���e�A���A�Q�r�������]���F�o�H�C
LONG);

    set("title", HIC"�L�����"NOR);
    set("race", "celestial");
    set("age", 2);
    set("level", 50 );
    set("addition/hp",20000);
    /* �H���ʧ@ */
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }) );

    /* �԰��ʧ@ */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
      (: do_fight_issue :),
      (: do_fight_heal :),
    }) );
    set("attitude", "aggressive");
    setup();
    set_temp("apply/hit", 300);
    set_temp("apply/shield",300);
    set_temp("apply/armor",300);
    set_living_name("_UNQUIET_MANOR_NPC_");
    set_temp("apply/bar", 5);
    set_temp("apply/wit", 3);   
    carry_object(__DIR__"obj/q_plate");
    carry_object(__DIR__"obj/q_plate");
}

