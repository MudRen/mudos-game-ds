#include <path.h>
inherit MOBROOM;
void create()
{
	set("short", "���]�~��");
	set("long", @LONG

  �o�̬O���]���~���a�A�����٪��F�@�Ǥp��M�@�Ǳq�ӨS���ݹL
���p�����J�C�����٦����p�����A���L�̭��S�����A�u���@�Ƕ�����
�M�콦�U�C
LONG
	);
set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room2",
  "west" : __DIR__"room4",
//  "bridge" : LUKY_NOW+"area_1/room80",
]));
//        set("light",1);
        set("outdoors","land");
	set("chance",50);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"npc/roach",
	__DIR__"npc/bug",
	__DIR__"npc/mosquito",
	}) );
	setup();
	
	//�`�N, �~��MOBROOM�� �����i�H�� replace_program(ROOM);
}
