inherit ROOM;
void create()
{
     set("short","�W�E���l�m�߳��y���Űϡz");
      set("long",@LONG
�o�̳��O�y���ڰ򪺤��ť͡A�P��誺��ťͦ��ܤj���t�O�A�|�P��
�X�Q�������������¡A�O�H�Y�夣�w�A�o�@���D���O���y���ڰ򪺤H�m�\
�Ϊ��A�e�観�@�ӹq�l�G�i��(BBS)�C
LONG);
set("exits",([
      "south":__DIR__"2.c",
      "east":__DIR__"10.c",
      "west":__DIR__"8.c",
]) );
set("item_desc",([
"BBS":"�V���Olv 1x�׽m�ҡA�k��O�i�������C\n"
]));
        set("world", "future"); 
set("objects",([
__DIR__"npc/lv10" :4
]) );
setup();
replace_program(ROOM); 
}
