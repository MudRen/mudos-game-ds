
inherit ROOM;

void create()
{
       set("short", "����");
        set("long", @LONG
�������ѩ^�ۦp�Ӧ򹳡A�|���H���A���Y�¿p�A���e�@�L���l�A�W��
�T�ڥb�W�U���A�����Ƶ۲H�H���ȭ��C�@�i�¤�G�L�\���򹳫e�A�L�W
�i��������ơA�M������q�C�V�������ư_�A�����\�\�A���������C
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"temple05",
  "south" : __DIR__"temple03",
]));
        set("no_clean_up", 0);
    set("objects", ([
    __DIR__"npc/bonze" : 1,
     ]) );
        set("light",1);
        setup();
        replace_program(ROOM);
}
