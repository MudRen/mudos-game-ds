inherit ROOM;

void create()
{
        set("short", "��D");
        set("long", @LONG
�o�̬O���ѫ����n��A�F�����ɬO��a�A���_����D�Q���e��
���n�i�H���}�ѫ��A�o���x�����ƬO���b�A�s���������S���C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sdoor",
  "north" : __DIR__"plaza2.c",
]));
         set("objects",([
             __DIR__"npc/man" : 1,
         ]));
        set("no_clean_up", 0);
         set("outdoors","land");
        setup();
        replace_program(ROOM);
}
