// Room: /u/a/acme/area/plaza3.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o�̬O�ѫ����F��s���A�A�i�H�ݨ�\�h�p�Ħb���H���A�o�̬۷�
���e�s�A���H��b����}�߯ݡA�b���Ǧ��Ӫ����A�W����F�ӯ����A��
���W�K�F�@�i���ȡA�W���g�ۡu�^���v�A���O���������H�Ѵ����C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"plaza1",
  "east" : __DIR__"street3",
]));
    set("objects",([
       __DIR__"npc/child" : 3,
          __DIR__"obj/teapot" : 1,
    ]));
	set("no_clean_up", 0);
       set("outdoors","land");

	setup();
	replace_program(ROOM);
}
