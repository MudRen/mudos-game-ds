inherit ROOM;
void create()
{
        set("short","�s����");
        set("long",@LONG
�o�̬ݤU�h�i�H�ݲM����ӫ�s�W�����ΡA�ӥB���H�Pı�D�`�ΪA�A
��^�M�U���������P�A�O�H�ᬰ�Ǵe�A�|�P�J�ӬݤF�@�U�A�A�o�{��ӬO
�@���j�۵o�X������A���H���@�ؤQ��������Pı�C
LONG
        );
  
        set("exits", ([
            "down" : __DIR__"mu22",
            ]));
        set("objects",([
            __DIR__"sun-rock" : 1,
            ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}




