
#include <ansi.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
    set_name("�b�~�H�x�Ϊ�", ({ "orc regimental commander", "orc", "regimental", "commander", "_CRUSH_BONE_ORC_" }) );

    set("long", @LONG
�b�~�H�A����e�t���A���ۤ@�i�u���y�A�L�O�ݩ�H���몺�x�Ϊ��C
LONG);

    set("title", HIW"�H����"NOR);
    set("gender", "male");
    set("age", 23);
        set("attack_merits", "bar");
      set("level",45 + random(5) );

    /* �ޯ�]�w */
    set_skill("dodge", 100);
    set_skill("axe", 100);
    set_skill("parry", 100);
    set_skill("unarmed", 100);


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

    set("vendetta_mark", "_CRUSH_BONE_ORC_");
    set("attitude", "aggressive");

    setup();
	set_temp("apply/armor",150);
	set_temp("apply/damage",150);
	set_temp("apply/shield",150);

    set_living_name("_CRUSH_BONE_ORC_");
    carry_object(__DIR__"obj/orc_belt")->wear();
    carry_object(__DIR__"obj/cb_boots")->wear();
    carry_object(__DIR__"obj/army_helmet")->wear();
    carry_object(__DIR__"obj/wristlet")->wear();
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_skull");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_rib");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_foot");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_shin_bone");
}

