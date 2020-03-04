// Room: /open/world1/tmr/bagi/ghat2.c

inherit ROOM;

void create()
{
	set("short", "�s�D");
	set("long", @LONG
�A�����b�@���ճ��J�J���s�D�A���n���h�O�o���s�D�����Y�A�ݨӬO
�B�a�V�A�s�D�G�ǺɬO�ǪQ�B�f���������C���ȴH�Ӫ��A���ӥi�ݨ�@��
�p�����B�p���ߥX�S�b���ǡC�s�D���䦳���˫ΡA�ݨӦ��H�~��b���A
�˫γz�S�ۤ@�Ѳ��M�ӥ��R����^�C
LONG
	);
	set("world", "past");
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"ghat3",
  "west" : __DIR__"house",
  "south" : __DIR__"ghat1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
