#include <room.h>
inherit ROOM;
void create()
{
 set("short","���Y");
 set("long",@LONG
�A����@�����Y�W��, �ݰ_�Ӻ�����, �A�ݤ���o�Ӫ��Y
�����Y�쩳�b����, ���F�w���_��, �A�̦n�p�ߤ@�I������w
��.
LONG
    );
 set("exits",([ "southwest":__DIR__"secret1_7",
                "north":__DIR__"secret3_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
