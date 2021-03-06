#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit SWORD;

void create()
{
        set_name(HIC"無形氣劍"NOR"(無)"NOR,({"hp sword","sword"}) );
        set("long",
 "由一股強大的氣勁所形成的劍，若得其心，便可令它幻化為威力不同的型態\n"
 "可以幻化(turn)的類型有光(light)跟闇(dark)屬性，也可以回復(none)。\n"
        );
        set_weight(10000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("limit_skill",100);
        }
        set("weapon_prop/tec",2);
        init_sword(70);
        setup();        
}
void init()
{
     add_action("do_turn","turn");
}
int do_turn(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object(); 
    
        if(ob->query_temp("light")==1) return notify_fail("現在已為光劍型態\n");
        if(arg=="light")
        { 
          message_vision(HIW"$N運起內功\，將"+ob->name(1)+"幻化為光之型態\n"NOR,me);
          ob->set("name",HIC"無形氣劍"HIW"(光)"NOR);           ob->start_light(1); 
          ob->add_temp("light",1); 
          ob->delete_temp("dark",1);
          ob->delete_temp("none",1);
        }
        if(ob->query_temp("dark")==1) return notify_fail("現在已為闇劍型態\n");
        if(arg=="dark")
        { 
          message_vision(HIW"$N運起內功\，將"+ob->name(1)+"幻化為闇之型態\n"NOR,me);
          ob->set("name",HIC"無形氣劍"BLK"(闇)"NOR);
          ob->start_light(0); 
          ob->add_temp("dark",1); 
          ob->delete_temp("none",1);
          ob->delete_temp("light",1);
        }  
        if(ob->query_temp("none")==1) return notify_fail("現在已為基本型態\n");
        if(arg=="none")
        { 
          message_vision(HIW"$N運起內功\，將"+ob->name(1)+"幻化為基本型態\n"NOR,me);
          ob->set("name",HIC"無形氣劍"NOR"(無)"NOR);
          ob->start_light(0); 
          ob->add_temp("none",1); 
          ob->delete_temp("light",1);
          ob->delete_temp("dark",1);
        } 
        return 1;
}
int attack(object me, object victim,string arg)
{ 
    string msg=""; 
    object ob=this_object();
    int damage;
    if(!me || !victim) return 0;   
    if(random(5)) return 0;
    if(me->query_skill("dodge")*2/3 > victim->query_dex()*3/4 ) 
      if(this_object()->query_temp("light")==1 ) 
     {
      damage=me->query_str()+random(me->query_skill("sword")*3/4);
      msg += "\n一道白光！從"+ob->name(1)+"噴出！抵制住"HIW""+victim->name()+"的行動！\n"NOR;   
      message_vision(msg,me); 
      tell_object(me,HIR"["+damage+"]點的傷害！\n"NOR);
      victim->receive_damage("hp",damage,victim); 
      victim->start_busy(5);  
      return 1; 
     }  
            else if(this_object()->query_temp("dark")==1) 
           { 
      damage=me->query_str()*3+random(me->query_skill("sword")*2/3);  
      msg += "\n一股黑色氣勁從"+ob->name(1)+"噴出！強大的威力！擊向"HIW""+victim->name()+"！\n"NOR; 
      message_vision(msg,me); 
      tell_object(me,HIR"["+damage+"]點的傷害！\n"NOR);
      victim->receive_damage("hp",damage,victim);
      victim->start_busy(1);    
      return 1; 
           }   
}

