// Room: /u/s/suez/workroom.c

#include <ansi.h>
inherit ROOM;


void create()

{

	set("short",HIG "�_�P�a"NOR);

	set("long", @LONG  
�A�@�i�J�o�өж��A�o�{�o�̳��O�˻s���a��A��⪺��
�ȤW�\���F�@�����j�N���u�ˮѡA�D�D�����N��W���e�j����
��Ÿ�ʡA���G�����f�Ǧ��i�p�Ѯ�A��W�\�F�����O���M�\�h
���C�o�̴N�O�Z�L�_�LĬ�l�_�����~���ҡA���������H�٥H
���O�����̤H���Ȫ��ѩЩO�I
LONG

);
	
                set("exits", ([ /* sizeof() == 2 */
 
                "out" : __DIR__"fall",

                "hall" : "/d/wiz/hall1",
                "com" : "/u/c/cominging/workroom",
]));

	set("item_desc", ([ /* sizeof() == 1 */

  "�u�ˮ�" : "�o�ǽu�ˮѤW�e���F���e.....

�ݨӳo���Τl���D�H....��....�C 
",

]));

	set("world", "undefine");

	set("no_clean_up", 0);

	set("valid_startroom", 1);


	setup();

	 call_other("/obj/board/suez_b", "???");


}
