#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIW"迪蘭斯"HIR"大道"NOR);
        set ("long", @LONG
你剛踏進城門，除了被蔚為風尚的氣息所吸引外
，這裡的人似乎都相當和藹可親，你走在一條大道上
。兩旁整齊的排列著兵器，從戟到槍到劍，一應俱全
，每位士兵看起來也都相當訓練有素。你不禁更加敬
畏這個軍團了。
LONG);
        
        set("exits", ([
        "south": __DIR__"dragon1",
        "north": __DIR__"dragon3",
        "west" : __DIR__"dragon4",
        "east" : __DIR__"dragon5",
         ]) );
        set("objects", ([
        __DIR__"npc/soldier" : 1,
        ]) );
set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}    
