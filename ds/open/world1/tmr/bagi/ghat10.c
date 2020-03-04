// Room: /open/world1/tmr/bagi/ghat10.c

inherit ROOM;

void create()
{
	set("short", "�L�D");
	set("long", @LONG
�H�檺���թI�S�몺����b�L�줧���A�ȥզ⪺���a�Ϯg�ۨ벴����
���A���y�z���H���N��פ���o���Y�Ū����ҡC�����U�۪����B���F��
�H�����u�A�����M�j�j�i�H�ݨ�L�D�s�V��_����N�_�F�A���ӥN�����N
�O�@�B�L�a�C
LONG
	);
	set("outdoors", "snow");
	set("current_light", 4);
	set("no_clean_up", 0);
	set("world", "past");
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"ghat11",
  "southeast" : __DIR__"ghat5",
]));

	setup();
	replace_program(ROOM);
}
