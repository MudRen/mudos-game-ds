#include <room.h>
inherit ROOM;
void create()
{
 set("short","���U");
 set("long",@LONG
�o�̬O���U�����W��, ���G���I���n���n��, �A�w���@��,
��ӬO���⬣���Y�Y�_�F����, �����D�O���F�����]�O? ��
�\�A�i�H�L�h�ݬݧa.
LONG
    );
 set("exits",([ "east":__DIR__"inroom65",
               "south":__DIR__"inroom67",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
