inherit ROOM;
void create()
{
        set("short", "�y�������y");        
        set("long",@LONG
�o�̬O�f������f���񪺮��y�A���y�W���۳\�h���ͪ��A�`�`����
���ҨӦ��a�����@�Ǯ����A�ӨӦ����C�Ȥ]�`�ӳo���[���A��O���䪺
�@�ӯS��A�������h�@���j���űy�y������A�[�W�ѤW�ն���Ũ���A
���H���ͤ@�ض}�諸���h�C
LONG
        );
        set("exits", ([
   "south" : __DIR__"se16",
   "southeast" : __DIR__"se10",
   "west" : __DIR__"se12", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}







