// Room: /u/s/slency/area/ugelan/road4.c

inherit ROOM;

void create()
{
	set("short", "[1;33m�վB���j�D[2;37;0m");
	set("long", @LONG
�@���ѫC�۩ҾQ�����e��D���A���즹�B�A����M�ܼe���_�ӡA��
�����H�̤]��h�F�A���B�A�i�H�����ݨ��@�y�������Q�����b�@���e
���⩤�A��Ӯ�H�Q�����[�A�F��V�O�@���e�s���H��j�D�C
LONG
	);
	set("outdoors", "land");	
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road15",
  "west" : __DIR__"road6",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
