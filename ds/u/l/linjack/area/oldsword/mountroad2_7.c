#include <room.h>
inherit ROOM;
void create()
{
 set("short","�b�s�y�����x");
 set("long",@LONG
�ѩ��ӪC�s�ä��|�ܰ~, �]���s�����j�����i�H�𮧪�
���x�a, ���ǹA�a�b�o��ѥ�. �A���e�N���@���p�p�������,
���䦳�T��ӹA�Ҧb�ѧ@.
LONG
    );
 set("exits",([ "south":__DIR__"mountroad2_5",
                "west":__DIR__"mountroad2_8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}