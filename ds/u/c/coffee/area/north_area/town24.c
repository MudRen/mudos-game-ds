#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"村長家"NOR);
 set("long",@LONG
這裡是村長家，大廳佈置的古色古香，旁邊的圓桌上放
著一壺茶和一包茶葉，吹著外頭的風，讓你感覺十分的舒服
，而村長就昨在椅子上，不停的嘆息•••••

LONG
    );

       set("exits",([
       "south":__DIR__"town21",
           ]));

        set("objects", ([
           ])); 
 set("no_clean_up", 0);
 setup();
 set("light", 1);
}     

