#include <ansi.h> 
inherit NPC;  
void super();
void create() 
{ 
       set_name(HIW"�ʺA���H"NOR,({"golden man","man"}));
       set("gender","human"); 
       set("title",HIC"�e��"NOR); 
       set("level",40);
        set("mobhp",50);
        set_temp("apply/dodge",-999);
        set_temp("apply/armor",-10);
        set("combat_chance_chance",10);
        set("combat_chat_msg",({ 
  (: super :),   
}));
       set("long",@LONG      
�M���w��e���ҳ]�p�����H�A���۱j�j���S��A��H��
�����H���Ҥ��P�A�p�G���O�e�������h���A���i�O���|
�z�A���O�C

LONG
); 
        setup(); 
}  
void super()
{
     object me,victim;
     me=this_player();   
     if(!me->query("class1") == "�e����" )return; 
     message_vision(HIW"\n��S��šA���L�_�a�A"HIR"�|�m���~"HIW"�A�Ѧa�Ӱ_�I�Z�L���ǡy"HIG"�U�C�ê�"HIW"�z�I�I\n"NOR,me); 
     me->start_busy(2);  
     this_object()->start_busy(2);
     if(random(10)>5) 
     { 
message_vision(HIW"\n�U���C�����A�ѤW�ө�"+me->name()+"�h�A�y�ڡI�z�ƨ���~�q"+me->name()+"�z�o�A"HIR"�A��"HIW"���y�ӤU..\n"NOR,me);
                   COMBAT_D->do_attack(me, this_object(), 5);
                   COMBAT_D->report_status(me);
                   me->add_busy(3);   
                   me->receive_damage("hp",500+random(100));
        } 
        else{
                    message_vision(HIG""+me->name()+"�ƸѤF���ƨ���~�A�O�l������Ĥ��w..\n"NOR,me); 
                   this_object()->add_busy(3);
        } 
        return;} 
void heart_beat()
{
  object obj,corpse;
  obj=this_object();
  if( obj->query("mobhp") < 0 )
  {
   corpse=new(__DIR__"ccopper");
    message_vision("\n��M$N�o�X�@�}�y�ء�ա�z���n�A$N�w�g���a�F�C\n",obj); 
     this_player()->remove_all_killer();
    destruct(this_object());
    //::die();
  } else obj->add_block(2);

  return; 
}

int receive_damage(string type,int damage,object who)
{
  int j,mobhp;
  object obj;
  obj=this_object();
  j=random(15)+1;
  if( !who ) return 0;
  who->add("exp", j);
  tell_object(who,"\n�A�o��F"+j+"�I���g��ȡC\n");
  mobhp=obj->query("mobhp");
  obj->set("mobhp",mobhp-1);  
  if(who->query("ap")>0)
  {
    who->receive_damage("ap",3);
  }
  else {
    who->receive_damage("hp",10);
  }
}

