inherit ROOM;

void create()
{
        set("short", "�ೣ�����������B�D�n��");
        set("long", @LONG
�o�̬O�ೣ����������B�D���n���A�ӧA�����a��O�@���۶��A���_��
��V���@�ƪ��۶��A�s��@���j�ۤW�A�ѤH�[��Q�����ɤ@���ߨ����a�C��
���F�M����h�O���O�s�����F�w�W�A�Ѫo�H��͡C
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"city7",
                "south" : __DIR__"city39",
                "east" : __DIR__"city9",
                "north" : __DIR__"city1",
                                        ]));
                
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/fish":4 ,        
                                ]));           
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

