#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FIST;

void create()
{
    set_name(HIR"�E����"NOR,({"nine-fox claw","claw"}) );
    set("long","�E�������l�A���ˤO�D�`�j�A�ǻ��u�n�t�W�o�����l�A
�s���|�Z�\\�����`�H�]�i�H�ܦ��^���C\n");
        set_weight(10000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
        set("value",50000); 
        set("material","gold"); 
        set("replica_ob",__DIR__"fist3");
        }
        set("wield_msg",
         HIW "$N����M�W$n"HIW+"�A�n��$N�����g�X����⪺����A�O�H���ѱo�h�F�G�B�C\n"
         NOR);
        set("limit_level",45);
        set("limit_str",70);
        set("weapon_prop/dex", 4);
        set("weapon_prop/int", -2);
        set("weapon_prop/str", 3);
        set("weapon_prop/bar", 2);
        set("weapon_prop/wit", -1);
        set("weapon_prop/sou", -1);
        init_fist(53+random(7));  //�o�򰪷F��
        setup();
}
void init()
{ 
   add_action("check","wield"); 
   add_action("check","wi");
} 

int check(string arg)
{ 
   object me;
   me = this_player();
    if( me->query("MKS") < 30000)        { 
       message_vision("�A�����𤣰��S��k�˳Ƴo�ӪF��E\n",me);
       }
    else return ::wield(me,arg);
}

void attack(object me,object victim)
{
  object ob = this_object();      
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(10)) return; // 1/10 �����v�S��
message_vision(HIR"\n�E�����O�q���q�q$n"HIR"������F�X�ӡI�I\n"+
                  "\n$N�l���F�E�����O�q�A�g�ɤF�_�ӡI�I\n"NOR,me,ob); 
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);   
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);  
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);  
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);  
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);  
        return; 
}

