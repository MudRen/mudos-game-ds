inherit ROOM;
void create()
{
      set("short","�W�E���l�m�߳��y��Űϡz");
      set("long",@LONG
�o�̪��s�⮳�ۥ����j��B���F�A��o�̧˱o�@�ξD�A�u�����D�L��
�߸̨쩳�b�Q����C�ݡI�S���@�W�s�⪺�����j�������ˤF�ۤv�A�Q���@
�H����U�h�A�o�̬ݰ_�Өä��O�Q���w���C
LONG);
set("exits",([
     "east":__DIR__"2.c",
    "west":__DIR__"4.c",
]) );
set("objects",(
[__DIR__"npc/lv2_guard"   :4]
) );
        set("world", "future");
setup();
replace_program(ROOM); 
}
