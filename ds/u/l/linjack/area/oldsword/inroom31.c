#include <room.h>
inherit ROOM;
void create()
{
 set("short","空客房");
 set("long",@LONG
這間客房空蕩蕩的, 只有一些簡單的擺飾和設備, 如果你
不嫌棄的話, 這邊還是可以睡人的. 而且特別安靜喔. 
LONG
    );
 set("exits",(["south":__DIR__"inroom30",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
