#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�s���̹D"NOR);

 set("long",@LONG
�o�̬O�@���ѩx���ҭ׾㪺�x�D, �ҥH�O�Q�U�j�s���̥i
�H�٬��O������, ��ӥi�H�ѳo���̹D�����H�T�Ѹ}�{�׹L�Q
�U�j�s, �i�O�����w�b�e�褣���B�_�F, �A�i�H�b�F�_�褣��
�B�ݨ�@���p�ȴ�.
LONG
    );
 set("exits",([ "north":__DIR__"ten_mountain9",
               "east":__DIR__"ten_mountain4",

    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
