// Room: /u/a/aring/tomb/6.c

inherit ROOM;

void create()
{
        set("short", "�j�Ӷ�Ъd��");
        set("long", @LONG
�o�̬O�j�Ӷ餤���@���d�ڤp���A��ǳ��O�X�өM����A���b�o��
�Pı��S�ƤS�H�A�e�誺���W�٦��@�Ǧ��H�D�H���}�L�C
LONG
        );
        set("no_clean_up", 0);
        set("light", "0");
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"8.c",
  "northeast" : __DIR__"1.c",

]));
        set("current_light", 2);

        setup();
        replace_program(ROOM);
}

