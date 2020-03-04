inherit NPC;

void create()
{
  set_name("黑熊", ({"black bear","bear"}) );
  set("long",@LONG
在深山居住已久的熊，毛色棕黑色，雙爪十分巨大，看來很生氣。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",100);
  set("level",30);
  set("limbs", ({ "頭部", "腹部","胸部","爪子" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
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


