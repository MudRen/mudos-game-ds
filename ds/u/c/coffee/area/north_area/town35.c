#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"民房"NOR);
 set("long",@LONG
這間屋子十分簡陋，連屋頂下雨時都會漏水，屋裡十分
雜亂，只看見一名中年婦女在大廳哭泣，不知發生了什麼事
，或許你可以幫她。

LONG
    );

       set("exits",([
       "west":__DIR__"town34",
           ]));

        set("objects", ([
           ])); 
 set("no_clean_up", 0);
 setup();
}     

