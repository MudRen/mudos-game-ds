#include <path.h>
#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name(HIW"雪玉鐲"NOR,({ "ice bracelet","bracelet" }) );
  set("long",HIW @LONG
一只雪白的玉鐲，隱隱發出白光，從玉鐲傳來清涼入心而不寒冷的涼
意，你不由得小心弈弈深怕不小心摔壞了它(break)。
LONG NOR);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(500);
    set("unit", "副");
    set("value",6000);
    set("volume",1);
    set("light",1);
  }
  set("armor_prop/armor", 2);
  set("armor_prop/shield",5);
  set("limit_con",20);
  set("limit_int",15);
  set("armor_prop/int", 2);
  if( !random(30) )
  {
    set_name(HIC"雪玉鐲"NOR,({ "ice bracelet","bracelet" }) );
    call_out("receive_by_bracelet", 30);
  }
  setup();
}

void init()
{
  add_action("break_bracelet","break");
}

int break_bracelet(string str)
{
  object me,env,ob,z,b;
  me=this_player();
  env=environment(me);
  ob=find_living("_NPC_KEN_");
  if(!me) return 0;
       
  if(str=="bracelet")
  {
    message_vision(
    HIW"\n$N一狠心拿起雪玉鐲往地下用力一砸，頓時雪玉鐲碎裂成無數破片\n"NOR
    HIW"\n，同時周遭寒氣被碎片吸收化成溫暖的白光，$N在白光中只覺得宛如重生！\n"NOR,me);
    me->receive_heal("hp",me->query("max_hp") - me->query("hp"));
    me->receive_heal("ap",me->query("max_ap") - me->query("ap"));
    me->receive_heal("mp",me->query("max_mp") - me->query("mp"));
    me->receive_curing("head", 50);
    me->receive_curing("body", 50);
    me->receive_curing("right_arm", 50);
    me->receive_curing("left_arm", 50);
    me->receive_curing("right_leg", 50);
    me->receive_curing("left_leg", 50);
    me->apply_condition("poison", 0);
    me->apply_condition("blooding", 0);

    if( objectp(z=present("warrior ice statue",env)) )
    {
      if( objectp(ob) )
      {
        if(!environment(ob) )
        {
          destruct(ob);
        }
        else
        {
          message_vision(HIW"\n冰像受到雪玉鐲白光照射迅速地融解成一灘水。\n"NOR,me);
          destruct(z);
          destruct(this_object()); 
          return 1;
        }
      }
      message_vision(HIW"\n冰像受到雪玉鐲白光照射迅速地融解，冰塊中的武者也慢慢回復血色。\n"NOR
        HIC"\n柳生．筧向$N深深一鞠躬，隨後往山頂的方向縱躍而去。\n"NOR,me);
      message("world:world1:vision",
        HIR"\n\t柳生．筧喊道：八歧大蛇！今日定要將你這禍害除去！！\n\n"NOR
        ,users());
      b=new("open/world1/ksj/east_island/npc/ken.c");
      b->move("open/world1/ksj/east_island/room110.c");
      destruct(z);
    }
    destruct(this_object());
    return 1;
  }
}

void receive_by_bracelet()
{
  object me = environment(this_object());
  int p_mp;
  if( !this_object() || !me ) return;
  if( me->query_temp("armor/wrists")==this_object() )
  {
    p_mp = me->query("max_mp");
    if( me->query("mp") < p_mp*4/5 )
    {
      me->receive_heal("mp", p_mp*1/100);
      message_vision(HIW"雪玉鐲突然發出一道白光，你頓時感覺神清氣爽。\n"NOR, this_object(), me);
    }
  }
  call_out("receive_by_bracelet", 35);
}
