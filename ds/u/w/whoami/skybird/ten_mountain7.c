#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�U�D"NOR);

 set("long",@LONG
�o�̬O�@���U�p���D��, ���F���G���@�ӥ۪�, ����h�i�H
�^��Q�U�j�s��, �o���p�p���U�D���G�w�g�ܤ[�S���H���L�F, 
�A�u���ݨ�@�Ǽҽk���M������b�A���}�U....
LONG
    );
 set("exits",([ "east":__DIR__"bird1", 
                "northup":__DIR__"ten_mountain6",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

