inherit ROOM;
void create()
{
        set("short","���F�˪L����");
        set("long",@LONG
�o�̬O�˪L�������`�B�F�A�o�̦����������C�u�n�A���G���ۤ�
�򤣴M�����ƪ��s�b�A�H���ͪ��Pı�]����}�֡A���D������L�̩�
�ߩȪ����~�A�]�\���ӥJ�Ӫ��b���񱴴M�@�f�C
LONG
        );
        set("exits", ([
        "south" : __DIR__"t38", 
        "northeast" : __DIR__"t36",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}














