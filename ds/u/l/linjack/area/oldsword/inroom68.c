#include <room.h>
inherit ROOM;
void create()
{
 set("short","���U");
 set("long",@LONG
�o�̬O���U���k�W��, �o��ݰ_�ӴN����X�Ӧa�I�N�M
�F�@�I, �S����H�b�o��ε�, ���L��W�٦��Z�h���������,
�A���ܧ⥦�Y����F�a.
LONG
    );
 set("exits",([ "west":__DIR__"inroom65",
               "south":__DIR__"inroom66",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
