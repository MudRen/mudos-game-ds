// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�o�̬O�@���ѫC�۩ҾQ������D�A���F�Өө������H�s�A�èS����
��S�O���A�𨤤W���Ӥp�}�����a�y�X���ӡA���ܦh���y���ʪ��b����
�ܤ��Ѵ��C
LONG);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road9",
  "north" : __DIR__"road11",
]));
	set("item_desc",([
	"�p�}" : "�@���𨤪d�j�H���ҳy�����p�}, �}�̤��_�y�X���ӡC\n" ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
