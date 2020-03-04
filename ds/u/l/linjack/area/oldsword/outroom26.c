#include <room.h>
inherit ROOM;
void create()
{
 set("short","空地");
 set("long",@LONG
這裡是向雲堂西南側的一個小空地, 你發現到, 所有的
空地之中, 只有這邊有侍衛在看守, 而且空地之中有道路隔
開一塊塊的草坪, 草坪也有園丁在照顧, 看起來這邊是比較
重要的地方. 東邊有樓梯回到向雲堂中.
LONG
    );
 set("exits",([ "south":__DIR__"outroom27",
                "west":__DIR__"outroom28",
                "eastup":__DIR__"inroom22",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
