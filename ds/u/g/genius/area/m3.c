#include <ansi.h>
inherit ROOM;
void create()
{
set("short","山路");
 set("long", @LONG
你走在一條山路上，眼前斜坡愈來愈加傾斜，旁邊的林木也漸漸高大。
往西邊看去可以看到一個小池塘，水色相當混濁，看不見水裡面有什麼生物
，反倒是岸邊有幾隻鳥兒停在石頭上稍作休息，一動也不動。
LONG
);
set("item_desc",([
]));

set("exits",([
  "northeast":__DIR__"m2",
  "south":__DIR__"m4",]));
 set("objects",([
 ]));
setup();
}
