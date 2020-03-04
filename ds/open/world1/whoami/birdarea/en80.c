#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"千年"YEL"神木"NOR);
 set("long",@LONG
你現在站在千年古木的樹枝上, 雖然說是樹枝, 但卻是和平
常的樹木的樹幹差不多粗, 在這樹枝上有一隻巨大的鳥類正
在尋找食物, 牠看來肚子很餓的樣子.
LONG);
 
 set("exits",(["down":__DIR__"en70",
              ]));
 set("objects",([__DIR__"npc/godbird" : 1,
               ]));
 set("no_clean_up", 0);
 setup();
}        

