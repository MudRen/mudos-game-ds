#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"��������ť"NOR);
        set("long", @LONG
�o�̬O��������Žm�\���A�o��a��s�j�A�@����h�A�ɬO�m
�\���A�m�\���W���\�h���������̤l�b�m�@�Ϊ̽m���\�A���Φb��
�s�P���A�䤤�]�]�t�F�Z�L���H�ӽбСA���O�_�Ǫ��N�O�S���k��
���Z�L�H�h�A�m�\�����䳣���@�ө�ۤ@�������@�l�A�W����۳\
�h�_�����a�����@���Z���C
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"room12",
  "east" : __DIR__"room8",  
]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/app2" : 2,
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}
