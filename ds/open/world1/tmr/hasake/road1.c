// road1.c �p��

inherit ROOM;

void create()
{
        set("short", "�p��");
        set("long", @LONG
���O���A���O�H�~���W���L�d�U������A�Ѫ���[�N�����榨�F�C
�o�u���ħJ���ڦb�o�̩w�~�w�[�A�i�H�ݨ���B�O�o�ح�l���D���C
LONG
        );

        
        set("exits", ([
           "northeast" : __DIR__"gebi5",
            "west" : __DIR__"road2",
        ]));

        set("outdoors", "land");
        
        setup();
        replace_program(ROOM);
}
