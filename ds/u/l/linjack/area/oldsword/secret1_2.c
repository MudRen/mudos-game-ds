#include <room.h>
inherit ROOM;
void create()
{
 set("short","�۫F����");
 set("long",@LONG
�A��ۺôb����, ���i�F�ۭӬ�M�X�{���۫F��, �̭��Ūſ���
��, ����F��]�S��, �u�����ߪ��a�W���@���۪O, �i�O�A��������
�D�����۪O�O�F����Ϊ�.
LONG
    );
 set("exits",([ "up":__DIR__"secret1_1",
                "west":__DIR__"secret1_3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
