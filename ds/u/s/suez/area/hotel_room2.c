// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "�˩�");
	set("long",@LONG 
�ЦW�˩��A�C�����ڡA�o�̴N�O�\�h��H�h�l�̳��w���ж��C��M�]
���\�h�ӤH�G�@�����o�I�o�̯u����B���O�ˤl�A�@�T���ˤs���A�@ŧ��
î�A���~�˪K���J�Ф��C�a���ˤl���𪺭����_�j�e�A�L�Ѫ����ɳo�̤�
�M�M�n�p���C
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "north" : __DIR__"hotel_two",

              ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}