#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"秘道"NOR);
	set("long", @LONG
這條陰暗的秘道在山腹中曲折延伸，不知通往何處。這裡有有一塊大
石柱(pillar)擋著向上的出口，往前走好像可以看見一點亮光。
LONG);
	set("item_desc",([
	"pillar" : "這是根巨型圓柱，看樣子應該可以扳(move)動它。\n",
	]));
	set("exits", ([
	      "west" : __DIR__"lane02",
	]));
	setup(); 
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object room, me = this_player();
	
	if( (int)me->is_busy() || me->is_fighting()) 
		return notify_fail("你正忙著呢。\n");
		
        if( !arg || arg!="pillar" ) return 0;
	
	message("vision","石柱忽然發出軋軋的聲音，向一側緩緩移開，向上露出一個光亮的出口。\n", this_object() );
	set("exits/up", __DIR__"backyard08");
	if( room = load_object(__DIR__"backyard08") ) {
		 room->set("exits/down", __FILE__);
		 message("vision","石柱忽然發出軋軋的聲音，露出一個黑洞洞的洞口。\n",room );
	} 
	remove_call_out("close_door");
	call_out("close_door", 5);
	return 1;
}

void close_door()
{
	object room;
	if( !query("exits/up") ) return;
	message("vision","頭頂上忽然發出軋軋的聲音，石柱又緩緩地收了回去，階梯消失了。\n", this_object() );
	if( room = load_object(__DIR__"backyard08") ) {
		room->delete("exits/down");
                message("vision", "石柱忽然發出軋軋的聲音，緩緩地移回原處，將向下的洞口蓋\住了。\n", room );
		}
	delete("exits/up");
}
