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
"east" : __DIR__"temple06",
"west" : __DIR__"temple07",
"north" : __DIR__"temple04",
  "south" : __DIR__"temple02",
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
