#include <room.h>
inherit ROOM;
void create()
{
 set("short","�Ŧa");
 set("long",@LONG
�o�̬O�V�����n�����@�Ӥp�Ŧa, �A�o�{��, �Ҧ���
�Ŧa����, �u���o�䦳�ͽæb�ݦu, �ӥB�Ŧa�������D���j
�}�@��������W, ��W�]����B�b���U, �ݰ_�ӳo��O���
���n���a��. �o��X�{�F����e��.
LONG
    );
 set("exits",([ "west":__DIR__"outroom29",
                "east":__DIR__"outroom26",
                "south":__DIR__"outroom30",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
