#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"蓮池"NOR);

 set("long",@LONG
這裡是蓮池的延伸, 你發現這裡的土壤雖然很溼, 但卻相當
適合近水植物的生長, 所以這裡一片欣欣向榮的景像, 令人看了
相當舒暢.
LONG
    );
 set("exits",([ "south":__DIR__"med5",
		"west":__DIR__"med3",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}