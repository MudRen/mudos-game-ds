// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "�i��");
	set("long",@LONG
�o���ȩХs���i�ӡA�U�W��q�A�C��ıߡA�i�H�ѳo���ȩЬݨ���R
���i���C�������~�A��o���p�L�p�ȡA�Ȥ쪺�ɡA�[�W�@�T�᳾�e�A�ϱo
�ܦh�k�ȳ����w�n��o���ЩO�I
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "east" : __DIR__"hotel_two",
               ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}