#include <room.h>
inherit ROOM;
void create()
{
 set("short","��L��");
 set("long",@LONG
�A�Ө�F�L���p�����@�Ӥe��, ���@���O���訫, �ݰ_�ӥ�
�u����R��, �t�@���O���F�_��, ��L����@�K, ���u�y�z, �A
�n�����@�����O?
LONG
    );
 set("exits",([ "west":__DIR__"mountroad1_1",
                "south":__DIR__"mountroad3_1",
                "northeast":__DIR__"mountroad1_3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}