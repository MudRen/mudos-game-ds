#include <room.h>
inherit ROOM;
void create()
{
 set("short","�����W���J�f");
 set("long",@LONG
�A�Ө�F�Ŧa���D�����Y, �A���e�����B���@�ө_�Ǫ����H,
�������a�W�W���@�Ӥj����ι���, ������F�@�ǧA�ݤ��M����
�r. �A�������Ө��i�h�O?
LONG
    );
 set("exits",([ "east":__DIR__"outroom28",
                "south":__DIR__"outroom31",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
