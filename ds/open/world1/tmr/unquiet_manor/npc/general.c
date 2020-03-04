#include <ansi.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
    set_name(HIC"�L��N�x"NOR, ({ "obscure general", "general", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
�L��N�x�O�λ�L����骺�D�n�H���A�֦��@����m�\�ҡA�[�W
����G�_�A�M�`�H���ڥ��N���t��������C�L��N�x�����ժZ�²r
�A��l�W����¶�V�ӹL���M�͡A�@�I�@�l�����M�ͤ]�b�������ʡC
LONG);

    set("age", 500);
    set("level",50+random(5));
    set("race","celestial");
    set("attitude", "aggressive");
        set("title",HIG"�L�����"NOR);
    /* �H���ʧ@ */
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }) );

    /* �԰��ʧ@ */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
      (: do_fight_issue :),        
      (: do_fight_help :),
    }) );
    setup();
      set_temp("apply/armor", 150);
    set_temp("apply/damage", 200);
    set_temp("apply/hit", 100);

    set_living_name("_UNQUIET_MANOR_NPC_");
    if( random(100) < 80 ) carry_object(__DIR__"obj/q_plate");
    if( random(100) < 80 ) carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/blood_meat");
        carry_object(__DIR__"obj/yellow-skin")->wear();
        carry_object(__DIR__"obj/obscure-pike")->wield();
}

