#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
 int in,sk,cost,s,lev;
 int lv,mk,lck,tlv,r;
 int damage;
 string who,name;
 object victim;
 me=this_player();
// wis=this_player()->query("wis");
 in=this_player()->query("int");
 lev=this_player()->query("level");
 mk=me->query_skill("mindkill",1);
 cost=sk*20;
  if( lev > target->query("level"))
{
  if( target->query("level")<5 )
     return notify_fail("不能欺負還沒長大的小孩，這樣不好ㄡ。\n");
  else
     return notify_fail("你不能欺負等級比你小的玩家。\n");
}
 if ( !me->is_fighting())
    return notify_fail("這法術只有戰鬥時才能使用。\n");
 if ( !target ) target = offensive_target(me);
 if ( !target||!objectp(target = present(target, environment(me)))||target==me )
     return notify_fail("你要對誰施展這個法術﹖\n");
  if( !living (target) )
     return notify_fail(HIY"這不是生物喔！\n"NOR);
 if ( mk<1 )
    return notify_fail("你沒學過這這法術。\n");
 if( me->query_temp("mk")>0 )
    return notify_fail("你正在努力施法，別催了。\n");
 if( (int)me->query("mp") <  cost )
    return notify_fail("你的魔力不夠。\n");
 me->add("magicexp",2+random(3));
 me->add("mp", -cost);
 message_vision(HIG"$N集中自己的精神\n\n"+
 "開始心神歸一，精神力量充滿全身\n\n"
 +"突然$N雙手一合,大喝一聲！\n\n"
 +"§靈∼∼殺∼∼術§"NOR,me);

 tlv=target->query("level");
// lck=target->query("lck");
 name=target->query("name");
// evil=target->query("evil");
 me->start_busy(1);

 if( lv + random(in) + in > tlv+ random(in) )
{
  for ( r=0 ; r <= sk ; r++)
  { 
    message_vision(HIG"$N的靈殺術直擊敵人的心靈！\n\n"NOR);
    damage=( (in+in) * (1+random(2)) + mk * random(5) ) * random(2);
    if ( damage > 0)
      {
       message_vision(HIY"造成$n"+damage+"點的傷害！！！！\n"NOR,victim); 
       victim->receive_damage("hp", damage, me ); 
      }
 else
 message_vision(HIY"$n心靈堅定，將靈光彈開！\n"NOR,name);
}
    call_out("delay",2,target,me);
  }
// me->set_temp("mindkill",1);
 target->start_busy(3);
{
 if( mk>1 )
   {
 if( in>random(20) )
   if( me->query("magicexp")>sk )
   {
   me->improve_skill("mindkill",in+random(20));
   me->add("magicexp",-sk);
   }
}
 return 1;
}
}
