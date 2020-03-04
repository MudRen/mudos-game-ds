#include <room.h>
inherit ROOM;
void create()
{
 set("short","堂主夫人寢室");
 set("long",@LONG
這裡應該是向雲堂主的夫人寢室, 裡面的擺設真是極其
華麗, 金光耀眼的東西不計其數, 雖然堂主夫人已經去世一
年多了, 但是這個房間仍然保存的十分完整, 可以知道堂主
對夫人的用心了.
LONG
    );
 set("exits",([
               "west":__DIR__"inroom1",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
