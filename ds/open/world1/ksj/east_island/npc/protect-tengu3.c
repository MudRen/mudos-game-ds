#include <ansi.h>
inherit NPC;
void combat_ai();

void create()
{
  set_name(HIC"守護天狗"NOR, ({"protect tengu","tengu","_PROTECT_TENGU3_"}) );
  set("long",@LONG
能力高於一般的天狗，負責守護天狗的首領，每位守護天狗都有其擅
長的能力。
LONG);
  set("race","monster");
  set("unit","隻");
  set("age",50);
  set("attitude", "aggressive");
  set("gender", "男性" );
  set("level",45);
  set_skill("fork",40+random(15));
  set_skill("dodge",40+random(10));
  set_skill("parry",30+random(10));
  add("addition_armor",60+random(10));
  set("chat_chance", 50);
  set("chat_msg",({
     (:command("defend black tengu"):),
     }) );
  set("chat_chance_combat",30);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  set_living_name("_NPC_PROTECT_TENGU3_");
}

void combat_ai()
{        
  int mp,cat_hp,max_hp;
  object ob1,ob2,ob3;
  ob1=find_living("_NPC_BLACK_TENGU_");
  ob2=find_living("_NPC_PROTECT_TENGU1_");
  ob3=find_living("_NPC_PROTECT_TENGU2_");

  mp=this_object()->query("mp");
  cat_hp=ob1->query("hp");
  max_hp=ob1->query("max_hp");

  if( objectp(ob1) )
  {
    if(!environment(ob1) )
    {
      return;
    }
    else if( (ob1->query("hp") < (ob1->query("max_hp")-300)) )
    {
      message_vision("\n$N"HIY"朝著$n"HIY"吐出一團金色煙霧，"
                     +"只見$n"HIY"身上的傷口稍有癒合了。\n"NOR,this_object(),ob1);
      ob1->receive_heal("hp",200+random(50));
      return;
    }
  }

  if( objectp(ob2) )
  {
    if(!environment(ob2) )
    {
      return;
    }
    else if( (ob2->query("hp") < (ob2->query("max_hp")-300)) )
    {
      message_vision(HIY"\n$N朝著$n吐出一團金色煙霧，只見$n身上的傷口稍有癒合了。\n"NOR,this_object(),ob2);
      ob2->receive_heal("hp",200+random(50));
      return;
    }
  }

  if( objectp(ob3) )
  {
    if(!environment(ob3) )
    {
      return;
    }
    else if( (ob3->query("hp") < (ob3->query("max_hp")-300)) )
    {
      message_vision(HIY"\n$N朝著$n吐出一團金色煙霧，只見$n身上的傷口稍有癒合了。\n"NOR,this_object(),ob3);
      ob3->receive_heal("hp",200+random(50));
      return;
    }
  }
  else return;
}
