#include <room.h>
inherit ROOM;
void create()
{
 set("short","�h�A�e");
 set("long",@LONG
�A�Ө�F�@�p�����h�A���e, �o���p�|�W������������ӴN�O
�]���o�Ӫh�A�����Y�F. �J�ӬݤF�ݪh�A���u�����@�ǥ����b��
��. ���O�A�o���q�o�L�o���h�A�~��.
LONG
    );
 set("exits",([ "east":__DIR__"jungle7",
		"north":__DIR__"jungle9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}