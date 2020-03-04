// Room: /open/world1/tmr/xiangyang/eastjie3.c

inherit ROOM;

void create()
{
	set("short", "�F�j��");
	set("long", @LONG
�o�O�@���e�諸�C�۵�D�A�V�F����Y�����C�F���O�C�s
�����A�n��O��K�Q�A�����n�B�S���n�n�n�J�աC�_���O����
�����F�L��A������ť���̭��Ǩӧ��L���޽m�n�C����O�@��
�Q�r��f�A�u���H�ӤH���B��ö�����C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"eastjie2_e1",
  "south" : __DIR__"mujiang",
  "east" : __DIR__"eastgate1",
  "north" : __DIR__"bingying2",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -510,
  "x" : -470,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
