#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�A�����䦳�@�D�۪�, �ӳq���h�O���n�䩵���L�h, �o��
���M�٦��@�I��, �A���T���I�Y��.
LONG
    );
 set("exits",([ "south":__DIR__"secret3_5",
                "west":__DIR__"secret3_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
