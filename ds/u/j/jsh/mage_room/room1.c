inherit ROOM;

void create()
{
        set("short", "�E�Ѥ��a");
        set("long", @LONG
�@�C�}�����N�Q���e������ҧl�ަ�A�L��L�~���Ŷ��̡A���G������
�ۤ���A�A�^�Y�@�ݡA�u������O�`���������Ů��A�ӫe��O�@�D��⪺
�j���A�ϧA�n�_���Q�i�h�@�@�C
LONG
        );
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"enter-room",
]));
        set("no_clean_up", 0);
        set("world", "undefine");
        set("outdoors", "lands");

        setup();
        replace_program(ROOM);
}

