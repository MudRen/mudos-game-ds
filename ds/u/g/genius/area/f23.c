inherit ROOM;

void create()
{
set("short","���");
        set("long", @LONG
�o�̺ؤF�@�ǥ]�ߵ�H�νܨ��������@���A�C�檺�C�⥿�O���A�O�H
�ݤF�u�Q�Ħ��_�ӹ��|�@�f�C�o�̤]�ݪ���@�Ǭ��R���p��A�H�H�a�I��A
�O�H�P��;��s�M�A�Q���ΪA�C
LONG
        );
        set("exits", ([
        "northwest":__DIR__"f13",
        "west":__DIR__"f22",
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

