// shanqiu.c �p�s�C

inherit ROOM;

void create()
{
        set("short", "�p�s�C");
        set("long", @LONG
�o�̬O���M�˪L�����ɽu�A����i�H�ݨ찪�q�p�����Ѥs�s�ߩM�q
�o�̤@�������X�h���w���L�A���F�i�H�ݨ����ڪ��]�����A�������i�Hť
�����ħJ�ڤH���ܻy�C
LONG);        
        set("exits", ([
            "east" : __DIR__"road",
            "west" : __DIR__"senlin1",
        ]));

        set("objects", ([
                         __DIR__"npc/bird" : 1,
                         __DIR__"npc/supu" : 1,
        ]));

        set("outdoors", "land");
        
        setup();
        replace_program(ROOM);
}
