#include <ansi.h>
inherit NPC;
void create()
{
        set_name("銅人", ({ "copper's man" ,"man"}) );
        set("race", "robot");
        set("age", 1);
        set("long", "它是銅做的假人，雕塑的栩栩如生，跟真的一樣。\n");
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
    message_vision("\n突然銅人發出一陣『喀∼啦∼』數聲，銅人已經毀壞了。\n",obj); 
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
  tell_object(who,"\n你得到了"+j+"點的經驗值。\n");
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
