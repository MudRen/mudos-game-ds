inherit MOBROOM;
void create()
{
        set("short", "�s�D");
        set("long",@LONG
�o�̬O�q���s�W���s�D�A���W���O���ݨӦ~�[���סA�ݨӫܤ֤H��
�즹�a�A�D����ǤQ���U���A�]�����_�ӫD�`�w�C�A�ݨӭn��s�W�ӭn
�ᤣ�֮ɶ��A�_�䦳�@�������s�W�A�F�_�h�O���s�y�C
LONG
        );
  
set("exits", ([
  "northup" : __DIR__"mu5",
  "northeast" : __DIR__"mu11",
  "south" : __DIR__"mu3",
]));
set("chance",50);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"animal/sciurine",
}) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 







