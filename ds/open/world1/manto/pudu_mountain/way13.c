inherit ROOM;

void create()
{
       set("short", "�p�|");
        set("long", @LONG
����H�����\�a�C�C�˪L�A�˪L���M���B�A���������X�{���ˬ���A
�@�y�x�q�����䤤�C�O�H���Ѥߤ��@�M�A��ͥj��M�դ����A��b�O�Ӧn
�Ҧb�C
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"temple01",
  "east" : __DIR__"way12",
]));
        set("objects", ([ 
         __DIR__"npc/scholar" : 1,
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
