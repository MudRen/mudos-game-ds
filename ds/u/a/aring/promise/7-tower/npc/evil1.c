#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIC"妃喧"NOR, ({"fei xuan","xuan"}) );
  set("long",@LONG
七邪塔之中的女性王者，擅長操鞭，在以鞭器聞名的門派裡，能操弄得
像此女性旗鼓相當的人，寥寥可數。
LONG
);
  set("gender", "女生");  
  set("race", "人類");
  set("age",20);
  set("level",47);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIM"犬妖姬"NOR); 
  set("Merits/bar",10);
  set("Merits/bio",10);
  set("Merits/wit",1);
  set("Merits/tec",10);
  add("addition_damage",130);
  add("addition_armor",200);
  set("max_hp",10000);
  set("chat_chance", 30);
  set("chat_msg", ({
  HIM"妃喧"HIW"迅速的止住已飛賤出血的部位...."HIR"(+300)\n"NOR,
     (: heal :),
  }));
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),

}));

    setup();
  carry_object(__DIR__"eq/eq1")->wear();
  carry_object(__DIR__"wp/wp1")->wield();
 }

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;

  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") > 40 && userp(this_player()) )
    this_object()->kill_ob(this_player());
}

void heal()
{
  if(query("hp") > query("max_hp")) return;
  add("hp",300);
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))
  {
    me->start_busy(1);
    target->add_busy(2);
    message_vision("\n$N"HIR"站踏五魂步法，蓄勢待發，集內勁在鞭子上，使出驚人一擊！！\n"NOR,me);
    call_out("do_super",2,me);
    return 1;

}
 
}
void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIC"\n九道狂擊似飛雪般的消遙，道道襲擊你的要害！！\n"NOR,me);
  message_vision(HIG"\n你無法躲開任何攻擊，只能默默的看著數道鞭氣襲身！！\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 250+random(200);
      message_vision(HIR"$N被無情的雪花亂擊，看似非常痛苦，受到嚴重的傷害 "HIR"("+damage+")\n\n"NOR,inv[i]);
      message_vision(HIW"只見敵人攻擊未了，使出更驚人的鞭法修為！！\n"NOR,me);
      inv[i]->receive_damage("hp", damage, me);
      call_out("do_super2",2,me);      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIC"\n$N使出輕盈的輕功\，躲開此攻擊！！\n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(1);
  return;
} 

void do_super2(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;
  message_vision(HIW"\n只見$N"HIW"再次調息內力，慢慢的恢復以往的內息。\n\n"NOR,me);
  message_vision(HIW"\n煞那間，大地變色，道道雪花鞭氣佈滿了整片天........\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 400+random(100);
      message_vision("\n"HIC"妃暄"NOR+CYN"靜靜著默念著："HIW"花雪一步殺...................！！！\n\n"NOR,me);   
      message_vision(HIR"$N再次受到無情的雪花亂墜，造成比前次更嚴重的傷害.....。 "HIY"("+damage+")\n\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIC"\n$N使出輕盈的輕功\，躲開此攻擊！！\n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(1);
  return;
}
void die()
{
  object ob,env;
   int temp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  env = environment(ob);
  temp = NATURE_D->which_world(env);
  message("world:world1:vision", "\n\t"HIW"就在" +NATURE_D->game_time(temp)+"       "NOR+CYN"\n\n\t七邪塔哀號....縱橫七邪塔第一層 "HIM"妃喧 "HIW"敗在"HIY+ob->query("name")+HIW"手上\n\n"+NOR
       ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIY"消滅了妖邪，佛祖大開法恩賞賜你五點聲望以此嘉獎。"NOR);
    switch( random(50) )

  {
    case  0..25: new(__DIR__"obj/book")->move(ob);
          break;
    case  26..50: new(__DIR__"obj/gold-box")->move(this_object());

          break;
    }
  
   ::die();
  return;
}

