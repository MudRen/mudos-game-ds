#include <room.h>
inherit ROOM;
void create()
{
 set("short","��W");
 set("long",@LONG
�o��O�V�����_��V���p��W, �Q���b�s������, �u��
�o�@���p�p���Ŧa, �������@�Ǥp�ʪ��b�o��X�S. �a�W����
�C���A�A����, ���ӷ�˹����Ӥ���. �F�_��V�����ø�.
LONG
    );
 set("exits",([ "southup":__DIR__"inroom21",
                "north":__DIR__"outroom17",
                "northeast":__DIR__"outroom18",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
