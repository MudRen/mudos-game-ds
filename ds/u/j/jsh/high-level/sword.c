#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit SWORD;

void create()
{
        set_name(HIC"�L�ή�C"NOR"(�L)"NOR,({"hp sword","sword"}) );
        set("long",
 "�Ѥ@�ѱj�j����l�ҧΦ����C�A�Y�o��ߡA�K�i�O���ۤƬ��¤O���P�����A\n"
 "�i�H�ۤ�(turn)����������(light)����(dark)�ݩʡA�]�i�H�^�_(none)�C\n"
        );
        set_weight(10000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
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
    
        if(ob->query_temp("light")==1) return notify_fail("�{�b�w�����C���A\n");
        if(arg=="light")
        { 
          message_vision(HIW"$N�B�_���\\�A�N"+ob->name(1)+"�ۤƬ��������A\n"NOR,me);
          ob->set("name",HIC"�L�ή�C"HIW"(��)"NOR);           ob->start_light(1); 
          ob->add_temp("light",1); 
          ob->delete_temp("dark",1);
          ob->delete_temp("none",1);
        }
        if(ob->query_temp("dark")==1) return notify_fail("�{�b�w����C���A\n");
        if(arg=="dark")
        { 
          message_vision(HIW"$N�B�_���\\�A�N"+ob->name(1)+"�ۤƬ�����A\n"NOR,me);
          ob->set("name",HIC"�L�ή�C"BLK"(��)"NOR);
          ob->start_light(0); 
          ob->add_temp("dark",1); 
          ob->delete_temp("none",1);
          ob->delete_temp("light",1);
        }  
        if(ob->query_temp("none")==1) return notify_fail("�{�b�w���򥻫��A\n");
        if(arg=="none")
        { 
          message_vision(HIW"$N�B�_���\\�A�N"+ob->name(1)+"�ۤƬ��򥻫��A\n"NOR,me);
          ob->set("name",HIC"�L�ή�C"NOR"(�L)"NOR);
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
      msg += "\n�@�D�ե��I�q"+ob->name(1)+"�Q�X�I����"HIW""+victim->name()+"����ʡI\n"NOR;   
      message_vision(msg,me); 
      tell_object(me,HIR"["+damage+"]�I���ˮ`�I\n"NOR);
      victim->receive_damage("hp",damage,victim); 
      victim->start_busy(5);  
      return 1; 
     }  
            else if(this_object()->query_temp("dark")==1) 
           { 
      damage=me->query_str()*3+random(me->query_skill("sword")*2/3);  
      msg += "\n�@�Ѷ¦��l�q"+ob->name(1)+"�Q�X�I�j�j���¤O�I���V"HIW""+victim->name()+"�I\n"NOR; 
      message_vision(msg,me); 
      tell_object(me,HIR"["+damage+"]�I���ˮ`�I\n"NOR);
      victim->receive_damage("hp",damage,victim);
      victim->start_busy(1);    
      return 1; 
           }   
}

