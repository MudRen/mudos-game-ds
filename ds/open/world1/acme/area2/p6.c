// Room: /u/a/acme/area3/p6.c

inherit ROOM;

void create()
{
	set("short", "����p�|");
	set("long", @LONG
�A�����b�p���Ǫ��p�|���A�A�i�樣�������U�y������ۡA��������
���}�A�����W���C�줣�ɪ��s�ۡu�K��K��v�A�F�䦳�@�y�p�����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"p7",
  "west" : __DIR__"p3",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
