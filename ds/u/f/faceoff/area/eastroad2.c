#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�F�j�Y"NOR);

 set("long",@LONG
�A�S�V�e��F�n�X�Q���ػ�, ���Ǫ��B�J�̵M�s�����_, �A
���e����Q���سB���@�I����, ��M�X�f�w��b����, �A�^�Y��
�V�A���Ӹ�, �u���@���s�����B�J, �������~���G�@�L�Ҧ�, �i
���o���F�j�Y�����פF....
LONG
    );
 set("exits",([ "east":__DIR__"eastroad3",
                "west":__DIR__"eastroad1",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
