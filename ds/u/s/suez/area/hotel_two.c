// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "�ȴ̤G��");
	set("long",@LONG 
�o�̬O�ӡu�^�v�r�������Y�A���U�ݥi�H�ݨ�ȴ̪��j�U�A�@�Ӥ���
��b�ӱ�ǡA�O���ȤH�~��~�y�Ϊ��C�ӨC�ӫȩЪ����f������T�����
�A�o�X�H�H�������ƺ��F�|�P�A�i�H�ݥX�o�̪��D�H�Q���Ӥߥ��z�ȴ̪�
�Ʊ��C
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "eastdown" : __DIR__"hotel_step",
               "west": __DIR__"hotel_room1",
            "south": __DIR__"hotel_room2",
            "north": __DIR__"hotel_room3",

              ]));
        set("objects",([
              __DIR__"npc/drooler_wm" : 1,
              ]) );

         set("item_desc",([
        "����":"�@�ӯ��N���j�����A�̭��˺��F���C�����Ǳ��F�@�Ӥc�l�C\n",
        "����":"�զ⪺�����A�O�@�̶÷Q�X�Ӫ��F��A���@�w�s�b�C\n",
         ]));

	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}