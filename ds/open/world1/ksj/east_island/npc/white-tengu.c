#include <ansi.h>
#include <combat.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N右手一揮，一條似真似幻的巨蟒瞬即纏向$n的$l",
                "attact_type":  "sou",
                "damage_type":  "心靈創傷",
        ]),
        ([  "action":       "$N高舉雙手，從四面八方憑空飛來無數利箭襲向$n",
                "attact_type":  "sou",
                "damage_type":  "心靈創傷",
        ]),
        ([  "action":       "$N吐出一團白煙凝成一雙巨大的白色手掌，猛然抓向$n",
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
  set_name(HIW"白天狗"NOR, ({"white tengu","tengu"}) );
  set("long",@LONG
能力特強的三色天狗之一，擅於使用幻身術，在天狗中的地位僅在黑
天狗之下。
LONG);
  set("race", "人類");
  set("unit","隻");
  set("age",80);
  set("attitude", "aggressive");
  set("gender", "男性" );
  set("level",50);
  set("tengu",1);
  set("title",HIW"三色天狗"NOR); 
  set_skill("unarmed",100);
  set_skill("fork",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_temp("apply/hit",30);
  set_temp("apply/dodge",30);
  add("addition_armor",150);
  set_temp("float",1);
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("tengu-war-tengu");
  carry_object(__DIR__"eq/cloud-halbert")->wield();
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

int special_attack(object me, object target, int hitchance)
{
  object z;
  int sim,j;
  sim=random(3)+1;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  if( me->query_temp("wait_to_summon") ) return 0;

  if( !me->query_temp("weapon") && objectp(z=present("cloud halbert",me)) )
    command("wield halbert");

  if( !random(13) )
  {
    me->start_busy(1);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  else if( !random(9) )
  {
    me->start_busy(2);
    message_vision("\n$N"HIW"身上冒出大量煙霧，煙霧中竟出現"+sim+"隻白天狗！\n"NOR,me);
    for(j=0;j<sim;j++)
    {
      new(__DIR__"sim-tengu")->move(environment(me));
    }
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return 1;
  }
  return 0;
}

void delay()
{
  delete_temp("wait_to_summon");
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
  tell_object(ob,HIG"你得到 3 點聲望。"NOR);
  ::die();
  return;
}
