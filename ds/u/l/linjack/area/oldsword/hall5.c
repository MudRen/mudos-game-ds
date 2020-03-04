#include <room.h>
inherit ROOM;
void create()
{
 set("short","花崗迴廊起點");
 set("long",@LONG
你走到了這個迴廊的起點, 突然間覺得有點冷, 不過
四處還是有些花草, 也有些蝴蝶, 偶爾看到蜜蜂從你眼前
掠過, 不禁使你嚇了一會兒, 整個迴廊被裝設的漂漂亮亮.
LONG
    );
 set("exits",([
               "west":__DIR__"hall4",
               "south":__DIR__"inroom1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
