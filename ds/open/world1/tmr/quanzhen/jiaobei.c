// jiaobei.c �иO
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�иO");
        set("long", @LONG
�o�̬O���u�Ъ��иO�Ҧb�a�A���ǥߵۤ@���j�O(bei)�C�A���F
���N�O�ѤU�D�W���D�a�Ȫ����v--���u�Ъ��j���F�C�_�����@����
���A�����D�q�V���̡A����O�U�s�����C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup" : __DIR__"shijie6",
                "eastup" : __DIR__"damen",
                "west" : __DIR__"shijianyan",
        ]));
        set("item_desc", ([
        "bei": CYN"
        ����������
�@�@�@�@���@�@�@��
�@�@�@�@���@���@��
�@�@�@�@���@�@�@��
�@�@�@�@���@�u�@��
�@�@�@�@���@�@�@��
�@�@�@�@���@�j�@��
�@�@�@�@���@�@�@��
�@�@�@�@���@�С@��
�@�@�@�@���@�@�@��
�@�@�@�@����������
\n"NOR
        ]) );
        set("objects",([
                CLASS_D("quanzhen")+"/zhao" : 1,
        ]));

	set("coor/x", -3140);
	set("coor/y", 110);
	set("coor/z", 160);
	setup();
        replace_program(ROOM);
}