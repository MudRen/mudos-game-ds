#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIG"相柳"NOR, ({"xiangliu"}) );
  set("long",@LONG
相柳氏，人面蛇身，渾身青色，性情殘酷貪婪。他的身體像章魚的觸
手一樣扭曲在一起，具有如應龍一般招雨的能力，幾乎是只要他接觸
到的地方，馬上就會化為水澤，連他嘆氣或是吐出來的嘔吐物，都會
將肥沃的土地化為無法耕種，變成有瘴氣的沼澤，行走的速度極為迅
速。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",300);
  set("level",45+random(5));
  set("title",GRN"  妖獸 "NOR);
  set("attitude", "aggressive");
  set("limbs", ({ "頭部", "腹部","胸部","尾巴" }) );
  set("verbs", ({ "bite","crash" }) );
  set("chat_chance", 30);
  set("chat_msg", ({
   HIG"相柳"NOR"的蛇腹在地上爬行，形成一條冒著惡氣的水灘。\n",
   HIG"相柳"NOR"九個頭，十八顆碧綠的眼睛一起盯著你，使你全身發毛。\n",
   HIG"相柳"NOR"扭動絞纏的蛇身，虎視眈眈地看著你。\n",
     (: random_move :),
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
/*
  switch( random(19) )
  {
    case 0:
         say(HIG"相柳"NOR"突然一溜煙消失在草叢中。\n");
         destruct(this_object());
         break;
  }
*/
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
  ob->add("popularity",1); 
  tell_object(ob,HIG"你得到 1 點聲望。"NOR);     
  switch( random(100) )
  {
    case 0..29: new(__DIR__"eq/xiangliu_pill")->move(this_object());
         break;
    case 90..99: new(__DIR__"eq/xiangliu_cloth")->move(this_object());
         break;
  }
  ::die();
  return;
}
