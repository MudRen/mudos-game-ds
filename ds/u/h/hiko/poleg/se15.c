inherit ROOM;
void create()
{
        set("short", "�y�������y");        
        set("long",@LONG
�o�̬O�f������f������y�A�o������f�w�g���@�q�Z���F�A�]
���]����֤H�F�A���L�Pı�_�ӫo���|�Q���I��A�|�B�����Q���h��
�ͪ��b�o�̬��ʵۨҦp�H�~�ɥH�ή����̡A�ӥB���ۤ@��L�ڪ�����
���ѡA���H���۩M�۵M�@�骺�Pı�C
LONG
        );
        set("exits", ([
   "north" : __DIR__"se12",
   "southwest" : __DIR__"se14",
   "east" : __DIR__"se16", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}










