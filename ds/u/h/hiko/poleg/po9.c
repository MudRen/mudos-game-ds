inherit ROOM;
void create()
{
        set("short", "�y��������");        
        set("long",@LONG
�o�̬O�����F���A�H�s�w�g���֤F�A���L�̵M�Z���x�A�_��ǨӤ@
�}�}�����{���A�J�Ӥ@�ݬO�@�a���c�A�ݨӭn�R�s�A�����n�h���F�A�F
��O���y�����s���A���O���l���j�Ʈɪ��E���a�A�ݨӻE���F�@�ǤH��
�A�]�\������Ƶo�͡C
LONG
        );
        set("exits", ([
  "north" : __DIR__"po9n",
  "west" : __DIR__"po8" ,  
  "east" : __DIR__"po10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}





