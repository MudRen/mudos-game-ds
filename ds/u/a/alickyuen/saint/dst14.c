// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CRoad�IWest[2;37;0m");
	set("long", @LONG
�b�n�����@�Ӧa��A�A�i�H�b���̥ӽФ@���{�ɳq���ҡA�@�����ɤ�
�ݡC�ӧA��o�{�F�����S��F�@�I�A�ݨӨ��o�Ӥ�V�ǨS�����C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"pass",
  "west" : __DIR__"dst15.c",
  "east" : __DIR__"dst7.c",
]));
set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
