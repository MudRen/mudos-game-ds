#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���H", ({ "stake"}) );
        set("race", "robot");
        set("age", 1);
        set("long", "�o�O�@�Ӥ�y�����H�A�J�쪺�ݮݦp�͡A��u���@�ˡC\n");
        set("level",25);
        set("mobhp",100);
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
  } else obj->add_block(2);

  return; 
}

int receive_damage(string type,int damage,object who)
{
  int j;
  object obj;
  if( !who ) return 0;
  obj = this_object();
  j = 1 + random(3);
  who->add("exp", j);
  tell_object(who,"\n�A�o��F"+j+"�I���g��ȡC\n");
  set("mobhp", query("mobhp")-1);
  if(who->query("ap")>0)
  {
    who->receive_damage("ap", 5);
  }
  else {
    who->receive_damage("hp", 10);
  }
}

