inherit ROOM;

void create()
{
        set("short", "�{�ɤu�@��");
        set("long", @LONG
�o�̬O�ڤۤC��uŪ���{�ɤu�@�ǡC

	���o�uŪ�ͨ����ɽШc�O�H�U�ǫh:

	1. ���i�Q�ίS�v�ϧQ��L���a
	2. ���i�Q�ίS�v�M�`��L���a
	3. ���i������L���a���󪫫~
	4. ���i�M��L���a�o�;԰�
	
	�H�ϥH�W�W�h�N���ɡA�ר����A���ΡC
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : "/open/world2/lichi_town_2/map_5_26",
]));
        set("no_clean_up", 0);
	set("no_fight",1);
    set("valid_startroom",1);
	set("light",1);
        set("objects", ([ 
        ]) );
        setup();

call_other( "/obj/board/superplayer_b", "???" );
}

