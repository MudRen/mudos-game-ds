#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"施工處"NOR);

 set("long",@LONG
你走到這幾乎昏倒, 原來你一路追尋, 疑惑的敲擊聲居然是
南走道在施工的聲音, 你往施工的地方看了幾眼,發現不可能再
前進了...忽然一陣粉塵飄了過來....此地不宜久留!
LONG
    );
 set("exits",([ "north":__DIR__"walk4",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);           
}
