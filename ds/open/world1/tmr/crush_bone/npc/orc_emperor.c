#include <ansi2.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
     set_name("�b�~�H�ӫ�", ({ "orc emperor", "orc", "emperor", "_CRUSH_BONE_ORC_" , "_ORC_EMPEROR_" }) );

    set("long", @LONG
�b�~�H�A����e�t���A���ۤ@�i�u���y�A�L�O�ݩ�H���몺�ӫҡC
LONG);

    set("title", HIW"�H����"NOR);
    set("gender", "male");
    set("age", 23);
      set("level",55 );
        set("attack_merits", "bar");

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
            message_vision(HIG"$N�ֳt���b��U���Ӯ��h�A���X�F�@���u���}�����Y�v����]�F�U�h�C\n"NOR, this_object());
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
                HIR"\n�i���S���J�j"+HIG"�Գ��^���m"+ob->name(1)+"(" + ob->query("id") + ")�n�b�d�x�U���B�M��C�B�����A�w�O���U�H���ӫҪ����ŤF�I�I\n\n" NOR
        ,users() );

        ob->add("popularity", 4);
        tell_object(ob,HIG"�A��o���I�n��C\n"NOR);

        ::die();

        return;
}

