#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��"NOR"��H-����", ({ "yang-yui","yang","yui" }));
        set("race", "robot");
        set("age", 1);
        set("long",@LONG
�L���W��ۥղb���T����m�󨭫ᳬ�ث�ҡA�u���L��������
�H�Y�X�{�F�@���s�M�@�����F�A�S���L����b�Ť��񹺡A�s�h
�Ʀ��_�C���F�h�Ʀ��Z�ҩM�޵P�A�A�@�󦹴����W�N�Q��L�O
�Q�~�e�M���D�P�B�q���H���ԥ|�誺�Ѧa�m�k���F�N�n���աC
LONG);
      set("level",25);
        set("mobhp",45);
        set_temp("apply/dodge",-999);
        set_temp("apply/armor",-10);
        setup();
}
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
