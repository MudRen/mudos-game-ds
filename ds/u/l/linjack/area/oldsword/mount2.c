#include <room.h>
inherit ROOM;
void create()
{
 set("short","小石階上");
 set("long",@LONG
你站在一個極為險峻的山壁上, 石階的寬度只有兩尺不到, 
而且此處風勢不小, 若是根基不夠身厚, 無法穩住身子, 那隨
時有掉下山崖的可能. 你眼見在你身邊的雲霧漸漸消散開, 已
經可以清楚的看到閃著耀眼光芒的山頂了.
LONG
    );
 set("exits",([
               "southdown":__DIR__"mount3",
               "northup":__DIR__"mount1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
