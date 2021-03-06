#include <ansi.h>
#include <skill.h>

inherit NPC;

void create()
{
    set_name("半獸人百夫長", ({ "orc hundred leader", "orc", "hundred", "leader", "_CRUSH_BONE_ORC_" }) );

    set("long", @LONG
半獸人，身體呈暗綠色，有著一張猙獰的臉，他是屬於碎骨寨的百夫長。
LONG);


    set("title", HIW"碎骨寨"NOR);
    set("gender", "male");
    set("age", 23);
        set("attack_merits", "bar");
    set("level",33+random(5));

    /* 技能設定 */
    set_skill("dodge", 100);
    set_skill("axe", 100);
    set_skill("parry", 100);
    set_skill("unarmed", 100);


    /* 人物動作 */
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }) );

    set("vendetta_mark", "_CRUSH_BONE_ORC_");
    set("attitude", "aggressive");

    setup();

    set_living_name("_CRUSH_BONE_ORC_");
        carry_object(__DIR__"obj/orc_belt")->wear();
        carry_object(__DIR__"obj/cb_boots")->wear();
         carry_object(__DIR__"obj/huge-axe")->wield();
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_skull");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_foot");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_shin_bone");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_rib");


}

