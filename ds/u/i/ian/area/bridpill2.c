#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s�}�e"NOR);

 set("long",@LONG
�b�A���e, �O�@�Ӥs�}���}�f, �̭��º�����, �ݰ_�ӳ��˦ӥi��
, �����D�̭����S�����~�~��, �p�G���e�ĥX�ӧ����A, �i���O�x�۪�
��, �Q�۷Q��, �A���G�w�g�i�H�ݨ쨺�i���R�������~�§A�g�b�Ө�, 
�A���T�Q�������}���a...
LONG
    );
 set("exits",([ "enter":__DIR__"birdpill2", 
    ]));
 setup();
 replace_program(ROOM);
}
