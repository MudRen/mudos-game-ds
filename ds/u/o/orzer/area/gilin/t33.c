inherit ROOM;
void create()
{
        set("short","���F�˪L����");
        set("long",@LONG
�A�C�C���¦V�˪L�`�B���h�A�H���ͪ��]�V�ӶV�h�A�q�L�̬ݨ���
�M���Ӧ��N�ѡA�o�٬O�|�����ө����H�A�ϩ��b�O�õۤ���F��@��A
���G�]�N�O�o�Ѱ����A���L���~���ʤU�h�C
LONG
        );
        set("exits", ([
        "southwest" : __DIR__"t34", 
        "southeast" : __DIR__"t32",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}














