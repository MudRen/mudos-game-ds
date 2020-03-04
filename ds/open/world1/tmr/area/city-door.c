// Room: /u/t/tmr/area/city-door.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "�ɿ��_����");
	set("long", @LONG
�o�O�ɿ������_�����A�����f�U�E���ۦU���u�c�A�H�n���m�A�������s
�A�n�����x��!!�����B���ʦѺ_��A��U���D�F���F�@�ǹL�����ȫȦb��
�A�u���x�L�]�򧤦b���Ať�ۥL��"�Q�K��!!"���[���n�A�A�߸̭ˤ]�n���_
�ӡA�o�]�P���즹�a���M���B�w�֡C���n�O�@����D�A���_�X�����h�O�q��
���~���˪L�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
        "northeast" : COMINGING_PAST"area/forest5",
  "south" : __DIR__"street1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/garrison" : 4,
]));
	set("outdoors","land");
	set("no_clean_up", 0);
set("light",1);

	setup();
	replace_program(ROOM);
}
