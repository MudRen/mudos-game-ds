#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
你離開了石亭, 發現這邊和向雲堂是有別洞天, 十分陰暗,
可是不知道為什麼, 這種通道的空氣竟然還滿流通的, 當出設
置這個通道的設計者真是鬼斧神工.
LONG
    );
 set("exits",([ "southeast":__DIR__"secret1_5",
                "northeast":__DIR__"secret1_4",
                "east":__DIR__"secret1_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
