// /u/f/frank/workroom.c
inherit ROOM;

void create()
{
        set("short", "FRANK�u�@��");
        set("long", @LONG
�@�ӭ�ê��ж�,�a�W�񺡤F�U�ةФl���ҫ�,�Ѫ�O�W�����F�U
�����O,�H�ɦb�ܴ����m�C�b�ж��������@�ӮѮ�,�W���ﺡ�F�\
�h���p����A�i���o�D�H�O�ӤQ���q�~���H�C�o�ɧA�L�N���ݨ�
�U�����ȱ�--�W���g��.....�F���A �I�I�I
LONG
        );
        set("exits", ([ 
  		"wiz" :"/d/wiz/hall1",
]));
   	set("no_clean_up", 0);
  	set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
	load_object("/obj/board/frank_b");

}
