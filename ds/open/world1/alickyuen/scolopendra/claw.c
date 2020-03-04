#include <ansi2.h>

inherit NPC;

mapping *combat_action = ({
        ([
                "action" :      "$N�r�P����V$n��$l�L�h",
                "attack_type" : "bar",
                "damage_type" : "���",
        ]),
});

void create()
{
        set_name(HBK"���G�r��"NOR, ({ "poison claw", "claw" }) );
        set("level", 40);
        set("combat_exp", 0);
        set("race", "beast");
//        set("attitude", "aggressive");
        set("limbs", ({ "����" }) );
        set("max_hp", 3000);
        set("default_actions", (: call_other, __FILE__, "query_action" :) );
        setup();
        carry_object(__DIR__"grass");
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") > 25 && userp(this_player()) )
     this_object()->kill_ob(this_player());
}

void special_attack(object me, object victim, int hitrole)
{
//        if( random(3) )
        {
                message_vision("\n$N"HIR"��$n���W�g��ƤU�A�O$n���W�d�U�X���¦⪺�˲��C\n\n"NOR, me, victim);
                victim->apply_condition("scolopendra_poison", victim->query_condition("scolopendra_poison")+random(3));
        }
        me->kill_ob(victim);
        return;
}
