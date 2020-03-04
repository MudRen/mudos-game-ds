#include <ansi.h>
inherit NPC;
void create()
{
        set_name("假人", ({ "stake"}) );
        set("race", "robot");
        set("age", 1);
        set("long", "這是一個木造的假人，雕塑的栩栩如生，跟真的一樣。\n");
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
    message_vision("\n突然$N發出一陣『喀∼啦∼』數聲，$N已經毀壞了。\n",obj); 
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
  tell_object(who,"\n你得到了"+j+"點的經驗值。\n");
  set("mobhp", query("mobhp")-1);
  if(who->query("ap")>0)
  {
    who->receive_damage("ap", 5);
  }
  else {
    who->receive_damage("hp", 10);
  }
}

