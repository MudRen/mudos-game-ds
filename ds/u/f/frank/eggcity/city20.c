inherit ROOM;

void create()
{
        set("short", "�ೣ����D");
        set("long", @LONG
���b�o�̧A�i�H�P���ೣ�����ͩR�O�A�o�̨�B���p�c�b�s��A����
�����W�t�y�����A�H�ӤH�����n�����x�C���L�]�\�A�ä����D�A�b�o����
���H�s�쩳�����h�֤H�O�p���a�C
LONG
        );
        set("exits", ([                 
                "south" : __DIR__"city14",
                "east" : __DIR__"city21",
                "west" : __DIR__"city19",
                                        ]));

        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/man":2 ,
                                            ]));           

                
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

