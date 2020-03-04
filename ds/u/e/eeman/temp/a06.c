#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIC"斯蘭街"NOR);
        set("long", "古老的街景，碩大的石磚，這條類似中古世紀歐洲的街道充滿著
古意盎然的模樣。兩排的櫻木開滿了茂盛的枝葉，地下舖著用櫻花做
的地毯，在樹底下有著一些情侶在談情，也有家人一起來賞櫻的，一
幅美麗的圖案顯現在你的眼前。北邊有著鎮上唯一的雜貨舖。
");
        set("exits", ([
        "west":__DIR__"a10",
        ]));
        set("outdoor",1);
        setup();
        replace_program(ROOM);
}

