#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
     set_name( HIR"�]�C"HIW"-"NOR"�����W"NOR,({"tyrfing sword","sword"}) );
     set("long", "�_�گ��ܤ����]�C�A�]½Ķ���u�ٵ��C�v�C�O�@��X�T�N�o�l��A���M�|�a����\n"
                 "���̤j�q�a���A���]�|�ϫ����C�̳��J�������@�`�]�C�C\n");
     set_weight(12000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("unit", "��");             
            set("value", 6000);
            set("material","gold"); 
          }         
     set("limit_str",70);
     set("limit_level",40);
     set("weapon_prop/con", 1);
     set("weapon_prop/dex", 3);
     init_sword(70);
     setup();
}
void attack(object me,object victim)
{
     object ob = this_object();
     ::attack();
     if(!me || !victim || me->is_busy()) return;
     
     if( userp(me) ) me->receive_damage("hp", 20);
     tell_object(me, "�A���W�y�ʪ���G���b�C�C�a�Q"+ob->query("name")+"�l�������C\n");
     COMBAT_D->do_attack(me, victim, this_object(), random(5));
     COMBAT_D->report_statue(victim);  
     return;
}

