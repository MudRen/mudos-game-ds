#include <room.h>
#include <path.h>
inherit ROOM;
void create()
{
 set("short","潮濕的小路");
 set("long",@LONG
走了一陣子, 你發現前面已經有比較乾的風吹過來了,
路也漸漸變寬, 而比較能看得清前面的景物了. 好奇心驅
使之下, 你覺得你繼續走下去會比教好.
LONG
    );
 set("exits",([ "northeast":__DIR__"path1",
                "southwest":__DIR__"road1",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}