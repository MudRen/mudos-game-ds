// Room: /open/world1/acme/area/f1.c

inherit ROOM;

void create()
{
	set("short", "�p�|");
	set("long", @LONG
�A�����b�o�իժ��|���A�d�馱�骺�p�|�]�H�Ϩu�ܡA�p�|�W��
���F���ը~�A�b�o����藍�ɶǥX���Ϊ���s�n�A�t�X�۪K�Y�W����
���ХX�p���a�X�����ʤH�ֳ��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"f2",
  "southeast" : __DIR__"pass5",
]));
     set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
