#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L��");
 set("long",@LONG
�A����o��, �èS���oı����i�ê��a�誺, �p�|�O�V�_�~
����i�U�h, �L�F�@�|��, �A�Sť���F���~���s�n, ���O�Q����
�H��{�X�n�����ӷ�, �]���^���N�b�o�O�L���j��, �A�Ʀܳs�o
�O���زr�~���s�n�������D.
LONG
    );
 set("exits",([ "north":__DIR__"jungle7",
		"west":__DIR__"jungle5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}