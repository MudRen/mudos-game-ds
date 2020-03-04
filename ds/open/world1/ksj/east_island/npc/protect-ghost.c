#include <ansi.h>
inherit NPC;
void normal_ai();
void combat_ai();

void create()
{
  set_name("���k�v",({"protect ghost","ghost","_PROTECT_GHOST_"}) );
  set("long",@LONG
�H�k�N�l��X�Ӫ������A�ͫe�O�W�k�v�A��q�v�����k�N�C
LONG);
  set("race","monster");
 
  set("unit","��");
  set("title",HIC"�@��"NOR); 
  set("level",30+random(6));
  add("addition_armor",40);
  add("addition_damage",20);
  set_skill("unarmed", 40);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set("chat_chance", 30);
  set("chat_msg", ({
     (: normal_ai() :),
     }) );     
  set("chat_chance_combat", 100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );     
  setup();
  set_living_name("_NPC_PROTECT_GHOST_");
}

void normal_ai()
{        
  int mp,cat_hp,max_hp;
  object ob1;
  ob1=find_living("_NPC_CAT_OLDWOMAN_");

  mp=this_object()->query("mp");
  cat_hp=ob1->query("hp");
  max_hp=ob1->query("max_hp");

  if(mp < 200)
  {
    message_vision("\n$N�k�O�ӺɡA�Ƭ����Ϯ����L�ܤF�C\n",this_object());
    destruct(this_object());
    return;
  }

  if( this_object()->is_busy() ) return;
  if( objectp(ob1) )
  {
    if(!environment(ob1) )
    {
      return;
    }
    else if( (cat_hp < (max_hp-800)) && (mp > 200) )
    {
      message_vision(HIG"\n$N���x�X�Q�A����G�A�u���@�D����Ӯg�b�߱C�C���W�C\n"NOR,this_object());
      ob1->receive_heal("hp",500+random(300));
      this_object()->receive_damage("mp",200,this_object());
      this_object()->start_busy(3);
      return;
    }
  }
  else return;
}

void combat_ai()
{        
  int mp,cat_hp,max_hp;
  object ob1,me;
  ob1=find_living("_NPC_CAT_OLDWOMAN_");
  me=this_object();
  mp=me->query("mp");
  cat_hp=ob1->query("hp");
  max_hp=ob1->query("max_hp");

  if(mp < 200)
  {
    message_vision("\n$N�k�O�ӺɡA�Ƭ����Ϯ����L�ܤF�C\n",this_object());
    destruct(this_object());
    return;
  }

  if( me->is_busy() ) return;
  if( objectp(ob1) )
  {
    if(!environment(ob1) )
    {
      return;
    }
    else if( (cat_hp < (max_hp-800)) && (mp > 200) )
    {
      message_vision("\n$N"HIG"���x�X�Q�A����G�A�u���@�D����Ӯg�b�߱C�C���W�C\n"NOR,me);
      ob1->receive_heal("hp",250+random(100));
      me->receive_damage("mp",200,this_object());
      me->start_busy(2);
      return;
    }
  }
  else return;
}

void die()
{
  message_vision("\n$N���йL���A�Ƭ����Ϯ����L�ܤF�C\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
