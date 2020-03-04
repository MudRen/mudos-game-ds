#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"南走道"NOR);

 set("long",@LONG
你步行至此, 剛才的敲擊聲似乎比剛才在北端時更大了些,
你側耳頃聽, 發現那聲音像是有人以鐵撬敲擊石壁而成,發現了
這點, 你反而更想找出聲音的由來....
LONG
    );
 set("exits",([ "north":__DIR__"walk2",
            "south":__DIR__"walk6",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);   
}        
           
