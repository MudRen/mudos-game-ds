// Room: /u/a/acme/area/parlor.c

inherit ROOM;

void create()
{
	set("short", "���Z�j�U");
     set("light",1);
	set("long", @LONG
�o�̬O���Z�Ъ��j�U�A���䪺��W���ۤ@�T�s���e�A�j�U�e���i�Ӯv
�ȡA�����ȧ�W����s�Y�A�k���h��۪��Y�A�Ӯv�ȤW���ۤ@�줤�~�k�l
�A���L�o���J�W�䤤�A�å��oı�A����ӡA�b�Ӯv�ȫ᪺��W�K�ۤ@�T��
�l�A�W�Y�g�ۡu�߯෥��ߡv�A�u�G�෥��C�v�A�Q�Ӷª��j�r�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"corridor",
]));
    set("objects",([
       __DIR__"npc/liu" : 1,
//     __DIR__"npc/rankman" : 1,
    ]) );
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}
