#include <armor.h>
#include <ansi.h>
inherit SHIELD;

string *wounds = ({
  "head", 
  "body",
  "right_arm",
  "left_arm",
  "right_leg",
  "left_leg",
});

void create()
{
        set_name(HIB"�g��"NOR+BLU"����"NOR, ({ "greedy_shield","shield" }) );
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long",HIC"\n���ި��m�O��ΡA�O�j�ɥN���]�j�ԯd�U�Ӫ������C\n"NOR);
                set("unit", "��");
                set("value",12000);

                set("material","gold");
                set("armor_prop/str",2);
                set("armor_prop/int",2);
                set("armor_prop/dex",2);
                set("armor_prop/con",2);
                set("armor_prop/wit",1);
                set("armor_prop/sou",-1);
                set("armor_prop/tec",-1);
                set("armor_prop/bar",-3);
                set("armor_prop/armor", 20);
                set("limit_lv",40);
                set("limit_str",50);
                set("limit_con",50); 
                set("limit_int",30);
                set("limit_dex",35);
        }
        setup(); 
        call_out("heal", 60);
}


void heal()
{
        object me = environment(this_object()); 
                int p_hp, i;

        if( !this_object() || !me ) return;
        if( interactive(me) )
        {
                p_hp = me->query("max_hp");
                if( me->query("hp") < p_hp )
                {
                        me->receive_heal("hp", p_hp*10/100);
                        for(i=0;i<sizeof(wounds);i++)
                                me->receive_curing(wounds[i], 1);

                        message_vision(HIY+me->query("name")+"�����ޤW�o�X�H�H�������A�_��F�I"+me->query("name")+"���F�W�жˡC\n"NOR, this_object(), me);
                }
                else
                {
                        message_vision(HIR+me->query("name")+"�����ޤW�o�X�H�H�������A�����G�S�o�ͥ���ƪ��ˤl�C\n"NOR, this_object()); 
                }
                
       }
        call_out("heal", 30);
}

