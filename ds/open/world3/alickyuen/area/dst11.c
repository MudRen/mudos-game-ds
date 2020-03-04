// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CRoad�IEast[2;37;0m");
	set("long", @LONG
�o�̥_���O�@���j�s���A���̪��]�ƫD�`�����A��O�ܦh�H�簲��
�a��C�ӫe���������E�̵M�H�s�H���A�ݨ����ӬO�@���歹�������A�A�Q
�i�਺�̦��n���F��A�N�Q�ĹL�h�����x�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"inn.c",
  "west" : __DIR__"dst6.c",
  "east" : __DIR__"dst12.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
