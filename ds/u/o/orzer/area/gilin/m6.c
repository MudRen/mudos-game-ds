inherit ROOM;
void create()
{
        set("short","�s��");
        set("long",@LONG
�A�n���e���q�L�U�����檺�p�|�A�o�̪��D���e�s���֡A�Pı�߱�
�]���P�F�\�h�A�e���N�O�s�Y�U�A���G�q���ۤ@�y�˪L�A�ݨӳ����{�e
�A��^�Q�����M�`�A�i�঳����M�I���ƪ��C
LONG
        );
        set("exits", ([
  "southup" : __DIR__"m5-5",
  "northwest" : __DIR__"m7",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}





