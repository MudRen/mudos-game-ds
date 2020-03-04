#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","石頭路");

 set("long",@LONG
這是一條用石頭打造的路, 雖然說是石頭做的, 但
是走起來卻比平地還要平, 你往前望了望再往前一點便
到了天梟教的大門了, 原來剛聽到在練功的聲音是從這
裡傳來的。 

LONG
    );
 
 set("exits",(["east":__DIR__"bird13",
               "west":__DIR__"bird11",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
