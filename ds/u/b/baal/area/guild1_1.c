#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"���N�۫�"NOR);

 set("long",@LONG
�o�̦b���Y����ģ�U, �N�㪺���t�h�F, ���L, �o�̫o�۷�D�n�M��
�R�����ް_�A�`�N��, �O���b��W�m�m�����T�_�Ѫ��P���M�ľS, ����,
�~�O��L�C, �M�@�����Z��, ��W�ұ����P�����Q�����o�o�G�G, �b�o�O
���Ӯg�U��X��G�����~, �ľS�����~���۷��b, �����@���Ĩ����o�X
��, �������X�Ӭ�۱��ĸ˧����Ю{, ���b�M��ۤv���Ī��Ψ�.   
LONG
    );
 set("exits",([ "north":__DIR__"guild1", 
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

