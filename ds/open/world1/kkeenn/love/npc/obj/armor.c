#include <armor.h>
#include <ansi.h>
inherit ARMOR;
inherit F_UNIQUE;
void create()
{
          set_name(HIR"�P��"HIC"�H�B"NOR ,({ "frame-freeze armor","armor" }) );
        set("long",@LONG        
    �o�O�@��ǻ����Z�L�Q�j�W���ݡi���j�ݩʪ��@��A�H
�n���q���¶����l�t�W�_��B�q���³��u��Ӧ��A�ϥΪ̷|
�P��@�ѷŷx������¶�A�Q���ΪA�A���ǳQ�C���Q�j�W��
�C        
LONG
);
        set_weight(8800);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("unit", "��");
                set("limit_level",15);
        }
        set("no_sac",1);
        set("no_give",1);
    set("wear_msg", "$N�����Ǭ�M�Ĭ��D�I�M���P����- $n�I\n");
    set("unequip_msg", "$N�B��_�}�F���W����خ�- $n�I\n");
        set("no_put",1);
        set("no_sell",1);
        set("monster_armor_prop/con",3);
        set("armor_prop/show_damage",1);
        set("monster_armor_prop/armor",42);
        set("monster_armor_prop/shield",18);
        set("monster_armor_prop/dodge",4);
        
        set("armor_prop/dex",3);
        set("armor_prop/con",2);
        set("armor_prop/armor",36);
        set("armor_prop/shield",8);
        setup();
        call_out("receive", 60);
        call_out("receive2", 120);
}
void receive()
{
        object me = environment(this_object());
        int p_hp;

        if( !this_object() || !me ) return;
        if( interactive(me) && me->query_temp("armor/armor") == this_object())
        {
                p_hp = me->query("max_hp");
                if( me->query("hp") < p_hp )
                {
                        me->receive_heal("hp", p_hp*5/37);
message_vision("$N"HIW"�o�X�@�D�H�N����l�A$n"HIW"���쪺�~�˦��G���ǫ�_�I\n"NOR, this_object(), me);
                }
                else
                {
  message_vision("$N"HIW"�o�X�@�D�H�N����l�A���O�S������Ƶo�͡I\n"NOR, this_object());
                }
        }
        call_out("receive", 50);
}
void receive2()
{
        object me = environment(this_object());
        int p_ap;

        if( !this_object() || !me ) return;
        if( interactive(me) && me->query_temp("armor/armor") == this_object())
        {
                p_ap = me->query("max_ap");
                if( me->query("ap") < p_ap )
                {
                        me->receive_heal("ap", p_ap*3/40);
message_vision("$N"HIR"�o�X�@�D���Ū�����A$n"HIR"���쪺���˦��G���ǫ�_�I\n"NOR, this_object(), me);
                }
                else
                {
                        message_vision("$N"HIR"�o�X�@�D���Ū�����A���O�S������Ƶo�͡I\n"NOR, this_object());
                }
        }
        call_out("receive2", 60);
}


