// Room: /u/s/superbug/train/5.c

inherit ROOM;

void create()
{
	set("short", "�޲z�B");
	set("long", @LONG
�o�̬O�޲z�B���j���A�̭������u�����w���b�A�q���W���ǹШӬݤw
���@�}�l�S���H�}�ҹL�F�A�q�����i�h�A�̭����������G�٦b�B�@�ۡA
��A�Q�i�h�ݬݮɡA�~�o�{���Q��F�_�ӡC
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "�j��" : "�@���G���ǹШåB�Q��_�Ӫ����A�A�ݭn�@���_�ͨӶ}�ҡC\n",
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"3.c",
]));
        set("world", "future");
        set("light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
