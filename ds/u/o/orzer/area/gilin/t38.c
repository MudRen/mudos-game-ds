inherit ROOM;
void create()
{
        set("short","���F�˪L����");
        set("long",@LONG
�o�̬O�˪L�������̲`�B�A�C�u�n�V�a�񦹳B�q�o����A�ݨ���
�ӴN�O���B�ҶǥX�ӡA�����D�O����F��b���a�A�]�\�O���򰪤H�b
�o�������ۡA�]�\���ӥJ�Ӫ��b���񱴴M�@�f�C
LONG
        );
        set("exits", ([
        "north" : __DIR__"t37",         
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}














