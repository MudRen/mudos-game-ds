#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�o��O�@�Ӥ��e���������I, ���F�_���i�H�ݨ�@�����u,
���n�������D�O����, �ө��訫�i�H�~��b�o�ӳq��W����..
LONG
    );
 set("exits",([ "northeast":__DIR__"secret3_8",
                "west":__DIR__"secret3_5",
                "south":__DIR__"secret3_7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
