// �����s�} �J�f
inherit ROOM;
void create()
{
        set("short", "�L���s�}�J�f");
        set("long", @LONG
�A�`�N��P�D����F�W���ۤj�ΰʪ��������A���G�O�ئa�L�лx�C
LONG
);
        set("exits",([
        "west" : __DIR__"map_1_10",
        "east" : __DIR__"map_1_12",
        ]));
        set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

