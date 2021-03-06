/**
 * Shadow's area [荒廢漁村 - 古道 - oldway1]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"古道"NOR);
	set("long",@LONG
你進入了一條幽暗的的小徑，小路兩旁的雜草與肩齊高，四周突
兀地長著幾棵森天大樹，光線也被這幾棵大樹遮去大半，讓四周的氣
氛顯得有些怪異！舉目望去，方圓百里內似乎也看不到住戶，只見西
邊有一片更加茂密的森林，真讓人猶豫該不該繼續走下去！
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"a7",
		"west": __DIR__"oldway2",
	]));
  
	setup();
}

int room_effect(object me)
{
	switch(random(11))
	{               
		case 4:
		case 3:
			message_vision("∼呼∼ 四周吹來陣陣涼風。\n", me);
			return 1;
		case 2:
			message_vision("∼嘎∼嘎∼ $N突然被劃破寂靜的烏鴉聲嚇了一跳。\n", me);
			me->receive_damage("mp",random(5)+1);
			return 1;
		case 1:
		case 0:
			message_vision("$N突然感到一陣寒意，卻又說不出來哪裡不對勁。\n",me);
			return 1;
		default:
			return 1;
	}
}
