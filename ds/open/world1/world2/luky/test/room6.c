#include <path.h>
inherit MOBROOM;
void create()
{
	set("short", "旅館外圍");
	set("long", @LONG

  這裡是旅館的外圍草地, 附近還長了一些小樹和一些從來沒有看過的小型
石雕。旁邊還有條小水溝, 不過裡面的水幾乎乾了, 還有一些飲料罐和塑膠
袋。

LONG
	);
set("exits", ([ /* sizeof() == 3 */
  "east" : LOGIN_NOW,
  "north" : __DIR__"room5",
]));

//        set("light",1);
        set("outdoors","land");
	set("chance",50);	//則有 50% 的機率會出現怪物.
	set("mob_amount",3);	//則最多出現三個怪物.
	set("mob_object",({	//設定怪物檔名.
	__DIR__"npc/bug",
	__DIR__"npc/mosquito",
	}) );
	setup();
	
	//注意, 繼承MOBROOM後 絕不可以有 replace_program(ROOM);
}
