inherit ROOM;
void create()
{
 set("short","�t���c");
 set("long",@LONG
�o�̬O���ж��|���a��A�C�����n�ƶ��ХD�B�����t�ϩM�U��
�D�|�b�o�̫ŧG�A�������s���i�H�e�ǤU�Ƥd�H�A�|�P��W��۩���
���ץ\���~�A�|��۬W�W�J�ۼư��ݮݦp�ͪ��s�A�s�L�W�I�۸U�~��
�����t���N�|�P�ӫG�C
LONG
    );
 set("exits",([ "west": __DIR__"lighttop",
                "down": __DIR__"wl",
                "up": __DIR__"fire",
    ])); 

set("objects",([
__DIR__"item/ming-sky_tree":1,
]));

        set("no_kill",1);
        set("light",1);
 setup();
  call_other("/obj/board/ming_club_b" , "???");
        set("stroom",1);
}
//�o�̸Ӧ���board
//have ���Фj�ƪO(Ming board)
//�o�O�@�ӥΨ�post�Ф��j�ƪ��d���O

