inherit ROOM;

void create()
{
        set("short", "�ೣ���L����f");
        set("long", @LONG
�A���L�F�پx����D�A�@�B�@�B������F�@�ɤj�v�|�����f�A�b�o��
�S��ԣ�p�c�M��H�A�a�W�X�_�����b�A�u���@�Ǳq�j���Ǩ�������W��
�U�������A�M�@�ǳQ���Ӫ��ȫd�C���L�A�oť��@�ǤH�������n�A�b�A��
�n�_���X�ϤU�A�A�q���_�V�̭��ݡA�ݨ�@�s�C�Τj�~�A�b�̭��޺t�A��
�L�̪���A�A�A���D�L�̴N�O�ೣ�����Z�ҡA���ɳ��ݦb�̭��u���b����
�ɤ~�|�X�ӡA�קK�|�Z���A�ӳo�̷�M�N�O�ೣ���L�窺���f�F�C

LONG
        );
        set("exits", ([                 
                "north" : __DIR__"city31",
                "west" : __DIR__"city35",
                "south" : __DIR__"city37",
                                        ]));

        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/citysoldier":3 ,
                                            ]));           

                
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

