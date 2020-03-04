#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"青石廊"NOR);

 set("long",@LONG
石廊兩旁全是守衛, 個個虎目圓睜, 手緊緊抓著腰間匕首, 帶著警戒
心看著你, 像要看透你的心一般, 看的你全身發毛, 看來你在這只要心中
稍存歹念, 就會被這些守衛撕成碎片, 在走道旁有個階梯通到上面, 但,
在這麼多守衛的瞪視下, 你不禁開始考慮自己的安全... 
LONG
    );
 set("exits",([ "east":__DIR__"center1",
                "west":__DIR__"center3",
                "northup":__DIR__"hall",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

