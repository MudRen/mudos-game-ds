// Room: /u/m/mulder/area/shop3.c

inherit ROOM;

void create()
{
	set("short", "�s���o�Z���� -");
	set("long", @LONG
�o�O���Z�̤j���Z�����A�A�i�q�o�ضR�@�ǥ��i���Z���D��
�q�o�ػP��L�����a�洫�s���Z���A�A�]�i�H�b�o�ةM�L�̤@�_
�洫�D
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road5",
]));
	set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/weaponrobot" : 1,
]));

	setup();
	replace_program(ROOM);
}
