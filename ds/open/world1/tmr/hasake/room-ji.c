// room-ji.c ���

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�o�O�b���ڪF�_���t�s�s���@�y��סC�o�׫Τg��󳻡A�Φ��{�p��
�a�~�H���j�ΡA�u�O�Ƭ�²���A���䦳�@�Ӥp�����C�A���������V�p�Ϋ�
���A���Q���Y�q���l�V�Τ��i��A�����������@�i�y�P�ɱ��F�W�ӡC��_
�h�N�O�j����F�C
LONG
        );
        set("exits", ([
            "enter" : __DIR__"room-ji1",
            "south" : __DIR__"road2",
        ]));

        set("outdoors", "land");

        setup();
        replace_program(ROOM);
}

