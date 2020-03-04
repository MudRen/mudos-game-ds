#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIY"聖"NOR HIR"凰尊者"NOR, ({ "god spirit-man", "man" }));
        set("race", "robot");
        set("age", 1);
	set("title", HIY"鎮幫使者"NOR);
	set("long", @long
這位是武林中非常有名望的聖者,外表看起來仙風道古就連氣質都是聖賢之
氣,不可侵犯!!不但文學造詣非凡,就連武功也非常人能及,就連三大門派掌
門人:吳鐘,軒轅烈,蕭日山等人也曾受教於他,對他可說是敬佩不已!他在二 
十年前退隱華山修行,直到十幾年前周伯通上華山在機緣下遇見了這位聖者
,而在隨著天地會開創之時,幫主以大禮請這位聖者回來做鎮幫使者~連天地
會幫規(天地正法)和正法堂也是由這位前輩所撰寫,設立!使天地會不只成為
天下聞名的大幫,也成為中原文人所嚮往的神聖仙境!! 
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
