// Room: /tmr/garea/forest11.c

inherit ROOM;

void create()
{
	set("short", "�����p��");
	set("long", @LONG
�A�����b�@���L�����p���A�|�g�����ۤ@���H���A�ٳz�ۤ@���H��A
�ݨ쪺�����ɬO������ݤ��ƲM���A���n�g���`�B�@�h�A��G�դ@���A
�u�Ȩ��o�i�h�A�䤣����X��...
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
        "southwest" : __DIR__"forest9",
	  "northeast" : __DIR__"forest13",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
