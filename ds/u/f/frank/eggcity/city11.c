inherit ROOM;

void create()
{
        set("short", "�ೣ���n�Z��");
        set("long", @LONG
���X�F���t���˪L�B�D�ϡA�b�A���e���O�ೣ���������w�_�Z���A��
�����������q�J���A���ꪺ�j���O�Τ@�h�p�������K��W�A��T���{�ץs
�H�Q�Τ���V�V�ݡC�b�o�̧A�ݨ쪺�O�H�ӤH�����A�٦��p�c�b���s��O
�A�n�����x�A���L���b�����f���x�L�ˬO�A�Z��椣�J�o���x����^�A�@
�y�N�Ū��啕���H�A�J�ӽL�d�A���O�A�f�ǤH�����A�O�H���ΪA�C
LONG
        );
        set("exits", ([                 
                "north" : __DIR__"city45",
                                        ]));
                
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/citysoldier":3 ,
                __DIR__"npc/cityguard":2 ,
                                        ]));           
        

        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

