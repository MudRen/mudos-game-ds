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
  "south" : __DIR__"room1",
  "west" : __DIR__"room3",
]));
//        set("light",1);
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",2);	
	set("mob_object",({	
	__DIR__"npc/roach",
	__DIR__"npc/rat",
	}) );
	setup();
	
	//�`�N, �~��MOBROOM�� �����i�H�� replace_program(ROOM);
}
