
inherit ROOM;

void create()
{
        set("short", "�ೣ�����������B�D�F�n��");
        set("long", @LONG
�o�̬O�ೣ����������B�D��_���A�ӧA�����b�@�ӤH�u���p�F�w�W�A
����M���_���i�H������X�f�A����_��V�ݥh�i�H�ݨ��ೣ�����a�Тw
�Q�����C�ӧA�ҥߨ����F�w�Q������������¶�A�F�w�W�ؤF�@�Ǧˤl�A�Q��
���ֱ��ܷN�C
LONG
        );
        set("exits", ([                 
                "west" : __DIR__"city8",
                "north" : __DIR__"city6",
                                        ]));
                
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

