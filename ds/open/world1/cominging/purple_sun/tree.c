// �����s�j��W

inherit ROOM;

void create()
{
        set("short", "�j��W");
        set("long",@LONG
�A�{�b���W�F�o�ʾ�A��W����K��������A���ä��w�A���I����
�A��W���D���֡A��b�U���٭n�D�F�\�h�A���L�o�̫o�����z���A�A
ť�즳�ǼR�R�n�D�D
LONG
        );
        set("objects", ([
  __DIR__"npc/squirrel.c" : 2
]));
        set("exits", ([
  "down" : __DIR__"1f3.c",
]));
        set("no_drop",1);
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}

int query_max_capacity() { return 40; } // ���o���N���঳ replace_program(ROOM);, �̦n�] no_drop
