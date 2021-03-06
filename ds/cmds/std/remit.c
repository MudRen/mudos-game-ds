// hp cmds
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env,ob;
	string who;
        int amount,amount2;
	if(!arg) return notify_fail("請用 help remit 查詢用法。\n");
	if(sscanf(arg,"%s %d",who,amount)!=2)
	{
		if(sscanf(arg,"%d to %s",amount,who)!=2) return notify_fail("請用 help remit 查詢用法。\n");
	}
	if(amount < 2) return notify_fail("金額必須大於一個單位。\n");
	if(!env = environment(me)) return 0;
	if(area_domain(base_name(env)) != "world3") return notify_fail("只有未來世界才有電傳網路。\n");
	if(me->query("bank/future")< amount) return notify_fail("你的帳號裡沒有這麼多電子幣。\n");
	if(!ob = present(who, env))
	{
		if(!ob = find_player(who)) return notify_fail("沒有這個人。\n");
	}
	if( me == ob ) return notify_fail("給自己?想犯法吧\n");
	if(!living(ob))
	{
		if(!ob = find_player(who)) return notify_fail("沒有這個人。\n");
	}
	if(area_domain(base_name(environment(ob)))!="world3") return notify_fail("對方不在電傳網路的控制範圍。\n");
	amount2 = amount - amount/20;
	if(amount%20 > 0) amount2 -=1;
	if( !interactive(ob) )
	{
		notify_fail("電傳網路回應了一個轉帳失敗的訊息。\n");
		if(ob->accept_remit(me,amount2))
		{
			ob->add("bank/future",amount2);
			me->add("bank/futrue",-amount);
			return 1;
		} else return 0;
	}
	tell_object(ob,HIW"電傳網路通知你: "+me->name(1)+"傳送了"+amount2+"點電子幣到你的帳戶。\n"NOR);
	tell_object(me,HIW"電傳網路回應: 已傳送"+amount+"點電子幣到"+ob->name(1)+"的帳戶。\n"NOR);
	ob->add("bank/future",amount2);
        me->add("bank/future",-amount);
	return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : remit <who> <數量> 或 remit <數量> to <who>
 
利用未來世界先進的電傳網路，將你(妳)在未來時空擁有的存款匯給
其他人，但是將會扣除匯款金額的5%做為手續費。

HELP
);

    return 1;
}

