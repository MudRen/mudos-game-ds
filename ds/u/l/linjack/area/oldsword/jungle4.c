#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L��");
 set("long",@LONG
�A�Ҧb���O�L�q���}�l���F������㪺�q���X��, �ݰ_��
�X�G�@�Ҥ@��, �@���b�_��, �@���b�F��. �A�b�o��w�g�i�H
����ť��@�ǳ��~�ȼS���n��.
LONG
    );
 set("exits",([ "east":__DIR__"jungle5",
		"west":__DIR__"jungle3",
                "north":__DIR__"jungle11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}