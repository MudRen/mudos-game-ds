// Room: /u/s/sub/area/village/tree2.c

inherit MOBROOM;

void create()
{
	set("short", "��W");
	set("long", @LONG
�z�L�߲����K���i�H�ݨ��o�̽��Ū��ѪšA���@�S������Q�ìV����
��C��W���ɦ��Ǥp�ʪ��]�Ӷ]�h�A���H�]�g�V�F�o�̵L�~�L�{����^�A
���T�_�F�h�����ߡC�ѩ�o�̶Z���a�����|�Q�X���ت����סA�@����h��
�Ӥs�����@�ؤF�M�C�_�䦳���ʧ�����K�����줣���B���k���W�C
LONG
	);
	set("outdoors", "land");
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"tree1",
  "north" : __DIR__"tree3",
]));
    set("chance",50);
    set("mob_amount",2);
	set("world", "undefine");
        set("mob_object",({     
        __DIR__"npc/village_worm_1",
        }) );
	set("no_clean_up", 0);

	setup();
}
