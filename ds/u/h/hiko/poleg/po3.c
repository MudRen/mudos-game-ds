inherit ROOM;
void create()
{
        set("short", "�y�����n��");        
        set("long",@LONG
�o�̬O�y������D�A���_��@����L�h�i�H��������j���A���̤]
�y���������O�H�ο�H���ͪ��a��A���L�ƹ�W�b���W�D�ͦs�O�@���
�����ơA�ҥH�y�����]�O�ּƴX�ӥH�����ͪ����l�A�̪���G���ۼv�T
���l�w�窺�Ƶo�͡A�O�����H�̤Q�����w�C
LONG
        );
        set("exits", ([
  "north" : __DIR__"po4",
  "south" : __DIR__"po2",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}



