// Room: /u/a/acme/area2/t51.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�|�h]");
	set("long", @LONG
�o�̺����O���ȯ]�_�A�ݨӬO�խߨ��Ш�B�h���T�ӨӪ��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"t50",
]));
set("objects",([
    "/open/world1/acme/area/obj/herb5" : 3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
