// Room: /u/t/tmr/area/city-door.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "滄縣北城門");
	set("long", @LONG
這是滄縣城的北城門，城門口下聚集著各種攤販，人聲頂沸，車水馬龍
，好不熱鬧啊!!不遠處有棵老榕樹，樹下的涼亭除了一些過往的旅客在休息
，守城官兵也圍坐在那，聽著他們"十八啦!!"的吆喝聲，你心裡倒也好笑起
來，卻也感受到此地的和平、安樂。往南是一條街道，往北出城門則是通往
城外的森林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
        "northeast" : COMINGING_PAST"area/forest5",
  "south" : __DIR__"street1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/garrison" : 4,
]));
	set("outdoors","land");
	set("no_clean_up", 0);
set("light",1);

	setup();
	replace_program(ROOM);
}
