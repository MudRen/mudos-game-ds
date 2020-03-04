#include <ansi2.h>
inherit ROOM;

int go_bus();
int down_rebus();

void create()
{
	set("short", "空中纜車內");
	set("long", @LONG
這裡是空中纜車的內部。因為在很高空，所以視野非常的好。而
且這台纜車經過十分嚴格的測試，所以安全性無疑。從窗外望出去，
底下的房子都變的小小的。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("no_recall",1);

	setup();
}
void init()
{
	object me;
	me=this_player();
	
	if(!me) return;
	
	me->start_busy(4);
	call_out("go_bus",2,0);
}
int go_bus()
{
	object me;
	me=this_player();
	
	if (!me) return 0;
	
	tell_object(me,HIW"\n慢慢的，回到了報名地點的候車室。\n"NOR);
		       
	call_out("down_rebus",2,0);
}
int down_rebus()
{
	object me;
	me=this_player();

	if(!me) return 0;
	
	tell_object(me,HIW"\n\n一陣搖晃，纜車停了下來。\n"NOR
		       HIW"\n你打開了車門，走了出去。\n"NOR);
	
	me->move(__DIR__"chris1");
	return 1;
}