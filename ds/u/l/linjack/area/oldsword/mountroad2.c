#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s�������Y");
 set("long",@LONG
�o�@�q���A�X�G���O�C���Y�b��, ���M�A�o�{�A�}�񤧦a
�w�g���O�@�����g���F! �A�@���Y, ���e��h, �N�w�g�i�H�q
���_�����ݨ짧�[���V����F!
LONG
    );
 set("exits",([ "northwest":__DIR__"mountroad1",
                "southdown":__DIR__"mountroad3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
