#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"水泥路"NOR);
 set("long",@LONG 
這裡前面有一條入直通往前方，但兩旁的石壁十分高聳，使
得這條道入看起來十分的狹窄，而且這裡附近也開始沒有什麼行
讓你開始覺得有點怪怪的。
LONG
    );

       set("exits",([
       "north":__DIR__"town9",
       "south":__DIR__"town7",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}     
