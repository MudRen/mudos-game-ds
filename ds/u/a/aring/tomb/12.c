// Room: /u/a/aring/tomb/12.c

inherit ROOM;

void create()
{
        set("short", "�j�Ӷ�мX��");
        set("long", @LONG
�A�����b�@�y�X�Ӫ��W�Y�A�|�P�����۴X�Ӵä�A�����D�O�Q���X
�ӡA�٬O�ڥ��S���I�A�`���Ů𤤺��G�ͯ���A�u�O�O�H���H�Ԩ��C
LONG
        );
        set("light", "0");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"13.c",
  "west" : __DIR__"11.c",
]));
        set("current_light", 1);

        setup();
        replace_program(ROOM);
}

