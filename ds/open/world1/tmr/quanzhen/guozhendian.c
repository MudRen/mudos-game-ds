// guozhendian.c �L�u��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�L�u��");
        set("long", @LONG
�o�̬O�j����䪺�@�Ӱ����A�]�O���ݭ��n�ȤH���a��C����
�j�A�u�\��ۤ@�i��l�M�X��Ȥl�C��W�\��ۤ@�֫C�s��������
���A����W���ۤ@�Ǧr�e�C�q�o�̩��_�A�n�����@�y�|�h���p��C
LONG
        );
        set("exits", ([
                "west"  : __DIR__"cetang",
                "south" : __DIR__"datang3",
                "north" : __DIR__"cundaota1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2780);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}