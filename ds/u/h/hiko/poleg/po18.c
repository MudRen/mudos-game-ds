inherit ROOM;
void create()
{
        set("short", "�y�����F��");        
        set("long",@LONG
�o�̬O�y�����s�����F������D�A�b�A���e���ۤ@���Q���j���ؿv
���A�ݰ_�ӸӴN�O�����a�A�Pı�_�Ӹ��������v�@��ۮt�Ƥj�A�O�H
�����h�ð_�ӡA����@�ӧ������ۨ���h�]�O�A���L�٬O�u���i�h�@�@
�~���D�]�ѤF�C
LONG
        );
        set("exits", ([  
"enter" : __DIR__"vi1",
"west" : __DIR__"po17",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}








