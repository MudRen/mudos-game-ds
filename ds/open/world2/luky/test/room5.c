#include <path.h>
inherit MOBROOM;
void create()
{
	set("short", "���]�~��");
	set("long", @LONG

  �o�̬O���]���~���a, �����٪��F�@�Ǥp��M�@�Ǳq�ӨS���ݹL���p��
���J�C�����٦����p����, ���L�̭��S����, �u���@�Ƕ������M�콦�U�C

LONG
	);
set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room4",
  "south" : __DIR__"room6",
]));
//        set("light",1);
        set("outdoors","land");
	set("chance",35);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"npc/roach",
	__DIR__"npc/bug",
	__DIR__"npc/mosquito",
	}) );
	setup();
	
	//�`�N, �~��MOBROOM�� �����i�H�� replace_program(ROOM);
}
