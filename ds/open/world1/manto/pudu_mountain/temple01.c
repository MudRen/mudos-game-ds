
inherit ROOM;

void create()
{
       set("short", "�ѥؤ��q");
        set("long", @LONG
�D�W�ѤU������x�A�]�ȬO�@���p�p���x�q�Ӥw�A�ҿפs���b�����P
�h�F�A���o��W�Ҫ��x�q�A���ʨ��A���U�ʮy���h�C�ѥؤ��q�C�X����
�q�J�������ۤ��U�A�x�q�̶զӥߡC
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"way13",
  "north" : __DIR__"temple02",
]));
        set("objects", ([ 
          __DIR__"npc/man" : 1,
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
