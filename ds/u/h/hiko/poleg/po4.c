inherit ROOM;
void create()
{
        set("short", "�y�����谼");        
        set("long",@LONG
�o�̤w�g�O�y���������F�A���_��i�H��y����������A�i�H�ݨ�
���Ҧb���Ԥu�@�A�L�̦b�⮷�쪺����M�z�A�Ʊ���Ӧn�����A�Ӧ�
�ǫh�O���X�誺�ǳơA���������n�U���w���b���W�O�ܵL�U���A����h
�O�����A�i�H�L�h�ݬݦ�����s�A�F��C
LONG
        );
        set("exits", ([
  "north" : __DIR__"po5",
  "south" : __DIR__"po3",
  "east"  : __DIR__"po7",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}



