#include <room.h>
inherit ROOM;
void create()
{
 set("short","八陣圖前方入口");
 set("long",@LONG
你眼前所見的就是神奇的八陣圖了, 傳說中有八個陣門, 可是
你在這種昏暗的環境中跟本無法分辨整個陣局, 若是冒然進入恐怕
會不得其門而出, 最好是小心為妙.
LONG
    );
 set("exits",([ "west":__DIR__"secret1_8",
                "southeast":__DIR__"secret6_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
