#include <ansi2.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
     set_name("半獸人皇帝", ({ "orc emperor", "orc", "emperor", "_CRUSH_BONE_ORC_" , "_ORC_EMPEROR_" }) );

    set("long", @LONG
半獸人，身體呈暗綠色，有著一張猙獰的臉，他是屬於碎骨寨的皇帝。
LONG);

    set("title", HIW"碎骨寨"NOR);
    set("gender", "male");
    set("age", 23);
      set("level",55 );
        set("attack_merits", "bar");

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

    /* 戰鬥動作 */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
      (: do_fight_issue :),
      (: do_fight_help :),
    }) );

    set("vendetta_mark", "_CRUSH_BONE_ORC_");
    set("attitude", "aggressive");
      set("max_hp", 40000);

    setup();
        set_temp("apply/armor",300);
        set_temp("apply/damage",300);
        set_temp("apply/shield",300);

    set_living_name("_CRUSH_BONE_EMPEROR_");
    carry_object(__DIR__"obj/orc_belt")->wear();
    carry_object(__DIR__"obj/cb_boots")->wear();
    carry_object(__DIR__"obj/cb_necklace")->wear();
    carry_object(__DIR__"obj/cb_axe");
    carry_object(__DIR__"obj/cb_cloak")->wear();
      carry_object(__DIR__"obj/pith");
      carry_object(__DIR__"obj/pith");

    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_skull");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_rib");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_shin_bone");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_foot");
    if( random(100) < 70 ) carry_object(__DIR__"obj/orc_blood");
}

void die()
{
       object ob;

        if( this_object()->query("pill") < 2 ) {
            message_vision(HIG"$N快速的在跨下挫來挫去，挫出了一顆「伸腳瞪眼丸」趕緊吞了下去。\n"NOR, this_object());
            this_object()->set("hp", this_object()->query("max_hp"));
            this_object()->add("pill", 1);
            return;
        }


        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

                message("world:world1:vision",
                HIR"\n【奧特蘭克】"+HIG"戰場英雄《"+ob->name(1)+"(" + ob->query("id") + ")》在千軍萬馬、刀血劍雨之中，硬是取下碎骨皇帝的首級了！！\n\n" NOR
        ,users() );

        ob->add("popularity", 4);
        tell_object(ob,HIG"你獲得４點聲望。\n"NOR);

        ::die();

        return;
}

