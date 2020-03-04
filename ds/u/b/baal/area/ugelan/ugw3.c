#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", RED"幽遮蘭城城西守備隊駐所"NOR);
        set("long", @LONG
你來到了一間大通舖，這裡是幽遮蘭城城守備隊的寢室
，近十張的兩層式臥鋪圍繞著房間中央的一張大圓桌放在這
房間裡，有的床似乎還是空的，有的上面則凌亂的丟著一些
內衣褲，房內唯一的照明來自圓桌上一跟點燃的蠟燭。
LONG
        );
        set("exits", ([ 
                        "east": __DIR__"ugw2",
            ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        create_door("east","木門","west",DOOR_CLOSED);

}

