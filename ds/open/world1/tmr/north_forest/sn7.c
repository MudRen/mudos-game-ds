// Room: /u/l/lestia/area/sn7.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L");
	set("long", @LONG
�AĲ�ةҤΪ��A�u���@�ʴʰ��q�����A��𪺸��l�����D�`�Z���A��
�o�����L�k�Ӷi�ӡA�]�ϱo�˪L�̪���^���I���N�C���W�A�����F�C�a�A
�ݰ_�Ӧ��I���ߡA���Ȧp���A�a���W�����Y�]���O�C�a�A�ҥH�A�C�@�B���n
�p�ߪ����A�~���|�g�W�������ߪ��C�a�C�Ӵ˪L�����Ů�R���F�@�Ѳ����A
���F���n�D�������ߪ����D�A�A���ѱo��I�l��p�F�C
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("objects", ([ 
__DIR__"npc/wolf":2,
	__DIR__"npc/troll2":2,
]));

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sn8",
  "north" : __DIR__"sn6",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
