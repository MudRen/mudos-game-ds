inherit ROOM;
void create()
{
        set("short", "�s��");
        set("long",@LONG
�o�̬O�ѫ��F�䪺�s���A���W���O���ݨӦ~�[���סA�ݨӫܤ֤H��
�즹�a�A�D����������O�ͤQ����D�A�s�W�ӨS����H�~��A�Pı�D�`
�R�ĵL�n�A��n�M�_�䦳������e�p���C
LONG
        );
  
set("exits", ([
  "southwest" : __DIR__"mu2",
  "north" : __DIR__"mu4",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 




