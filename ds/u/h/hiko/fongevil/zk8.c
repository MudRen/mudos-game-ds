inherit ROOM;
void create()
{
        set("short","�p�D");
        set("long",@LONG
�o�̬O���~�򪺨��D�A�w�g�i�H�ܲM���ݨ��񪺼ˤl�A�O�Τj��
�Ҭ䦨�A�ӥB�Q�����j�A�b�`�s�������p���ؿv���H�Ǵe�A�|�P�J�ӷj��
�o�ݤ���J�f�A�F�_��O�@���s�D�A��n�O��񪺤@�����C
LONG
        );
  
set("exits", ([
  "northeast" : __DIR__"zk7",
  "southwest" : __DIR__"zk9",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}


