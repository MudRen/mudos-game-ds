inherit ROOM;

void create()
{
        set("short", "�p�ۥx");
        set("long", @LONG
�w�B�b�L���樫�A�V���V���A�L����o�}���A��۪Q�w�A�ܧ֨Ө��
�X��ػ\���ѡBפ�K��¶���a�Q���U�C�@�����b�����b��U�ۮध�W�A��
�L�ӥߡA���V����A�Ӫ��a�y�L�����޲z�ۨ��W�Ф�A�Ф��զp���C
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"temple13",
  "south" : __DIR__"temple12",
]));

 set("objects", ([
 __DIR__"obj/table" : 1,
 __DIR__"obj/seat" : 2,
 ]));
        set("outdoors", "land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
} 
