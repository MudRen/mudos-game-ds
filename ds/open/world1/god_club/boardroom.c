inherit ROOM;

void create()
{
        set("short", "�|ĳ�j�U");
        set("long", @long
�g�L�F�@�Ӫ��Y�A�Ө�F���Ҫ��|ĳ�j�U�A�j�U���������@�i��
�j�|ĳ��A�����٦��@�Ӥ��G��C�b�o�ӯ��t���|ĳ�j�U�̡A�|���i
�@�ǭ��j���Ʊ����|��@�Ǥj���|ĳ�C�p�G�A������Ʊ��Q�����A�]
�i�H�K�b���G��W�C�A���n���A�O�M���s��D�㪺�D�㤧�ΡC 

long);
        set("exits", ([
  "north" : __DIR__"ladder-1",
  "south" : __DIR__"room_item",
]));
        set("light", 1);
        setup();
        set("stroom", 1);
        call_other("/obj/board/club_god_1.c", "???");
}

