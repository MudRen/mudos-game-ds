// Room: /tmr/garea/forest10.c

inherit ROOM;

void create()
{
	set("short", "�L���p��");
	set("long", @LONG
�A�����b�@���L�����p���A�|�g�����ۤ@���H���A�ٳz�ۤ@���H��A
�_������V�K���ɶǨӤ@�Ѵc����A�z�L�g����h�A���������i�ݨ����B
��h�C���n�g���`�B�@�h�A�󨣺G�դ@���A�u�Ȩ��o�i�h�A�䤣����X��
.....
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
        "southeast" : __DIR__"forest9",
	  "northwest" : __DIR__"forest12",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
