#include <room.h>
inherit ROOM;
void create()
{
 set("short","�b�s�y�����x");
 set("long",@LONG
�ѩ��ӪC�s�ä��|�ܰ~, �]���s�����j�����i�H�𮧪�
���x�a, ���ǹA�a�b�o��ѥ�. �A������U�s�N�i�H��F�t�v
�Ĥ@�j���u�V�����v�F.
LONG
    );
 set("exits",([ "south":__DIR__"mountroad2_6",
                "east":__DIR__"mountroad2_7",
                "westdown":__DIR__"mountroad5_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}