#include <room.h>
inherit ROOM;
void create()
{
 set("short","��W�W");
 set("long",@LONG
�o��w�g�����U���F�_��, �A���F�����G�٦��@���p�Ŧa,
�V���󤤤����D���өж��N�b�A�e�������B, �A�A���F���@�I
�N��F. ���L�o�䦳�@�W���ﵵ�T���k�l���b�A���e, �A���T
�n�_���Q�n�ݰݥL���ڦW.
LONG
    );
 set("exits",([ "southwest":__DIR__"outroom16",
                "east":__DIR__"outroom19",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
