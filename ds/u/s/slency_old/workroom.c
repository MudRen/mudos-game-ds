#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
	set("short",HIG"綠水"HIW"工作室"NOR);
	set("long","這裡一眼望去, 盡是"HIC"青山"HIG"綠水"NOR", 你不禁出神徜徉在這片人間淨土\n"
"之中......""\n\n\n"
);
        set("exits", ([ /* sizeof() == 5 */
	"meet" :__DIR__"meetroom",
	"past" : "/open/world1/meetroom",
	"wiz": "/d/wiz/hall1",
	"ugelan": "/u/s/slency/area/ugelan/inn",
	"pastworld" : "/open/world1/tmr/area/hotel",
]));
	set("light",1);
	set("valid_startroom",1);  
	set("objects", ([ /* sizeof() == 2 */
	__DIR__"npc/secretary" : 1, 
	__DIR__"area/ugelan/npc/fanten" : 1,
]));
	setup();
call_other( "/obj/board/slency_b", "???" );
	replace_program(ROOM);
}                   
