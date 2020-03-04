#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"白"NOR"衣人-楊幽", ({ "yang-yui","yang","yui" }));
        set("race", "robot");
        set("age", 1);
        set("long",@LONG
他身上穿著白淨長袍雙手置於身後閉目思考，只見他念念有詞
隨即出現了一條龍和一隻幽靈，又見他雙手在空中比劃，龍則
化成寶劍幽靈則化成鎧甲和盾牌，你一件此景馬上就想到他是
十年前和幫主周伯通等人征戰四方的天地《法旋靈將》楊幽。
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
