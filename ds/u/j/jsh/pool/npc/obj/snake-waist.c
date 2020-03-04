#include <armor.h>
#include <ansi.h> 
inherit F_UNIQUE;   
inherit WAIST;
void create()
{
        set_name(HIR"���b�a"NOR,({ "blood-snake waist","waist" }) );
        set("long","��몺���q���n�A���U����\\�ΡC\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","steel");
        set("unit", "��" );
        set("value",4000);
        set("armor_prop/armor", 11);  
        set("replica_ob",__DIR__"snake-waist2");
         }
        setup(); 
        call_out("receive_by_waist", 60);
}
void receive_by_waist()
{

        object me = environment(this_object());
        int x, i;

        if( !this_object() || !me ) return;
        if( interactive(me) )
        {
                x = me->query("max_hp");
                if( me->query("hp") < x )
                {
                        me->receive_heal("hp", x*1/35);
                        message_vision(HIR"$n���M��������A�򴲦b$n���P��I\n"NOR, this_object(), me);
                }
                else
                {
                        message_vision(HIR"$N�o�X�@�����������A���èS����Ӥj���ܤơI\n"NOR, this_object());
                }
        }
        call_out("receive_by_waist", 30);
}

