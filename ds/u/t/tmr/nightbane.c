#include <ansi2.h>
#include <skill.h>

inherit NPC;

void create()
{
     set_name(HBK "���s "HIR"�]��" NOR, ({ "nightbane dragon", "nightbane", "dragon", "_BLOOD_FIELD_NPC_" }) );
    set("long", @LONG
�L��ͥP�O�L����骺�D�H�A�s�b���K�ʦ~�F�A�S���H���D�L���Ӿ��C
�A�L�k�ݲM���L��ͥP�������A�ݬݥJ���I�o�~�o�{�ͥP��Ӥ��u�O�@���
���A�ӬO�ͨ��Q�@�s�����W�����α���ۡA���αK�K�³¦a�����ͨ��A�٤�
�ɺ��X����C
LONG);

    set("title", HIM"��{��D"NOR);
      set("race", "celestial");
    set("age", 800);
    set("level",60 );
    /* �԰��ʧ@ */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
//      (: do_fight_issue :),
//      (: do_fight_help :),
    }) );
    set("attitude", "aggressive");
    setup();
        set("hp",30000);
        set("max_hp",30000);
      set_temp("apply/armor", 500);
      set_temp("apply/hit", 300);
    set_temp("apply/damage",300);
    set_temp("apply/shield",300);
    set_living_name("_UNQUIET_MANOR_NPC_");
    set_temp("apply/bar", 10);
    set_temp("apply/wit", 3);   
    

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
           HIR"\n�i���S���J�j"+name()+HIG"�b�{�����ڵo�X��q�A�H�Y�Q"+HIG"�Գ��^���m"+ob->name(1)+"(" + ob->query("id") + ")�n�ʷ���ǭ��Ϸ��A���餣�A�I�I\n\n" NOR
        ,users() );
        ob->add("popularity", 4);
        tell_object(ob,HIG"�A��o���I�n��C\n"NOR);

        ::die();

        return;
}


