// Write by -Alickyuen@ds-
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "天地祕室");
        set("long", @long
這是一間專門提供給各分堂堂主及護法休息聊天的地方，裡面設
置有交流討論板，可以讓各分堂聯絡感情及討論戰術；另設有武器、
防具及道具陳列架，可以存放重要的物品專供堂主及護法們使用。
long);
        set("objects", ([
                __DIR__"item/axe2" : 1,
                __DIR__"item/heaven_box" : 1,
        ]));
        set("light", 1);
        set("no_kill", 1);
        setup();
        set("stroom", 1);
        load_object("/obj/board/sky_secret_b");
}

