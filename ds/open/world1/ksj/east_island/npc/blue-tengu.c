#include <ansi.h>
#include <combat.h>     
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N���ʤ⤤���l�A�N�@�D�H�N�B��ݵ�V$n",
                "attact_type":  "wit",
                "damage_type":  "���",
        ]),
        ([  "action":       "$N���X�B�s�W�L�A�@�s��$n�g�X�ƪT",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
        ([  "action":       "$N�R�ʯ��N�A�N���⾮���@�����j�B���A���k���V$n",
                "attact_type":  "bio",
                "damage_type":  "����",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIC"�C�Ѫ�"NOR, ({"blue tengu","tengu"}) );
  set("long",@LONG
��O�S�j���T��Ѫ����@�A�թ�ϥΦB�N�A�b�Ѫ������a��Ȧb�¤�
�����U�C
LONG);
  set("race", "�H��");
  set("unit","��");
  set("age",80);
  set("attitude", "aggressive");
  set("gender", "�k��" );
  set("level",50);
  set("tengu",1);
  set("title",HIW"�T��Ѫ�"NOR); 
  set_skill("unarmed",100);
  set_skill("fork",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_temp("apply/hit",30);
  set_temp("apply/dodge",30);
  add("addition_armor",150);
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  set_temp("float",1);
  setup();
  set_living_name("tengu-war-tengu");
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object(__DIR__"eq/ice-halbert")->wield();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu-enemy") ) this_object()->kill_ob(this_player());
  if(userp(this_player())) this_object()->kill_ob(this_player());
}

int special_attack(object me,object target,int hitchance)
{
  object *inv,z;
  int damage,i;
  inv = all_inventory(environment(me));
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if( !me->query_temp("weapon") && objectp(z=present("ice halbert",me)) )
  { 
    command("wield halbert");
  }

  if( !random(13) )
  {
    me->start_busy(1);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  else if( !random(10) )
  {
    me->start_busy(2);
    message_vision("\n$N"HIW"���V�b�Ŧ��i���l�A�ϥX����"HIC"�i�Ѫ��r�j"HIW"�I\n"+NOR,me);
    for(i=0;i<sizeof(inv);i++)
    {
      if(inv[i] == me) continue;
      if( !me->visible(inv[i]) ) continue;
      if( living(inv[i]) && userp(inv[i]) )
      {
        if( inv[i]->is_corpse() ) continue;
        damage = random(100)+370-(inv[i]->query_shield())-(inv[i]->query_armor());
        if(damage < 0) damage=0;
        message_vision(HIR"$N�Q�Ƥ��M���y�U�B�r�����A�y�� ("+damage+") �I���Y���жˡI\n"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
        inv[i]->add_busy(random(2));
      }
    }
    return 1; 
  }
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
  ob->add("popularity",3);      
  tell_object(ob,HIG"�A�o�� 3 �I�n��C"NOR);
  ::die();
  return;
}
