// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�@���ΫC�۾Q������D�A��B�i�����֪��p�c�b���c�������A�~��
�̤]�j�����w�Ӧ��ʪ��A�K�y�B�����c�h�O��������S��A����O�@��
�������D�C
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road3",
  "north" : __DIR__"road7",
]));
 	set("outdoors", "land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
