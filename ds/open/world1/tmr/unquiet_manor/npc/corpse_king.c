#include <ansi2.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
     set_name(HIR "�L��ͥP" NOR, ({ "unquiet corpse-king", "king", "corpse", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
�L��ͥP�O�L����骺�D�H�A�s�b���K�ʦ~�F�A�S���H���D�L���Ӿ��C
�A�L�k�ݲM���L��ͥP�������A�ݬݥJ���I�o�~�o�{�ͥP��Ӥ��u�O�@���
���A�ӬO�ͨ��Q�@�s�����W�����α���ۡA���αK�K�³¦a�����ͨ��A�٤�
�ɺ��X����C
LONG);

    set("title", HIC"�L�����"NOR);
      set("race", "celestial");
    set("age", 800);
    set("level",60 );
    /* �԰��ʧ@ */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
      (: do_fight_issue :),
      (: do_fight_help :),
    }) );
    set("attitude", "aggressive");
    set("max_hp", 40000);

    setup();
      set_temp("apply/armor", 500);
      set_temp("apply/hit", 300);
    set_temp("apply/damage",300);
    set_temp("apply/shield",300);
    set_living_name("_UNQUIET_MANOR_NPC_");
    set_temp("apply/bar", 10);
    set_temp("apply/wit", 3);   
    
    carry_object(__DIR__"obj/q_plate");
    carry_object(__DIR__"obj/q_plate");
    carry_object(__DIR__"obj/q_plate");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/yellow-skin")->wear();
        carry_object(__DIR__"obj/pagoda-claw.c")->wield();
        if(random(100)<5)
                carry_object(__DIR__"obj/unquiet-ring")->wear();
        else
                carry_object(__DIR__"obj/unquiet-ring2")->wear();
}

void die()
{
       object ob;

        if( this_object()->query("pill") < 2 ) {
            message_vision(HIR"$N"HIR"�ͨ��W�ɮg�X�ƹD��B�A�}�[�谱�A�L��ͥP�S���F�_�ӡC\n"NOR, this_object());
            set("hp", this_object()->query("max_hp"));
            add("pill", 1);
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
           HIR"\n�i���S���J�j"+HIG"�Գ��^���m"+ob->name(1)+"(" + ob->query("id") + ")�n�O�ɤE���G�ꤧ�O�A�ש󧹥��ݷ����L��ͥP�F�I�I\n\n" NOR
        ,users() );
        ob->add("popularity", 4);
        tell_object(ob,HIG"�A��o���I�n��C\n"NOR);

        ::die();

        return;
}

