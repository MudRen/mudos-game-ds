// shantong.c ��s�s�}
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��s�s�}");
        set("long", @LONG
�o�̬O���u�ж}�s���v�������u�H�R�ת��s�}�C�}���j�A��
�̭��G�m�o�ܶ��P�A���j��H�a�����U�@�ˡC�}���W���ۤ@�Ƶe
(hua)�A��ȯ��L���ܺ�o�C
LONG
        );
        set("exits", ([
                "out" : __DIR__"xiaolu12",
        ]));
        set("item_desc", ([
        "hua": "�e���O�@�Ӥ��~�D�h���I�v�A�ݤ��X����ۻ��A�e���H�@����ѡA�e���D
�ۡ�"+MAG"�����H��"NOR+"���X�Ӥj�r�C\n"
        ]) );

        set("objects", ([
                CLASS_D("quanzhen")+"/wang" : 1,
        ]));

	set("coor/x", -2670);
	set("coor/y", 130);
	set("coor/z", 150);
	setup();
        replace_program(ROOM);
}