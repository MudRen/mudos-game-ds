// Room: /u/a/acme/area/pass10.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�A�����b�@���������s���W�A���W�E�F�۪O����A���Hı�o�p�i���a
�A���@��ı�o�O�b���s�A�B�ŦӤW�A�i�樣�ѫ��������A�V�n��h���Ӥp
���F�C�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"pass9",
  "southwest" : __DIR__"pathway8",
  "northwest" : __DIR__"farm1",
]));
   set("no_map",1);
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
