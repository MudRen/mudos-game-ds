inherit ROOM;
void create()
{
      set("short","�W�E���l�m�߳��y�J�f�z");
      set("long",@LONG
�o�̬O�y�W�E���l�m�߳��z���J�f�A�̭��Ǩ��������}�Ť��n�A�ϩ�
�O���Ӫ����s�o�¡A�n��@�����ƪ��q�q�]�����A���Ӫ����l�j���O�q��
�u�O�ܮ��ƪ��A���䦳�@�Ӷ]���O�A�̭��O���l�a��Գ��C
LONG);
set("exits",([
      "enter":__DIR__"2.c",
      "south":"/open/world3/tmr/basic/digging_road6.c",
] ) );
set("outdoors","land");
        set("world", "future"); 
setup();
 replace_program(ROOM);
}
