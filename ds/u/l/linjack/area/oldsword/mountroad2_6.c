#include <room.h>
inherit ROOM;
void create()
{
 set("short","�b�s�y�����x");
 set("long",@LONG
�ѩ��ӪC�s�ä��|�ܰ~, �]���s�����j�����i�H�𮧪�
���x�a, ���ǹA�a�b�o��ѥ�, �شӤ@�Ǥs�a��������G, �]
���ǹA�a�b�o�䪪��. �A�ݨ�o���٦��@�a�p����, �p�G�A��
�F�i�H�i�h�𮧥�, �ܭӯ�.
LONG
    );
 set("exits",([ "southdown":__DIR__"mountroad4_1",
                "east":__DIR__"mountroad2_5",
                "north":__DIR__"mountroad2_8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}