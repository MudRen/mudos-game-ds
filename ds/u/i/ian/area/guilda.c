#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"石廊"NOR);

 set("long",@LONG
這裡擠滿了天梟教眾, 人人比肩繼踵, 石廊擠的水洩不通, 石廊充斥
著教眾的吵雜聲, 再加上頭頂來回飛翔的小鷹, 不斷發出銳鳴, 北邊的大
石室傳來整齊的禱告聲, 南邊的石門雖緊閉著, 還是透出了一陣一陣的藥
香, 整個石廊亂哄哄的, 雖然你已經摀住耳朵, 噪音仍然無情鑽進你的腦
袋裡, 狠狠的侵擾你的神經.
LONG
    );
 set("exits",([ "east":__DIR__"guild1",
                "west":__DIR__"guildb",
                "north":__DIR__"guilda_1",
                "south":__DIR__"guilda_2",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

