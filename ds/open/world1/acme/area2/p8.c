// Room: /u/a/acme/area2/p8.c

inherit ROOM;

void create()
{
	set("short", "����p�|");
	set("long", @LONG
�A�����b�p���Ǫ��p�|���A�A�i�樣�������U�y������ۡA��������
���}�A�q�������ɶǨӫC��u�K��K��v���s�n�A���_��h�i�ݨ��@���p
�ΡA����h���@�y�����C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"p7",
     "north": __DIR__"start",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
