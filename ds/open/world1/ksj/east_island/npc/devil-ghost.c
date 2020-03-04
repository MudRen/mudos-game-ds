#include <ansi.h>
#include <combat.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N�Ƭ�����Ţ�n��$n�������A�h�W������I�V$n������",
                "attact_type":  "sou",
                "damage_type":  "���F�ж�",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"����"NOR,({"devil ghost","ghost"}) );
  set("long",@LONG
�������������E�������y�������C
LONG);
  set("race", "���~");    
  set("unit","��");
  set("Merits/sou",3);
  set("age",80+random(20));
  set("level",10+random(5));
  set("attitude", "killer");  
  set("limbs", ({ "����"}) ); 
  set("verbs", ({ "bite" }) );     
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  call_out("dest_ghost", 60);
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(2))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

void dest_ghost()
{
  message_vision("\n$N���麥������Ť��A�����L�ܤF�C\n",this_object());
  destruct(this_object());
}

/*
void die()
{
  message_vision("\n$N���йL���A�Ƭ����Ϯ����L�ܤF�C\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
*/
