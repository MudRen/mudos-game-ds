#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s�}��"NOR);

 set("long",@LONG
[B[B�b�s�}��, �s�}�f�����u���z���i�ӤF, �A�u��a�s�}�׳��W���}
�}�ǨӪ��L�z���u���������G�{�X�s�}��������, �_�Ǫ��O, �s�}�׳�
�W���}�}���G���O�ѵM�Φ���, �L�̤������G���@�w�Z��...
LONG
    );
 set("exits",([ "south":__DIR__"birdpill2",
                "west":__DIR__"birdpill4",
                "east":__DIR__"birdpill5",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

