inherit ROOM;

void create()
{
        set("short", "��Ԩ���");
        set("long", @LONG
�o�̬O�@�ϥѼƽ��������ۥH�K���_�ó�_�Ӫ��@���Ŧa
�A�a�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"camp022",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

