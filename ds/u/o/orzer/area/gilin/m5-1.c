inherit ROOM;
void create()
{
        set("short","�s��");
        set("long",@LONG
�A�n���e���q�L�U�����檺�p�|�A�o�̪��D���e�s���֡A�Pı�߱�
�]���P�F�\�h�A�e���N�O�s�Y�U�A���e�q�ߵۤ@�ӭ�ӡA���A�ᬰ��_
�A�b�o�H�Ϩu�ܪ��a��A���M���x�L�b�u�ơC
LONG
        );
        set("exits", ([
  "southup" : __DIR__"m5",
  "north" : __DIR__"m5-2",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}







