inherit ROOM;
void create()
{
     set("short","�W�E���l�m�߳��y���Űϡz");
      set("long",@LONG
�o�̪������H�ݰ_�ӤQ������A�ݨӭY���O������l���H�O���|��
��o�䪺�A���ǨӰ}�}���j���n�A�ݨӤS���H�Q���ˤF�A�u�����D�o��
���ͤƤH�O���򰵪��A�p���j��I�H
LONG);
set("exits",([
       "west":__DIR__"10.c",
]) );
        set("world", "future"); 
set("objects",([
__DIR__"npc/lv12"  : 4,
]));
setup();
replace_program(ROOM); 
}
