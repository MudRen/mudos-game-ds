#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIY"聖"NOR HIC"天雲龍"NOR, ({"god flying cloud-dragon", "god", "dragon" }));
        set("race", "robot");
        set("age", 1);
	set("title", HIY"天地神獸"NOR);
	set("long", @long
這隻神獸它是自天地會開創以來一直守護著天地的神獸,多年來隨著周伯通
和各位長老們征戰四方,仗義四海!它是龍族的最高領袖,自從遇到了創幫幫
主周伯通就一直跟隨著他,義無反悔.等到天地會創立之後,被周伯通冊封為
守護天地會的護幫神獸!!從此天地會名聲大震,威震江湖~!! 
long);
      set("level",25);
        set("mobhp",30);
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
