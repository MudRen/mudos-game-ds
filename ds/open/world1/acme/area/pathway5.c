inherit ROOM;

void create()
{
        set("short", "�p�|");
        set("long", @LONG
�o�̸��U���U�p�A�P�򪺳���F�X��N�p�����T�S�F�A�o��B���O
�����j�j����A��M�O�H�ϵ}�֡A�����i���F��M�_�䦳�@���p�|�C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"pathway4",
  "north" : __DIR__"pathway6",
  "east" : __DIR__"pathway7",
]));
        set("objects",([
        __DIR__"npc/dog.c" : 2,
]) );
        set("no_clean_up", 0);
         set("outdoors","land");

        setup();
        replace_program(ROOM);
}
