#include <room.h>
inherit ROOM;
void create()
{
 set("short","大走道");
 set("long",@LONG
這邊就是向雲堂壯麗無比的大走道, 寬達兩丈, 地上鋪著
青藍色有白雲花紋的地毯. 左右兩邊掛了很多字畫, 你看了一
看, 這幾首字畫都是你未曾見過的. 聽說是他們堂主自己題的
呢! 左右兩旁有幾名侍衛和奴僕和你道好.
LONG
    );
 set("exits",([ "north":__DIR__"inroom7",
                "south":__DIR__"outroom1",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}