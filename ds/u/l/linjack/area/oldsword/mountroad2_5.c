#include <room.h>
inherit ROOM;
void create()
{
 set("short","�b�s�y�����x");
 set("long",@LONG
�ѩ��ӪC�s�ä��|�ܰ~, �]���s�����j�����i�H�𮧪�
���x�a, ���ǹA�a�b�o��ѥ�, �شӤ@�Ǥs�a��������G, �]
���ǹA�a�b�o�䪪��.
LONG
    );
 set("exits",([ "northeast":__DIR__"mountroad2_4",
                "west":__DIR__"mountroad2_6",
                "north":__DIR__"mountroad2_7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}