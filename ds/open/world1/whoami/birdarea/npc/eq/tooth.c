#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FORK;
void create()
{
     set_name( HIW"�E"HIY"��"NOR"����"HIR"�m�j�n"NOR,({"nine tail tooth","tooth","pike"}) );
     set_weight(12000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","�E���������A�����o�X�ǳ\\�����O�A���G�i�H���ܦ��O�تZ���E\n"
                  +"( change <type>, ex: change sword )\n"
                  +"( type : pike sword blade dagger staff)\n");
            set("unit", "��");             
            set("value",11000);
            set("material","gold"); 
            set("replica_ob",__DIR__"tooth1");
           }         
        set("limit_str",20);
        set("limit_level",40);
        set("weapon_prop/str",3);
        set("weapon_prop/con",1);
        set("weapon_prop/int",-2);
        set("weapon_prop/dex",-1);
        set("weapon_prop/bar",1);
        set("weapon_prop/tec",-1);
        set("weapon_prop/hit",15);
        init_fork(73);
        setup();
}
void init()
{
    add_action("do_change","change");
}
int do_change(string str)
{ 
   object ob = this_object();   if( ob->query("equipped") )
   return notify_fail("�Х��Ѱ��˳ơC\n"); 
   switch(str)
   {
     case "staff":
           set("skill_type", "staff");
set_name(HIW"�E"HIY"��"NOR"����"HIY"�m���n"NOR,({"nine tail tooth","tooth","staff"}));
write(HIW"�E"HIY"��"NOR"���������𺥺����o�ͤF�ܤơK�K�K\n"
HIW"�E"HIY"��"NOR"�����ܤƦ�"HIY"����"NOR"�F�E\n");
           set("weapon_prop/str",1);
           set("weapon_prop/con",3);
           set("weapon_prop/int",3);
           set("weapon_prop/dex",-3);
           
           set("weapon_prop/bar",0);
           set("weapon_prop/tec",-1);
           set("weapon_prop/sou",-1);
           set("weapon_prop/bio",1);
           set("weapon_prop/wit",1);
           
           set("weapon_prop/hit",15);
           break;
     case "sword":
           set("skill_type", "sword");
set_name(HIW"�E"HIY"��"NOR"����"HIG"�m�C�n"NOR,({"nine tail tooth","tooth","sword"}));  
write(HIW"�E"HIY"��"NOR"���������𺥺����o�ͤF�ܤơK�K�K\n"
HIW"�E"HIY"��"NOR"�����ܤƦ�"HIG"�C��"NOR"�F�E\n");
           set("weapon_prop/str",-2);
           set("weapon_prop/con",2);
           set("weapon_prop/int",-1);
           set("weapon_prop/dex",1);
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",0);
           set("weapon_prop/sou",0);
           set("weapon_prop/bio",1);
           set("weapon_prop/wit",-2);
           
           set("weapon_prop/hit",0);
           break;
     case "blade":
           set("skill_type", "blade");
set_name(HIW"�E"HIY"��"NOR"����"HIC"�m�M�n"NOR,({"nine tail tooth","tooth","blade"}));  
write(HIW"�E"HIY"��"NOR"���������𺥺����o�ͤF�ܤơK�K�K\n"
HIW"�E"HIY"��"NOR"�����ܤƦ�"HIC"�M��"NOR"�F�E\n");
           set("weapon_prop/str",2);
           set("weapon_prop/con",4);
           set("weapon_prop/int",-1);
           set("weapon_prop/dex",-2);
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",0);
           set("weapon_prop/sou",-1);
           set("weapon_prop/bio",0);
           set("weapon_prop/wit",0);

           set("weapon_prop/hit",10); 
           break;
     case "dagger":
           set("skill_type", "dagger");
set_name(HIW"�E"HIY"��"NOR"����"HIW"�m�P�n"NOR,({"nine tail tooth","tooth","dagger"}));  
write(HIW"�E"HIY"��"NOR"���������𺥺����o�ͤF�ܤơK�K�K\n"
HIW"�E"HIY"��"NOR"�����ܤƦ�"HIW"�P��"NOR"�F�E\n");
           set("weapon_prop/str",3);
           set("weapon_prop/con",-2);
           set("weapon_prop/int",-2);
           set("weapon_prop/dex",3);
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",-2);
           set("weapon_prop/sou",0);
           set("weapon_prop/bio",1);
           set("weapon_prop/wit",0);
           
           set("weapon_prop/hit",11); 
           break;
     case "pike":
           set("skill_type", "fork");
set_name(HIW"�E"HIY"��"NOR"����"HIR"�m�j�n"NOR,({"nine tail tooth","tooth","pike"}));  
write(HIW"�E"HIY"��"NOR"���������𺥺����o�ͤF�ܤơK�K�K\n"
HIW"�E"HIY"��"NOR"�����ܤƦ�"HIR"�j��"NOR"�F�E\n");
           set("weapon_prop/str",3);
           set("weapon_prop/con",1);
           set("weapon_prop/int",-2);
           set("weapon_prop/dex",-1);
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",-1);
           set("weapon_prop/sou",0);
           set("weapon_prop/bio",0);
           set("weapon_prop/wit",0);
           
           set("weapon_prop/hit",15);
           break;
     default:      
           write("�E�������S���o�اκA�I\n");
   }
     return 1;
}

void attack(object me,object victim)
{
  object ob = this_object();      
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(4)) return; // 1/4 �����v�S��
        message_vision("$N"HIY"�⤤��$n"HIY"���X�j�q��"NOR+MAG"����"HIY"�K�K�K\n"NOR,me,ob);
        COMBAT_D->do_attack(me, victim, this_object(), random(5));
        COMBAT_D->report_statue(victim);  
        victim->add_busy(1); 
        me->add_busy(2);
        if( me->query("ap") > 300 ){
           switch( random(9) ){
           case 0..3: 
            message_vision("\n$N"HIR"��W��$n"HIR"�����F�ͩR�몺�ʤF�_�ӡI�I\n\n"NOR,me,ob);
            COMBAT_D->do_attack(me, victim, this_object(), random(5));
            COMBAT_D->report_statue(victim); 
            COMBAT_D->do_attack(me, victim, this_object(), 4);
            COMBAT_D->report_statue(victim); 
            COMBAT_D->do_attack(me, victim, this_object(), random(5));
            COMBAT_D->report_statue(victim);
            victim->add_busy(1);
           break; 
           default:
            message_vision(HIB"\n��M$n"HIB"����j���A$N�L�k����⤤��$n"HIB"�A�ۦ�����ı���@���K�K�K\n"NOR,me,ob);
            me->receive_damage("hp",random(200));
            me->start_busy(2);
           break;
           }
        } else {
         message_vision(HIB"\n��M$n"HIB"����j���A$N�L�k����⤤��$n"HIB"�A�ۦ�����ı���@���K�K�K\n"NOR,me,ob);
         me->receive_damage("hp",random(200));
         me->start_busy(2);
        }
        me->receive_damage("ap",random(50));
        return;
}

int can_stab()
{
    if( query("skill_type")=="dagger" ) return 1;
    else return 0;
}
