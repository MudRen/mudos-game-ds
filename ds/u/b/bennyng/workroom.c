inherit ROOM;
void create ()
{
        set ("short",  "�������Ω�" );
        set ("long", @LONG
�o�̬O�������ΩСA�q�o�̧A�i�H�P��t��ǨӪ������O�q�A
�o�ؤO�q�ϧAı�o���A�h�ҡA�q���~�ݥX�h�A�A�i�H�ݨ쪱�a�̥�
�V�O�D�Ըt���h���D�o�̦��@�Ӭy�����ѦU�촣�ѷN���D
LONG);
        set("light", 1);
        set("exits", ([ /* sizeof() == 4 */
   "luky":"/u/l/luky/workroom.c",
   "shengsan":"/u/s/shengsan/workroom.c",
   "wiz" : "/d/wiz/hall1",
   "east" : "/u/b/bennyng/test/rm1.c",
]));
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
         call_other( "/obj/board/bennyng_b", "???" ); 
}
