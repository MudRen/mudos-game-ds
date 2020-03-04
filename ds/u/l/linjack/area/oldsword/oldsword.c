#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","古劍亭");
 set("long",@LONG
這裡就是傳說中的古劍亭, 若沒有一定底子是來不了的. 裡面掛滿
了天下名劍, 若是在豔陽高照的時刻, 此地便金光閃閃, 若從低處仰望, 
便會覺得此處散發著一道神聖無比的淡金光芒, 而凡人又不可能攀爬至
此, 當然會將此地傳說為一處仙境. 若是平時, 則光芒會褪去五分, 不
過能到古劍亭的人反而覺得四處的鐵銀反光, 散發淡淡邪氣.
LONG
    );
 set("exits",([
               "east":__DIR__"mount1",]));
 set("light",1);
 set("objects",([
		__DIR__"npc/shura":1,
 ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

