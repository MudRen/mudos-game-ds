inherit MOBROOM;
void create()
{
        set("short", "�s��");
        set("long",@LONG
�o�̬O�ѫ��F�䪺�s���A���W���O���ݨӦ~�[���סA�ݨӫܤ֤H��
�즹�a�A�D����������O�ͤQ����D�A�s�W�ӨS����H�~��A�Pı�D�`
�R�ĵL�n�A��n�M�F�_��������e�p���C
LONG
        );
  
set("exits", ([
  "southwest" : __DIR__"mu1",
  "northeast" : __DIR__"mu3",
]));
set("chance",50);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"animal/gold-bug",
}) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 




