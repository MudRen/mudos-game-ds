// Room: /open/world1/tmr/gumu/mudao09w8.c

inherit ROOM;

void create()
{
	set("short", "[1;32m�ӹD[0m");
	set("long", @LONG
�o���O�j�Ӥ����ӹD�A�|�P�K���z���A�ɵ��٤W���t���O���A�A��
�j�j����X��V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X�o�ƬO�����A��
�H�q����X�@���_�ءC�O���Ӧb�C�۾��W�A�{�{�ۺѫիժ����I�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"mudao10",
    "southeast" : __DIR__"mudao09w7.c",
]));
        set("objects", ([ /* sizeof() == 1*/
          __DIR__"npc/apprentice" : 3,
        ]));      


	setup();
	replace_program(ROOM);
}
