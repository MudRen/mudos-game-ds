inherit ROOM;
void create()
{
        set("short","���F�˪L����");
        set("long",@LONG
�o�̬O�˪L�������`�B�F�A���a������]�̬��@�p�A�ӥB�H����
���]�V�ӶV�j�A�]�\�A���U���N��o���L�̫O�@���F��A�]���A��
�ԷV�p�߰_�ӡA�]�\���O����²�檺�F��C
LONG
        );
        set("exits", ([
        "northwest" : __DIR__"t42", 
        "northeast" : __DIR__"t44",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}














