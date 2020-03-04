// Room: /u/a/aiwa/room/home.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIG+"艾華工作室"+NOR);
	set("long", @LONG
真是令人驚訝！在這麼一個不起眼的小屋裡，居然有如此先進 ？
的設備，所有居家生活用品應有儘有！你看到有個人正坐在電腦
前聚精會神的操作著電腦， 還是不要去打擾他好了！ 
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
            ]));

	set("light", 1);

	set("exits", ([ /* sizeof() == 7 */
		"out" : "/u/a/aiwa/workroom",
            ]));

	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me=this_player();
	add_action("do_out","out");
	if(me->query("id")!="aiwa")
		tell_object(me,"\n"HIW+"某人(Somebody)告訴你: 不要打擾他寫程式喔!!\n");
}

void do_out()
{
	object me;

	me = this_player();
	tell_object(me,"\n\n[1;37m謝謝光臨艾華工作室\n\n");
	tell_object(me,"有空再來坐喔！[m\n\n\n");
}