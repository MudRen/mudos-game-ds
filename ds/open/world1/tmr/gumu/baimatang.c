// baimatang.c
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
        set("short", "�հ���");
        set("long", @LONG
�o�Ӽ��_�׫n�s�D�p�@�a�A�@���W�s�w�n�e���W��C���䦳�@��
��T���Фl�٭n�j���ե��Y�A�o���Y�����C���Y���A���Y���e�b�I���b
���̡A��b�I�d�b���W�C�Ѧ��b���������b�I���Y�U���٤��ɫ_�X�@��
��ժj�A�ѻ��ݥh�����@���˪ű������P���A�]����a�H���s���欰��
����C���_�O�@���T�򪺤s���C
LONG    );
        set("outdoors", "gumu");
        set("exits", ([
                "northup" : __DIR__"shanlu6",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

