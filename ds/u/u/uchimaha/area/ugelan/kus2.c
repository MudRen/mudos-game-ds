#include <room.h>
inherit ROOM;
void create()
{
 set("short","庫司港");

 set("long",@LONG
這裡是泊船處的交接口, 海風輕輕的吹過你的臉, 使你的
心情十分舒暢, 在你的東、北和南方停有各式各樣的船, 有些
是從東方大陸來的, 有些則是私人的渡假小船•
LONG
    );
 
 set("exits",(["west":__DIR__"kus1",
               "north":__DIR__"kus3",
               "south":__DIR__"kus4",
               "east":__DIR__"kus5",
              ]));
 set("outdoors","land");
 setup();
}           

