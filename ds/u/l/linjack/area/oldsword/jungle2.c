#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L�J�f");
 set("long",@LONG
�A�D�`�D�`�p���l�l������, �g�L�F���p�|, �Ө�F�o���O�L
����...., �o��D�`�����t�ӥB����, �����i�H�ݨ�@�ǧA���`��
���ͪ�. ���㪺�X�����G�u�����_���F.
LONG
    );
 set("exits",([ "west":__DIR__"jungle1",
		"north":__DIR__"jungle3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
