#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIR"血眼"WHT"逆角龍"NOR, ({"blood-eye dragon","dragon","_BLOOD_EYE_DRAGON_"}) );
  set("long",@LONG
上古魔獸，有著血紅似火的三隻眼睛及岩石般暗灰的身體，最特別的
是頭上一對向前逆長的巨大畸角，據傳說記載上古人類運用智慧將牠
引至泥沼之中，再群起而攻，才將牠葬身在泥沼之下。
LONG
);
  set("gender", "雄性");  
  set("race", "beast");
  set("unit","隻");
  set("age",3000);
  set("level",60);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",RED"  魔獸 "NOR); 
  set("limbs", ({ "頭部", "腹部","胸部","尾巴","前爪","後爪","兩翼" }) );
  set("verbs", ({ "bite","crash","claw" }) );
  set("Merits/bar",10);
  set("Merits/bio",9);
  set("Merits/wit",4);
  set("Merits/tec",4);
  add("addition_damage",100+random(10));
  add("addition_armor",200);
  set("chat_chance", 35);
  set("chat_msg", ({
     (: heal :),
     }));
  set("chat_chance_combat",20);
  set("chat_msg_combat", ({
   HIR"血眼"WHT"逆角龍"NOR"張開排滿尖牙的雙嘴，發出一陣震天的嘶吼。\n",
   HIR"血眼"WHT"逆角龍"NOR"雙翼微動，形成一股強風，使你幾乎站不住腳。\n",
   HIR"血眼"WHT"逆角龍"NOR"的前腳踏在地上造成一陣晃動。\n",
     }) );
  setup();
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper1");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper2");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper3");

  set_living_name("_NPC_BLOOD_EYE_DRAGON_");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
  if( this_player()==this_object()->query_temp("last_opponent") )
  {
    message_vision(HIG"(已有防備)"HIR"血眼"WHT"逆角龍"NOR"的眼睛瞪向$N，$N一時間雙眼疼痛難以視物！！\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

void heal()
{
  if( query("hp")+500 < query("max_hp") )
  {
    message_vision("$N身上發出淡淡的紅光。\n",this_object());
    add("hp",250+random(200));
    return;
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(8))
  {
    me->start_busy(2);
    target->add_busy(1);
    message_vision("\n$N突然停止了動作，頭上的三隻眼睛漸漸發出"HIR"紅光"NOR"！！\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  else if(!random(8))
  {
    me->start_busy(1);
    target->add_busy(3);
    message_vision("\n$N"HIW"飛上了半空，雙翼猛力搧動！！\n"NOR,me);
    call_out("do_super2",1,me);
    return 1;
  }
  else if(!random(8))
  {
    message_vision( "$N發出一陣怒吼。\n", me );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision("\n$N"HIR"的三隻眼睛凝聚出強烈的紅色光柱，向四周掃射！！\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(200)+350-(inv[i]->query_armor());
      message_vision(HIR"$N被光柱擊中的部位瞬間著火焦爛.... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
/*    else
    {
      message_vision(HIR"\n$N在一瞬間燒成灰燼 .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
*/
  }
  me->start_busy(2);
  return;
}

void do_super2(object me)
{
  // 這裡的 me 是指 this_object()
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIW"\n空間中氣流衝撞引起沙塵滾滾，繼而拔樹走石，煞是驚人！！\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(100)+50;
      message_vision(HIW"$N被氣流捲起在半空中翻滾，落地時已是頭昏眼花氣血翻騰.... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
  }
  return;
}

int receive_damage(string type,int cost)
{
  object ob,me;
  ob = this_object();
  me = this_player();
  ::receive_damage(type,cost,me);
  return 0;
}

void die()
{
  object ob,eqp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
    HIG"\n\t【遺世島】："+RED"上古魔獸  "HIR"血眼"HIW"逆角龍"HIW"  被英勇的"+ob->name(1)+"消滅了...\n\n"+NOR
    ,users());
  ob->add("popularity",7);      
  tell_object(ob,HIG"你得到 7 點聲望。"NOR);
  if( random(5000) )
    eqp=new(__DIR__"eq/inverse-horn-helmet");
  else
    eqp=new(__DIR__"eq/blood-eye-dragon-armor");
  eqp->move(this_object());
  ::die();
  return;
}
