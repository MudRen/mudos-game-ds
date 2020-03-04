#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "幼龍塔入口");
  set("long", @LONG
此區為幼龍塔入口，身旁景物完全一致，但無任何生物，乍看之
下還有點像沙漠。此區為新手練習區，初入江湖的新手能到此練習技
能。
LONG);
  set("exits", ([
  "enter" : __DIR__"room1", 
  "south" : "/open/world1/cominging/area/forest5", ])); 
  set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/dragon-guard" : 1,
]));
  set("outdoor","land");
  setup();
}


int valid_leave(object me, string dir)

{
        string gender;
        gender=me->query("gender");
        if ( gender=="男性" ) gender="你";
        if ( gender=="女性" ) gender="妳";
        if ( me->query("age") > 50 ) gender="您";
        
        if( dir=="enter" )
        {
                if(me->query("level")>15)
                {
                        message_vision(HIY"守衛龍說："HIG" 這裡不適合"+gender+""HIG"出入，請速離開。\n"NOR, me);;
                        return notify_fail("那裡只有等級15以下才能進去。\n");
                }
        }
        return ::valid_leave(me, dir);
}


