// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CCenter�IMiddle[2;37;0m");
	set("long", @LONG
�o�̴N�OSaint��Centre�F�A���O�bSaint����������m�C�A�i�H�N�o
�̷��A�b�o�����}���X�o�I�A�]���o�̤H�h���{�A���ȷ|�g���C�o�̦�
�F�B�n�B��B�_�|�Ӥ�V�A�A�ۤv��B�}�}�A�����w���N�~��ì�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dst3.c",
  "west" : __DIR__"dst7.c",
  "north" : __DIR__"dst5.c",
  "east" : __DIR__"dst6.c",
]));
   set("outdoors","land");
	set("world", "future");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/pot.c" : 1,
__DIR__"npc/child.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
