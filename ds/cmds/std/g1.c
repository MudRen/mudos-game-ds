// go.c
#include <ansi.h>

inherit F_CLEAN_UP;
inherit SSERVER;
mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"東",
	"west":			"西",
	"northup":		"北邊",
	"southup":		"南邊",
	"eastup":		"東邊",
	"westup":		"西邊",
	"northdown":		"北邊",
	"southdown":		"南邊",
	"eastdown":		"東邊",
	"westdown":		"西邊",
	"northeast":		"東北",
	"northwest":		"西北",
	"southeast":		"東南",
	"southwest":		"西南",
	"up":			"上",
	"down":			"下",
	"enter":		"內",
	"out":			"外",
]);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	mixed dest;
	string mout, min, dir,who,*busy_type;
	object env, obj,victim,ride,defender,protecter;
	mapping exit=([ ]),h_exit=([ ]),is_busy=([ ]);
	int wound=0,check=0,i=0;
	
	if( in_edit(me) || in_input(me) || me->query_temp("Fall_sleep")) return 0;
	if( !arg ) return notify_fail("你要往哪個方向走﹖\n");

	if( me->over_encumbranced() )
		return notify_fail("你的負荷過重﹐動彈不得。\n");

	if( me->is_busy() )
		return notify_fail("你的動作還沒有完成﹐不能移動。\n");
	if(mapp(is_busy=me->query_temp("is_busy")))
	{
		busy_type=keys(is_busy);
		for(i=0;i<sizeof(is_busy);i++)
		{
			if(stringp(is_busy[busy_type[i]])) return notify_fail(is_busy[busy_type[i]]+"\n");
			if(!is_busy[busy_type[i]]) return notify_fail("你暫時無法移動。\n");
		}
	}
	ride=me->query_temp("ride");
	if(wound = me->query("wound/foot") && !ride)
	{
		wound/=10;
		if(random(14-wound)==1) check = 1;
		if(wound>8 && check)
		{
			me->start_busy(1);
			return notify_fail(HIC"你的雙腳傷勢過重, 動彈不得。\n"NOR);
		} else
		if(wound>5 && check)
		{
			me->start_busy(1);
			return notify_fail(HIC"你的雙腳突然一陣疼痛, 痛的你無法移動。\n"NOR);
		}
	}
        env = environment(me);
        if(!env) return notify_fail("你哪裡也去不了。\n");
	exit = env->query("exits");
        h_exit = env->query("hide_exits");
        if( mapp(exit) && !undefinedp(exit[arg]) );
        else
        if( !mapp(h_exit) || undefinedp(h_exit[arg]) )
        {
        	if( query_verb()=="go")
	    		return notify_fail("這個方向沒有出路。\n");
                else
                        return 0;
        }
        if(!mapp(exit))
        {
        	dest = h_exit[arg];
        }
        else
        if( undefinedp(exit[arg]) )
        {
        	dest = h_exit[arg];
        }
        else
        {
        	dest = exit[arg];
        }

	if( stringp(dest) )
	{
	        if( !(obj = find_object(dest)) ) call_other(dest, "???");
	        if( !(obj = find_object(dest)) ) return notify_fail("無法移動。\n");
	        if( !env->valid_leave(me, arg) ) return 0;
	        if( !undefinedp(default_dirs[arg]) )
	                dir = default_dirs[arg];
	        else
	                dir = arg;
	        if(obj->is_house())
	        {
	        	obj->remeber_exit(env);
	        	env->set("exits/"+arg,obj);
	        }
	}
	else if( objectp(dest) )
	{
		obj=dest;
		if( !env->valid_leave(me, arg) ) return 0;
		if( obj->is_house() ) dir=obj->outside_vision(me);
		else dir=arg;
	}
	
	if( me->is_fighting() && victim = offensive_target(me))
	{
		if(
		   victim->visible(me)
		   && !userp(victim)
		   && random(2)
		   && random(victim->query_dex()) > random(me->query_dex()*2+10)
		   && !victim->is_busy()
		   && !victim->is_block()
		)
		{
			me->add_busy(1);
			return notify_fail(HIM"正當你想離開的時候，"+victim->name()+HIM"閃身擋住了你的去路!!!\n"NOR);
		}
		mout = "往" + dir + "落荒而逃了。\n";
		if(me->query("race")=="human")
			min = "滿頭大汗, 十分慌張地跑了過來。\n";
		else min = "很狼狽的逃了過來。\n";
		if(victim) 
		{
			tell_object(me,"  【離開時你注意到"+COMBAT_D->status(victim)+"】\n\n");
		}
	} else {
		mout = "往" + dir + "離開。\n";
		if(me->query("race")=="human")
				min = "來到此地。\n";
		else min = "來到此處。\n";

	}
	if(me->query_temp("hide")) me->delete_temp("hide");
	if(me->query_temp("sneak")) me->delete_temp("sneak");
	if(defender=me->query_temp("defender"))
	{
		defender->delete_temp("protecter");
		me->delete_temp("defender");
	}
	if(protecter=me->query_temp("protecter"))
	{
		protecter->delete_temp("defender");
		me->delete_temp("protecter");
	}
	who=me->name();
	if(ride) who=who+"騎著"+ride->name();
	if(me->query_temp("invis") < 1 )
	{
	 	message( "vision", who + mout, environment(me), ({me}) );
	}
	if( me->move(obj) )
	{
		me->remove_all_enemy();
		if(check)
		{
		   min+=me->name()+"抱著腳, 一副很痛苦的樣子。\n";
		   write("\n你雙腳的傷口隱隱作痛。\n");
		}
		if(me->query_temp("invis")<1)
			message( "vision", who + min, environment(me), ({me}) );
		me->delete_temp("visible_ob");
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	object env,target;
	mapping exits;
	string *directions;
	if(!me) return;
	if(!living(me) ) return;
	env = environment(me);
	if( !env || base_name(env) == VOID_OB ) return;
	exits = env->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, HIW"\n你開始找機會逃跑...\n"NOR);
	if(!userp(me) && random(2)) return;
	if(me->query("ride/riding"))
	{
		main(me, directions[random(sizeof(directions))]);
		return;
	}
	if(random(me->query("wound/foot"))>40)
	{
		tell_object(me, HIM"你想落跑可是你的雙腳卻不聽使喚..\n"NOR);
		return;
	}
	
	if(target = offensive_target(me))
	{
		if(random(10+me->query_dex()*2)<random(target->query_dex()) )
		{
			tell_object(me, HIM"糟了!!你想落跑可是卻被對手給攔住了!!!..這下子糗了..\n"NOR);
			return;
		}
	}
//	main(me, directions[random(sizeof(directions))]);
        me->force_me("go "+directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
讓你往指定的方向移動。
 
HELP
    );
    return 1;
}
