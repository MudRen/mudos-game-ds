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
                "east" : __DIR__"city22",
                "west" : __DIR__"city20",
                                        ]));          
                
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

