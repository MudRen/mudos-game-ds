inherit ROOM;
void create()
{
        set("short","�j��W");
        set("long",@LONG
�A�b�j��W�樫�ۡA�j��W�������u���ӨΡA�\�h���e����K�צ�e��
�A���A�n�@�����}��K�@���e�i�A���L�j�쳻�ݶǨө_�S���n�A�ӥB�o�ǥj
����G�Q����F��O�@�ۡA���𤣷|�Q���j�P�A���L�o�W�����ͪ��ݨӤ���
�͵��C
LONG
        );
        set("exits", ([
  "west" : __DIR__"stn1",
  "east" : __DIR__"stn3",
]));
        set("no_clean_up", 0);
        set("light",0);
        setup();
        replace_program(ROOM);
}










