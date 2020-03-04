// Roo: /d/guu/yaofang.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"藥房"NOR);
	set("long", @LONG
這里是一間石室，周圍的火把將石室照的燈火通明，石室里面擺滿
了很多瓶瓶罐罐，上面都貼好了標簽，一瓶瓶玉蜂漿被古墓弟子制成后
放在此處。你能看見幾個古墓弟子正在忙碌的干活。
LONG	);
	set("exits", ([
		"north" : __DIR__"mudao10",
	]));
        set("objects", ([ /* sizeof() == 1*/
          __DIR__"npc/apprentice2" : 3,
        ]));      

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

void init()
{
//	add_action("do_make","make");
//	add_action("do_make","huo");
}

int do_make(string arg)
{
	object ob, name1, me = this_player();
	int exp,pot,score;

	ob= present("feng mi", me);
	name1= me->query("id");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙著呢。\n");	
	if ( arg =="jiang")
	{
		if ( ! me->query_temp("gm_job1"))
            return notify_fail("你還沒去採蜜呢，無法製造玉蜂漿。\n");
		if (!objectp(present("feng mi", me)))
            return notify_fail("你用什麼來制成玉蜂漿？\n");
		if ( ob->query_temp("gm/make") != name1 )
			return notify_fail("這蜂蜜好象不是你采來的吧？\n");	
		message_vision(HIY"$N仔細地將蜂蜜調和均勻，制成玉蜂漿，放在架上。\n"NOR,me);
		me->delete_temp("gm_job1");
		exp=40+random(20);
		me->add("combat_exp",exp);
		pot= 10+random(10);
		me->add("potential",pot); 
		score=2+random(5);
		me->add("score",score);
		call_out("destroying", 1, ob);
//        tell_object(me,HIW"因為勞作，你增長了：" + chinese_number(exp) + "點實戰經驗" + chinese_number(pot) + "點潛能" + chinese_number(score) + "點江湖閱歷。\n"NOR); 
		return 1;
	}
    return notify_fail("你想把蜂蜜製成什麼？\n");
}

void destroying(object ob)
{
	destruct(ob);
	return;
}

