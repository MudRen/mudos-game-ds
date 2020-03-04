#include <ansi.h>
inherit NPC;
void heal();

void create()
{
  set_name(HIW"���l�s"NOR, ({"silver dragon","dragon"}) );
  set("long",@LONG
�������ժ����s�A���ߦa���ɤ�@���Τl�٤j�A���l�i�}���H�B�h�b
���ѪšA�ߺD�H�H�B�𮧭���y����A���W�]����R������Ӻu�S��
��Ŧ�C
LONG);
  set("race", "beast");
  set("gender", "�۩�");
  set("unit","��");
  set("age",1100);
  set("level",45);
  set("evil",50);
  set("title",RED"  �]�~ "NOR); 
  set("attitude", "aggressive");
  set("limbs", ({ "�Y��", "����","�ݳ�","����","�e��","���","���l" }) );
  set("verbs", ({ "bite","crash","claw" }) );
  add("addition_armor",50);
  set("chat_chance", 40);
  set("chat_msg", ({
     (: heal :),
     }));
  setup();
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

void heal()
{
  if(query("hp") > query("max_hp")) return;
  add("hp",50+random(50));
  return;
}

int special_attack(object me, object target, int hitchance)
{
  int damage;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(10))
  {
    message_vision(HIW"\n���l�s"NOR"��M���W�b�šA�H�Y������ĦӤU�A���t�q$n���Ǳ۳ΦӹL�I\n"NOR, this_object(), target);
    if(random(target->query_dex()) < 30)
    {
      damage=300-( target->query_armor() )+random(150);
      target->receive_damage("hp",damage,me);
      message_vision("�y��$N"HIR" "+damage+" "NOR"�I���ˮ`�I\n\n",target);
      target->apply_condition("blooding", target->query_condition("blooding")+(random(5)+3));
    }
    else
    {
      message_vision(HIC"$N�@��½�u�A���I�a�פF�}�ӡI\n\n"NOR,target);
      return 1;
    }
    return 1;
  }

  else if(!random(10))
  {
    message_vision(HIW"\n���l�s"HIC"��$N�i�f�Q�X���H��I\n"NOR, target);
    if(random(target->query_dex()) < 30)
    {
      damage=250-( target->query_shield() )+random(100);
        if( damage <  30 ) damage = 30 + random(50);
      target->receive_damage("hp",damage,me);
      message_vision("�y��$N"HIR" "+damage+" "NOR"�I����ˡI\n\n",target);
      target->add_busy(1);
    }
    else
    {
      message_vision(HIC"$N�@��½�u�A���I�a�פF�}�ӡI\n\n"NOR,target);
      me->start_busy(1);
      return 1;
    }
    return 1;
  }

  return 0;
}

int receive_damage(string type,int cost)
{
  object ob,target;
  ob = this_object();
  target = this_player();
  ::receive_damage(type,cost,target);
  return 0;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  ob->add("popularity",2);      
  tell_object(ob,HIG"�A�o�� 2 �I�n��C"NOR);
  switch( random(99) )
  {
    case 0..89: new(__DIR__"eq/silver-dragon-heart")->move(this_object());
         break;
    case 90..99: new(__DIR__"eq/silver-dragon-claw")->move(this_object());
         break;
  }
  ::die();
  return;
}
