// xiaohuayuan1.c �p���
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�p���");
        set("long", @LONG
�o�̬O�����[�̪��p���A�Ů��Ƶۤ@���A�᪺�����C�A��
�_�h�A�N�O�������F�C�o�Ӫ�餣�j�A�o�O���u�̤l�m�\���س̷R
�ӹC�����a��C�餤������@������A�]�\�M�����H�t�d�޲z�o�̡C
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "southwest" : __DIR__"houtang3",
                "northeast" : __DIR__"xiaohuayuan2",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/zhangyuan" : 1,
        ]));

	set("coor/x", -2730);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}