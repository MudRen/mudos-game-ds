// force_push.c
// mulder 我只幫你寫被攻擊者被移到別格房間的程式...
// 剩下的部分你應該自己寫囉....還有...被攻擊者能不能到那間房間
// 也要你自己把它完成...就降子...
//					Shengsan@DS
inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
	mapping exit=([ ]);
	string to_dir,to_dir_name,*dir,*dir_name;
	int i;
	object env;

	if(!me) me=this_player();

	env = environment(me);

	if(env->query("no_cast")) return notify_fail("這裡不能施法。\n");

	if ( !target ) target = offensive_target(me);
	if ( !target )	return notify_fail("你要對誰施展這個法術﹖\n");

	exit = env->query("exits");
	dir_name = keys(exit);
	dir = values(exit);

// debug 用....
//	for(i=0;i<sizeof(dir);i++)
//	{
//		write(i+" :"+dir[i]+"\n");
//	}
	i = random(sizeof(dir));
	to_dir = dir[i];
	to_dir_name = dir_name[i];
	target->move(to_dir);
	write( target->query("name")+"被莫名之力推至 "+to_dir_name+" 了\n");

	return 1;
}
if(me->query_spell("force_push",1) < 90)
{
damege
};
else
move

{
 int inn,sk,cost,mk;
 
 if(!me) me=this_player();
 inn=me->query_int();
 mk=me->query_spell("force_push");
 sk=mk/10+1;
 cost=(mk/3)+10;
 
 if(environment(me)->query("no_cast")) return notify_fail("這裡不能施法。\n");
 
 if ( !target ) target = offensive_target(me);
 if ( !target )	return notify_fail("你要對誰施展這個法術﹖\n");

	//檢查是否可以攻擊
 if(!me->can_fight(target))
		return me->can_fight(target);

 if( (int)me->query("mp") <  cost )
	    return notify_fail("你的法力不夠。\n");
	    
 message_vision(HIG"\n$N眼光一閃，望向$n\n"NOR,me);
 me->start_busy(2); //施法動作時間
 me->receive_damage("mp",cost);	//施法扣MP
 me->set_temp("power_cast",2+mk/20);
 call_out("delay",3,target,me,mk);
 return 1;
}

int delay(object target,object me,int mk)
{
	
 int inn,sk,damage;
							
 if(!me) return 0;					
 if(!target) return notify_fail("目標消失了。\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("目標離開了你的施法範圍。\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"因為受到創傷而亂了思緒, 無法順利施展Force Push。\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 sk=mk/20+random(mk/20)+1;
 inn=me->query_int();
 
 message_vision(HIG"\n$N你申出五指，指向$n！！\n\n"NOR,me,target);

    damage= inn +random(mk+inn);
    damage = damage- target->query_sheild()/2 -random(target->query_sheild());
    if(damage<1) damage=random(inn/2);

 if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
    if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()))
    {
	// 增加素質對傷害的影響
	damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
       target->receive_damage("hp", damage, me ); 
       message_vision(HIC"  只見$N閃避不給$n的攻擊，$N向後直飛並「啊」的一聲大叫！"NOR,target);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
	tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       if(wizardp(me) && me->query("env/debug")) tell_object(me,"  造成"+damage+"點傷害!!\n"); 
       COMBAT_D->report_status(target);		//顯示target狀態
       target->start_busy(1);
    }
    else
	{
       		message_vision(GRN"  只見$N十分狼狽地閃避開$n的攻擊。\n"NOR,target);
	}
 } else message_vision(GRN"只見$N左閃右避「Force Push」的攻勢，但是也中了。\n"NOR,target);


 if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
 if(!target->is_fighting(me)) target->kill_ob(me);
 if(!me->is_fighting(target)) me->kill_ob(target);
 return 1;
}

