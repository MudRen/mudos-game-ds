inherit NPC;

void create()
{
  set_name("野狼", ({"wolf"}) );
  set("long",@LONG
十分兇狠的狼種，會主動攻擊人類，性好獨行，白天會結伴出外覓食。
LONG
);
  set("attitude", "aggressive");
  set("race", "beast");
  set("unit","隻");
  set("age",5);
  set("level",22);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  add_money("coin",100);
}

void init()
{
        ::init();

if(userp(this_player() ) && this_object()->visible(this_player()))
 {
   message_vision("$N怒吼一聲，開始攻擊$n！！\n",this_object(),this_player() );
        this_object()->kill_ob(this_player() ); 
        }
        return;
}

