#include <room.h>
inherit ROOM;
void create()
{
 set("short","�Ŧa");
 set("long",@LONG
�o�̬O�V�����n�����@�Ӥp�Ŧa, �A�o�{��, �Ҧ���
�Ŧa����, �u���o�䦳�ͽæb�ݦu, �ӥB�Ŧa�������D���j
�}�@��������W, ��W�]����B�b���U, �ݰ_�ӳo��O���
���n���a��. �F�䦳�ӱ�^��V����.
LONG
    );
 set("exits",([ "south":__DIR__"outroom27",
                "west":__DIR__"outroom28",
                "eastup":__DIR__"inroom22",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
