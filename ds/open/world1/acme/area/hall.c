// Room: /u/a/acme/area/hall.c

inherit ROOM;

void create()
{
	set("short", "�Z�U");
     set("light",1);
	set("long", @LONG
�o�̬O���Z�Ъ��m�Z�U�A�o�O����J�Ъ��̤l�b���߼C�A�@��@����
���A��̭�F�A���̰�T�C�j�U���f�W���T���B�A�W�Y�g�ۥ|�Ӥj�r�u�C
��R�]�v�A���k�������ڡA���O�m�Z���H�ҮѡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"corridor",
]));
     set("objects",([
        __DIR__"npc/apprentice" : 3,
        __DIR__"npc/woodman" : 4,
     ]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
