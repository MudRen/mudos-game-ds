#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��H", ({ "wood's man" ,"man"}) );
        set("race", "robot");
        set("age", 1);
        set("long", "���O���Y�������H�A�J�쪺�ݮݦp�͡A��u���@�ˡC\n");
        set("level",1);
        set("mobhp",10);
        set_temp("apply/dodge",-999);
        set_temp("apply/armor",-10);
        setup();
}
void heart_beat()
{
  object obj;
  obj=this_object();
  if( obj->query("mobhp") < 1 )
  {
    message_vision("\n��M��H�o�X�@�}�y�ء�ա�z���n�A��H���n���_�C\n",obj);
     this_player()->remove_all_killer();
    destruct(obj);
  } else obj->add_block(2);

  return; 
}

int receive_damage(string type,int damage,object who)
{
  int j,mobhp;
  object obj;
  obj=this_object();
  j=random(10)+1;
  if( who ) who->add("exp", j);
  tell_object(who,"\n�A�o��F"+j+"�I���g��ȡC\n");
  mobhp=obj->query("mobhp");
  obj->set("mobhp",mobhp-1);  
  if(who->query("ap")>1)
  {
    who->receive_damage("ap",2);
  }
  else {
    who->receive_damage("hp",10);
  }
}

