inherit ROOM;
void create()
{
        set("short","���");
        set("long",@LONG
�A�Ө�F��Ӹ̭��A�o�̪��x�L�ݨӰV�m�����A���Ӥ��O���q�h�L
�A�ӭӬݨӫ²r�𲱡A�ӥB�����U�Q�L��A�Pı�ɮɨ�賣�O����ĵ��
�A�o�]�\�O�§ʬ��Ӫ���U�����C
LONG
        );
        set("exits", ([
  "up" : __DIR__"m5-4",
  "east" : __DIR__"m5-2",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}








