#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�s�f"NOR);

 set("long",@LONG
�o�̦A���_���N�O�ۦW���Q�U�j�s�F, �ڻ��ѱ��m�Z�@��
�K�O���~�b�s�s��, �ȥB�����o��, �N�O���e������]�۷�
�g�H, �h�h�s�p�ݥߦb�A�����e, �O���@�f�a�D������.
LONG
    );
 set("exits",([ "north":__DIR__"ten_mountain3",
		"southwest":__DIR__"road8",

    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
