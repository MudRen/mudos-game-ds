inherit ROOM;
void create()
{
        set("short","�p�D");
        set("long",@LONG
�o�̬O���~�򪺨��D�A�w�g�i�H�ܲM���ݨ��񪺼ˤl�A�O�Τj��
�Ҭ䦨�A�ӥB�Q�����j�A�b�`�s�������p���ؿv���H�Ǵe�A�|�P�J�ӷj��
�o�ݤ���J�f�A��_��O�ݩ��񪺤@�����A�F�n�O�@�y�s�^�C
LONG
        );
  
set("exits", ([
  "northwest" : __DIR__"zk9",
  "southeast" : __DIR__"zk1",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}


