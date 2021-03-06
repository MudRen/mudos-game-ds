// goto.c
#include <ansi.h>
inherit F_CLEAN_UP;
void go(object me,string env);
int main(object me, string arg)
{
	int goto_inventory = 0,world,world2;
	object obj,where;
	string msg;
	seteuid(getuid(me));
	if( !arg ) return notify_fail(@WHERE
	
 你要去哪裡﹖(goto workroom 或是 goto <who>)

	workroom	工作室
	aovandis	奧凡迪斯
	malo_town	梅龍鎮

WHERE
	);
	if(me->is_busy()) return notify_fail("你正在忙。\n");
	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;
	if( !arg ) return notify_fail("你要去哪裡﹖\n");
	if( environment(me) )
		if(environment(me)->query("no_goto") ) return notify_fail("這裡不能使用GOTO指令。\n");
	if(arg == "workroom" )
	{
		if(me->money_type()!=2) return notify_fail("請先自行回到現代。\n");
		obj = load_object("/open/world2/obj/workroom");
		if(!obj) return notify_fail("工作室已經垮了。\n");
		go(me,"/open/world2/obj/workroom");
		return 1;
	}
	if(arg == "aovandis" )
	{
		if(me->money_type()!=2) return notify_fail("請先自行回到現代。\n");
		go(me,"/open/world2/shengsan/aovandis/room079");
		return 1;
	}
	if(arg == "malo_town" )
	{
		if(me->money_type()!=2) return notify_fail("請先自行回到現代。\n");
		go(me,"/open/world2/lichi_town_2/map_5_26");
		return 1;
	}
			obj = find_player(arg);
			//if(!obj) obj = find_living(arg);
			if(!obj || !me->visible(obj))
			{
				return notify_fail("沒有這個玩家、生物、或地方。\n");

			}
			where=find_object("/open/always/ppl_jail");
			if( environment(obj)==where &&  wiz_level(me) < 2)
				return notify_fail("對方正在監獄服刑, 你最好不要去免的出不來。\n");
			world=me->money_type();
			world2=obj->money_type();
			// Extra limite for other world
			if(world != world2) return notify_fail("對方和你處於不同時空。\n");
			if(world != 2 && obj->query("level") > 5) return notify_fail("這個動作不是在你的工作範圍內。\n");
			// End of Extra limite
			if(!goto_inventory && environment(obj))	obj = environment(obj);
			
			if( !obj ) return notify_fail("這個物件沒有環境可以 goto。\n");
			
			if(!me->query_temp("invis"))
			{
    			  if( stringp(msg = me->query("env/msg_mout")) )
        			message_vision(msg+"\n", me);
			  else
				message_vision("$N大喊:"+HIW+" ＴＡＸＩ∼"+NOR+"突然一部計程車衝了出來把$N載走了。\n"NOR, me);
			}
			me->move(obj);
			if(!me->query_temp("invis"))
			{
			  if( stringp(msg = me->query("env/msg_min")) )
        			message_vision(msg+"\n", me);
			  else
				message_vision(HIW"不知道從哪裡衝出了一部計程車，$N打開車門走了下來。\n"NOR, me);
			}

	return 1;
}

void go(object me,string env)
{
 if(!me->query_temp("invis"))
 	message_vision("$N大喊:"+HIW+" ＴＡＸＩ∼"+NOR+"突然一部計程車衝了出來把$N載走了。\n"NOR, me);
 me->move(env);
 if(!me->query_temp("invis")) message_vision(HIW"不知道從哪裡衝出了一部計程車，$N打開車門走了下來。\n"NOR, me);                  
}
int help(object me)
{
write(@HELP
指令格式 : goto [-i] <目標>
 
這個指令會將你傳送到指定的目標. 
 
HELP
    );
    return 1;
}
