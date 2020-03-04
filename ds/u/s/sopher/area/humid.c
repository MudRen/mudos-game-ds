#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", YEL"通往沼澤地的通路上"NOR);
        set ("long", @LONG
雙倍的潮濕，悶熱像你席捲而來。令人最受不了的
，除來令人做噁的屍臭味外，地上一具半死不活的屍
體還在蠕動，蠕動著~~~~~~
LONG);  
        
        set("exits", ([
        "east" : __DIR__"humid2",
        "west" : __DIR__"road3",
        ]) );
        set("objects", ([
        __DIR__"npc/corpse" : 1,
        __DIR__"npc/item/saint_water" :1,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
