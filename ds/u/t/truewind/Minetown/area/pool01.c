#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "地下水道");
        set("long", NOR""+
"伸手不見五指，黑漆漆的地下水道，卻是礦區居民和礦工賴以維\n"+
"生的飲水系統所在的地方，一條一條的管線蔓延在四周圍，下水道中\n"+
"間有一條水道，似乎是居民主要的飲水來源。\n\n"+
"一條"HIG"綠色水道(river)"NOR"從角落流過去。\n\n");
        set("current_light", 0);
        set("exits", ([ /* sizeof() == 2 */
        "up" : __DIR__"machinefield5",
        "east" : __DIR__"pool02",
]));

	setup();
}
