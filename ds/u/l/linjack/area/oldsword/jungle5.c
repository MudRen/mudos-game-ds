#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L��");
 set("long",@LONG
�A����o��, �èS���oı����i�ê��a�誺, �p�|�O���F���
�V������, �A���F���N��`�J�o���O�L�����F. �A�i�H�ݨ�A�ҽ�
���a�O�V�ӶV����F, ���G���񦳪h�A�٬O����.
LONG
    );
 set("exits",([ "east":__DIR__"jungle6",
		"west":__DIR__"jungle4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}