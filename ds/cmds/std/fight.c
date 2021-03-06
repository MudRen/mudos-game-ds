// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target,owner;
	
        if(me->is_ghost()) return notify_fail("	你現在還是鬼魂吧\n");
	if( environment(me)->query("no_fight") || environment(me)->query("no_kill"))
		return notify_fail("這裡禁止戰鬥。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻擊誰﹖\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一點﹐那並不是生物。\n");

	if( obj->is_fighting(me) )
		return notify_fail("加油﹗加油﹗加油﹗\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "已經無法戰鬥了。\n"); 
        if(obj->is_ghost()) return notify_fail("這個人並沒有形體。\n");
	if(obj==me)	return notify_fail("你不能攻擊自己。\n");
	if(userp(me) && !userp(obj) && obj->query_temp("pending/fight")!=me) return notify_fail("你只能找玩家比試武藝。\n");
	if(!me->can_fight(obj))	return me->can_fight(obj);
	//lock here
	//if(!wizardp(me) && !wizardp(obj)) return notify_fail("	Fight指令暫停使用中。\n");
	
	if(!userp(me) && userp(owner=me->query("creater")) && userp(obj) )
	{
 		if(!owner->can_fight(obj))
 		tell_object(owner,"你不可以攻擊此人!!\n");
		return owner->can_fight(obj);
	}
	
	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me ) {
		message_vision("\n$N對著$n說道﹕" 
			+ RANK_D->query_self(me) 
			+ me->name() + "﹐領教"
			+ RANK_D->query_respect(obj) + "的高招﹗\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "取消了和你比試的念頭。\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "如果你願意和對方進行比試﹐請你也對" + me->name() + "("+(string)me->query("id")+")"+ "下一次 fight 指令。\n" NOR);
		write(YEL "由於對方是由玩家控制的人物﹐你必須等對方同意才能進行比試。\n" NOR);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N對著$n說道﹕" 
			+ RANK_D->query_self(me) 
			+ me->name() + "﹐領教"
			+ RANK_D->query_respect(obj) + "的高招﹗\n\n", me, obj);

		notify_fail("看起來" + obj->name() + "並不想跟你較量。\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N大喝一聲﹐開始對$n發動攻擊﹗\n\n", me, obj);
		me->fight_ob(obj);
		obj->fight_ob(me);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : fight <人物>
 
這個指令讓你向一個人物「討教」或者是「切磋武藝」﹐這種形式的戰鬥純粹是
點到為止﹐因此只會消耗體力﹐不會真的受傷﹐但是並不是所有的  NPC 都喜歡
打架﹐因此有需多狀況你的比武要求會被拒絕。
 
其他相關指令: kill

PS. 如果對方不願意接受你的挑戰﹐你仍然可以逕行用 kill 指令開始戰鬥﹐有
    關 fight 跟 kill 的區分請看 'help combat'.
HELP
    );
    return 1;
}
 
