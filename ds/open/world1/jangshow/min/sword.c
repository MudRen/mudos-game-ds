// Jangshow@DS ���� LPC �ɤ��@,��]�n�p�� =_=a
// �γ�²�檺�覡�g, �_���^�O��S��i�ɥR
// �S�I, �S�𥲤�  
// �б��U�Ӫ�wiz�ɥR��L���^�O wp 
// save wp

#include <ansi.h>
#include <weapon.h> 
#define WPNAME "�^�O���C"
inherit SWORD;

//string *stone= ({"�@�D�����I�g�Q�R�ѡI","

void create()
{
  set_name(HIY"�^�O���C"NOR , ({ "inlay sword","sword" }) ); 
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�W�����@�Ӥp�}�A�����D�O�F�ª�[inlay xxx]�C\n");
    set("material", "gold");
    set("value",30000);
  }
  set("weapon_prop/dodge",10);
//  set("weapon_prop/sword",10);    
  init_sword(50); 
  setup();
}
void init()
{
     add_action("do_inlay","inlay");
}
int do_inlay(string arg)
{ 
    object me=this_player(),obj;  
    if(this_object()->query_temp("inlaied")==1) 
       return notify_fail("�̭��w�g�^�F�@���_�ۡA�A�S�ݨ�ܡH\n");    

    /***************************************�^�O�}�l****************************************/ 

    if(arg =="red stone") 
              { 
               if(!objectp(obj=present("red stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N�p���l�l���N"HIR"���_"NOR"�A�^�i�F"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","�o�O�@���^�F�@��"HIR"���_"NOR"���C�A�W�����p�}�w�g�Q�񺡤F�C\n"
                                           HIW"�S���O�G"HIR"���t"HIW"����\n"NOR);   
                    destruct(obj);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/red",1);
                    }  
              return 1;
              }      
    if( arg =="blue stone") 
              { 
               if(!objectp(obj=present("blue stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N�p���l�l���N"BLU"���_"NOR"�A�^�i�F"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","�o�O�@���^�F�@��"BLU"���_"NOR"���C�A�W�����p�}�w�g�Q�񺡤F�C\n"
                                           HIW"�S���O�G"BLU"���t"HIW"����\n"NOR);   
                    destruct(obj);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/blue",1);
                    }  
              return 1;
              }  
    if( arg =="white stone") 
              { 
               if(!objectp(obj=present("white stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N�p���l�l���N"HIW"���_"NOR"�A�^�i�F"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","�o�O�@���^�F�@��"HIW"���_"NOR"���C�A�W�����p�}�w�g�Q�񺡤F�C\n"
                                           HIW"�S���O�G"HIW"���t"HIW"����\n"NOR);   
                    destruct(obj);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/white",1);
                    }  
              return 1;
              }     
    if(arg =="green stone") 
              { 
               if(!objectp(obj=present("green stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N�p���l�l���N"HIG"���_"NOR"�A�^�i�F"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","�o�O�@���^�F�@��"HIG"���_"NOR"���C�A�W�����p�}�w�g�Q�񺡤F�C\n"
                                           HIW"�S���O�G"HIG"�r�t"HIW"����\n"NOR);   
                    destruct(obj);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/green",1);
                    }  
              return 1;
              }      
} 
int attack(object me, object victim,string arg)
{ 
    string msg="";
    int damage;
    if(!me || !victim) return 0;   
    if(random(5)) return 0;
    if(me->query_skill("dodge")*2/3 > victim->query_dex()*3/4 ) 
    /************�S�����*************************************/  

      if(this_object()->query_temp("inlay/red")==1 ) 
     {
      damage=me->query_str()*3+random(me->query_skill("sword")*3/4);
      msg += HIR"\n�@�D�����I�r�M�q"HIY""+WPNAME+""HIR"«�X�I�h�V"HIW""+victim->name()+"�I\n"NOR;   
      message_vision(msg,me); 
      tell_object(me,HIR"["+damage+"]�I���ˮ`�I\n"NOR);
      victim->receive_damage("hp",damage,me); // victim->me by alick@ds 16042005
      victim->start_busy(2);  
      //victim->add_temp("firing",1);
      //call_out("fired",10,victim);  
      //call_out("de_fired",31,victim); 
      return 1; 
     } 
      else if(this_object()->query_temp("inlay/blue")==1) 
           { 
      damage=me->query_str()*3+random(me->query_skill("sword")*2/3);  
      msg += BLU"\n�@�}����q"HIY""+WPNAME+""BLU"���X�E�E�Φ��@�ئ������s������I���V"HIW""+victim->name()+"�I\n"NOR; 
      message_vision(msg,me); 
      tell_object(me,HIR"["+damage+"]�I���ˮ`�I\n"NOR);
      victim->receive_damage("hp",damage,me); // victim->me by alick@ds 16042005
      victim->start_busy(3);   //delay���[ 
      return 1; 
           }   
      else if(this_object()->query_temp("inlay/white")==1) 
           {  
      damage=me->query_str()+random(me->query_skill("sword")*2/3);  
      msg += HIW"\n�u�C���@�{�v�A�S�p�����j�a�A�벴�����~�A���F"+victim->name()+"����ʡI\n"NOR;
      message_vision(msg,me);
      tell_object(me,HIR"["+damage+"]�I���ˮ`�I �óy��"+victim->name()+"���^�X�������I\n"NOR);
      victim->receive_damage("hp",damage,me); // victim->me by alick@ds 16042005
      victim->start_busy(6);
      return 1; 
            } 
      else if(this_object()->query_temp("inlay/green")==1) 
            { 
      damage=me->query_str()*2/3+random(me->query_skill("sword")*2/3); 
     msg += HIW"\n"+me->name()+"���R��"HIY""+WPNAME+""HIW"�A�å������b"+victim->name()+"���W�e�X�@�D�ˤf�I\n"
     HIR"�ˤf"HIW"������"HIG"���w���r....\n"NOR;     
      message_vision(msg,me);
      tell_object(me,HIR"["+damage+"]�I���ˮ`�I�óy��"+victim->name()+"�r�ʴݯd�I\n"NOR);
      victim->receive_damage("hp",damage,me); // victim->me by alick@ds 16042005
      victim->start_busy(2);
    if( userp(victim) ) victim->apply_condition("poison", victim->query_condition("poison")+ (15+random(5)));
    //else victim->apply_condition("poison", victim->query_condition("poison")+ (15+random(5))); 
         return 1;
         }
         else return damage;
} 
int query_autoload() { return 1; }

/*
�n���S�@��
void fired(object me,object ob,object victim)
{    
     int damage=50+random(10);
     if(victim->query_temp("firing") >= 0)
     {
     message_vision(HIW""+victim->query_name()+"�����W�_�X�@�@���J��..\n"NOR,victim);  
      victim->receive_damage("hp",damage,me); // victim->me by alick@ds 16042005
     call_out("fired",10,victim); 
     } 
     else return ;
}
void de_fired(object victim)
{ 
     victim->delete_temp("firing"); 
     return ;
} 
*/  
    

