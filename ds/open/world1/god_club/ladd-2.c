inherit ROOM;
void create()
{
    set("short","�ѯ���ĤG�h");
    set("long",@long
�o�y���q�J��������N�O�ǻ������j�ѯ��ҫسy���u�ѯ���v�C
�ѩ�ѯ����O���v�T�A�o�y�������q�쯫�ҨC�Ӧa��A�Ӳ{�b�Ҧb
����m�O�ѯ��𪺲ĤG�h�A���U�ӱ�i�H�q�D�Ĥ@�h�C���h���F�|��
�A�ѬɡB�P�ɡB�߬ɡB�]�ɡA�_��h�O�|�ɤ����ڤ��P�����ѭ̶}�|
�ҨϥΪ��|ĳ�ǡC
long);
    set("exits",([
    "down" : __DIR__"ladder-1",
    "northeast" : __DIR__"flag_faerie",
  "up" : __DIR__"bank", 
  "north" : __DIR__"eldership", 
    "southwest" : __DIR__"flag_dark",
    "southeast" : __DIR__"flag_devilrom",
    "northwest" : __DIR__"flag_heaven",
]));
    set("objects",([
    __DIR__"shopman":1,
]));
    set("light",1);
    setup();
        set("stroom", 1);
}
