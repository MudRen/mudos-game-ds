#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "井底旁");
        set("long",@LONG
這裡是井底下，在這裡有一些些的生物，像是青蛙一類的，正在向
你呱呱大叫，不過他對你而言沒有什麼傷害力可言，而在東方是井底，
從那有串串水流流過來。
LONG
        );
        set("exits", ([
  "east" : __DIR__"well.c",
])); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

