#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);

 set("long",@LONG
�A�S���F�n�@�q�ɶ�, �A�Y�W�������w�g�p�U�B��
���y�U, �A��_�Y�ө��W��F��, �ש�ݨ쳻�F!!
�A�ߤ����Ѫ������U��, �]���A���V�O�ש󦳤F�N
��, ��O�A�[�ָ}�B, ���W���h�C

LONG
    );
 
 set("exits",(["up":__DIR__"bird7",
               "down":__DIR__"bird5",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
