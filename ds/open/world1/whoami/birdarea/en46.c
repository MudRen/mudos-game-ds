#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG 
你來到了樹木很濃密的樹林, 你感覺到這裡濕氣很重, 使你
覺得渾身不舒服, 聽說這裡的青蛙很多, 你可以在這裡看到各種
蛙類.
LONG
    );
 
 set("exits",(["north":__DIR__"en72",
               "southwest":__DIR__"en47",
               "southeast":__DIR__"en41",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        


