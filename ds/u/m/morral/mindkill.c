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
 sk=mk/10+1;
 cost=sk*20;
  if( lev > target->query("level"))
{
  if( target->query("level")<5 )
     return notify_fail("����ۭt�٨S���j���p�ġA�o�ˤ��n���C\n");
  else
     return notify_fail("�A����ۭt���Ť�A�p�����a�C\n");
}
 if ( !me->is_fighting())
    return notify_fail("�o�k�N�u���԰��ɤ~��ϥΡC\n");
 if ( !target ) target = offensive_target(me);
 if ( !target||!objectp(target = present(target, environment(me)))||target==me )
     return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");
  if( !living (target) )
     return notify_fail(HIY"�o���O�ͪ���I\n"NOR);
 if ( mk<1 )
    return notify_fail("�A�S�ǹL�o�o�k�N�C\n");
 if( me->query_temp("mk")>0 )
    return notify_fail("�A���b�V�O�I�k�A�O�ʤF�C\n");
 if( (int)me->query("mp") <  cost )
    return notify_fail("�A���]�O�����C\n");
 me->add("magicexp",2+random(3));
 me->add("mp", -cost);
 message_vision(HIG"$N�����ۤv���믫\n\n"+
 "�}�l�߯��k�@�A�믫�O�q�R������\n\n"
 +"��M$N����@�X,�j�ܤ@�n�I\n\n"
 +"���F�������N��"NOR,me);

 tlv=target->query("level");
// lck=target->query("lck");
 name=target->query("name");
// evil=target->query("evil");
 me->start_busy(1);

 if( lv + random(in) + in > tlv+ random(in) )
{
  for ( r=0 ; r <= sk ; r++)
  { 
    message_vision(HIG"$N���F���N�����ĤH�����F�I\n\n"NOR);
    damage=( (in+in) * (1+random(2)) + mk * random(5) ) * random(2);
    if ( damage > 0)
      {
       message_vision(HIY"�y��$n"+damage+"�I���ˮ`�I�I�I�I\n"NOR,victim); 
       victim->receive_damage("hp", damage, me ); 
      }
 else
 message_vision(HIY"$n���F��w�A�N�F���u�}�I\n"NOR,name);
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
