// Room: /u/t/truewind/Minetown/area/minetown_bill1.c

inherit ROOM;

void create()
{
	set("short", "�G�өж�");
	set("long", @LONG
���ӬO�񺸦��a��A���ɭԤ]�R��ȩСA���O�۱q�񺸦b�q��
�Ȩ줣�֧Q��R�F�s�ΥH��A�o�̴N�ܦ��o���x�ëǤF�A��B���O�j
���ǹСA���O�A�`�N�쨤�����@�Ӧ��o�n�����Q�H�h�ʹL������..
.�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"minetown_bill",
]));

	setup();
	replace_program(ROOM);
}
