#include <ansi.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
    set_name(YEL"���X�ͥP"NOR, ({ "grave demon", "demon", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
���X�ͥP���O�طL�ͪ��A�H�覺�`�����鬰�J�D�A�s�E�b�ͨ��ͦs�C
LONG);

    set("age", 500);
    set("level",45+random(5));
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
        (: do_fight_heal :),        
      (: do_fight_help :),
    }) );
    setup();
    set_temp("apply/armor", 200);
    set_temp("apply/bar", 3);
    set_living_name("_UNQUIET_MANOR_NPC_");
    if( random(100) < 50 ) carry_object(__DIR__"obj/q_plate");
    if( random(100) < 50 ) carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/blood_meat");
        carry_object(__DIR__"obj/yellow-skin")->wear();
        if(random(100)<50)
                carry_object(__DIR__"obj/yellow-staff")->wield();
        else
                carry_object(__DIR__"obj/yellow-whip")->wield();
}

