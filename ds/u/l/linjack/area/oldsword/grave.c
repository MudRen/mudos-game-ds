#include <room.h>
inherit ROOM;
void create()
{
 set("short","�j�X��");
 set("long",@LONG
�A�@���L��, �t�I�~�F�@��, ��ӬO�@�Ө�Ǧ�����J���j��
�X��. ���M�o�䳱�𺡭���, ���L�A�J����|, �o�{���𤧤�����
�z�X�@�Ѱ��䪺��, �ݨӹӤ��ҮI���H, �ͫe���w���O�x�x����.
LONG
    );
 set("exits",([ "southwest":__DIR__"mountroad1_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}