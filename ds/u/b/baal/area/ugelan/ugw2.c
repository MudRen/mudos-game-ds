#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", RED"幽遮蘭城城西守備隊駐所"NOR);
        set("long", @LONG
牆上插著數支火炬，將走廊照的燈火通明，走廊兩邊各
掛著一面戰旗，走廊的兩旁及盡頭各有一扇木門，門上雕著
守備隊共同的徽記：一面被區分為四個區域的盾牌，其四個
區域分別刻上的不同的印記，走廊盡頭那扇門兩旁著各放了
一副中古樣式的連身鎧甲以為裝飾用。
LONG
        );
        set("exits", ([ 
                        "north": __DIR__"ugwcommand",
                        "south": __DIR__"ugw1",
"west": __DIR__"ugw3",
"east": __DIR__"ugw4",
            ]));
           set("item_desc",([
"盾牌徽記" : "
一個盾牌形狀的徽記，被區分為四塊，左上雕著一個卷
軸，代表命令，右上雕著一本厚厚的大書，代表法律，
左下則是一雙互握的雙手，代表團結，最後在右下則有
著一把長劍，代表力量，這個徽記代表了構成守備隊的
四個要素：命令、律法、團結、及力量。\n",
"戰旗" : "
代表幽遮蘭城城西守備隊的戰旗，紅底藍邊，上繡著一
朵大波斯菊中崁有一顆藍色寶石。\n",
                 ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
                create_door("north","木門","south",DOOR_CLOSED);
create_door("west","木板門","east",DOOR_CLOSED);

}

