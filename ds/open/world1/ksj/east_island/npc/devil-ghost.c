#include <ansi.h>
#include <combat.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N化為網狀籠罩住$n的全身，痛苦的怨念侵向$n的腦中",
                "attact_type":  "sou",
                "damage_type":  "心靈創傷",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"妖魂"NOR,({"devil ghost","ghost"}) );
  set("long",@LONG
怨念不散的鬼魂聚成的綠色球狀煙霧。
LONG);
  set("race", "野獸");    
  set("unit","隻");
  set("Merits/sou",3);
  set("age",80+random(20));
  set("level",10+random(5));
  set("attitude", "killer");  
  set("limbs", ({ "煙霧"}) ); 
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
  message_vision("\n$N形體漸漸散於空中，消失無蹤了。\n",this_object());
  destruct(this_object());
}

/*
void die()
{
  message_vision("\n$N受創過重，化為輕煙消失無蹤了。\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
*/
