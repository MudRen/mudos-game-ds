// Room: /u/s/slency/area/ugelan/road2.c

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�o�O�@���c�ت���D�C���񦳤@���Z�����A�����a�ݨ�۵P�W���g
�ۡi�Z�����j�A�ݨӬO��@�Ǩ����Z�����ө��A�����ɪŮȦ�̪�
�A�A���@��C�Τ@�Ǩ������Z���Q�ӬO���沈�n���A���_�K�O���a�Z��
���C
LONG
	);
        set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road1",
  "east" : __DIR__"road3",
  "north" : __DIR__"weapon",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
