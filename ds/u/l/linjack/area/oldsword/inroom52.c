#include <room.h>
inherit ROOM;
void create()
{
 set("short","�G�ӥ𮧫Ǩ��D���Y");
 set("long",@LONG
�o�̬O�𮧫ǤG��, �o�ӼӼh�j�h���O������U����
���ͽéάO����L���̤l. �a�O�W���@�Ǥg���⪺��, �J
�Ӥ@�ݭ�ӬO���Ǭ�g��b�a�W. �n�_�ⰼ���[�Ц����b�m
�\���n��, �̦n���n�i�h���Z�L��. �F�������q���x�ëǪ�
��.
LONG
    );
 set("exits",([ "north":__DIR__"inroom53",
                 "west":__DIR__"inroom49",
                "south":__DIR__"inroom54",
                 "east":__DIR__"inroom55",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
