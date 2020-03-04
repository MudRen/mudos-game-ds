#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
     set_name( HIW"�E"HIY"��"NOR"�����m�j�n"NOR,({"nine tail tooth","tooth","pike"}) );
     set_weight(12000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","�E���������A�����o�X�ǳ\\�����O�A���G�i�H���ܦ��O�تZ���E\n"
                  +"( change <type>, ex: change sword )\n"
                  +"( type : pike sword blade dagger staff)\n");
            set("unit", "��");             
            set("value",6500);
            set("material","gold"); 
           }         
        set("limit_str",30);
        set("limit_level",40); 
        set("weapon_prop/str",3); 
        set("weapon_prop/bar",1);
        set("weapon_prop/tec",-1);
        init_fork(55);
        setup();
}
void init()
{
    add_action("do_change","change");
}
int do_change(string str)
{
   object ob = this_object();
   if( ob->query("equipped") )
   return notify_fail("�Х��Ѱ��˳ơC\n"); 
   switch(str)
   {
     case "staff":
           set("skill_type", "staff");
set_name(HIW"�E"HIY"��"NOR"�����m���n"NOR,({"nine tail tooth","tooth","staff"}));
write(HIW"�E"HIY"��"NOR"���������𺥺����o�ͤF�ܤơE�E�E\n"
HIW"�E"HIY"��"NOR"�����ܤƦ�"HIY"����"NOR"�F�E\n");
           set("weapon_prop/str",0); 
           set("weapon_prop/con",0); 
           set("weapon_prop/int",3); 
           set("weapon_prop/dex",-2); 
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",-1);
           set("weapon_prop/wit",0);
           set("weapon_prop/bio",0);
           set("weapon_prop/sou",0);
           break;
     case "sword":
           set("skill_type", "sword");
set_name(HIW"�E"HIY"��"NOR"�����m�C�n"NOR,({"nine tail tooth","tooth","sword"}));  
write(HIW"�E"HIY"��"NOR"���������𺥺����o�ͤF�ܤơE�E�E\n"
HIW"�E"HIY"��"NOR"�����ܤƦ�"HIG"�C��"NOR"�F�E\n");
           set("weapon_prop/str",-1); 
           set("weapon_prop/con",2); 
           set("weapon_prop/int",3); 
           set("weapon_prop/dex",-2); 
           
           set("weapon_prop/bar",-1);
           set("weapon_prop/tec",0);
           set("weapon_prop/wit",1);
           set("weapon_prop/bio",0);
           set("weapon_prop/sou",0);
           break;
     case "blade":
           set("skill_type", "blade");
set_name(HIW"�E"HIY"��"NOR"�����m�M�n"NOR,({"nine tail tooth","tooth","blade"}));  
write(HIW"�E"HIY"��"NOR"���������𺥺����o�ͤF�ܤơE�E�E\n"
HIW"�E"HIY"��"NOR"�����ܤƦ�"HIC"�M��"NOR"�F�E\n");
           set("weapon_prop/str",1); 
           set("weapon_prop/con",-2); 
           set("weapon_prop/int",0); 
           set("weapon_prop/dex",0); 

           set("weapon_prop/bar",1);
           set("weapon_prop/tec",0);
           set("weapon_prop/wit",-1);
           set("weapon_prop/bio",1);
           set("weapon_prop/sou",-1);

           break;
     case "dagger":
           set("skill_type", "dagger");
set_name(HIW"�E"HIY"��"NOR"�����m�P�n"NOR,({"nine tail tooth","tooth","dagger"}));  
write(HIW"�E"HIY"��"NOR"���������𺥺����o�ͤF�ܤơE�E�E\n"
HIW"�E"HIY"��"NOR"�����ܤƦ�"HIW"�P��"NOR"�F�E\n");
           set("weapon_prop/str",3); 
           set("weapon_prop/con",0); 
           set("weapon_prop/int",0); 
           set("weapon_prop/dex",-2); 
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",-1);
           set("weapon_prop/wit",0);
           set("weapon_prop/bio",0);
           set("weapon_prop/sou",0);

           set("backstab_bonus",36);
           break;
     case "pike":
           set("skill_type", "fork");
set_name(HIW"�E"HIY"��"NOR"�����m�j�n"NOR,({"nine tail tooth","tooth","pike"}));  
write(HIW"�E"HIY"��"NOR"���������𺥺����o�ͤF�ܤơE�E�E\n"
HIW"�E"HIY"��"NOR"�����ܤƦ�"HIR"�j��"NOR"�F�E\n");
           set("weapon_prop/str",3); 
           set("weapon_prop/con",0); 
           set("weapon_prop/int",0); 
           set("weapon_prop/dex",0); 
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",-1);
           set("weapon_prop/wit",0);
           set("weapon_prop/bio",0);
           set("weapon_prop/sou",0);

           break;
     default:      
           write("�E�������S���o�اκA�I\n");
   }
     return 1;
}


int can_stab()
{
    if( query("skill_type")=="dagger" ) return 1;
    else return 0;
}
