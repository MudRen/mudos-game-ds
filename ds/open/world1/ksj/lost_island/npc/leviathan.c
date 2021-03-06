#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIC"利貝亞森"NOR, ({"leviathan","_LEVIATHAN_"}) );
  set("long",@LONG
巨大的海蛇，擁有像劍一般的利牙，盔甲般的鱗甲，當牠在海中翻滾
時會引起大海嘯，是名符其實的海中王者，據說牠會襲擊船隻，至於
是何原因仍無人知曉。
LONG
);
  set("gender", "雄性");  
  set("race", "beast");
  set("unit","隻");
  set("age",2800);
  set("level",62);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",RED"  魔獸 "NOR); 
  set("limbs", ({ "頭部", "腹部","胸部","尾巴","背部"}) );
  set("verbs", ({ "bite"}) );
  set("Merits/bar",8);
  set("Merits/bio",9);
  set("Merits/wit",5);
  set("Merits/tec",5);
  add("addition_damage",90);
  add("addition_armor",150);
  set_temp("apply/hit",20);
  set_temp("apply/dodge",10);
  set("chat_chance", 30);
  set("chat_msg", ({
  HIC"利貝亞森"NOR"迅速地在海中翻騰出沒，身體不時閃爍波光。\n",
     (: heal :),
  }));

  setup();
        if(random(100)>90) // 10%
                carry_object(__DIR__"eq/treasure-paper1");
        if(random(100)>90) // 10%
                carry_object(__DIR__"eq/treasure-paper2");
        if(random(100)>90) // 10%
                carry_object(__DIR__"eq/treasure-paper3");

  set_living_name("_NPC_LEVIATHAN_");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") > 25 && userp(this_player()) )
    this_object()->kill_ob(this_player());
  if(!random(3))
  {
    message_vision(HIC"利貝亞森"HIR"突然從海浪中竄出，令$N來不及反應慌了手腳！！\n\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

void heal()
{
  if(query("hp") > query("max_hp")) return;
  add("hp",250+random(120));
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(8))
  {
    me->start_busy(1);
    target->add_busy(2);
    message_vision("\n$N突然潛入海中，隨即在海中翻攪，引發吞天滅地的"HIC"大海嘯"NOR"！！\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  else if(!random(7))
  {
    message_vision( "$N張開長滿無數利牙的大嘴。\n", me );
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

  message_vision(HIC"\n大海嘯瞬間已經移動到這裡，眼前望去只有濤天的海水！！\n"NOR,me);
  message_vision("\n你無處可逃，只有凝聚內力承受這一擊！\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(250)+190;
      message_vision(HIC"$N被數十噸的海水重壓，頓時口吐鮮血，癱在一旁.... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      if( inv[i]->query_con() > 90 )
        inv[i]->add_busy(1);
      else if( inv[i]->query_con() > 75 )
        inv[i]->add_busy(2);
      else
        inv[i]->add_busy(3);
      COMBAT_D->report_status(inv[i]);
    }
/*
    else
    {
      message_vision(HIC"\n$N被強烈的海流捲走了 .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
*/
  }
  me->start_busy(1);
  return;
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
       HIG"\n\t【遺世島】："+RED"上古魔獸  "HIC"利貝亞森"HIW"  被英勇的"+ob->name(1)+"消滅了...\n\n"+NOR
       ,users());
  ob->add("popularity",7);      
  tell_object(ob,HIG"你得到 7 點聲望。"NOR);
  if( random(5000) )
    eqp=new(__DIR__"eq/leviathan-mask");
  else
    eqp=new(__DIR__"eq/leviathan-earring");
  eqp->move(this_object());
  ::die();
  return;
}
