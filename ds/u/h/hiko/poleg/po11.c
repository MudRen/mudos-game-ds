inherit ROOM;
void create()
{
        set("short", "�y��������");        
        set("long",@LONG
�o�̬O�y�����s���_���A�ѩ��ݩ󤺰��ݰ_�ӤH���֡A�b�A���F��
���ۤ@����v�A�Pı�Q������o����S��A�O�οj�䪺�A�b�o�Ӥj����
�H�̬ҥέT��s�ήɡA�o���o�اΦ��ؿv�A�Q���a��ӬO�Z�����Ať��
���|�Y�شN��o����C
LONG
        );
        set("exits", ([
  "north" : __DIR__"po12",  
  "east" : __DIR__"po11e",
  "south" : __DIR__"po10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}







