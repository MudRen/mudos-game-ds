#include <ansi.h>
//updated 26/12
inherit ROOM;
void create()
{
	set("short", HIC"ST�CRoad�IGate"NOR);
	set("long", "�Ө�o�˫�A�A�P��H�s�o�ˤ�n��W�[�F���֡A���Ať�쨺���n��
�ܤj�A�ܹ����@�ǨƱ��b����o�ͤF�����C�A�n�_�߫o�s�ϧA�h������
���x�A�[�ָ}�B�ݬݧa�C\n");
 set("exits",([ 
"north":__DIR__"dst18.c",
"south":__DIR__"dst9.c",
]));
   set("outdoors","land");
	setup();
	replace_program(ROOM);
}
