inherit ROOM;
void create()
{
        set("short", "�������s��");
        set("long", @LONG
�e��s���̪��a�W�O�ѦU�ج��R�����J�O�j�Ҧ����A�C�Ѧ�����ﱵ
�ȤH���N�O�o�Ǭ��R�����J�O�j�C�A���b�����������߼s���������A���e
�����N�O�ǻ������������F�A����L�N�O���������C
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"room1",
  "northeast" : __DIR__"room3",
  "northwest" : __DIR__"room4",
  "north" : __DIR__"room5",
  "southeast" : __DIR__"room6",
  "southwest" : __DIR__"room7",  
]));
set("no_recall",1);
set("light",1);
        set("objects", ([
 __DIR__"npc/dwller" : 3,
__DIR__"npc/obj/well"  :1,
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}

