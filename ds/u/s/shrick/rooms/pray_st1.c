// pray_streat1.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"神殿道"NOR);
        set("long",@LONG
  這條猶羅村的神殿道路從這裡向西走是神殿。
向東走是凱恩大道南路。
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"kain_s4",
                "west"    : __DIR__"pray_st2",
                ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
