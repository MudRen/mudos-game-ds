#include <room.h>
inherit ROOM;
void create()
{
 set("short","��Y�W");
 set("long",@LONG
�A�Ө�F�O�@�ӫܥ��w����Y�W, �����i�H�ݨ�s�}�U���A�a
�b�o���ϩάO���. �A�Y�q����h, �F��]�O�@����Y, �Ӧ���
�N�O�b�s�y�F.
LONG
    );
 set("exits",([ "east":__DIR__"mountroad2_3",
                "southwest":__DIR__"mountroad2_5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}