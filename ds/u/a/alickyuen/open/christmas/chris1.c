#include <ansi2.h>
inherit ROOM;

int go_airbus();

void create()
{
	set("short", HIW"堆雪人大賽報名處"NOR);
	set("long", @LONG
這裡是堆雪人大賽的報名處。首先映入眼簾的是許多要報名參加
比賽的民眾，正在報名的櫃檯前聚集詢問，而攤位上有親切美麗的服
務小姐在解說著。旁邊則是一個空中纜車的候車處。後面還有數位工
作人員正在忙進忙出的處理各種大大小小的事情，你注意到旁邊牆上
貼著一張公告。
LONG
	);
	set("item_desc",([
        	"公告":"欲參加活動者，請至櫃檯登記(register)。\n"
        ]));
        set("objects",([
	__DIR__"obj/record_board.c":1,
	]));
        set("exits", ([
        	"down" : "/open/world1/tmr/area/inn_3f",
	]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("no_recall",1);

	setup();
}
void init()
{
	string year;

        year = ctime(time())[20..23];
	if( year == "2001" )
	{
	add_action("do_register","register");
}
}
int do_register()
{
	object me,ob,obj;
	me=this_player();
	
	if(!me) return 0;
	me->start_busy(3);
	tell_object(me,HIW"\n工作人員親切的說：謝謝您的參加，請稍待一會。\n"NOR);
	if(!objectp(ob=present("christmas book",me)))
	{
		tell_object(me,HIW"\n工作人員看了看你後說：您身上好像沒有活動手冊，讓我給您一本吧。\n"NOR);
		ob=new(__DIR__"obj/christmas_book");
		obj=present("adventure notebook",me);
		ob->move(environment(obj));
	}
	call_out("go_airbus",2,0);
	return 1;
}
int go_airbus()
{
	object me;
	me=this_player();
	
	if(!me) return 0;
	tell_object(me,HIW"\n你站在候車室，看見了纜車由遠方靠近。\n"NOR
		       HIW"\n當纜車停下來之後，你打開纜車的車門，走了進去。\n\n"NOR);
	me->move(__DIR__"airbus");
	return 1;
}
