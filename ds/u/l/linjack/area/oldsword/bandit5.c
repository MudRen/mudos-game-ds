#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���p�|");
 set("long",@LONG
�z�L�O�ͪ���L, �A���G�������ݨ즳�X�Ӽv�l�b�̰�,
�����D������F��b����....�A�̦n����ĵı.
LONG
    );
 set("exits",([ "west":__DIR__"bandit4",
                "north":__DIR__"bandit6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
