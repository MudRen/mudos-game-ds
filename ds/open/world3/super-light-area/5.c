inherit ROOM;
void create()
{
      set("short","�W�E���l�m�߳��y��Űϡz");
      set("long",@LONG
���e�@���կ���A���䦳��ӷs�⥿�b�X�O�ץL�̪����l�j�A�ݨ�
�O�L�̪����l���i���X�F�@�I���D�A�᭱���@�W���űнm���b�оɥL����
�ͽm�ߥΥ��l�j�g�q�l�Ч�C
LONG);
set("exits",([
      "west":__DIR__"2.c",
       "east":__DIR__"6.c",
]) );
set("objects",([
__DIR__"npc/lv3_guard"      :4,
]) );
        set("world", "future"); 
setup();
replace_program(ROOM);
}
