// File: /d/duli_port/duli_bank.c
// Updated by tmr (Thu Feb 28 02:26:30 2002)

#include <room.h>
inherit BANK;

void create()
{
	  set("short", "������f�Ȧ�");
	  set("long", @LONG
�o�̬O�@�����W�Ҫ��ӷ~�Ȧ�A�M�䪺�Q�����b���ۿj�a�O�A�M��
�L���U�Ȫ��˼v�A�Ѫ�O�W�����T�����ۤ@�q�M�֪����֡A���w���ۤ���
���d�i�٬O�����F�I���B�s�ڪ��H�s�C�����̤@�Ӧ~�ڪ��Ѱ��H���ε۩�
��@�T�@�T���M�z�a�O�C
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"west" : __DIR__"map_10_16",
]));

        set("objects",([
                __DIR__"npc/bank_guard":2,
        ]));
	setup();
}
