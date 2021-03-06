// relieve.c
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	
	seteuid(getuid(me));

	if(!arg)
		return notify_fail("請指定對象!!\n");

	ob = present(arg, environment(me));
	if (!ob) ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("這裡沒有這個人!!\n");

	if( me->query_skill("relieve") < random(50) )
		return notify_fail("你的解救行動失敗了。\n");

	if( ob == me )
		return notify_fail("你解救你自己幹嘛阿?\n");

	if( !ob->is_fighting() )
		return notify_fail(ob->query("name")+"目前並沒有跟任何人在戰鬥, 你解救誰阿?\n");
	if( me->is_ghost() )
		return notify_fail("\n你現在可是鬼呀！怎麼解救人阿？\n");
	if( me->is_busy() )
		return notify_fail("\n先等你做完手邊的事再說吧。\n");
	if( me->is_fighting_ob(ob) )
		return notify_fail("你正在跟"+ob->query("name")+"戰鬥耶...怎麼去解救他阿...\n");
	if( ob->is_fighting_ob(me) )
		return notify_fail(ob->query("name")+"正在跟你戰鬥耶...怎麼去解救他阿...\n");

	message_vision(HIG"$N"HIG"奮勇的向前解救"HIG"$n"HIG"﹗﹗﹗\n"NOR,me,ob);
	if( ! ob->relieve(me) )
		return notify_fail(me->query("name")+"解救"+ob->query("name")+"的行動失敗了...\n");
	else
	{
		tell_object(ob,me->query("name")+"出手解救了你﹗\n");
		tell_object(me,"解救成功\了﹗\n");
	}
	if( me->query("int")+me->query("level") < random(50) )
		me->improve_skill("relieve", random(3), 1);

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : relieve 對象

這是解救的指令，你必須要先學習「解救」這個技能才能使用。
當你解救你的對象後，原先被救者的敵人將會攻擊你，而且你一次只能解救一人。

HELP
    );
    return 1;
}

