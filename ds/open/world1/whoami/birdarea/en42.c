#include <room.h>
inherit ROOM;
void create()
{
 set("short","草叢");
 set("long",@LONG
你穿過草叢來到這兒, 這裡雜草叢生, 讓你很難行
動, 不時有些蚊子在你旁邊盤旋, 讓你不自覺得揮動雙
手, 想趕走牠們, 你看到東方隱隱約約有一條小路.
LONG);
 set("exits",(["east":__DIR__"en43",
               "southwest":__DIR__"en41",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        



