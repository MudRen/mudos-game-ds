#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIB"青"NOR"衣人-李鷹", ({ "lee-in","lee","in"}));
        set("race", "robot");
        set("age", 1);
        set("long",@LONG
身上穿著青色衣裳胸前繡著一隻銀鷹，此人是江湖上有名輕功世
家的第十代傳人，同時也是傳人之中最聰明的。
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
    message_vision("\n突然$N發出一陣『喀∼啦∼』數聲，$N已經毀壞了。\n",obj); 
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
