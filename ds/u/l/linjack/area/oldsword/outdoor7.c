#include <room.h>
inherit ROOM;
void create()
{
 set("short","狹道");
 set("long",@LONG
你從石門之上走了下來, 來到一條狹道之中, 大約有兩
三個人的寬度, 這條狹道不知道是通到哪裡的, 最好小心一
點比較好.
LONG
    );
 set("exits",([ "west":__DIR__"outdoor8",
                "eastup":__DIR__"outdoor6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}