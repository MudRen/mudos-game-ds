#include <room.h>
inherit ROOM;
void create()
{
 set("short","�𮧫Ǩ��D");
 set("long",@LONG
�o��M�ﭱ���~���ȩХ��n�ۤ�, �o�̪��ж����O���V����
�������ݦb�𮧪��a��. �_��ǨӤ@�}�}�H�H���������n, �٦�
�H�b�̭����@�ǹ��O�o�s�ƪ��H�b������, �f�����M�J���ûy��,
�A�̦n���n���̭�������n.
LONG
    );
 set("exits",([ "north":__DIR__"inroom44",
                 "east":__DIR__"inroom40",
                "south":__DIR__"inroom45",
                 "west":__DIR__"inroom46",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
