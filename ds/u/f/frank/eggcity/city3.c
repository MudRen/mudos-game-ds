inherit ROOM;

void create()
{
        set("short", "�ೣ�����������B�D�_��");
        set("long", @LONG
�o�̬O�ೣ����������B�D���_���A�ӧA�����a��O�@���۶��A���n
����V���@�ƪ��۶��A�s��@���j�ۤW�A�ѤH�[��Q�����ɤ@���ߨ����a
�C�ө��F�M����h�O���O�s�����F�w�W�A�Ѫo�H��͡C
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"city28",
                "south" : __DIR__"city1",
                "east" : __DIR__"city4",
                "west" : __DIR__"city2",
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

