#include <ansi2.h>
inherit ROOM;
inherit F_SAVE;

string str;
int roll1,roll2,comp1,comp2;
mapping game_record;

string query_save_file() 
{
        return DATA_DIR+"game/sdo_snowman";
}
void create()
{
	set("short", "雪山上");
	set("long", @LONG
這裡是一座高山上的平台，四周白茫茫的一片，充滿著冬天的氣
氛。你看了看四周，有不少的遊客在堆雪人、打雪仗，玩的不亦樂乎
。這裡有一塊地被主辦單位圍了起來，看來就是比賽的地點了。
LONG
	);
	set("exits", ([
		"south" : __DIR__"chris2",
	]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("no_recall",1);
	set("outdoors", "land");

	setup();
}
void init()
{
	::init();
	add_action("do_build","build");
}
int do_build(string str)
{
	object me,room;
	me=this_player();
	room=find_object(__DIR__"obj/record_board.c");
	
	if (!me) return 0;
	if( me->is_busy() ) return notify_fail("你現在還在忙。\n");
	if (!str) return notify_fail("你想做什麼東西？\n");
	if (str=="body" && me->query_temp("sdogame/build")=="body") return notify_fail("你現在已經是在做身體了！\n");
	if (str=="head" && me->query_temp("sdogame/build")=="head") return notify_fail("你現在已經是在做頭部了！\n");
	if (str == "body" || str == "head")
	{
		add_action("do_roll","roll");
		add_action("do_compress","compress");
	}
	if (str=="body")
	{
		tell_object(me,"你打算開始動手做雪人的身體了！\n");
		me->set_temp("sdogame/build",str);
	}
	if (str=="head")
	{
		tell_object(me,"你打算開始動手做雪人的頭部了！\n");
		me->set_temp("sdogame/build",str);
	}
	if (str=="snowman")
	{	
		me->start_busy(6);
		
		roll1=me->query_temp("sdogame/roll1");
		roll2=me->query_temp("sdogame/roll2");
		comp1=me->query_temp("sdogame/comp1");
		comp2=me->query_temp("sdogame/comp2");
		
		if (roll1<=0 || roll2<=0 || comp1<=0 || comp2<=0) return notify_fail("你想要製作國王的雪人啊？\n");
		
		tell_object(me,HIW"你拍了拍手上的雪，小心翼翼的把雪球做成的頭放在雪球做成的身體上。\n"NOR);
		
		if ((roll1+comp1) < (roll2+comp2)) 
		{
			tell_object(me,HIW"『啪！』的一聲，雪球做成的頭掉了下來，散了一地！\n"NOR);
			return 1;
		}
		if ( comp1 < (comp2 *4/5))
		{
			tell_object(me,HIW"雪人的頭好像太重了，把身體壓爛了^^;...\n"NOR);
			return 1;
		}
		else
		{
			message_vision(
			HIW"$N把雪球做成的頭穩穩的放在身體上，撿了兩隻樹枝插在身體的兩邊都做手臂。\n"NOR
			HIW"接著撿了三個石頭，當作雪人的眼睛和鼻子，一個$N特製的雪人出現了！\n"NOR,me);
                        room->measure(me);
			return 1;
		}
		return 1;
	}
	return 1;
}
int do_roll(string str1)
{
	object me=this_player();
	string str;
	str=me->query_temp("sdogame/build");
	
	if (!me) return 0;
	if( me->is_busy() ) return notify_fail("你現在還在忙。\n");
	if (!str1 || str1 != "snowball") return notify_fail("你想滾什麼？\n");
	me->start_busy(1);
	if (str == "body")
	{
		roll1=me->query_temp("sdogame/roll1");
		comp1=me->query_temp("sdogame/comp1");
		if ( (roll1-1) > (comp1 * 3/2) || random(15)==0 )
		{
			tell_object(me,"你一個不小心，把正在滾的雪球弄散了。\n");
			me->delete_temp("sdogame/roll1");
			me->delete_temp("sdogame/comp1");
		}
		else
		{
			tell_object(me,"你的雪球似乎變大了些。\n");
			me->set_temp("sdogame/roll1",roll1+1);
		}
	}
	else if (str == "head")
	{
		roll2=me->query_temp("sdogame/roll2");
		comp2=me->query_temp("sdogame/comp2");
		if ( (roll1-1) > (comp1 * 3/2) || random(15)==0 )
		{
			tell_object(me,"你一個不小心，把正在滾的雪球弄散了。\n");
			me->delete_temp("sdogame/roll2");
			me->delete_temp("sdogame/comp2");
		}
		else
		{
			tell_object(me,"你的雪球似乎變大了些。\n");
			me->set_temp("sdogame/roll2",roll2+1);
		}
	}
	else
	{
		tell_object(me,"你想做什麼東西？\n");
	}
	return 1;
}
int do_compress(string str2)
{
	object me=this_player();
	string str;
	str=me->query_temp("sdogame/build");
	
	if (!me) return 0;
	if( me->is_busy() ) return notify_fail("你現在還在忙。\n");
	if (!str2 || str2 != "snowball") return notify_fail("你想壓實什麼東西？\n");
	me->start_busy(1);
	if (str == "body")
	{
		if ( random(10) == 0 )
		{
			tell_object(me,"你一不小心，把雪球壓壞了。\n");
			me->delete_temp("sdogame/roll1");
			me->delete_temp("sdogame/comp1");
		}
		else
		{
			tell_object(me,"你把雪球壓的結實了些。\n");
			me->set_temp("sdogame/comp1",comp1+1);
		}
	}
	else if (str == "head")
	{
		if ( random(10) == 0 )
		{
			tell_object(me,"你一不小心，把雪球壓壞了。\n");
			me->delete_temp("sdogame/roll2");
			me->delete_temp("sdogame/comp2");
		}
		else
		{
			tell_object(me,"你把雪球壓的結實了些。\n");
			me->set_temp("sdogame/comp2",comp2+1);
		}
	}
	else
	{
		tell_object(me,"你想做什麼東西？\n");
	}
	return 1;
}
