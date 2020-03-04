#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"龍井斷橋"NOR);

 set("long",@LONG
這邊就是龍井棧道的斷裂處了, 從這裡可以看見龍井橋由
中間斷成兩段, 也因為這條橋斷了, 且龍井棧道對官府的利益
並沒有預料中的大, 所以也就任它荒廢, 橋的另一端就是望月
崖了, 你在想該不會有哪個瘋子想飛過著個壑谷到對岸吧? 話
說回來, 你的左方倒是有一家客棧, 也許你可以進去看看.
LONG
    );
 set("exits",([ "south":__DIR__"ten_mountain8",

               "west":__DIR__"hotel1",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
