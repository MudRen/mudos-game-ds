// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CRoad�ISouth[2;37;0m");
	set("long", @LONG
�ݨ�e���o�y�������ؿv���A�N���D���O���ӥ@�ɮɫسy���C�@�y��
�����а�A�ݤW�h�N�����L�ʦ~���v�A�O����a�O�@���j�N�ؿv�C���O�A
�A�q�o���а�W�A�����Pı���쯫�t�A�٦��@�I���ˮ��ơD�D�D�D�D�D
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dst3.c",
  "south" : __DIR__"dst1.c",
  "west" : __DIR__"church",
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
