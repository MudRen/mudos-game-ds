// Room: /u/a/alickyuen/area/dst6.c

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CRoad�IEast[2;37;0m");
	set("long", @LONG
�o�̱��񥫤��ߡA�ҥH�A�P��ܹ˧n�C���O�A�ݨ�e�����@�ө_�Ǫ��{
�H�A�N�O�e���E���F�@��H�s�A�A���n�_�߱ЧA�Q�쨺�̬ݬݡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dmid.c",
  "east" : __DIR__"dst11.c",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
