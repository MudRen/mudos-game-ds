#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"神隼聖廊"NOR);

 set("long",@LONG
這條走廊不算長, 如果在平時, 你可以輕輕鬆鬆的走過, 甚至不會
注意到這條走廊, 但, 這條走廊有所不同, 它沒有會噴火的機關, 沒有
會考驗你武技的銅人, 沒有兇猛的獅子, 虎豹, 更沒有會陷落的地板,
只是, 這裡站滿了... 一隻一隻的隼, 他們像山霸王一樣占滿整個走道
, 有的甚至建立起自己的家園, 看來你要通過這裡得費一番功夫了, 在
你的頭頂上方有一個匾額, 上面刻著『神隼聖廊』四個大字, 看來這名
字真是取的再恰當不過了.
LONG
    );
 set("exits",([ "south":__DIR__"guild2",
                "north":__DIR__"guild4",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

