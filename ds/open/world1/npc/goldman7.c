#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIR"焯火金人"NOR, ({ "fire gold's man", "man" }) );
        set("race", "robot");
        set("age", 1);
	set("long", @long
你隱約看到眼前的火團中有一個人,再定睛一看,發現他原來是被一道道的紅蓮之火所包圍著
他緊閉著雙目,口中也喃喃地念著咒文,而一道道的神武真火也從其手上冒出來了
再看著看著..竟然發現火團中還有著數十條火龍隨著真火而冒出了頭來
就像要把你眼前的人吞噬似的.
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
