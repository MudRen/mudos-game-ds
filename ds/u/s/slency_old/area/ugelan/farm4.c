// Room: /u/s/slency/area/ugelan/farm4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", "�o�̬O���~�����ϰϡA�i�H�ݨ��@�Ǫ��H�P���Ϥ��b���W���ʡA\n""�s�諸�a�P�ѥ�����@�T�C�R���ϵe�A���谪�s�Q���hŢ�n��A��L�e\n""�z�A�n�@�Ӷ������N�H��!!\n"
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"farm2",
  "west" : __DIR__"farm5",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
