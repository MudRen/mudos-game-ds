// Room: /u/s/slency/area/ugelan/farm5.c

inherit ROOM;

void create()
{
	set("short","�����~");
	set("long", "�A�Ө�F�վB�����������~�A���q�������N�q�ߦb�A�����e�A����\n""�a�i�H�ݨ�@�Ǧu���@�ï��b�����f�߬d�ۥX�J�ȫȪ�����A�]���o�y\n""���O����̤j���@�y��, �]���`�O���ܦh�l�l���w�쫰�̧@�áA�u���@\n""�ä��o�H�u�n�ɱ`�߬d�����򤣪k�H�h�������J�վB�����A�ѳo�̩��_\n""���N�쫰���F�C
"
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"bigdoor",
  "south" : __DIR__"farm1",
  "west" : __DIR__"farm6",
  "east" : __DIR__"farm4",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
