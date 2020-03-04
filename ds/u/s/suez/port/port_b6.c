#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",GRN"地下洞穴"NOR);
	set("long",@LONG
一個巨大的地下洞穴突然出現在眼前，沒想到薩爾薩斯的地底竟有這
麼壯麗的景色，寬廣的地下河緩緩的流動著，在河面下點點的螢光不停的
閃爍，猶如從上方俯瞰星空一般。在東南方稍遠的黑暗中隱隱可以聽到低
沉的吼聲，迴盪在四周的空氣中，撼動著你靈魂的深處。
LONG 
);	
	set("light",0);
	set("exits",([
	    "out":__DIR__"port_b4"
		]));
	set("world","world1");
	setup();

}
int valid_leave(object me, string dir)
{
 	mixed *m=me->query("sarsass_2");
 	m=([1,1,1]);
	if( (dir=="out") && me->query_temp("sarsass_test_q") > 0 && !this_player()->query("sarsass_2"))
 	{
 	 	if(!m)  me->set("sarsass_2",m);
		m[1]++;
 		//紀錄執行這個行為後的屬性改變。//
 		me->set("sarsass_2",m);
	 }
        ::valid_leave(me, dir);
	}
	return ::valid_leave(me, dir);
}
