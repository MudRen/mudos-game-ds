// Room: /u/a/acme/area/pathway8.c

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o�̬O�α��ۤѤs�M���F���������p���A�@�}���j�ӡA���_�F�@����
�F�A�F�l�������R�V�A��ŧ�ӨӡA���W�Q���F�αo�����@�h�A�f��o�]�l
�i�F���֪��F�A�O�H�@�áC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"pass10",
  "southeast" : __DIR__"pathway9",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
