#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
	set("short",HIG"���"HIW"�u�@��"NOR);
	set("long","�o�̤@����h, �ɬO"HIC"�C�s"HIG"���"NOR", �A���T�X���u��b�o���H���b�g\n"
"����......""\n\n\n"
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
