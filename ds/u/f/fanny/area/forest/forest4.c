// Room: /u/f/fanny/area/forest/forest4.c

inherit ROOM;

void create()
{
    set("short", "�s�}");
    set("long", @LONG
�i��o�̡A���W����v�������۸T���ݥߤF�_�ӡA�A����ı���\
�X�ۤv�̱j�����ΨӫO�@�ۤv�A�@�ئ��`���𮧥��b�I�k�ۧA�~���
�b�o�̪��N�ӡC
LONG
        );
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"forest3.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/u/f/fanny/area/npc/tiger" : 1,
  "/u/f/fanny/area/npc/tigress" : 1,
  "/u/f/fanny/area/npc/cutetiger" : 3,
]));
	setup();
	replace_program(ROOM);
}
