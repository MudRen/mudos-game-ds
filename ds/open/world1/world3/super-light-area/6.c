inherit ROOM;
void create()
{
       set("short","�W�E���l�m�߳��y���@�ǡz");
      set("long",@LONG
�o�̬O�W�E���l�m�߳������@�ǡA�@�i��o�̴N�D��@�Ѩ���Ĩ�
�A���䦳��W�����N�h���b�Ρy���E�����O�z�m�Ϥ@�W�Q���l�j�~�g���s
��A���䱾�ۤ@�ӵP�l(sign)�C
LONG);
set("item_desc",([ 
"sign":"�������G1000�q�l���C\n"
]) );
set("objects",([
__DIR__"npc/doctor.c"      :1,
]));
        set("world", "future"); 
set("exits",([
      "west":__DIR__"5.c",
]) );
setup();
}
