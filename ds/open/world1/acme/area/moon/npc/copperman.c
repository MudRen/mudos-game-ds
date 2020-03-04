#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ɤH", ({ "copper's man" ,"man"}) );
        set("race", "robot");
        set("age", 1);
        set("long", "���O�ɰ������H�A�J�쪺�ݮݦp�͡A��u���@�ˡC\n");
        set("level",5);
        set("mobhp",35);
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
    message_vision("\n��M�ɤH�o�X�@�}�y�ء�ա�z���n�A�ɤH�w�g���a�F�C\n",obj); 
     this_player()->remove_all_killer();
    corpse->move(environment(this_object()));
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
