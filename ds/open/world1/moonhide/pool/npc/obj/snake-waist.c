#include <armor.h>
#include <ansi.h> 
inherit F_UNIQUE;   
inherit WAIST;

void create()
{
        set_name(HIR"���b�a"NOR,({ "blood-snake waist","waist" }) );
        set("long","�o�O�@��u���v�����q���n�A�ǻD���������˪��\\�ΡA�O�@�󤣥i�h�o���_�ò��_�C\n");

        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("material","steel");
                set("unit", "��" );
                set("value",4000); 
                set("replica_ob",__DIR__"snake-waist2");
         }
                set("armor_prop/con",2);
                set("armor_prop/str",2);
                set("armor_prop/armor", 11);  
                set("beast_armor_prop/armor", 11);  
        setup(); 
        call_out("receive_by_waist", 60);
}

void receive_by_waist()
{
        object me; 
        int effect;

        if( !this_object() ) return;

        me = environment(this_object());

        if( !me || !interactive(me) || me->query_temp("armor/waist") != this_object() ) {
                //�S���H�ϥΤ�
                        call_out("receive_by_waist", 180); 
                        return ;
                }

        effect = me->query("max_hp");

        if( me->query("hp") < effect*3/4 )
        {
                me->receive_heal("hp", effect*1/15);
                message_vision("�@�}�ũM��"HIR"������~"NOR"�q$N"NOR"�������o�ӥX�A$N"NOR"�uı�o���W���ˤf���G¡�X���֤F�C\n"NOR, me);
                call_out("receive_by_waist", 60);
        } else {
                message_vision(CYN"$N"CYN"�����o�X�L�z�����~�A���O�èS���o�ͤ���ơC\n"NOR, this_object(), me);
                call_out("receive_by_waist", 90);
        }
}


