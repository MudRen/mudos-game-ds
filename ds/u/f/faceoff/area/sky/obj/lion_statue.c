#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"白獅像"NOR, ({ "lion statue", "statue" }) );
        set("race", "robot");
        set("age", 1);
        set("long", @long
這是一隻守衛神殿的白獅雕像.
long);
      set("level",25);
        set("mobhp",50);
        set_temp("apply/dodge",-999);
        set_temp("apply/armor",50);
        setup();
}
void heart_beat()
{
  object obj,corpse;
  obj=this_object();
  if( obj->query("mobhp") < 0 )
  {
   corpse=new(__DIR__"ccopper");
    message_vision("\n突然$N整個垮了下來....-.0\n",obj); 
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
  j=random(6)+1;
  if( !who ) return 0;
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
