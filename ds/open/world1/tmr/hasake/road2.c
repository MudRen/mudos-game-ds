// road2.c �p��

inherit ROOM;

void create()
{
        set("short", "�p��");
        set("long", @LONG
���O���A���O�H�~���W���L�d�U������A�Ѫ���[�N�����榨�F�C
�o�u���ħJ���ڦb�o�̩w�~�w�[�A�i�H�ݨ���B�O�o�ح�l���D���C�_��
�n�����@���p��סC
LONG);
        
        set("exits", ([
            "east" : __DIR__"road1",
            "north" : __DIR__"room-ji",
            "southwest" : __DIR__"caoyuan6",
        ]));

         set("objects", ([
                    __DIR__"npc/bird" : 1

        ]));

        set("outdoors", "land");
        
        setup();
        replace_program(ROOM);
}
