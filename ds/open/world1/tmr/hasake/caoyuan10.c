// caoyuan10.c ���
inherit ROOM;
void create()
{
        set("short", "�j���");
        set("long", @LONG
�A���i�F�o�M�����������j���A�}�U�O�o�p���C��A�n�������ٯu
���n���A�ݨӶR�ǰ��ӥN�B��O���n�D�N�C
LONG);
        set("exits", ([
            "south" : __DIR__"caoyuana",
            "west" : __DIR__"caoyuan7",
            "east" : __DIR__"caoyuan8",
            "north" : __DIR__"caoyuan9",
        ]));
        set("objects", ([
                    __DIR__"npc/dingtong" : 1
        ]));
        set("outdoors", "land");
        setup();
        replace_program(ROOM);
}
