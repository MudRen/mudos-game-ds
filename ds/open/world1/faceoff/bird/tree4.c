#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","森林");

 set("long",@LONG
你越是向前行走, 越感覺到有人在此生活, 你腳下的燃燒過後
的餘燼, 身旁紮營後殘留的木樁, 在在顯示出有人在此生活, 你心
裡忽然感到一陣寒顫, 莫非天梟護木的傳說是真? 
LONG
    );

 set("exits",([ "south":__DIR__"tree3",

    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
