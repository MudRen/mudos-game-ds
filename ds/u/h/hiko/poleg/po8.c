inherit ROOM;
void create()
{
        set("short", "�y��������");        
set("long",@LONG
�o�̬O���������A�i�Hť��@�������n���A�O�Hı�o�ǩǡA���
�O�n�䦳�@�a���K�E�A�̭������K�v��ť���M�ɿ��Ѯv�ŬO�P���A�]��
���K�޳N�]�Q���D�W�A�_��O�@�a���E�A�ݱo�X�Ӥ]�O�Ѧr���F�A�F��
�h�]�O�����C
LONG
        );
        set("exits", ([
  "north" : __DIR__"po8n",
  "west" : __DIR__"po7" , 
  "east" : __DIR__"po9",
  "south" : __DIR__"po8s",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}





