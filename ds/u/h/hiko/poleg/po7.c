inherit ROOM;
void create()
{
        set("short", "�y��������");        
        set("long",@LONG
�o�̬O�y�����������A�ݰ_�����Z���x���A�\�h�C�ȩM�������b��
���ʤ�`�Ϋ~�M�S���A�_��N�O�@�a�S�����A�̭��檺�F�賣�O�ݩ�y
�������S���O�a��O�R���쪺�A�]���ͷN�٤����A�F��]�O�ݩ󥫶��A
�i�H�L�h�@�@�C
LONG
        );
        set("exits", ([
  "north" : __DIR__"po7n",
  "west" : __DIR__"po4" ,  "east" : __DIR__"po8",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}




