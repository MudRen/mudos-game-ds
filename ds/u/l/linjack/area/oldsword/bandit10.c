#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s��J�f");
 set("long",@LONG
�A�J�Ӫ��ݤF�|�P���a�z, ���ժ���ܤF�o�@�w�O�Ӥs��, 
�ӥB�̭����H���藍�O����n�Ƥl. �i�O�A���e�Ҩ��o�S��
���, �]�S���g��|�B����, �쩳�O���^��? �A���ӥh�˭�
����.
LONG
    );
 set("exits",([ "north":__DIR__"b_inside1",
                "south":__DIR__"bandit9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}