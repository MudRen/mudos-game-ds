// 這個檔案沒有縮排!! 請自己做好縮排
// 我改了幾個bug, 但是還是有不少bug. 加油吧!
// delay() 要分出來. 否則施法完全不會delay

#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
 int inn,sk,cost,lev;	//請不要用 in 當變數, 我改為inn
 int lv,mk,lck;
 string who,name;
 
 if(!me) me=this_player();
 inn=me->query_int();	//luky fix
 lev=me->query("level");
 mk=me->query_skill("mindkill",1);
 sk=mk/10+1;
 cost=sk*20;

/* 盡量不要讓法術只有戰鬥能用, 攻擊性法術只要加上最後幾行讓NPC反擊即可.
 if ( !me->is_fighting())
    return notify_fail("這法術只有戰鬥時才能使用。\n");
*/
 if ( !target ) target = offensive_target(me);
 if ( !target||!objectp(target = present(target, environment(me)))||target==me )
     return notify_fail("你要對誰施展這個法術﹖\n");
 if( !living (target) )
     return notify_fail(HIY"這不是生物喔！\n"NOR);
 if( lev > target->query("level") && userp(target) ) //放到尋找target之後, 且只需對userp
 {
  if( target->query("level")<5 )
     return notify_fail("不能欺負還沒長大的小孩，這樣不好ㄡ。\n");
  else
     return notify_fail("你不能欺負等級比你小的玩家。\n");
 }
 if ( mk<1 )
    return notify_fail("你沒學過這這法術。\n");
 if( me->query_temp("mk")>0 )
    return notify_fail("你正在努力施法，別催了。\n");
 if( (int)me->query("mp") <  cost )
    return notify_fail("你的魔力不夠。\n");
 me->add("magicexp",2+random(3));
 me->add("mp", -cost);
 message_vision(HIG"$N集中自己的精神.."+
 "開始心神歸一，精神力量充滿全身\n\n"NOR,me);

  me->start_busy(2);
  call_out("delay",3,target,me,mk);
  return 1;
}

int delay(object target,object me,int mk)
{
 int tlv,inn,lv,sk,i,damage;
 							//在delay之後,要考慮物件的變化
 if(!me) return 0;					//1.me 可能死亡或是離線
 if(!target) return notify_fail("目標消失了。\n");	//2.target可能死亡或是離線
 if( environment(me) != environment(target) )		//3.目標可能會離開.
  return notify_fail("目標離開了你的施法範圍。\n");
 sk=mk/20+random(mk/20)+1;
 inn=me->query_int();
 lv=me->query("level");
 message_vision(HIG"突然$N雙手一合,大喝一聲！ "
 +HIC"∼∼ §靈∼∼殺∼∼術§∼∼\n\n"NOR,me);

 tlv=target->query("level");

 if( lv + random(inn) + inn > tlv+ random(inn) )
 {
  for ( i=0 ; i <= sk ; i++)
  { 
    message_vision(HIG"$N"HIG"的靈殺術直擊$n"HIG"的心靈！ "NOR,me,target);
    damage=( inn + (1+random(2)) + mk * random(5) ) * random(2); //這一行碼要好好想想再寫過
    damage -= target->query_sheild();	//query_shield()會傳回該人物之魔法防禦力
    if ( damage > 0)
    {
       message_vision(HIY"造成$N"HIW+damage+HIY"點的傷害！！！！\n"NOR,target); 
       target->receive_damage("hp", damage, me ); 
    }
    else
    message_vision(GRN"$N"GRN"心靈堅定，將靈光彈開！\n"NOR,target);
  }
 }
 COMBAT_D->report_status(target);	//加上這行可以顯示target的健康狀況
 target->start_busy(3);
 if( mk>1 )
 {
     if( inn>random(20) )
       if( me->query("magicexp")>sk )
       {
         me->improve_skill("mindkill",inn+random(20));
         me->add("magicexp",-sk);
       }
 }
 if(!target->is_fighting(me)) target->kill_ob(me);	//攻擊性法術加上這兩行
 if(!me->is_fighting(target)) me->kill_ob(target);	//
 return 1;
}
