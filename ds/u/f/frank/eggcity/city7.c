inherit ROOM;

void create()
{
        set("short", "�ೣ�����������B�D��n��");
        set("long", @LONG
�o�̬O�ೣ����������B�D��n���A�ӧA�����b�@�ӤH�u���p�F�w�W�A
���F�M���_���i�H������X�f�A���F�_��V�ݥh�i�H�ݨ��ೣ�����a�Тw
�Q�����C�ӧA�ҥߨ����F�w�Q������������¶�A�F�w�W�ؤF�@�Ǧˤl�A�Q��
���ֱ��ܷN�C
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"city5",
                "east" : __DIR__"city8",
                                        ]));
        
        
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

