#include <ansi.h>
inherit NPC;
inherit SSERVER;
void combat_ai();

void create()
{
  set_name("�̨̥۰�",({"stone puppet","puppet","_STONE_PUPPET_"}) );
  set("long",@LONG
�@�Ӥ�`�H�ٰ��j���۰��A�Ѥj�j�p�p���P���H�ۤl�E���Ӧ��C
LONG);
  set("race", "���~");    
  set("unit","��");
  set("level",20 + random(6));
  set("limbs", ({ "�Y��", "����","�ⳡ","�}��"}) ); 
  set("verbs", ({ "claw","crash" }) );
  add("addition_armor",100);
  add("addition_damage",30);
  set("chat_chance", 20);
  set("chat_msg", ({
     (: combat_ai() :),
     }) );     
  set("chat_chance_combat", 30);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );     
  setup();
  set_living_name("_NPC_STONE_PUPPET_");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
        this_object()->kill_ob(this_player());
}

void combat_ai()
{
  // ������
  object obj,target,me;
  me=this_object();
  obj=find_living("_NPC_CAT_OLDWOMAN_");
  if(!obj) return;
  target = offensive_target(obj);
  if(!target) return;
  if(target->can_fight(me)) {
    command("say �q������");
    target->kill_ob(me);
    me->kill_ob(target);
  }
  return;
}

void die()
{
  message_vision("\n$N���йL���A���˦b�a�ܦ��@��H�ۡC\n",this_object());
//   destruct(this_object());
  ::die();
  return;
}

