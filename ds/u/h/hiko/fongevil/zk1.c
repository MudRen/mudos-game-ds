inherit ROOM;
void create()
{
        set("short", "�s�^");
        set("long",@LONG
�o�̬ݰ_�ӤQ�����ˡA�Ѥs�^�W�ݥh�i�H�ݨ�\�h�����X�A���H��
���Q�h�d�b���a�A�åB�������@�شH�N���Pı�A���G�N�O�ҿת����ߡA
���`�]�O���L�H�ܡA�ӥB�V���e�Pı�N�V�j�P�A���񪺯��H���o�X��
�n���]���A�����ԷX�A��_�M�F�_��������e�p���C
LONG
        );
  
set("exits", ([
  "south" : __DIR__"zk22",
  "northwest" : __DIR__"zk10",
  "northeast" : __DIR__"zk11",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 




