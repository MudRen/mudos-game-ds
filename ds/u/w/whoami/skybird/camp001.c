inherit ROOM;

void create()
{
        set("short", "�H�۸�");
        set("long", @LONG
�ݨӳo�̸g�L�F�@�f�}�ݡA�~�N���ΪӪ����󵹲M���A�åB
�b�W���Q�W�H�ۡA�H��K�x�Ϊ��B�騮���q��C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"ten9",
  "east" : __DIR__"camp002",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

