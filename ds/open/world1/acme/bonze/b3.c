// Room: /open/world1/acme/bonze/b3.c

inherit ROOM;

void create()
{
	set("short", "�s�D");
	set("long", @LONG
�Ѧ��a�g�A�V�o�Y�D�I�I�A���_�_���򪺯T�z��ڡA��S��q�A
�e�}���I���ѪšA��W���H�N�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"b4",
  "northwest" : __DIR__"b2",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
