// Room: /u/a/acme/area/pass8.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o�O�@���ᬰ�U�p���s���A�|�P�����O�͡A���_�i�ݨ�@���p�ΡA�n
��h�O�@���@�K���˪L�A�b�s���Ǧ��Ӵݯ}���i�ܵP�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"forest1",
  "west" : __DIR__"wewd1",
  "north" : __DIR__"hunter",
]));
	set("no_clean_up", 0);
     set("outdoors","land");
     set("objects",([
        __DIR__"npc/obj/sign" : 1,
     ]));

	setup();
	replace_program(ROOM);
}
