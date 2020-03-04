// pmchang.c �]����

inherit ROOM;

void create()
{
        set("short", "�]����");
        set("long", @LONG
�o�@�j�M��a�N�O���ħJ�ڤH���]�����F�C�s�諸�Ŷ��M�ө������h
�ӤH�ϥ������o�@�a���c�������|�a�M�����C�@�~�@�ת��L�����ɩM�]��
�`�]�b�o���|��C
LONG
        );
        set("objects", ([
                    __DIR__"npc/hasake" : 1,
                    __DIR__"npc/niu" : 1,
                      __DIR__"npc/sheep" : 1,
                    __DIR__"npc/chen" : 1,
        ]));

        set("exits", ([
            "northeast" : __DIR__"shop",
            "west" : __DIR__"road",
            "northwest" : __DIR__"caochang",
            "southeast" : __DIR__"caoyuan",
            "southwest" : __DIR__"shuijing",
        ]));

        set("outdoors", "land");
        
        setup();
        replace_program(ROOM);
}
