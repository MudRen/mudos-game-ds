// Room: /open/world1/tmr/dragoncity/house1.c

inherit ROOM;

void create()
{
	set("short", "�֫ө��Фj��");
	set("long", @LONG
�@�y�ؿv�j�몺�j�v�|�X�{�b�A�����e�C�u�����Ӱ��D�A�W�ѥ����j
�r�u�֫ө��v�C�֫ӭx���X�Ӥl�̧L�M�a�B�N�u�b���e�A���ݫe�ӫO�ýY
�s�����ȤH�A�u���H�̶i�i�X�X�A�D�`�����x�C
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "land");
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/guard3" : 2,
]));

	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"house2",
  "south" : __DIR__"south_din",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
