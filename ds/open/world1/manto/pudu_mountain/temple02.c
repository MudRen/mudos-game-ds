inherit ROOM;

void create()
{
       set("short", "�x�e");
        set("long", @LONG
�@�y�j���A���k�U�@���鷵�A�F��[�ЬO�I�лP�׫����ҡA�i��²��
�S²�A�H�ܩ�l�C�Ӧx�|�e��צˡA��ӫC�Q�A�s�u�Ӧۥ����A¶�x�ӤU
�C�Ѫż���C�s�L���������A���M����A�O�A���H���@�Z�A�ᦳ�]�R�Ѧa
���P�C
LONG
        );
        set("exits", ([ 
 "north" : __DIR__"temple03",
  "south" : __DIR__"temple01",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
