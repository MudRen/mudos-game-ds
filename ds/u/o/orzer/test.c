inherit ROOM;
#include <ansi.h>
void create()
{
      set("short", HIG"測試房"NOR);
      set("long", HIW"\n\t一個測試房間...只有一個人偶。\n\n"
                     "\n\t和一大堆的雜物...看來不常整理\n\n"                                                
      NOR);
             
    set("no_clean_up",0);        
    set("light",1);               
    set("exits", ([
         ]));         set("light",1);
        set("valid_startroom", 1);
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/test" : 1,
            ]));
        setup();
        replace_program(ROOM);
}





