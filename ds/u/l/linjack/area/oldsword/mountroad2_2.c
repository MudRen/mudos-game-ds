#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���W");
 set("long",@LONG
�o���s���]�O�i�H�q��V���󪺤@���s��, �o�䪺�s����
�ܿ������, �A�@���p�ߴN�|�g�F���F. �A�i�H�~��W�s, ��
�̬O����_����F�s�y�����x�W.
LONG
    );
 set("exits",([ "northwest":__DIR__"mountroad2_3",
                "east":__DIR__"mountroad2_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}