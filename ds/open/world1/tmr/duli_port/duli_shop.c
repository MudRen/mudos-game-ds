// File: /d/duli_port/duli_shop.c
// Updated by tmr (Wed Feb 27 21:34:15 2002)

#include <room.h>
inherit HOCKSHOP;

void create()
{
	  set("short", "�����p�ө�");
	  set("long", @LONG
�o�̬O�@���R��F�誺�ө��A��������W���F�j�j�@�i����~���ѡA
�C�B�K�Ӧ�˵������u���b�U���d�i�W�i��M�U�Ȫ�����γB�z�ƶ��A��
�f���_���i�ӷQ�n������U�ȡA�j���O�]���o���ө�����f������A��
�N�ȷ��~�|�p���������_�C
LONG
	  );
	  set("objects", ([ ]));
	  set("exits", ([ /* 1 element(s) */
	"south" : __DIR__"map_5_9",
]));

	setup();
}
