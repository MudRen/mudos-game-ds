// room-ji1.c

inherit ROOM;

void create()
{
        set("short", "�p��");
        set("long", @LONG
�p�Τ����]²���A����Ⱦ��A�����o�����b�b�C�@��ѤH�����b��
�l�W��z�۸J�_�C�|�P��F�������A�������p���ۤW���F�X�ӥ˳��A��
�X�}�}���H������C
LONG
        );
        set("exits", ([
            
            "out" : __DIR__"room-ji",
        ]));
        
        set("objects", ([
                    __DIR__"npc/ji" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
