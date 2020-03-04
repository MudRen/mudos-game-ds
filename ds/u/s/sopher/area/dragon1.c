#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIY"超龍"HIR"軍團"HIW"城門口"NOR);
        set ("long", @LONG
這裡就是超龍軍團的城門了，鬼斧神工的雕刻技術
，令人不禁為之一驚，其藝術氣息之濃厚，實在無法與
傳說中最強的超龍軍團聯想在一起。城門口站著兩位守
城衛兵，似乎是要得到許可才能進入喔。
LONG);
        
        set("exits", ([
        "south": __DIR__"road1.c",
        "north": __DIR__"dragon2",
         ]) );
        set("objects", ([
        __DIR__"npc/guard2" : 2,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
