inherit ROOM;

void create()
{
        set("short", "�ೣ�����������Q���f");
        set("long", @LONG
�o�̬O��������������m�A�A�����b�@���j���Y�W�A�A�C�U�Y�ӥi
�H�M�����ݨ����������s�b�����ۥѦۦb���C�ӹC�h�Q���g�N�C�ӧA���e
���Q���W���b���_���ܴ���ˡA�o�ǨӦۦ�誺���N��`�`�l�ޤF�A����
���A�N��A����A�w�g�Q�Q���������ᵹ�Q��F�A���O�A�̵M�S�Pı�A��
�¨I�K�b���e�����������C
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"city5",
                "south" : __DIR__"city8",
                "east" : __DIR__"city6",
                "north" : __DIR__"city3",
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

