inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�A�Ө�F���D�������󪺦a��A���_��A�ϩ��ݪ������ӷݨ��Y��
���������n�ۧA�ݡA�Pı��@�ѴHŸ�A���n��O�@�������ж��M�p�٤l
�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"path7",
  "west" : __DIR__"path4",
  "north" : __DIR__"hall",
  "south" : __DIR__"path2",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
