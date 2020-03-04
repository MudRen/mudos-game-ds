#include <room.h>
inherit ROOM;
void create()
{
        set("short","茶館");
        set("long", @LONG
這間茶館看起來生意不錯, 雖然只有掌櫃和一位小二哥十分的
忙碌, 可是看得出來他們十分高興. 這邊兩三張桌子約略聚集了六
七個人. 在這種荒郊野外的茶館能有那麼多人, 你不禁覺得有點怪
異.
LONG
        );
        set("exits", (["out":__DIR__"mountdown3",]));
	set("light",1);
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
