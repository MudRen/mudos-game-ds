#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N化為一團黑霧穿過$n，$n的$l感到如蝕骨般的劇痛",
                "attact_type":  "sou",
                "damage_type":  "心靈傷害",
        ]),
});

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIW""BLK"影犬"NOR, ({"black dog","dog"}) );
  set("long",@LONG
一團犬形的黑影，無法判斷它是動物還是魔物或是幽魂，據說它通常
潛藏於影子中，至於其它的事情仍一無所知。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",70);
  set("gender", "雄性" );
  set("level",42+random(4));
  set("title","  謎之獸 ");
  set("limbs", ({ "黑影" }) );
  set("verbs", ({ "bite","claw" }) );
  set("str",39);
  set("con",91);
  set("int",70);
  set("dex",85);
  set("Merits/sou",5);
  set("combat_exp", 300000);
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
      "你覺得身後的影子好像有點異動？\n",
     }));
  set("chat_chance_combat", 30 );
  set("chat_msg_combat", ({
     (: random_move :),
     }) );
  set_temp("apply/dodge",100);
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object(__DIR__"eq/black-dog-bone")->wield();
}

void init()
{        
  ::init();
  switch( random(20) )
  {
    case 0..18:
         this_object()->set_temp("hide",1);
         break;
  }
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
  {
    this_player()->receive_damage("mp",random(10),this_object());
    if( this_object()->query("hp")+100 < this_object()->query("max_hp") )
      this_object()->receive_heal("hp", random(100));
  }
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
  tell_object(ob,HIG"你得到 2 點聲望。"NOR);
  ::die();
  return;
}
