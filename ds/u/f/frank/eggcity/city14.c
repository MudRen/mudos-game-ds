inherit ROOM;

void create()
{
        set("short", "���~");
        set("long", @LONG
��L�F���e�A�A���i�F�@�ɥ��v���A�̭����G�m�Q��������A�q�ƳE
�γE��������ȩM���e�A�H�ΰ��b�������A��M����A�A���D�o�a�O��
���[�H�A�ӫθ̪��k�H���H�g�X�h�إФF�A�u�Ѱ��H�b�����a���A�M�p��
�b�a�W���C

LONG
        );
        set("exits", ([                 
                "north" : __DIR__"city20",
                                        ]));

        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/yang":1 ,
                                            ]));           

                
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

