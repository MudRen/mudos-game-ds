// Room: /open/world1/tmr/frost/observatory.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-�[���x");
	set("long", @LONG
�[���x���M���ʾ]�s�b�s�y�A���a�����A���ѩ󦹳B���{�˨��A��
�_���h���������ɬO�@���}��A�W����P�B�U�[�˪L�A�ѱ�ܩ]�A�Ӵ�
�L�ɵL�賣���@�A��d�ܸU�ۦӹܤѦa�����B�A�u���u�����ѹL���H�~��
��|�A���O�T����y�N��D�ɪ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hill1",
  "east" : __DIR__"observatory2",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bisongbo" : 1,
]));

	setup();
	replace_program(ROOM);
}
