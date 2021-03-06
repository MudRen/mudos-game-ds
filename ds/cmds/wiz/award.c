// award.c			Shengsan@DS
// 獎懲指令
inherit F_CLEAN_UP;
#include <ansi.h>
#define PRIZE_VALUE	 100
#define PUNISH_VALUE	-50

int help(object me);
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object target,obj;
	string type,note,who;
	int value,i,j;

	write("獎懲指令!!!\n");

	if(!arg || sscanf(arg, "%s -%s %d %s",who,type,value,note)!=4)
	{
		help(me);
		return 1;
	}
	if(!objectp(target = present(who, environment(me))) || !living(target))
		return notify_fail("這裡沒有這個人。\n");
	switch(type)
	{
		case "p":	break;
		case "r":	value *= -1; break;
		default:
		{
			help(me);
			return 1;
		}
	}

	target->add("award/totalvalue",value);

	if( target->query("award/totalvalue") <= PUNISH_VALUE )
	{
		message_vision("$N真是罪大惡極，$N的獎懲點數居然是 "+target->query("award/totalvalue")+" 點，看來$N該受點懲罰了。\n",target);
		for(j=0;j<10;j++)
		{
			target->skill_death_penalty();
			target->spell_death_penalty();
		}
		target->set("exp",0);
		target->set("combat_exp",0);
		target->set("dex",1+target->query("dex")/2);
		target->set("int",1+target->query("int")/2);
		target->set("con",1+target->query("con")/2);
		target->set("str",1+target->query("str")/2);
		target->save();
		target->add("award/totalvalue",-PUNISH_VALUE);
		return 1;
	}
/*	if( target->query("award/totalvalue") >= PRIZE_VALUE )
	{
		message_vision("$N"HIY"的獎勵點數已經集滿 "HIR+PRIZE_VALUE+HIY" 點，因此獲得替死娃娃一個。\n"NOR,target);
		obj = new("/open/always/doll");
		if(!obj->move(target))
		{
			destruct(obj);
			return notify_fail("...喔喔喔...替死娃娃取得失敗...\n");
		}
		target->add("award/totalvalue",-PRIZE_VALUE);
	}
*/
	if( userp(target)) log_file("award",
		sprintf("%s(%s) award %s (%d) on %s because %s\n", me->name(1), geteuid(me), target->name(1),value,
			ctime(time()),note ) );
	if(value>=0) message_vision("$N的獎勵點數目前是 "+target->query("award/totalvalue")+" 點，獎勵點數可以去兌換獎品喔。\n",target);
	else message_vision("$N的獎勵點數目前是 "+target->query("award/totalvalue")+" 點，小心犯規太多會受到嚴重懲罰喔。\n",target);
	return 1;
}

int help(object me)
{
write(@HELP

指令格式 : award [對象] [-p|-r] [獎懲數值] [補充說明]

獎懲項目:	-p	給予獎勵點數
		-r	給予懲罰點數
獎懲標準:

	更正錯字:				-p 1
	提供完整semote並採納:			-p 3
	提出富建設性之構想獲採用者:		-p 4
	主動回報有利玩家之Bug:			-p 6
	提供完整可行之構想企劃並獲採用者:	-p 8
	提供重大Bug解決方案,並有效者:		-p 10
	
	惡意騷擾他人:				-r 10
	以公開頻道散佈解迷方法:			-r 15
	利用bug牟利:(情節重大者砍檔)		-r 25
	其他違反rules之行為:			-r 10 ~ 25 (視情節輕重)
	
HELP
    );
    return 1;
}
