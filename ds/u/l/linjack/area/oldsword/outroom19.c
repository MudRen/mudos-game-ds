#include <room.h>
inherit ROOM;
void create()
{
 set("short","��D��ǥ~��");
 set("long",@LONG
�A�Ө�F�o��, �J�Ӫ��^�Q�F�V�����Ӫ��a�z���p,
�~���D�o���өM��D��ǥu���@�𤧹j. �x? �����D��
�D�b�̭����Ǥ����, �A�i�H�w�b����ťť.
LONG
    );
 set("exits",([ "west":__DIR__"outroom18",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
